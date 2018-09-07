/*
 * drivers/video/riva/rivafb.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __RIVAFB_H
#define __RIVAFB_H

#include <linux/fb.h>
#include <video/vga.h>
#include <linux/i2c.h>
#include <linux/i2c-algo-bit.h>

#include "riva_hw.h"

/* GGI compatibility macros */
#define NUM_SEQ_REGS		0x05
#define NUM_CRT_REGS		0x41
#define NUM_GRC_REGS		0x09
#define NUM_ATC_REGS		0x15

/* I2C */
#define DDC_SCL_READ_MASK       (1 << 2)
#define DDC_SCL_WRITE_MASK      (1 << 5)
#define DDC_SDA_READ_MASK       (1 << 3)
#define DDC_SDA_WRITE_MASK      (1 << 4)

/* holds the state of the VGA core and extended Riva hw state from riva_hw.c.
 * From KGI originally. */
struct riva_regs {
	u8 attr[NUM_ATC_REGS];
	u8 crtc[NUM_CRT_REGS];
	u8 gra[NUM_GRC_REGS];
	u8 seq[NUM_SEQ_REGS];
	u8 misc_output;
	RIVA_HW_STATE ext;
};

struct riva_par;

struct riva_i2c_chan {
	struct riva_par *par;
	unsigned long   ddc_base;
	struct i2c_adapter adapter;
	struct i2c_algo_bit_data algo;
};

struct riva_par {
	RIVA_HW_INST riva;	/* interface to riva_hw.c */
	u32 pseudo_palette[16]; /* default palette */
	u32 palette[16];        /* for Riva128 */
	u8 __iomem *ctrl_base;	/* virtual control register base addr */
	unsigned dclk_max;	/* max DCLK */

	struct riva_regs initial_state;	/* initial startup video mode */
	struct riva_regs current_state;
#ifdef CONFIG_X86
	struct vgastate state;
#endif
	struct mutex open_lock;
	unsigned int ref_count;
	unsigned char *EDID;
	unsigned int Chipset;
	int forceCRTC;
	Bool SecondCRTC;
	int FlatPanel;
	struct pci_dev *pdev;
	int cursor_reset;
#ifdef CONFIG_MTRR
	struct { int vram; int vram_valid; } mtrr;
#endif
	struct riva_i2c_chan chan[3];
};

void riva_common_setup(struct riva_par *);
unsigned long riva_get_memlen(struct riva_par *);
unsigned long riva_get_maxdclk(struct riva_par *);
void riva_delete_i2c_busses(struct riva_par *par);
void riva_create_i2c_busses(struct riva_par *par);
int riva_probe_i2c_connector(struct riva_par *par, int conn, u8 **out_edid);

#endif /* __RIVAFB_H */

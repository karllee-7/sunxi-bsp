/*
 * arch/mips/include/asm/mach-db1x00/db1300.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
/*
 * NetLogic DB1300 board constants
 */

#ifndef _DB1300_H_
#define _DB1300_H_

/* FPGA (external mux) interrupt sources */
#define DB1300_FIRST_INT	(ALCHEMY_GPIC_INT_LAST + 1)
#define DB1300_IDE_INT		(DB1300_FIRST_INT + 0)
#define DB1300_ETH_INT		(DB1300_FIRST_INT + 1)
#define DB1300_CF_INT		(DB1300_FIRST_INT + 2)
#define DB1300_VIDEO_INT	(DB1300_FIRST_INT + 4)
#define DB1300_HDMI_INT		(DB1300_FIRST_INT + 5)
#define DB1300_DC_INT		(DB1300_FIRST_INT + 6)
#define DB1300_FLASH_INT	(DB1300_FIRST_INT + 7)
#define DB1300_CF_INSERT_INT	(DB1300_FIRST_INT + 8)
#define DB1300_CF_EJECT_INT	(DB1300_FIRST_INT + 9)
#define DB1300_AC97_INT		(DB1300_FIRST_INT + 10)
#define DB1300_AC97_PEN_INT	(DB1300_FIRST_INT + 11)
#define DB1300_SD1_INSERT_INT	(DB1300_FIRST_INT + 12)
#define DB1300_SD1_EJECT_INT	(DB1300_FIRST_INT + 13)
#define DB1300_OTG_VBUS_OC_INT	(DB1300_FIRST_INT + 14)
#define DB1300_HOST_VBUS_OC_INT	(DB1300_FIRST_INT + 15)
#define DB1300_LAST_INT		(DB1300_FIRST_INT + 15)

/* SMSC9210 CS */
#define DB1300_ETH_PHYS_ADDR	0x19000000
#define DB1300_ETH_PHYS_END	0x197fffff

/* ATA CS */
#define DB1300_IDE_PHYS_ADDR	0x18800000
#define DB1300_IDE_REG_SHIFT	5
#define DB1300_IDE_PHYS_LEN	(16 << DB1300_IDE_REG_SHIFT)

/* NAND CS */
#define DB1300_NAND_PHYS_ADDR	0x20000000
#define DB1300_NAND_PHYS_END	0x20000fff

#endif	/* _DB1300_H_ */

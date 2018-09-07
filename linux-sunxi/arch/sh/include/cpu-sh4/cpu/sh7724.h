/*
 * arch/sh/include/cpu-sh4/cpu/sh7724.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __ASM_SH7724_H__
#define __ASM_SH7724_H__

/* Boot Mode Pins:
 *
 * MD0: CPG - Clock Mode 0->7
 * MD1: CPG - Clock Mode 0->7
 * MD2: CPG - Clock Mode 0->7
 * MD3: BSC - Area0 Bus Width (16/32-bit) [CS0BCR.9,10]
 * MD5: BSC - Endian Mode (L: Big, H: Little) [CMNCR.3]
 * MD8: Test Mode
 * BOOT: FBR - Boot Mode (L: MMCIF, H: Area0)
 */

/* Pin Function Controller:
 * GPIO_FN_xx - GPIO used to select pin function
 * GPIO_Pxx - GPIO mapped to real I/O pin on CPU
 */
enum {
	/* PTA */
	GPIO_PTA7, GPIO_PTA6, GPIO_PTA5, GPIO_PTA4,
	GPIO_PTA3, GPIO_PTA2, GPIO_PTA1, GPIO_PTA0,

	/* PTB */
	GPIO_PTB7, GPIO_PTB6, GPIO_PTB5, GPIO_PTB4,
	GPIO_PTB3, GPIO_PTB2, GPIO_PTB1, GPIO_PTB0,

	/* PTC */
	GPIO_PTC7, GPIO_PTC6, GPIO_PTC5, GPIO_PTC4,
	GPIO_PTC3, GPIO_PTC2, GPIO_PTC1, GPIO_PTC0,

	/* PTD */
	GPIO_PTD7, GPIO_PTD6, GPIO_PTD5, GPIO_PTD4,
	GPIO_PTD3, GPIO_PTD2, GPIO_PTD1, GPIO_PTD0,

	/* PTE */
	GPIO_PTE7, GPIO_PTE6, GPIO_PTE5, GPIO_PTE4,
	GPIO_PTE3, GPIO_PTE2, GPIO_PTE1, GPIO_PTE0,

	/* PTF */
	GPIO_PTF7, GPIO_PTF6, GPIO_PTF5, GPIO_PTF4,
	GPIO_PTF3, GPIO_PTF2, GPIO_PTF1, GPIO_PTF0,

	/* PTG */
			      GPIO_PTG5, GPIO_PTG4,
	GPIO_PTG3, GPIO_PTG2, GPIO_PTG1, GPIO_PTG0,

	/* PTH */
	GPIO_PTH7, GPIO_PTH6, GPIO_PTH5, GPIO_PTH4,
	GPIO_PTH3, GPIO_PTH2, GPIO_PTH1, GPIO_PTH0,

	/* PTJ */
	GPIO_PTJ7, GPIO_PTJ6, GPIO_PTJ5,
	GPIO_PTJ3, GPIO_PTJ2, GPIO_PTJ1, GPIO_PTJ0,

	/* PTK */
	GPIO_PTK7, GPIO_PTK6, GPIO_PTK5, GPIO_PTK4,
	GPIO_PTK3, GPIO_PTK2, GPIO_PTK1, GPIO_PTK0,

	/* PTL */
	GPIO_PTL7, GPIO_PTL6, GPIO_PTL5, GPIO_PTL4,
	GPIO_PTL3, GPIO_PTL2, GPIO_PTL1, GPIO_PTL0,

	/* PTM */
	GPIO_PTM7, GPIO_PTM6, GPIO_PTM5, GPIO_PTM4,
	GPIO_PTM3, GPIO_PTM2, GPIO_PTM1, GPIO_PTM0,

	/* PTN */
	GPIO_PTN7, GPIO_PTN6, GPIO_PTN5, GPIO_PTN4,
	GPIO_PTN3, GPIO_PTN2, GPIO_PTN1, GPIO_PTN0,

	/* PTQ */
	GPIO_PTQ7, GPIO_PTQ6, GPIO_PTQ5, GPIO_PTQ4,
	GPIO_PTQ3, GPIO_PTQ2, GPIO_PTQ1, GPIO_PTQ0,

	/* PTR */
	GPIO_PTR7, GPIO_PTR6, GPIO_PTR5, GPIO_PTR4,
	GPIO_PTR3, GPIO_PTR2, GPIO_PTR1, GPIO_PTR0,

	/* PTS */
		   GPIO_PTS6, GPIO_PTS5, GPIO_PTS4,
	GPIO_PTS3, GPIO_PTS2, GPIO_PTS1, GPIO_PTS0,

	/* PTT */
	GPIO_PTT7, GPIO_PTT6, GPIO_PTT5, GPIO_PTT4,
	GPIO_PTT3, GPIO_PTT2, GPIO_PTT1, GPIO_PTT0,

	/* PTU */
	GPIO_PTU7, GPIO_PTU6, GPIO_PTU5, GPIO_PTU4,
	GPIO_PTU3, GPIO_PTU2, GPIO_PTU1, GPIO_PTU0,

	/* PTV */
	GPIO_PTV7, GPIO_PTV6, GPIO_PTV5, GPIO_PTV4,
	GPIO_PTV3, GPIO_PTV2, GPIO_PTV1, GPIO_PTV0,

	/* PTW */
	GPIO_PTW7, GPIO_PTW6, GPIO_PTW5, GPIO_PTW4,
	GPIO_PTW3, GPIO_PTW2, GPIO_PTW1, GPIO_PTW0,

	/* PTX */
	GPIO_PTX7, GPIO_PTX6, GPIO_PTX5, GPIO_PTX4,
	GPIO_PTX3, GPIO_PTX2, GPIO_PTX1, GPIO_PTX0,

	/* PTY */
	GPIO_PTY7, GPIO_PTY6, GPIO_PTY5, GPIO_PTY4,
	GPIO_PTY3, GPIO_PTY2, GPIO_PTY1, GPIO_PTY0,

	/* PTZ */
	GPIO_PTZ7, GPIO_PTZ6, GPIO_PTZ5, GPIO_PTZ4,
	GPIO_PTZ3, GPIO_PTZ2, GPIO_PTZ1, GPIO_PTZ0,

	/* BSC (PTA/PTB/PTJ/PTQ/PTR/PTT) */
	GPIO_FN_D31, GPIO_FN_D30, GPIO_FN_D29, GPIO_FN_D28,
	GPIO_FN_D27, GPIO_FN_D26, GPIO_FN_D25, GPIO_FN_D24,
	GPIO_FN_D23, GPIO_FN_D22, GPIO_FN_D21, GPIO_FN_D20,
	GPIO_FN_D19, GPIO_FN_D18, GPIO_FN_D17, GPIO_FN_D16,
	GPIO_FN_D15, GPIO_FN_D14, GPIO_FN_D13, GPIO_FN_D12,
	GPIO_FN_D11, GPIO_FN_D10, GPIO_FN_D9,  GPIO_FN_D8,
	GPIO_FN_D7,  GPIO_FN_D6,  GPIO_FN_D5,  GPIO_FN_D4,
	GPIO_FN_D3,  GPIO_FN_D2,  GPIO_FN_D1,  GPIO_FN_D0,
	GPIO_FN_A25, GPIO_FN_A24, GPIO_FN_A23, GPIO_FN_A22,
	GPIO_FN_CS6B_CE1B,  GPIO_FN_CS6A_CE2B,
	GPIO_FN_CS5B_CE1A,  GPIO_FN_CS5A_CE2A,
	GPIO_FN_WE3_ICIOWR, GPIO_FN_WE2_ICIORD,
	GPIO_FN_IOIS16,     GPIO_FN_WAIT,
	GPIO_FN_BS,

	/* KEYSC (PTA/PTB)*/
	GPIO_FN_KEYOUT5_IN5, GPIO_FN_KEYOUT4_IN6, GPIO_FN_KEYIN4,
	GPIO_FN_KEYIN3,  GPIO_FN_KEYIN2,  GPIO_FN_KEYIN1,  GPIO_FN_KEYIN0,
	GPIO_FN_KEYOUT3, GPIO_FN_KEYOUT2, GPIO_FN_KEYOUT1, GPIO_FN_KEYOUT0,

	/* ATAPI (PTA/PTB/PTK/PTR/PTS/PTW) */
	GPIO_FN_IDED15, GPIO_FN_IDED14, GPIO_FN_IDED13, GPIO_FN_IDED12,
	GPIO_FN_IDED11, GPIO_FN_IDED10, GPIO_FN_IDED9,  GPIO_FN_IDED8,
	GPIO_FN_IDED7,  GPIO_FN_IDED6,  GPIO_FN_IDED5,  GPIO_FN_IDED4,
	GPIO_FN_IDED3,  GPIO_FN_IDED2,  GPIO_FN_IDED1,  GPIO_FN_IDED0,
	GPIO_FN_IDEA2,     GPIO_FN_IDEA1,     GPIO_FN_IDEA0,  GPIO_FN_IDEIOWR,
	GPIO_FN_IODREQ,    GPIO_FN_IDECS0,    GPIO_FN_IDECS1, GPIO_FN_IDEIORD,
	GPIO_FN_DIRECTION, GPIO_FN_EXBUF_ENB, GPIO_FN_IDERST, GPIO_FN_IODACK,
	GPIO_FN_IDEINT,    GPIO_FN_IDEIORDY,

	/* TPU (PTB/PTR/PTS) */
	GPIO_FN_TPUTO3, GPIO_FN_TPUTO2, GPIO_FN_TPUTO1, GPIO_FN_TPUTO0,
	GPIO_FN_TPUTI3, GPIO_FN_TPUTI2,

	/* LCDC (PTC/PTD/PTE/PTF/PTM/PTR) */
	GPIO_FN_LCDD23, GPIO_FN_LCDD22, GPIO_FN_LCDD21, GPIO_FN_LCDD20,
	GPIO_FN_LCDD19, GPIO_FN_LCDD18, GPIO_FN_LCDD17, GPIO_FN_LCDD16,
	GPIO_FN_LCDD15, GPIO_FN_LCDD14, GPIO_FN_LCDD13, GPIO_FN_LCDD12,
	GPIO_FN_LCDD11, GPIO_FN_LCDD10, GPIO_FN_LCDD9,  GPIO_FN_LCDD8,
	GPIO_FN_LCDD7,  GPIO_FN_LCDD6,  GPIO_FN_LCDD5,  GPIO_FN_LCDD4,
	GPIO_FN_LCDD3,  GPIO_FN_LCDD2,  GPIO_FN_LCDD1,  GPIO_FN_LCDD0,
	GPIO_FN_LCDVSYN,  GPIO_FN_LCDDISP,  GPIO_FN_LCDRS,  GPIO_FN_LCDHSYN,
	GPIO_FN_LCDCS,    GPIO_FN_LCDDON,   GPIO_FN_LCDDCK, GPIO_FN_LCDWR,
	GPIO_FN_LCDVEPWC, GPIO_FN_LCDVCPWC, GPIO_FN_LCDRD,  GPIO_FN_LCDLCLK,

	/* SCIF0 (PTF/PTM) */
	GPIO_FN_SCIF0_TXD, GPIO_FN_SCIF0_RXD, GPIO_FN_SCIF0_SCK,

	/* SCIF1 (PTL) */
	GPIO_FN_SCIF1_SCK, GPIO_FN_SCIF1_RXD, GPIO_FN_SCIF1_TXD,

	/* SCIF2 (PTE/PTF/PTN) with LCDC, VOU */
	GPIO_FN_SCIF2_L_TXD, GPIO_FN_SCIF2_L_SCK, GPIO_FN_SCIF2_L_RXD,
	GPIO_FN_SCIF2_V_TXD, GPIO_FN_SCIF2_V_SCK, GPIO_FN_SCIF2_V_RXD,

	/* SCIF3 (PTL/PTN/PTZ) with VOU, IRQ */
	GPIO_FN_SCIF3_V_SCK, GPIO_FN_SCIF3_V_RXD, GPIO_FN_SCIF3_V_TXD,
	GPIO_FN_SCIF3_V_CTS, GPIO_FN_SCIF3_V_RTS,
	GPIO_FN_SCIF3_I_SCK, GPIO_FN_SCIF3_I_RXD, GPIO_FN_SCIF3_I_TXD,
	GPIO_FN_SCIF3_I_CTS, GPIO_FN_SCIF3_I_RTS,

	/* SCIF4 (PTE) */
	GPIO_FN_SCIF4_SCK, GPIO_FN_SCIF4_RXD, GPIO_FN_SCIF4_TXD,

	/* SCIF5 (PTS) */
	GPIO_FN_SCIF5_SCK, GPIO_FN_SCIF5_RXD, GPIO_FN_SCIF5_TXD,

	/* FSI (PTE/PTU/PTV) */
	GPIO_FN_FSIMCKB,   GPIO_FN_FSIMCKA,    GPIO_FN_FSIOASD,
	GPIO_FN_FSIIABCK,  GPIO_FN_FSIIALRCK,  GPIO_FN_FSIOABCK,
	GPIO_FN_FSIOALRCK, GPIO_FN_CLKAUDIOAO, GPIO_FN_FSIIBSD,
	GPIO_FN_FSIOBSD,   GPIO_FN_FSIIBBCK,   GPIO_FN_FSIIBLRCK,
	GPIO_FN_FSIOBBCK,  GPIO_FN_FSIOBLRCK,  GPIO_FN_CLKAUDIOBO,
	GPIO_FN_FSIIASD,

	/* AUD (PTG) */
	GPIO_FN_AUDCK,   GPIO_FN_AUDSYNC, GPIO_FN_AUDATA3,
	GPIO_FN_AUDATA2, GPIO_FN_AUDATA1, GPIO_FN_AUDATA0,

	/* VIO (PTS) (common?) */
	GPIO_FN_VIO_CKO,

	/* VIO0 (PTH/PTK) */
	GPIO_FN_VIO0_D15, GPIO_FN_VIO0_D14, GPIO_FN_VIO0_D13, GPIO_FN_VIO0_D12,
	GPIO_FN_VIO0_D11, GPIO_FN_VIO0_D10, GPIO_FN_VIO0_D9,  GPIO_FN_VIO0_D8,
	GPIO_FN_VIO0_D7,  GPIO_FN_VIO0_D6,  GPIO_FN_VIO0_D5,  GPIO_FN_VIO0_D4,
	GPIO_FN_VIO0_D3,  GPIO_FN_VIO0_D2,  GPIO_FN_VIO0_D1,  GPIO_FN_VIO0_D0,
	GPIO_FN_VIO0_VD,  GPIO_FN_VIO0_CLK,
	GPIO_FN_VIO0_FLD, GPIO_FN_VIO0_HD,

	/* VIO1 (PTK/PTS) */
	GPIO_FN_VIO1_D7,  GPIO_FN_VIO1_D6, GPIO_FN_VIO1_D5, GPIO_FN_VIO1_D4,
	GPIO_FN_VIO1_D3,  GPIO_FN_VIO1_D2, GPIO_FN_VIO1_D1, GPIO_FN_VIO1_D0,
	GPIO_FN_VIO1_FLD, GPIO_FN_VIO1_HD, GPIO_FN_VIO1_VD, GPIO_FN_VIO1_CLK,

	/* Eth  (PTL/PTN/PTX) */
	GPIO_FN_RMII_RXD0,    GPIO_FN_RMII_RXD1,
	GPIO_FN_RMII_TXD0,    GPIO_FN_RMII_TXD1,
	GPIO_FN_RMII_REF_CLK, GPIO_FN_RMII_TX_EN,
	GPIO_FN_RMII_RX_ER,   GPIO_FN_RMII_CRS_DV,
	GPIO_FN_LNKSTA,       GPIO_FN_MDIO,
	GPIO_FN_MDC,

	/* System (PTJ) */
	GPIO_FN_PDSTATUS, GPIO_FN_STATUS2, GPIO_FN_STATUS0,

	/* VOU (PTL/PTM/PTN*/
	GPIO_FN_DV_D15,  GPIO_FN_DV_D14, GPIO_FN_DV_D13,   GPIO_FN_DV_D12,
	GPIO_FN_DV_D11,  GPIO_FN_DV_D10, GPIO_FN_DV_D9,    GPIO_FN_DV_D8,
	GPIO_FN_DV_D7,   GPIO_FN_DV_D6,  GPIO_FN_DV_D5,    GPIO_FN_DV_D4,
	GPIO_FN_DV_D3,   GPIO_FN_DV_D2,  GPIO_FN_DV_D1,    GPIO_FN_DV_D0,
	GPIO_FN_DV_CLKI, GPIO_FN_DV_CLK, GPIO_FN_DV_VSYNC, GPIO_FN_DV_HSYNC,

	/* MSIOF0 (PTL/PTM) */
	GPIO_FN_MSIOF0_RXD,   GPIO_FN_MSIOF0_TXD,
	GPIO_FN_MSIOF0_MCK,   GPIO_FN_MSIOF0_TSCK,
	GPIO_FN_MSIOF0_SS1,   GPIO_FN_MSIOF0_SS2,
	GPIO_FN_MSIOF0_TSYNC, GPIO_FN_MSIOF0_RSCK,
	GPIO_FN_MSIOF0_RSYNC,

	/* MSIOF1 (PTV) */
	GPIO_FN_MSIOF1_RXD,   GPIO_FN_MSIOF1_TXD,
	GPIO_FN_MSIOF1_MCK,   GPIO_FN_MSIOF1_TSCK,
	GPIO_FN_MSIOF1_SS1,   GPIO_FN_MSIOF1_SS2,
	GPIO_FN_MSIOF1_TSYNC, GPIO_FN_MSIOF1_RSCK,
	GPIO_FN_MSIOF1_RSYNC,

	/* DMAC (PTU/PTX) */
	GPIO_FN_DMAC_DACK0, GPIO_FN_DMAC_DREQ0,
	GPIO_FN_DMAC_DACK1, GPIO_FN_DMAC_DREQ1,

	/* SDHI0 (PTY) */
	GPIO_FN_SDHI0CD, GPIO_FN_SDHI0WP, GPIO_FN_SDHI0CMD, GPIO_FN_SDHI0CLK,
	GPIO_FN_SDHI0D3, GPIO_FN_SDHI0D2, GPIO_FN_SDHI0D1,  GPIO_FN_SDHI0D0,

	/* SDHI1 (PTW) */
	GPIO_FN_SDHI1CD, GPIO_FN_SDHI1WP, GPIO_FN_SDHI1CMD, GPIO_FN_SDHI1CLK,
	GPIO_FN_SDHI1D3, GPIO_FN_SDHI1D2, GPIO_FN_SDHI1D1,  GPIO_FN_SDHI1D0,

	/* MMC (PTW/PTX)*/
	GPIO_FN_MMC_D7,  GPIO_FN_MMC_D6,  GPIO_FN_MMC_D5, GPIO_FN_MMC_D4,
	GPIO_FN_MMC_D3,  GPIO_FN_MMC_D2,  GPIO_FN_MMC_D1, GPIO_FN_MMC_D0,
	GPIO_FN_MMC_CLK, GPIO_FN_MMC_CMD,

	/* IrDA (PTX) */
	GPIO_FN_IRDA_OUT, GPIO_FN_IRDA_IN,

	/* TSIF (PTX) */
	GPIO_FN_TSIF_TS0_SDAT, GPIO_FN_TSIF_TS0_SCK,
	GPIO_FN_TSIF_TS0_SDEN, GPIO_FN_TSIF_TS0_SPSYNC,

	/* IRQ (PTZ) */
	GPIO_FN_INTC_IRQ7, GPIO_FN_INTC_IRQ6, GPIO_FN_INTC_IRQ5,
	GPIO_FN_INTC_IRQ4, GPIO_FN_INTC_IRQ3, GPIO_FN_INTC_IRQ2,
	GPIO_FN_INTC_IRQ1, GPIO_FN_INTC_IRQ0,
};

enum {
	HWBLK_TLB, HWBLK_IC, HWBLK_OC, HWBLK_RSMEM, HWBLK_ILMEM, HWBLK_L2C,
	HWBLK_FPU, HWBLK_INTC, HWBLK_DMAC0, HWBLK_SHYWAY,
	HWBLK_HUDI, HWBLK_UBC,
	HWBLK_TMU0, HWBLK_CMT, HWBLK_RWDT, HWBLK_DMAC1, HWBLK_TMU1,
	HWBLK_SCIF0, HWBLK_SCIF1, HWBLK_SCIF2, HWBLK_SCIF3,
	HWBLK_SCIF4, HWBLK_SCIF5, HWBLK_MSIOF0, HWBLK_MSIOF1,
	HWBLK_KEYSC, HWBLK_RTC, HWBLK_IIC0, HWBLK_IIC1,
	HWBLK_MMC, HWBLK_ETHER, HWBLK_ATAPI, HWBLK_TPU, HWBLK_IRDA,
	HWBLK_TSIF, HWBLK_USB1, HWBLK_USB0, HWBLK_2DG,
	HWBLK_SDHI0, HWBLK_SDHI1, HWBLK_VEU1, HWBLK_CEU1, HWBLK_BEU1,
	HWBLK_2DDMAC, HWBLK_SPU, HWBLK_JPU, HWBLK_VOU,
	HWBLK_BEU0, HWBLK_CEU0,	HWBLK_VEU0, HWBLK_VPU, HWBLK_LCDC,
	HWBLK_NR,
};

enum {
	SHDMA_SLAVE_INVALID,
	SHDMA_SLAVE_SCIF0_TX,
	SHDMA_SLAVE_SCIF0_RX,
	SHDMA_SLAVE_SCIF1_TX,
	SHDMA_SLAVE_SCIF1_RX,
	SHDMA_SLAVE_SCIF2_TX,
	SHDMA_SLAVE_SCIF2_RX,
	SHDMA_SLAVE_SCIF3_TX,
	SHDMA_SLAVE_SCIF3_RX,
	SHDMA_SLAVE_SCIF4_TX,
	SHDMA_SLAVE_SCIF4_RX,
	SHDMA_SLAVE_SCIF5_TX,
	SHDMA_SLAVE_SCIF5_RX,
	SHDMA_SLAVE_USB0D0_TX,
	SHDMA_SLAVE_USB0D0_RX,
	SHDMA_SLAVE_USB0D1_TX,
	SHDMA_SLAVE_USB0D1_RX,
	SHDMA_SLAVE_USB1D0_TX,
	SHDMA_SLAVE_USB1D0_RX,
	SHDMA_SLAVE_USB1D1_TX,
	SHDMA_SLAVE_USB1D1_RX,
	SHDMA_SLAVE_SDHI0_TX,
	SHDMA_SLAVE_SDHI0_RX,
	SHDMA_SLAVE_SDHI1_TX,
	SHDMA_SLAVE_SDHI1_RX,
};

extern struct clk sh7724_fsimcka_clk;
extern struct clk sh7724_fsimckb_clk;
extern struct clk sh7724_dv_clki;

#endif /* __ASM_SH7724_H__ */

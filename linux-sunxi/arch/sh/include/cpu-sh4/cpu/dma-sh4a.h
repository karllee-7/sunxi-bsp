/*
 * arch/sh/include/cpu-sh4/cpu/dma-sh4a.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef __ASM_SH_CPU_SH4_DMA_SH7780_H
#define __ASM_SH_CPU_SH4_DMA_SH7780_H

#if defined(CONFIG_CPU_SUBTYPE_SH7343) || \
	defined(CONFIG_CPU_SUBTYPE_SH7730)
#define DMTE0_IRQ	48
#define DMTE4_IRQ	76
#define DMAE0_IRQ	78	/* DMA Error IRQ*/
#define SH_DMAC_BASE0	0xFE008020
#define SH_DMARS_BASE0	0xFE009000
#elif defined(CONFIG_CPU_SUBTYPE_SH7722)
#define DMTE0_IRQ	48
#define DMTE4_IRQ	76
#define DMAE0_IRQ	78	/* DMA Error IRQ*/
#define SH_DMAC_BASE0	0xFE008020
#define SH_DMARS_BASE0	0xFE009000
#elif defined(CONFIG_CPU_SUBTYPE_SH7763) || \
	defined(CONFIG_CPU_SUBTYPE_SH7764)
#define DMTE0_IRQ	34
#define DMTE4_IRQ	44
#define DMAE0_IRQ	38
#define SH_DMAC_BASE0	0xFF608020
#define SH_DMARS_BASE0	0xFF609000
#elif defined(CONFIG_CPU_SUBTYPE_SH7723)
#define DMTE0_IRQ	48	/* DMAC0A*/
#define DMTE4_IRQ	76	/* DMAC0B */
#define DMTE6_IRQ	40
#define DMTE8_IRQ	42	/* DMAC1A */
#define DMTE9_IRQ	43
#define DMTE10_IRQ	72	/* DMAC1B */
#define DMTE11_IRQ	73
#define DMAE0_IRQ	78	/* DMA Error IRQ*/
#define DMAE1_IRQ	74	/* DMA Error IRQ*/
#define SH_DMAC_BASE0	0xFE008020
#define SH_DMAC_BASE1	0xFDC08020
#define SH_DMARS_BASE0	0xFDC09000
#elif defined(CONFIG_CPU_SUBTYPE_SH7724)
#define DMTE0_IRQ	48	/* DMAC0A*/
#define DMTE4_IRQ	76	/* DMAC0B */
#define DMTE6_IRQ	40
#define DMTE8_IRQ	42	/* DMAC1A */
#define DMTE9_IRQ	43
#define DMTE10_IRQ	72	/* DMAC1B */
#define DMTE11_IRQ	73
#define DMAE0_IRQ	78	/* DMA Error IRQ*/
#define DMAE1_IRQ	74	/* DMA Error IRQ*/
#define SH_DMAC_BASE0	0xFE008020
#define SH_DMAC_BASE1	0xFDC08020
#define SH_DMARS_BASE0	0xFE009000
#define SH_DMARS_BASE1	0xFDC09000
#elif defined(CONFIG_CPU_SUBTYPE_SH7780)
#define DMTE0_IRQ	34
#define DMTE4_IRQ	44
#define DMTE6_IRQ	46
#define DMTE8_IRQ	92
#define DMTE9_IRQ	93
#define DMTE10_IRQ	94
#define DMTE11_IRQ	95
#define DMAE0_IRQ	38	/* DMA Error IRQ */
#define SH_DMAC_BASE0	0xFC808020
#define SH_DMAC_BASE1	0xFC818020
#define SH_DMARS_BASE0	0xFC809000
#else /* SH7785 */
#define DMTE0_IRQ	33
#define DMTE4_IRQ	37
#define DMTE6_IRQ	52
#define DMTE8_IRQ	54
#define DMTE9_IRQ	55
#define DMTE10_IRQ	56
#define DMTE11_IRQ	57
#define DMAE0_IRQ	39	/* DMA Error IRQ0 */
#define DMAE1_IRQ	58	/* DMA Error IRQ1 */
#define SH_DMAC_BASE0	0xFC808020
#define SH_DMAC_BASE1	0xFCC08020
#define SH_DMARS_BASE0	0xFC809000
#endif

#define REQ_HE		0x000000C0
#define REQ_H		0x00000080
#define REQ_LE		0x00000040
#define TM_BURST	0x00000020

#endif /* __ASM_SH_CPU_SH4_DMA_SH7780_H */

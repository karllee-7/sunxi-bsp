/*
 * arch/arm/mach-at91/include/mach/gsia18s.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
/* Buttons */
#define GPIO_TRIG_NET_IN		AT91_PIN_PB21
#define GPIO_CARD_UNMOUNT_0		AT91_PIN_PB13
#define GPIO_CARD_UNMOUNT_1		AT91_PIN_PB12
#define GPIO_KEY_POWER			AT91_PIN_PA25

/* PCF8574 0x20 GPIO - U1 on the GS_IA18-CB_V3 board */
#define GS_IA18_S_PCF_GPIO_BASE0	NR_BUILTIN_GPIO
#define PCF_GPIO_HDC_POWER		(GS_IA18_S_PCF_GPIO_BASE0 + 0)
#define PCF_GPIO_WIFI_SETUP		(GS_IA18_S_PCF_GPIO_BASE0 + 1)
#define PCF_GPIO_WIFI_ENABLE		(GS_IA18_S_PCF_GPIO_BASE0 + 2)
#define PCF_GPIO_WIFI_RESET		(GS_IA18_S_PCF_GPIO_BASE0 + 3)
#define PCF_GPIO_ETH_DETECT		4 /* this is a GPI */
#define PCF_GPIO_GPS_SETUP		(GS_IA18_S_PCF_GPIO_BASE0 + 5)
#define PCF_GPIO_GPS_STANDBY		(GS_IA18_S_PCF_GPIO_BASE0 + 6)
#define PCF_GPIO_GPS_POWER		(GS_IA18_S_PCF_GPIO_BASE0 + 7)

/* PCF8574 0x22 GPIO - U1 on the GS_2G_OPT1-A_V0 board (Alarm) */
#define GS_IA18_S_PCF_GPIO_BASE1	(GS_IA18_S_PCF_GPIO_BASE0 + 8)
#define PCF_GPIO_ALARM1			(GS_IA18_S_PCF_GPIO_BASE1 + 0)
#define PCF_GPIO_ALARM2			(GS_IA18_S_PCF_GPIO_BASE1 + 1)
#define PCF_GPIO_ALARM3			(GS_IA18_S_PCF_GPIO_BASE1 + 2)
#define PCF_GPIO_ALARM4			(GS_IA18_S_PCF_GPIO_BASE1 + 3)
/* bits 4, 5, 6 not used */
#define PCF_GPIO_ALARM_V_RELAY_ON	(GS_IA18_S_PCF_GPIO_BASE1 + 7)

/* PCF8574 0x24 GPIO U1 on the GS_2G-OPT23-A_V0 board (Modem) */
#define GS_IA18_S_PCF_GPIO_BASE2	(GS_IA18_S_PCF_GPIO_BASE1 + 8)
#define PCF_GPIO_MODEM_POWER		(GS_IA18_S_PCF_GPIO_BASE2 + 0)
#define PCF_GPIO_MODEM_RESET		(GS_IA18_S_PCF_GPIO_BASE2 + 3)
/* bits 1, 2, 4, 5 not used */
#define PCF_GPIO_TRX_RESET		(GS_IA18_S_PCF_GPIO_BASE2 + 6)
/* bit 7 not used */

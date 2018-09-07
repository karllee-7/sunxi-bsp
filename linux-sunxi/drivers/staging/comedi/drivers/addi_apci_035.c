/*
 * drivers/staging/comedi/drivers/addi_apci_035.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#define CONFIG_APCI_035 1

#define ADDIDATA_WATCHDOG 2	/*  Or shold it be something else */

#define ADDIDATA_DRIVER_NAME	"addi_apci_035"

#include "addi-data/addi_common.c"

MODULE_AUTHOR("Comedi http://www.comedi.org");
MODULE_DESCRIPTION("Comedi low-level driver");
MODULE_LICENSE("GPL");

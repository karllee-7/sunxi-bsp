/*
 * modules/gpu/sgx544/linux/kernel_mode/eurasia_km/services4/srvkm/env/linux/linkage.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
/*************************************************************************/ /*!
@Title          Linux specific Services code internal interfaces
@Copyright      Copyright (c) Imagination Technologies Ltd. All Rights Reserved
@Description    Interfaces between various parts of the Linux specific
                Services code, that don't have any other obvious
                header file to go into.
@License        Dual MIT/GPLv2

The contents of this file are subject to the MIT license as set out below.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

Alternatively, the contents of this file may be used under the terms of
the GNU General Public License Version 2 ("GPL") in which case the provisions
of GPL are applicable instead of those above.

If you wish to allow use of your version of this file only under the terms of
GPL, and not to allow others to use your version of this file under the terms
of the MIT license, indicate your decision by deleting the provisions above
and replace them with the notice and other provisions required by GPL as set
out in the file called "GPL-COPYING" included in this distribution. If you do
not delete the provisions above, a recipient may use your version of this file
under the terms of either the MIT license or GPL.

This License is also included in this distribution in the file called
"MIT-COPYING".

EXCEPT AS OTHERWISE STATED IN A NEGOTIATED AGREEMENT: (A) THE SOFTWARE IS
PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT; AND (B) IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/ /**************************************************************************/
#ifndef __LINKAGE_H__
#define __LINKAGE_H__

#if !defined(SUPPORT_DRI_DRM)
long PVRSRV_BridgeDispatchKM(struct file *file, unsigned int cmd, unsigned long arg);
#endif

IMG_VOID PVRDPFInit(IMG_VOID);
PVRSRV_ERROR PVROSFuncInit(IMG_VOID);
IMG_VOID PVROSFuncDeInit(IMG_VOID);

#ifdef DEBUG

IMG_INT PVRDebugProcSetLevel(struct file *file, const IMG_CHAR *buffer, IMG_UINT32 count, IMG_VOID *data);
void ProcSeqShowDebugLevel(struct seq_file *sfile,void* el);

#ifdef PVR_MANUAL_POWER_CONTROL
IMG_INT PVRProcSetPowerLevel(struct file *file, const IMG_CHAR *buffer, IMG_UINT32 count, IMG_VOID *data);

void ProcSeqShowPowerLevel(struct seq_file *sfile,void* el);

#endif /* PVR_MANUAL_POWER_CONTROL */

#endif	/* DEBUG */

#endif /* __LINKAGE_H__ */
/*****************************************************************************
 End of file (linkage.h)
*****************************************************************************/

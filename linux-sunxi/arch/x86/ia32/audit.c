/*
 * arch/x86/ia32/audit.c
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include <asm/unistd_32.h>

unsigned ia32_dir_class[] = {
#include <asm-generic/audit_dir_write.h>
~0U
};

unsigned ia32_chattr_class[] = {
#include <asm-generic/audit_change_attr.h>
~0U
};

unsigned ia32_write_class[] = {
#include <asm-generic/audit_write.h>
~0U
};

unsigned ia32_read_class[] = {
#include <asm-generic/audit_read.h>
~0U
};

unsigned ia32_signal_class[] = {
#include <asm-generic/audit_signal.h>
~0U
};

int ia32_classify_syscall(unsigned syscall)
{
	switch (syscall) {
	case __NR_open:
		return 2;
	case __NR_openat:
		return 3;
	case __NR_socketcall:
		return 4;
	case __NR_execve:
		return 5;
	default:
		return 1;
	}
}

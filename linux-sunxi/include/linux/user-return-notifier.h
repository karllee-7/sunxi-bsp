/*
 * include/linux/user-return-notifier.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef _LINUX_USER_RETURN_NOTIFIER_H
#define _LINUX_USER_RETURN_NOTIFIER_H

#ifdef CONFIG_USER_RETURN_NOTIFIER

#include <linux/list.h>
#include <linux/sched.h>

struct user_return_notifier {
	void (*on_user_return)(struct user_return_notifier *urn);
	struct hlist_node link;
};


void user_return_notifier_register(struct user_return_notifier *urn);
void user_return_notifier_unregister(struct user_return_notifier *urn);

static inline void propagate_user_return_notify(struct task_struct *prev,
						struct task_struct *next)
{
	if (test_tsk_thread_flag(prev, TIF_USER_RETURN_NOTIFY)) {
		clear_tsk_thread_flag(prev, TIF_USER_RETURN_NOTIFY);
		set_tsk_thread_flag(next, TIF_USER_RETURN_NOTIFY);
	}
}

void fire_user_return_notifiers(void);

static inline void clear_user_return_notifier(struct task_struct *p)
{
	clear_tsk_thread_flag(p, TIF_USER_RETURN_NOTIFY);
}

#else

struct user_return_notifier {};

static inline void propagate_user_return_notify(struct task_struct *prev,
						struct task_struct *next)
{
}

static inline void fire_user_return_notifiers(void) {}

static inline void clear_user_return_notifier(struct task_struct *p) {}

#endif

#endif

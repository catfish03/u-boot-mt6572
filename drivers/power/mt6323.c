// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019 Frank Wunderlich <frank-w@public-files.de>
 */

#include <command.h>
#include <asm/io.h>
#include <linux/delay.h>

#define PWRAP_BASE        0x1000f000
#define PWRAP_WACS2_CMD   0x9c
#define MT6323_PWRC_BASE  0x8000
#define RTC_BBPU          0x0000
#define RTC_BBPU_KEY      (0x43 << 8)
#define RTC_WRTGR         0x003c

#define PWRAP_CALC(adr, wdata) ((1 << 31) | (((adr) >> 1) << 16) | (wdata))

int do_poweroff(struct cmd_tbl *cmdtp, int flag, int argc, char *const argv[])
{
	u32 addr, val;

	addr = PWRAP_BASE + PWRAP_WACS2_CMD;
	val = PWRAP_CALC(MT6323_PWRC_BASE + RTC_BBPU, RTC_BBPU_KEY);
	writel(val, addr);
	mdelay(10);

	val = PWRAP_CALC(MT6323_PWRC_BASE + RTC_WRTGR, 1);
	printf("%s: powering off...\n", __func__);
	writel(val, addr);
	
	/* If poweroff is successful, this code is never reached */
	mdelay(1000);
	printf("%s: failed to power off\n", __func__);
	return 1;
}

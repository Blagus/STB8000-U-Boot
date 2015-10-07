/*
 * Copyright (C) STMicroelectronics Ltd. 2008-2012
 *
 * All rights reserved.
 */

/*
 * This is derived from STMicroelectronics gnu toolchain example:
 *   sh-superh-elf/examples/bare/sh4reg/sti5197reg.h
 */


#ifndef __ASM_ST40_STX5197REG_H
#define __ASM_ST40_STX5197REG_H

#include "sh4regtype.h"

/*----------------------------------------------------------------------------*/

/*
 * Peripheral versions
 */

#ifndef ST40_LMI_VERSION
#define ST40_LMI_VERSION 4
#endif
#ifndef ST40_NAND_CONTROLLER_VERSION
#define ST40_NAND_CONTROLLER_VERSION 2
#endif

/*----------------------------------------------------------------------------*/

/*
 * Base addresses for control register banks.
 */

/* Generic SH4 control registers */
#ifndef SH4_TMU_REGS_BASE
#define SH4_TMU_REGS_BASE 0xffd80000
#endif

/* Common ST40 control registers */
#ifndef ST40_CPG_REGS_BASE
#define ST40_CPG_REGS_BASE 0xffc00000
#endif
#ifndef ST40_INTC_REGS_BASE
#define ST40_INTC_REGS_BASE 0xffd00000
#endif

#ifndef STX5197_COMMS_BASE
#define STX5197_COMMS_BASE 0xfd100000
#endif

#ifndef ST40_ILC_REGS_BASE
#define ST40_ILC_REGS_BASE STX5197_COMMS_BASE
#endif

/* STi5197 control registers */
#ifndef STX5197_SYSSERV_REGS_BASE
#define STX5197_SYSSERV_REGS_BASE 0xfdc00000
#endif

#ifndef STX5197_HD_CONFIG_MONITOR_BASE
#define STX5197_HD_CONFIG_MONITOR_BASE 0xfd901000
#endif

/* System Architecture Volume 2: Bus Interfaces */
#ifndef ST40_LMI_REGS_BASE
#define ST40_LMI_REGS_BASE 0xfe000000
#endif
#ifndef ST40_EMI_REGS_BASE
#define ST40_EMI_REGS_BASE 0xfdf00000
#endif

/* System Architecture Volume 4: I/O Devices */
#ifndef ST40_PIO0_REGS_BASE
#define ST40_PIO0_REGS_BASE (STX5197_COMMS_BASE + 0x00020000)
#endif
#ifndef ST40_PIO1_REGS_BASE
#define ST40_PIO1_REGS_BASE (STX5197_COMMS_BASE + 0x00021000)
#endif
#ifndef ST40_PIO2_REGS_BASE
#define ST40_PIO2_REGS_BASE (STX5197_COMMS_BASE + 0x00022000)
#endif
#ifndef ST40_PIO3_REGS_BASE
#define ST40_PIO3_REGS_BASE (STX5197_COMMS_BASE + 0x00023000)
#endif
#ifndef ST40_PIO4_REGS_BASE
#define ST40_PIO4_REGS_BASE (STX5197_COMMS_BASE + 0x00024000)
#endif

#define ST40_PIO_BASE(x)    (ST40_PIO0_REGS_BASE + (0x1000*(x)))

#ifndef ST40_ASC0_REGS_BASE
#define ST40_ASC0_REGS_BASE (STX5197_COMMS_BASE + 0x00030000)
#endif
#ifndef ST40_ASC1_REGS_BASE
#define ST40_ASC1_REGS_BASE (STX5197_COMMS_BASE + 0x00031000)
#endif
#ifndef ST40_ASC2_REGS_BASE
#define ST40_ASC2_REGS_BASE (STX5197_COMMS_BASE + 0x00032000)
#endif
#ifndef ST40_ASC3_REGS_BASE
#define ST40_ASC3_REGS_BASE (STX5197_COMMS_BASE + 0x00033000)
#endif
#ifndef ST40_SSC0_REGS_BASE
#define ST40_SSC0_REGS_BASE (STX5197_COMMS_BASE + 0x00040000)
#endif
#ifndef ST40_SSC1_REGS_BASE
#define ST40_SSC1_REGS_BASE (STX5197_COMMS_BASE + 0x00041000)
#endif
#ifndef ST40_SSC2_REGS_BASE
#define ST40_SSC2_REGS_BASE (STX5197_COMMS_BASE + 0x00042000)
#endif

/*----------------------------------------------------------------------------*/

#include "st40reg.h"

/*
 * STi5197 control registers
 */

/* System services registers (STi5197 variant) */
#define STX5197_SYSSERV_PLLA_CONFIG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x00)
#define STX5197_SYSSERV_PLLA_CONFIG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x04)
#define STX5197_SYSSERV_PLLB_CONFIG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x08)
#define STX5197_SYSSERV_PLLB_CONFIG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x0C)
#define STX5197_SYSSERV_FS216_SETUP_A		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x10)
#define STX5197_SYSSERV_FSA_SETUP		STX5197_SYSSERV_FS216_SETUP_A
#define STX5197_SYSSERV_FS216X4_CLK1_SETUP0	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x14)
#define STX5197_SYSSERV_SPARE1_CLK_SETUP0	STX5197_SYSSERV_FS216X4_CLK1_SETUP0
#define STX5197_SYSSERV_FS216X4_CLK1_SETUP1	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x18)
#define STX5197_SYSSERV_SPARE1_CLK_SETUP1	STX5197_SYSSERV_FS216X4_CLK1_SETUP1
#define STX5197_SYSSERV_FS216X4_CLK2_SETUP0	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x20)
#define STX5197_SYSSERV_PCM_CLK_SETUP0		STX5197_SYSSERV_FS216X4_CLK2_SETUP0
#define STX5197_SYSSERV_FS216X4_CLK2_SETUP1	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x24)
#define STX5197_SYSSERV_PCM_CLK_SETUP1		STX5197_SYSSERV_FS216X4_CLK2_SETUP1
#define STX5197_SYSSERV_FS216X4_CLK3_SETUP0	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x30)
#define STX5197_SYSSERV_SPDIF_CLK_SETUP0	STX5197_SYSSERV_FS216X4_CLK3_SETUP0
#define STX5197_SYSSERV_FS216X4_CLK3_SETUP1	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x34)
#define STX5197_SYSSERV_SPDIF_CLK_SETUP1	STX5197_SYSSERV_FS216X4_CLK3_SETUP1
#define STX5197_SYSSERV_FS216X4_CLK4_SETUP0	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x40)
#define STX5197_SYSSERV_SC_CLK_SETUP0		STX5197_SYSSERV_FS216X4_CLK4_SETUP0
#define STX5197_SYSSERV_FS216X4_CLK4_SETUP1	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x44)
#define STX5197_SYSSERV_SC_CLK_SETUP1		STX5197_SYSSERV_FS216X4_CLK4_SETUP1
#define STX5197_SYSSERV_FS216_SETUP_B		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x50)
#define STX5197_SYSSERV_FSB_SETUP		STX5197_SYSSERV_FS216_SETUP_B
#define STX5197_SYSSERV_FS216X4_CLK5_SETUP0	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x54)
#define STX5197_SYSSERV_PIX_CLK_SETUP0		STX5197_SYSSERV_FS216X4_CLK5_SETUP0
#define STX5197_SYSSERV_FS216X4_CLK5_SETUP1	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x58)
#define STX5197_SYSSERV_PIX_CLK_SETUP1		STX5197_SYSSERV_FS216X4_CLK5_SETUP1
#define STX5197_SYSSERV_FS216X4_CLK6_SETUP0	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x60)
#define STX5197_SYSSERV_FDMA_FS_CLK_SETUP0	STX5197_SYSSERV_FS216X4_CLK6_SETUP0
#define STX5197_SYSSERV_FS216X4_CLK6_SETUP1	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x64)
#define STX5197_SYSSERV_FDMA_FS_CLK_SETUP1	STX5197_SYSSERV_FS216X4_CLK6_SETUP1
#define STX5197_SYSSERV_FS216X4_CLK7_SETUP0	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x70)
#define STX5197_SYSSERV_AUX_CLK_SETUP0		STX5197_SYSSERV_FS216X4_CLK7_SETUP0
#define STX5197_SYSSERV_FS216X4_CLK7_SETUP1	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x74)
#define STX5197_SYSSERV_AUX_CLK_SETUP1		STX5197_SYSSERV_FS216X4_CLK7_SETUP1
#define STX5197_SYSSERV_FS216X4_CLK8_SETUP0	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x80)
#define STX5197_SYSSERV_USB_CLK_SETUP0		STX5197_SYSSERV_FS216X4_CLK8_SETUP0
#define STX5197_SYSSERV_FS216X4_CLK8_SETUP1	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x84)
#define STX5197_SYSSERV_USB_CLK_SETUP1		STX5197_SYSSERV_FS216X4_CLK8_SETUP1
#define STX5197_SYSSERV_CLKDIV0_CFG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x90)
#define STX5197_SYSSERV_CLKDIV0_CFG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x94)
#define STX5197_SYSSERV_CLKDIV0_CFG2		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x98)
#define STX5197_SYSSERV_CLKDIV1_CFG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xa0)
#define STX5197_SYSSERV_CLKDIV1_CFG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xa4)
#define STX5197_SYSSERV_CLKDIV1_CFG2		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xa8)
#define STX5197_SYSSERV_CLKDIV2_CFG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xac)
#define STX5197_SYSSERV_CLKDIV2_CFG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xb0)
#define STX5197_SYSSERV_CLKDIV2_CFG2		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xb4)
#define STX5197_SYSSERV_CLKDIV3_CFG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xb8)
#define STX5197_SYSSERV_CLKDIV3_CFG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xbc)
#define STX5197_SYSSERV_CLKDIV3_CFG2		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xc0)
#define STX5197_SYSSERV_CLKDIV4_CFG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xc4)
#define STX5197_SYSSERV_CLKDIV4_CFG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xc8)
#define STX5197_SYSSERV_CLKDIV4_CFG2		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xcc)
#define STX5197_SYSSERV_CLKDIV6_CFG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xd0)
#define STX5197_SYSSERV_CLKDIV6_CFG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xd4)
#define STX5197_SYSSERV_CLKDIV6_CFG2		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xd8)
#define STX5197_SYSSERV_CLKDIV7_CFG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xdc)
#define STX5197_SYSSERV_CLKDIV7_CFG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xe0)
#define STX5197_SYSSERV_CLKDIV7_CFG2		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xe4)
#define STX5197_SYSSERV_CLKDIV8_CFG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xe8)
#define STX5197_SYSSERV_CLKDIV8_CFG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xec)
#define STX5197_SYSSERV_CLKDIV8_CFG2		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xf0)
#define STX5197_SYSSERV_CLKDIV9_CFG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xf4)
#define STX5197_SYSSERV_CLKDIV9_CFG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xf8)
#define STX5197_SYSSERV_CLKDIV9_CFG2		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0xfc)
#define STX5197_SYSSERV_CLKDIV10_CFG0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x100)
#define STX5197_SYSSERV_CLKDIV10_CFG1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x104)
#define STX5197_SYSSERV_CLKDIV10_CFG2		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x108)
#define STX5197_SYSSERV_MODE_CONTROL		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x110)
#define STX5197_SYSSERV_REDUCED_PWR_CONTROL	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x114)
#define STX5197_SYSSERV_LOW_POWER_DIS0		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x118)
#define STX5197_SYSSERV_LOW_POWER_DIS1		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x11C)
#define STX5197_SYSSERV_LOW_POWER_COUNTER_CFG0	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x120)
#define STX5197_SYSSERV_LOW_POWER_COUNTER_CFG1	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x124)
#define STX5197_SYSSERV_WATCHDOG_COUNTER_CFG0	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x130)
#define STX5197_SYSSERV_WATCHDOG_COUNTER_CFG1	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x134)
#define STX5197_SYSSERV_RESET_STATUS		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x140)
#define STX5197_SYSSERV_SC_POWER_DETECT_CFG	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x144)
#define STX5197_SYSSERV_SC_INSERTION_RST_CFG	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x148)
#define STX5197_SYSSERV_CPU_INT_CFG		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x150)
#define STX5197_SYSSERV_DCO_SD_COUNT		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x160)
#define STX5197_SYSSERV_DCO_CMD			SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x164)
#define STX5197_SYSSERV_DCO_PCM_COUNT		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x168)
#define STX5197_SYSSERV_DCO_HD_COUNT		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x16C)
#define STX5197_SYSSERV_DCO_MODE_CFG		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x170)
#define STX5197_SYSSERV_CLOCK_SEL_CFG		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x180)
#define STX5197_SYSSERV_DIV_FORCE_CFG		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x184)
#define STX5197_SYSSERV_CLK_OBS_CFG		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x188)
#define STX5197_SYSSERV_RTCS_LSB_LP		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x200)
#define STX5197_SYSSERV_RTCS_MSB_LP		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x204)
#define STX5197_SYSSERV_RTCS_CONTROL_LP		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x208)
#define STX5197_SYSSERV_RTCS_LSB_27		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x210)
#define STX5197_SYSSERV_RTCS_MSB_27		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x214)
#define STX5197_SYSSERV_RTCS_CONTROL_27		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x218)
#define STX5197_SYSSERV_REG_LOCK_CFG		SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x300)
#define STX5197_SYSSERV_CLKBIST_PLL0_REFCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x0390)
#define STX5197_SYSSERV_CLKBIST_PLL0_CMPCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x0394)
#define STX5197_SYSSERV_CLKBIST_PLL0_OUTCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x0398)
#define STX5197_SYSSERV_CLKBIST_PLL0_CONTROL	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x039c)
#define STX5197_SYSSERV_CLKBIST_PLL1_REFCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03a0)
#define STX5197_SYSSERV_CLKBIST_PLL1_CMPCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03a4)
#define STX5197_SYSSERV_CLKBIST_PLL1_OUTCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03a8)
#define STX5197_SYSSERV_CLKBIST_PLL1_CONTROL	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03ac)
#define STX5197_SYSSERV_CLKBIST_PCM_REFCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03b0)
#define STX5197_SYSSERV_CLKBIST_PCM_CMPCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03b4)
#define STX5197_SYSSERV_CLKBIST_PCM_OUTCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03b8)
#define STX5197_SYSSERV_CLKBIST_PCM_CONTROL	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03bc)
#define STX5197_SYSSERV_CLKBIST_FS0_REFCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03c0)
#define STX5197_SYSSERV_CLKBIST_FS0_CMPCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03c4)
#define STX5197_SYSSERV_CLKBIST_FS0_OUTCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03c8)
#define STX5197_SYSSERV_CLKBIST_FS0_CONTROL	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03cc)
#define STX5197_SYSSERV_CLKBIST_FS1_REFCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03d0)
#define STX5197_SYSSERV_CLKBIST_FS1_CMPCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03d4)
#define STX5197_SYSSERV_CLKBIST_FS1_OUTCOUNT	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03d8)
#define STX5197_SYSSERV_CLKBIST_FS1_CONTROL	SH4_DWORD_REG(STX5197_SYSSERV_REGS_BASE + 0x03dc)

#define STX5197_HD_CONF_MON_CONFIG_CONTROL_C	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x0)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_D	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x4)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_E	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x8)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_F	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0xC)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_G	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x10)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_H	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x14)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_I	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x18)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_J	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x1C)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_K	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x40)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_L	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x44)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_M	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x48)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_N	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x4C)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_O	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x50)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_P	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x54)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_Q	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x58)
#define STX5197_HD_CONF_MON_CONFIG_CONTROL_R	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x5C)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_C	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x20)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_D	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x24)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_E	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x28)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_F	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x2C)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_G	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x30)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_H	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x34)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_I	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x38)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_J	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x3C)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_K	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x60)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_L	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x64)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_M	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x68)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_N	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x6C)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_O	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x70)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_P	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x74)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_Q	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x78)
#define STX5197_HD_CONF_MON_CONFIG_MONITOR_R	SH4_DWORD_REG(STX5197_HD_CONFIG_MONITOR_BASE + 0x7C)

#define STX5197_DEVID_5197c1_VAL	0x003f	/* STx5197 cut 1.x */	/* QQQ - TO CHECK */
#define STX5197_DEVID_5197c2_VAL	0x003f	/* STx5197 cut 2.x */
#define STX5197_DEVID_ID_SHIFT		12
#define STX5197_DEVID_ID_MASK		0x3ff	/* ten bits */
#define STX5197_DEVID_CUT_SHIFT		28
#define STX5197_DEVID_CUT_MASK		0xf	/* four bits */

#define STX5197_DEVICEID_5197(ID)	(	\
	((((ID)>>STX5197_DEVID_ID_SHIFT)&STX5197_DEVID_ID_MASK)==STX5197_DEVID_5197c1_VAL)  || \
	((((ID)>>STX5197_DEVID_ID_SHIFT)&STX5197_DEVID_ID_MASK)==STX5197_DEVID_5197c2_VAL)     )
#define STX5197_DEVICEID_CUT(ID)  ((((ID) >> STX5197_DEVID_CUT_SHIFT) & STX5197_DEVID_CUT_MASK) + 1)

#endif /* __ASM_ST40_STX5197REG_H */

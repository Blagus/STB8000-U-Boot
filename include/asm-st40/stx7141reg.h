/*
 * Copyright (C) STMicroelectronics Ltd. 2008-2012
 *
 * All rights reserved.
 */

/*
 * This is derived from STMicroelectronics gnu toolchain example:
 *   sh-superh-elf/examples/bare/sh4reg/sti7141reg.h
 */


#ifndef __ASM_ST40_STX7141REG_H
#define __ASM_ST40_STX7141REG_H

#include "sh4regtype.h"

/*----------------------------------------------------------------------------*/

/*
 * Peripheral versions
 */

#ifndef ST40_LMIGP_VERSION
#define ST40_LMIGP_VERSION 1
#endif
#ifndef ST40_NAND_CONTROLLER_VERSION
#define ST40_NAND_CONTROLLER_VERSION 1
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

#ifndef STX7141_COMMS_BASE
#define STX7141_COMMS_BASE 0xfd000000
#endif

/* This is the COMMS ILC */
#ifndef ST40_ILC_REGS_BASE
#define ST40_ILC_REGS_BASE STX7141_COMMS_BASE
#endif

/*
 * The STx7141 has two further ILC3's which we access in a similar way, but
 * specify the ILC index first.
 */
#define STX7141_ILC_INPUT_INTERRUPT(n, m)	SH4_DWORD_REG(STX7141_ILC##n##_REGS_BASE + (0x0080 + ((m) * 4)))
#define STX7141_ILC_STATUS(n, m)		SH4_DWORD_REG(STX7141_ILC##n##_REGS_BASE + (0x0200 + ((m) * 4)))
#define STX7141_ILC_CLEAR_STATUS(n, m)		SH4_DWORD_REG(STX7141_ILC##n##_REGS_BASE + (0x0280 + ((m) * 4)))
#define STX7141_ILC_ENABLE(n, m)		SH4_DWORD_REG(STX7141_ILC##n##_REGS_BASE + (0x0400 + ((m) * 4)))
#define STX7141_ILC_CLEAR_ENABLE(n, m)		SH4_DWORD_REG(STX7141_ILC##n##_REGS_BASE + (0x0480 + ((m) * 4)))
#define STX7141_ILC_SET_ENABLE(n, m)		SH4_DWORD_REG(STX7141_ILC##n##_REGS_BASE + (0x0500 + ((m) * 4)))
#define STX7141_ILC_WAKEUP_ENABLE(n, m)		SH4_DWORD_REG(STX7141_ILC##n##_REGS_BASE + (0x0600 + ((m) * 4)))
#define STX7141_ILC_WAKEUP_ACTIVE_LEVEL(n, m)	SH4_DWORD_REG(STX7141_ILC##n##_REGS_BASE + (0x0680 + ((m) * 4)))

/* eSTB ST40 ILC */
#ifndef STX7141_ILC0_REGS_BASE
#define STX7141_ILC0_REGS_BASE 0xfd120000
#endif

/* eCM ST40 ILC */
#ifndef STX7141_ILC1_REGS_BASE
#define STX7141_ILC1_REGS_BASE 0xfd122000
#endif

#ifdef __STX7141_ECM__
/* The eCM has an INTC2 */
#ifndef ST40_INTC2_REGS_BASE
#define ST40_INTC2_REGS_BASE 0xfd124000
#endif
#endif

/* STx7141 control registers */
#ifndef STX7141_SYSCONF_REGS_BASE
#define STX7141_SYSCONF_REGS_BASE 0xfe001000
#endif

#ifndef STX7141_CLOCKGENA_REGS_BASE
#define STX7141_CLOCKGENA_REGS_BASE 0xfe213000
#endif

#ifndef STX7141_CLOCKGENB_REGS_BASE
#define STX7141_CLOCKGENB_REGS_BASE 0xfe000000
#endif

/* System Architecture Volume 2: Bus Interfaces */
#ifndef ST40_LMI0_REGS_BASE
#define ST40_LMI0_REGS_BASE 0xfe901000
#endif
#ifndef ST40_LMI1_REGS_BASE
#define ST40_LMI1_REGS_BASE 0xfe902000
#endif
#ifndef ST40_EMI_REGS_BASE
#define ST40_EMI_REGS_BASE 0xfe700000
#endif

/* System Architecture Volume 4: I/O Devices */
#ifndef ST40_PIO1_REGS_BASE
#define ST40_PIO1_REGS_BASE (STX7141_COMMS_BASE + 0x00020000)
#endif
#ifndef ST40_PIO2_REGS_BASE
#define ST40_PIO2_REGS_BASE (STX7141_COMMS_BASE + 0x00021000)
#endif
#ifndef ST40_PIO3_REGS_BASE
#define ST40_PIO3_REGS_BASE (STX7141_COMMS_BASE + 0x00022000)
#endif
#ifndef ST40_PIO4_REGS_BASE
#define ST40_PIO4_REGS_BASE (STX7141_COMMS_BASE + 0x00023000)
#endif
#ifndef ST40_PIO5_REGS_BASE
#define ST40_PIO5_REGS_BASE (STX7141_COMMS_BASE + 0x00024000)
#endif
#ifndef ST40_PIO6_REGS_BASE
#define ST40_PIO6_REGS_BASE (STX7141_COMMS_BASE + 0x00025000)
#endif
#ifndef ST40_PIO7_REGS_BASE
#define ST40_PIO7_REGS_BASE (STX7141_COMMS_BASE + 0x00026000)
#endif

/* The STx7141 also has a bank of stand-alone bank of PIOs */
#ifndef STX7141_T1_PIO_REGS_BASE
#define STX7141_T1_PIO_REGS_BASE 0xfe010000
#endif

#ifndef ST40_PIO8_REGS_BASE
#define ST40_PIO8_REGS_BASE STX7141_T1_PIO_REGS_BASE
#endif
#ifndef ST40_PIO9_REGS_BASE
#define ST40_PIO9_REGS_BASE (STX7141_T1_PIO_REGS_BASE + 0x00001000)
#endif
#ifndef ST40_PIO10_REGS_BASE
#define ST40_PIO10_REGS_BASE (STX7141_T1_PIO_REGS_BASE + 0x00002000)
#endif
#ifndef ST40_PIO11_REGS_BASE
#define ST40_PIO11_REGS_BASE (STX7141_T1_PIO_REGS_BASE + 0x00003000)
#endif
#ifndef ST40_PIO12_REGS_BASE
#define ST40_PIO12_REGS_BASE (STX7141_T1_PIO_REGS_BASE + 0x00004000)
#endif
#ifndef ST40_PIO13_REGS_BASE
#define ST40_PIO13_REGS_BASE (STX7141_T1_PIO_REGS_BASE + 0x00005000)
#endif
#ifndef ST40_PIO14_REGS_BASE
#define ST40_PIO14_REGS_BASE (STX7141_T1_PIO_REGS_BASE + 0x00006000)
#endif
#ifndef ST40_PIO15_REGS_BASE
#define ST40_PIO15_REGS_BASE (STX7141_T1_PIO_REGS_BASE + 0x00007000)
#endif
#ifndef ST40_PIO16_REGS_BASE
#define ST40_PIO16_REGS_BASE (STX7141_T1_PIO_REGS_BASE + 0x00008000)
#endif

#define ST40_PIO_BASE(x)					\
	(((x) < 8)						\
		? (ST40_PIO1_REGS_BASE+(0x1000*((x)-1)))	\
		: (ST40_PIO8_REGS_BASE+(0x1000*((x)-8))))


#ifndef ST40_ASC0_REGS_BASE
#define ST40_ASC0_REGS_BASE (STX7141_COMMS_BASE + 0x00030000)
#endif
#ifndef ST40_ASC1_REGS_BASE
#define ST40_ASC1_REGS_BASE (STX7141_COMMS_BASE + 0x00031000)
#endif
#ifndef ST40_ASC2_REGS_BASE
#define ST40_ASC2_REGS_BASE (STX7141_COMMS_BASE + 0x00032000)
#endif
#ifndef ST40_SSC0_REGS_BASE
#define ST40_SSC0_REGS_BASE (STX7141_COMMS_BASE + 0x00040000)
#endif
#ifndef ST40_SSC1_REGS_BASE
#define ST40_SSC1_REGS_BASE (STX7141_COMMS_BASE + 0x00041000)
#endif
#ifndef ST40_SSC2_REGS_BASE
#define ST40_SSC2_REGS_BASE (STX7141_COMMS_BASE + 0x00042000)
#endif
#ifndef ST40_SSC3_REGS_BASE
#define ST40_SSC3_REGS_BASE (STX7141_COMMS_BASE + 0x00043000)
#endif
#ifndef ST40_SSC4_REGS_BASE
#define ST40_SSC4_REGS_BASE (STX7141_COMMS_BASE + 0x00044000)
#endif
#ifndef ST40_SSC5_REGS_BASE
#define ST40_SSC5_REGS_BASE (STX7141_COMMS_BASE + 0x00045000)
#endif
#ifndef ST40_SSC6_REGS_BASE
#define ST40_SSC6_REGS_BASE (STX7141_COMMS_BASE + 0x00046000)
#endif
#ifndef ST40_MAILBOX0_REGS_BASE
#define ST40_MAILBOX0_REGS_BASE 0xfe211000
#endif
#ifndef ST40_MAILBOX1_REGS_BASE
#define ST40_MAILBOX1_REGS_BASE (ST40_MAILBOX0_REGS_BASE + 0x1000)
#endif
#ifndef ST40_MAILBOX2_REGS_BASE
#define ST40_MAILBOX2_REGS_BASE (ST40_MAILBOX0_REGS_BASE + 0x0800)
#endif
#ifndef ST40_MAILBOX3_REGS_BASE
#define ST40_MAILBOX3_REGS_BASE (ST40_MAILBOX0_REGS_BASE + 0x1800)
#endif

/*----------------------------------------------------------------------------*/

#include "st40reg.h"

/*
 * STx7141 control registers
 */

/* Clock Generator control registers (STx7141 variant) */
#define STX7141_CLOCKGENA_PLL0_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x00)
#define STX7141_CLOCKGENA_PLL1_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x04)
#define STX7141_CLOCKGENA_POWER_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x10)
#define STX7141_CLOCKGENA_CLKOPSRC_SWITCH_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x14)
#define STX7141_CLOCKGENA_OSC_ENABLE_FB		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x18)
#define STX7141_CLOCKGENA_PLL0_ENABLE_FB	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x1c)
#define STX7141_CLOCKGENA_PLL1_ENABLE_FB	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x20)
#define STX7141_CLOCKGENA_CLKOPSRC_SWITCH_CFG2	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x24)
#define STX7141_CLOCKGENA_CLKOBS_MUX1_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x30)
#define STX7141_CLOCKGENA_CLKOBS_MASTER_MAXCOUNT SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x34)
#define STX7141_CLOCKGENA_CLKOBS_CMD		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x38)
#define STX7141_CLOCKGENA_CLKOBS_STATUS		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x3c)
#define STX7141_CLOCKGENA_CLKOBS_SLAVE0_COUNT	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x40)
#define STX7141_CLOCKGENA_CLKOBS_OSCMUX_DEBUG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x44)
#define STX7141_CLOCKGENA_CLKOBS_MUX2_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x48)
#define STX7141_CLOCKGENA_LOW_POWER_CTRL	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x4c)
#define STX7141_CLOCKGENA_OSC_DIV0_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x800)
#define STX7141_CLOCKGENA_OSC_DIV1_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x804)
#define STX7141_CLOCKGENA_OSC_DIV2_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x808)
#define STX7141_CLOCKGENA_OSC_DIV3_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x80c)
#define STX7141_CLOCKGENA_OSC_DIV4_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x810)
#define STX7141_CLOCKGENA_OSC_DIV5_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x814)
#define STX7141_CLOCKGENA_OSC_DIV6_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x818)
#define STX7141_CLOCKGENA_OSC_DIV7_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x81c)
#define STX7141_CLOCKGENA_OSC_DIV8_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x820)
#define STX7141_CLOCKGENA_OSC_DIV9_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x824)
#define STX7141_CLOCKGENA_OSC_DIV10_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x828)
#define STX7141_CLOCKGENA_OSC_DIV11_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x82c)
#define STX7141_CLOCKGENA_OSC_DIV12_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x830)
#define STX7141_CLOCKGENA_OSC_DIV13_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x834)
#define STX7141_CLOCKGENA_OSC_DIV14_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x838)
#define STX7141_CLOCKGENA_OSC_DIV15_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x83c)
#define STX7141_CLOCKGENA_OSC_DIV16_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x840)
#define STX7141_CLOCKGENA_OSC_DIV17_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x844)
#define STX7141_CLOCKGENA_PLL0HS_DIV0_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x900)
#define STX7141_CLOCKGENA_PLL0HS_DIV1_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x904)
#define STX7141_CLOCKGENA_PLL0HS_DIV2_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x908)
#define STX7141_CLOCKGENA_PLL0HS_DIV3_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0x90c)
#define STX7141_CLOCKGENA_PLL0LS_DIV4_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa10)
#define STX7141_CLOCKGENA_PLL0LS_DIV5_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa14)
#define STX7141_CLOCKGENA_PLL0LS_DIV6_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa18)
#define STX7141_CLOCKGENA_PLL0LS_DIV7_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa1c)
#define STX7141_CLOCKGENA_PLL0LS_DIV8_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa20)
#define STX7141_CLOCKGENA_PLL0LS_DIV9_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa24)
#define STX7141_CLOCKGENA_PLL0LS_DIV10_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa28)
#define STX7141_CLOCKGENA_PLL0LS_DIV11_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa2c)
#define STX7141_CLOCKGENA_PLL0LS_DIV12_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa30)
#define STX7141_CLOCKGENA_PLL0LS_DIV13_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa34)
#define STX7141_CLOCKGENA_PLL0LS_DIV14_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa38)
#define STX7141_CLOCKGENA_PLL0LS_DIV15_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa3c)
#define STX7141_CLOCKGENA_PLL0LS_DIV16_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa40)
#define STX7141_CLOCKGENA_PLL0LS_DIV17_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xa44)
#define STX7141_CLOCKGENA_PLL1_DIV0_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb00)
#define STX7141_CLOCKGENA_PLL1_DIV1_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb04)
#define STX7141_CLOCKGENA_PLL1_DIV2_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb08)
#define STX7141_CLOCKGENA_PLL1_DIV3_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb0c)
#define STX7141_CLOCKGENA_PLL1_DIV4_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb10)
#define STX7141_CLOCKGENA_PLL1_DIV5_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb14)
#define STX7141_CLOCKGENA_PLL1_DIV6_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb18)
#define STX7141_CLOCKGENA_PLL1_DIV7_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb1c)
#define STX7141_CLOCKGENA_PLL1_DIV8_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb20)
#define STX7141_CLOCKGENA_PLL1_DIV9_CFG		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb24)
#define STX7141_CLOCKGENA_PLL1_DIV10_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb28)
#define STX7141_CLOCKGENA_PLL1_DIV11_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb2c)
#define STX7141_CLOCKGENA_PLL1_DIV12_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb30)
#define STX7141_CLOCKGENA_PLL1_DIV13_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb34)
#define STX7141_CLOCKGENA_PLL1_DIV14_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb38)
#define STX7141_CLOCKGENA_PLL1_DIV15_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb3c)
#define STX7141_CLOCKGENA_PLL1_DIV16_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb40)
#define STX7141_CLOCKGENA_PLL1_DIV17_CFG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xb44)
#define STX7141_CLOCKGENA_PLL0_BIST_REFCOUNT	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf00)
#define STX7141_CLOCKGENA_PLL0_BIST_CMPCOUNT	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf04)
#define STX7141_CLOCKGENA_PLL0_BIST_CONFIG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf08)
#define STX7141_CLOCKGENA_PLL0_BIST_OUTCOUNT	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf0c)
#define STX7141_CLOCKGENA_PLL1_BIST_REFCOUNT	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf10)
#define STX7141_CLOCKGENA_PLL1_BIST_CMPCOUNT	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf14)
#define STX7141_CLOCKGENA_PLL1_BIST_CONFIG	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf18)
#define STX7141_CLOCKGENA_PLL1_BIST_OUTCOUNT	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf1c)
#define STX7141_CLOCKGENA_JITTERBIST_PAT	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf20)
#define STX7141_CLOCKGENA_JITTERBIST_CMD	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf24)
#define STX7141_CLOCKGENA_JITTERBIST_CPT_PAT	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf28)
#define STX7141_CLOCKGENA_JITTERBIST_CPT_NOT_PAT SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf2c)
#define STX7141_CLOCKGENA_JITTERBIST_BEAT_COUNT	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf30)
#define STX7141_CLOCKGENA_JITTERBIST_BEAT_EDGE	SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xf34)
#define STX7141_CLOCKGENA_BIST_BENDBAD		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xff8)
#define STX7141_CLOCKGENA_BIST_SELECT		SH4_DWORD_REG(STX7141_CLOCKGENA_REGS_BASE + 0xffc)

/* System configuration registers (STx7141 variant) */
#define STX7141_SYSCONF_DEVICEID_0		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0000)
#define STX7141_SYSCONF_DEVICEID_1		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0004)
#define STX7141_SYSCONF_DEVICEID		SH4_GWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0000)
#define STX7141_SYSCONF_SYS_STA00		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0008)
#define STX7141_SYSCONF_SYS_STA01		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x000c)
#define STX7141_SYSCONF_SYS_STA02		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0010)
#define STX7141_SYSCONF_SYS_STA03		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0014)
#define STX7141_SYSCONF_SYS_STA04		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0018)
#define STX7141_SYSCONF_SYS_STA05		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x001c)
#define STX7141_SYSCONF_SYS_STA06		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0020)
#define STX7141_SYSCONF_SYS_STA07		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0024)
#define STX7141_SYSCONF_SYS_STA08		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0028)
#define STX7141_SYSCONF_SYS_STA09		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x002c)
#define STX7141_SYSCONF_SYS_STA10		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0030)
#define STX7141_SYSCONF_SYS_STA11		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0034)
#define STX7141_SYSCONF_SYS_STA12		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0038)
#define STX7141_SYSCONF_SYS_STA13		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x003c)
#define STX7141_SYSCONF_SYS_STA14		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0040)
#define STX7141_SYSCONF_SYS_STA15		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0044)
#define STX7141_SYSCONF_SYS_CFG00		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0100)
#define STX7141_SYSCONF_SYS_CFG01		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0104)
#define STX7141_SYSCONF_SYS_CFG02		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0108)
#define STX7141_SYSCONF_SYS_CFG03		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x010c)
#define STX7141_SYSCONF_SYS_CFG04		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0110)
#define STX7141_SYSCONF_SYS_CFG05		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0114)
#define STX7141_SYSCONF_SYS_CFG06		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0118)
#define STX7141_SYSCONF_SYS_CFG07		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x011c)
#define STX7141_SYSCONF_SYS_CFG08		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0120)
#define STX7141_SYSCONF_SYS_CFG09		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0124)
#define STX7141_SYSCONF_SYS_CFG10		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0128)
#define STX7141_SYSCONF_SYS_CFG11		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x012c)
#define STX7141_SYSCONF_SYS_CFG12		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0130)
#define STX7141_SYSCONF_SYS_CFG13		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0134)
#define STX7141_SYSCONF_SYS_CFG14		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0138)
#define STX7141_SYSCONF_SYS_CFG15		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x013c)
#define STX7141_SYSCONF_SYS_CFG16		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0140)
#define STX7141_SYSCONF_SYS_CFG17		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0144)
#define STX7141_SYSCONF_SYS_CFG18		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0148)
#define STX7141_SYSCONF_SYS_CFG19		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x014c)
#define STX7141_SYSCONF_SYS_CFG20		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0150)
#define STX7141_SYSCONF_SYS_CFG21		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0154)
#define STX7141_SYSCONF_SYS_CFG22		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0158)
#define STX7141_SYSCONF_SYS_CFG23		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x015c)
#define STX7141_SYSCONF_SYS_CFG24		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0160)
#define STX7141_SYSCONF_SYS_CFG25		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0164)
#define STX7141_SYSCONF_SYS_CFG26		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0168)
#define STX7141_SYSCONF_SYS_CFG27		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x016c)
#define STX7141_SYSCONF_SYS_CFG28		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0170)
#define STX7141_SYSCONF_SYS_CFG29		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0174)
#define STX7141_SYSCONF_SYS_CFG30		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0178)
#define STX7141_SYSCONF_SYS_CFG31		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x017c)
#define STX7141_SYSCONF_SYS_CFG32		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0180)
#define STX7141_SYSCONF_SYS_CFG33		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0184)
#define STX7141_SYSCONF_SYS_CFG34		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0188)
#define STX7141_SYSCONF_SYS_CFG35		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x018c)
#define STX7141_SYSCONF_SYS_CFG36		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0190)
#define STX7141_SYSCONF_SYS_CFG37		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0194)
#define STX7141_SYSCONF_SYS_CFG38		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x0198)
#define STX7141_SYSCONF_SYS_CFG39		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x019c)
#define STX7141_SYSCONF_SYS_CFG40		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01a0)
#define STX7141_SYSCONF_SYS_CFG41		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01a4)
#define STX7141_SYSCONF_SYS_CFG42		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01a8)
#define STX7141_SYSCONF_SYS_CFG43		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01ac)
#define STX7141_SYSCONF_SYS_CFG44		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01b0)
#define STX7141_SYSCONF_SYS_CFG45		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01b4)
#define STX7141_SYSCONF_SYS_CFG46		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01b8)
#define STX7141_SYSCONF_SYS_CFG47		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01bc)
#define STX7141_SYSCONF_SYS_CFG48		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01c0)
#define STX7141_SYSCONF_SYS_CFG49		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01c4)
#define STX7141_SYSCONF_SYS_CFG50		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01c8)
#define STX7141_SYSCONF_SYS_CFG51		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01cc)
#define STX7141_SYSCONF_SYS_CFG52		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01d0)
#define STX7141_SYSCONF_SYS_CFG53		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01d4)
#define STX7141_SYSCONF_SYS_CFG54		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01d8)
#define STX7141_SYSCONF_SYS_CFG55		SH4_DWORD_REG(STX7141_SYSCONF_REGS_BASE + 0x01dc)

/* Device ID values, masks & predicates */
#define STX7141_DEVID_7141_VAL		0x03C
#define STX7141_DEVID_ID_SHIFT		12
#define STX7141_DEVID_ID_MASK		0x3ff
#define STX7141_DEVID_CUT_SHIFT		28
#define STX7141_DEVID_CUT_MASK		0xf

#define STX7141_DEVICEID_7141(ID) ((((ID) >> STX7141_DEVID_ID_SHIFT) & STX7141_DEVID_ID_MASK) == STX7141_DEVID_7141_VAL)
#define STX7141_DEVICEID_CUT(ID)  ((((ID) >> STX7141_DEVID_CUT_SHIFT) & STX7141_DEVID_CUT_MASK) + 1)

#endif /* __ASM_ST40_STX7141REG_H */

/*
 * (C) Copyright 2009-2012 STMicroelectronics.
 *
 * Sean McGoogan <Sean.McGoogan@st.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */

#define CONFIG_ST40	1		/* This is an SH4 CPU		*/
#define CONFIG_CPU_SUBTYPE_SH4_3XX	/* it is an SH4-300		*/


/*-----------------------------------------------------------------------
 * Are we booting directly from a SPI Serial Flash device ?
 * If so, then define the "CONFIG_SYS_BOOT_FROM_SPI" macro,
 * otherwise (e.g. for NOR/NAND Flash booting), do not define it.
 * As the STx5197-CAB board only has SPI flash, then define it.
 */
#define CONFIG_SYS_BOOT_FROM_SPI			/* define to build a SPI-bootable image */


/*-----------------------------------------------------------------------
 * Start addresses for the final memory configuration
 * Assume we run out of uncached memory for the moment
 */

#ifdef CONFIG_ST40_SE_MODE
#define CONFIG_SYS_SE_PHYSICAL_BASE	0x40000000	/* LMI Physical Address */
#define CONFIG_SYS_SDRAM_BASE		0x80000000	/* LMI Cached addr via PMB */
#else
#define CONFIG_SYS_SDRAM_BASE		0x8C000000	/* SDRAM in P1 region */
#endif

#define CONFIG_SYS_SDRAM_SIZE		0x04000000	/* 64 MiB of LMI SDRAM */

#define CONFIG_SYS_EMI_SPI_BASE		0xA0000000	/* SPI Serial FLASH in SPIBOOT-mode */
#define CONFIG_SYS_MONITOR_BASE		0		/* Offset in SPI for u-boot.bin */
#define CONFIG_SYS_MONITOR_LEN		0x00040000	/* Reserve 256 KiB for Monitor */
#define CONFIG_SYS_MALLOC_LEN		(1 << 20)	/* Reserve 1 MiB for malloc */
#define CONFIG_SYS_GBL_DATA_SIZE	1024		/* Global data structures */

#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(TEXT_BASE - CONFIG_SYS_MALLOC_LEN - (1 << 20))

#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

#define XSTR(s) STR(s)
#define STR(s) #s

#define BOARD 5197cab

#define CONFIG_EXTRA_ENV_SETTINGS \
		"board=" XSTR(BOARD) "\0" \
		"monitor_base=" XSTR(CONFIG_SYS_MONITOR_BASE) "\0" \
		"monitor_len=" XSTR(CONFIG_SYS_MONITOR_LEN) "\0" \
		"load_addr=" XSTR(CONFIG_SYS_LOAD_ADDR) "\0" \
		"update=" \
		  "eeprom write $load_addr $monitor_base $monitor_len\0"

/*--------------------------------------------------------------
 * Command line configuration.
 */

#include <config_cmd_default.h>

#define CONFIG_CMD_ASKENV
#define CONFIG_CMD_NFS
#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII

/*--------------------------------------------------------------
 * Serial console info
 */

/*
 * We can use one of two methods for the "serial" console.
 * We can either use the (normal hardware) internal ST ASC UART;
 * OR we can use STMicroelectronics' DTF (Data Transfer Format)
 * mechanism over a JTAG link to a remote GDB debugger.
 */
#if 1
#	define CONFIG_STM_ASC_SERIAL		/* use a ST ASC UART */
#else
#	define CONFIG_STM_DTF_SERIAL		/* use DTF over JTAG */
#endif

#define CONFIG_SYS_STM_ASC2_BASE		0xfd132000ul	/* UART2 = AS0 */
#define CONFIG_SYS_STM_ASC3_BASE		0xfd133000ul	/* UART3 = AS1 */

/* 9-pin Female connector (J1), or 4-pin header (J2) */
#define CONFIG_SYS_STM_ASC_BASE		CONFIG_SYS_STM_ASC3_BASE

/*---------------------------------------------------------------
 * Ethernet driver config
 */

/* are we using the internal ST MAC device ? */
#define CONFIG_DRIVER_NETSTMAC

/* Config for on-chip STMAC + LAN8700 PHY */
#ifdef CONFIG_DRIVER_NETSTMAC
#	define CONFIG_SYS_STM_STMAC_BASE	0xfde00000ul	/* MAC = STM MAC */
#	define CONFIG_STMAC_LAN8700				/* PHY = SMSC LAN8700 */
#else
#	undef CONFIG_CMD_NET		/* un-define if no networking at all */
#endif	/* CONFIG_DRIVER_NETSTMAC */

/*  If this board does not have eeprom for ethernet address so allow the user
 *  to set it in the environment
 */
#define CONFIG_ENV_OVERWRITE

/*---------------------------------------------------------------
 * USB driver config
 */

/* Choose if we want USB Mass-Storage Support */
#define CONFIG_ST40_STM_USB

#ifdef CONFIG_ST40_STM_USB
#	define CONFIG_CMD_USB
#	define CONFIG_CMD_FAT
#	define CONFIG_USB_STORAGE
#	define CONFIG_SYS_USB0_BASE			0xfdd00000	/* front panel */
#	define CONFIG_SYS_USB_BASE			CONFIG_SYS_USB0_BASE
#	if 0	/* use OHCI (USB 1.x) ? */
#		define CONFIG_USB_OHCI_NEW				/* enable USB 1.x, via OHCI */
#		define CONFIG_SYS_USB_OHCI_CPU_INIT
#		define CONFIG_SYS_USB_OHCI_REGS_BASE		AHB2STBUS_OHCI_BASE
#		define CONFIG_SYS_USB_OHCI_SLOT_NAME		"ohci"
#		define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	1
#	else	/* else, use EHCI (USB 2.0) */
#		define CONFIG_USB_EHCI					/* enable USB 2.0, via EHCI */
#		define CONFIG_USB_EHCI_STM				/* use EHCI for STMicroelectronics */
#	endif	/* use OHCI/EHCI */
#endif	/* ifdef CONFIG_ST40_STM_USB */

/*---------------------------------------------------------------
 * IDE driver config
 */

#if defined(CONFIG_ST40_STM_USB)
#	define CONFIG_SYS_64BIT_LBA
#	define CONFIG_LBA48
#	define CONFIG_DOS_PARTITION
#	define CONFIG_CMD_EXT2
#endif

/*-----------------------------------------------------------------------
 * Miscellaneous configurable options
 */

#define CONFIG_SYS_HUSH_PARSER		1
#define CONFIG_AUTO_COMPLETE		1
#define CONFIG_SYS_LONGHELP		1			/* undef to save memory		*/
#define CONFIG_SYS_PROMPT		"5197CAB> "		/* Monitor Command Prompt	*/
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_HZ			1000			/* HZ for timer ticks	*/
#define CONFIG_SYS_LOAD_ADDR		CONFIG_SYS_SDRAM_BASE	/* default load address		*/
#define CONFIG_BOOTDELAY		10			/* default delay before executing bootcmd */
#define CONFIG_ZERO_BOOTDELAY_CHECK

#define CONFIG_CMDLINE_EDITING

/*-----------------------------------------------------------------------
 * FLASH organization
 */

/* Choose if we want FLASH Support (SPI, NAND &/or NOR devices)
 *
 * Note: by default CONFIG_CMD_FLASH & CONFIG_CMD_IMLS are both
 * defined in config_cmd_default.h.
 * However if we do not have any NOR flash, then un-define them.
 */
#undef CONFIG_CMD_FLASH				/* NOR-flash specific */
#undef CONFIG_CMD_IMLS				/* NOR-flash specific */
#define CONFIG_SYS_NO_FLASH			/* NOR-flash specific */

/*-----------------------------------------------------------------------
 * SPI SERIAL FLASH organization
 */

/*
 *	Name	Manuf	Device
 *	-----	-----	------
 *	U10	ST	M25P32
 *	U13	ST	M25PX64/128
 *	U4	Atmel	AT45DB321
 *	U12	Mxic	MX25Lxx
 */
/* choose Atmel or ST SPI Serial Flash */
#if 1
#	define CONFIG_SPI_FLASH_ST		/* ST M25Pxx (U10, U13) */
#elif 1
#	define CONFIG_SPI_FLASH_ATMEL		/* ATMEL AT45DB321 (U4) */
#else
#	define CONFIG_SPI_FLASH_MXIC		/* MXIC MX25Lxxx (U12) */
#endif

#define CONFIG_SPI				/* enable the SPI driver */
#define CONFIG_STM_SSC_SPI			/* Use the H/W SSC for SPI */
#define CONFIG_CMD_SPI				/* SPI serial bus command support */
#define CONFIG_CMD_EEPROM			/* enable the "eeprom" command set */
#define CONFIG_SYS_I2C_FRAM			/* to minimize performance degradation */
#undef  CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS	/* to minimize performance degradation */

#if defined(CONFIG_STM_SSC_SPI)			/* Use the H/W SSC for SPI */
#	define CONFIG_SYS_STM_SPI_SSC_BASE	ST40_SSC0_REGS_BASE	/* SPI is on SSC #0 */
#endif	/* defined(CONFIG_STM_SSC_SPI) */

/*
 *	NOTE: To use the Atmel AT45DB321D serial flash for booting,
 *	then it is required to re-program the page size to 512 bytes.
 *	(default is 528 bytes per page). This is a once only,
 *	irreversible programming option, and can not be undone.
 *	This programming may be done from U-boot (booted via JTAG)
 *
 *		U-Boot> sspi 0 32 3D2A80A6	--> FFFFFFFF
 *		U-Boot> sspi 0 16 D7		--> FFB4
 *	Then power-cycle the board before using it.
 */

/*-----------------------------------------------------------------------
 * Address, size, & location of U-boot's Environment Sector
 */

#define CONFIG_ENV_SIZE			0x4000			/* 16 KiB of environment data */

#if 1
#	define CONFIG_ENV_IS_IN_EEPROM				/* ENV is stored in SPI Serial Flash */
#	define CONFIG_ENV_OFFSET	CONFIG_SYS_MONITOR_LEN	/* immediately after u-boot.bin */
#else
#	define CONFIG_ENV_IS_NOWHERE				/* ENV is stored in volatile RAM */
#	undef  CONFIG_CMD_SAVEENV				/* no need for "saveenv" */
#endif

#endif	/* __CONFIG_H */

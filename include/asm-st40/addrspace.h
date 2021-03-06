/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 1999 by Kaz Kojima
 *
 * Defitions for the address spaces of the SH CPUs.
 */
#ifndef __ASM_ST40_ADDRSPACE_H
#define __ASM_ST40_ADDRSPACE_H

/* Memory segments (32bit Priviledged mode addresses)  */
#define P0SEG		0x00000000
#define P1SEG		0x80000000
#define P2SEG		0xa0000000
#define P3SEG		0xc0000000
#define P4SEG		0xe0000000

#if defined(__sh3__)
/* Should fill here */
#elif defined(__SH4__)
/* Detailed P4SEG  */
#define P4SEG_STORE_QUE	(P4SEG)
#define P4SEG_IC_ADDR	0xf0000000
#define P4SEG_IC_DATA	0xf1000000
#define P4SEG_ITLB_ADDR	0xf2000000
#define P4SEG_ITLB_DATA	0xf3000000
#define P4SEG_OC_ADDR	0xf4000000
#define P4SEG_OC_DATA	0xf5000000
#define P4SEG_TLB_ADDR	0xf6000000
#define P4SEG_PMB_ADDR	0xf6100000
#define P4SEG_TLB_DATA	0xf7000000
#define P4SEG_PMB_DATA	0xf7100000
#define P4SEG_REG_BASE	0xff000000
#endif


/* ----------------------------------------------------------------------------
		29-bit Mode memory alias translations
   ---------------------------------------------------------------------------*/
#ifndef CONFIG_ST40_SE_MODE

/* Returns the privileged segment base of a given address  */
#define PXSEG(a)	(((unsigned long)(a)) & 0xe0000000)

/* Returns the physical address of a PnSEG (n=1,2) address   */
#define PHYSADDR(a)	(((unsigned long)(a)) & 0x1fffffff)

/*
 * Map an address to a certain privileged segment
 */
#define P1SEGADDR(a)	((__typeof__(a))(((unsigned long)(a) & 0x1fffffff) | P1SEG))
#define P2SEGADDR(a)	((__typeof__(a))(((unsigned long)(a) & 0x1fffffff) | P2SEG))
#define P3SEGADDR(a)	((__typeof__(a))(((unsigned long)(a) & 0x1fffffff) | P3SEG))
#define P4SEGADDR(a)	((__typeof__(a))(((unsigned long)(a) & 0x1fffffff) | P4SEG))
#endif /* CONFIG_ST40_SE_MODE */


/* ----------------------------------------------------------------------------
		SE-Mode memory alias translations
   ---------------------------------------------------------------------------*/
#ifdef CONFIG_ST40_SE_MODE
	/*
	 *	Define a macro for LMI UN-cached address (via PMB) in 32-bit mode.
	 *	It should be 0xBF000000, if there is 512MiB of usable SDRAM mapped
	 *	by the PMB, otherwise it should just be 0x90000000.
	 */
#if !defined(CONFIG_SYS_SE_UNCACHED_BASE)
#if (CONFIG_SYS_SDRAM_SIZE==512<<20)
#	define CONFIG_SYS_SE_UNCACHED_BASE	0xBF000000	/* LMI UN-cached address via PMB (last 16MiB) */
#else
#	define CONFIG_SYS_SE_UNCACHED_BASE	0x90000000	/* LMI UN-cached address via PMB */
#endif
#endif

	/*
	 *	define CONFIG_SYS_SE_SDRAM_WINDOW, if not already defined.
	 */
#if !defined(CONFIG_SYS_SE_SDRAM_WINDOW)
#	define CONFIG_SYS_SE_SDRAM_WINDOW	(CONFIG_SYS_SDRAM_SIZE-1)
#endif

	/*
	 *	define CONFIG_SYS_SDRAM_BASE, if not already defined.
	 */
#if !defined(CONFIG_SYS_SDRAM_BASE)
#	define CONFIG_SYS_SDRAM_BASE		0x80000000      /* LMI Cached address via PMB */
#endif

	/*
	 * a few sanity checks for macros, when in SE (32-bit) mode
	 */
#if !defined(CONFIG_SYS_SE_SDRAM_WINDOW) || !defined(CONFIG_SYS_SE_PHYSICAL_BASE) || !defined(CONFIG_SYS_SE_UNCACHED_BASE)
#error	SH-4 SE Memory Mappings needs to be defined!
#endif

	/*
	 *	Convert VIRTUAL (cached) address to a UN-CACHED one.
	 */
#if (CONFIG_SYS_SDRAM_SIZE == (512*1024*1024) )			/* 512 MiB of RAM ? */
#define P2SEGADDR(a)	((unsigned long)(a)^(CONFIG_SYS_ST40_PMB_TEXT_CACHED_PAGE^CONFIG_SYS_ST40_PMB_TEXT_UNCACHED_PAGE))
#else	/* 512 MiB of RAM ? */
#define P2SEGADDR(a)	(((unsigned long)(a)&CONFIG_SYS_SE_SDRAM_WINDOW)|CONFIG_SYS_SE_UNCACHED_BASE)
#endif	/* 512 MiB of RAM ? */

	/*
	 *	Convert VIRTUAL address to a PHYSICAL one.
	 *	Our normal convention is that SDRAM is mapped in PMB virtual
	 *	space between 0x80000000..0x9fffffff. Hence, we wish to map virtual
	 *	addresses in this range to the appropriate physical address in
	 *	SDRAM, which we assume is determined by the SDRAM window + base.
	 *	For *all* other addresses, we assume they are *not* in SDRAM,
	 *	and hence, we do not map them at all!
	 *	Note: to do this 'properly', then we would need to loop round
	 *	all the PMB slots to decode each PMB slot, and the match on the
	 *	correct one. In practice, the above should suffice!
	 */
#define PHYSADDR(a)										\
(												\
	/* SDRAM is 0x80 to 0x9F, just check the top 3 bits */					\
	(((unsigned long)(a)&0xE0000000ul)==0x80000000ul)				?	\
	(((unsigned long)(a)&CONFIG_SYS_SE_SDRAM_WINDOW)|CONFIG_SYS_SE_PHYSICAL_BASE)	:	\
	((unsigned long)(a))									\
)
#endif	/* CONFIG_ST40_SE_MODE */

#endif /* __ASM_ST40_ADDRSPACE_H */

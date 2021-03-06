/*
 * The poke table is a series of long words, in the format
 *
 *	opcode, address, operand, ...
 *
 * An opcode of 0 marks the table end
 */


#include "asm/fli7510reg.h"
#include "../../../cpu/st40/init_ram.S"


	.section .data.init, "a"

	.balign 32

__memory_setup_table:


	/*
	 * include the appropriate set of "GDB pokes", (usually) generated
	 * using the "romgen" utility, from a known good target-pack.
	 *
	 * This file may be regenerated by executing the following
	 * command (redirecting the output), *without* needing any
	 * access to either a MicroConnect or a target board:
	 *
	 * host% romgen --show-comment dummy:fldb_gpd201:st40host,boot_companions=0
	 *
	 * Where "dummy" need not correspond to any real IP address on
	 * your network.  In addition, note that "fldb_gpd201" should
	 * substituted if you have a custom target-pack connect command.
	 *
	 * Note: The connect command used with "romgen", should connect
	 * only in 29-bit mode - even though U-Boot will be built for 32-bit mode.
	 * That is, do not use the "seuc=1" (or similar) option with "romgen".
	 */
#include "fldb-fli7510.romgen"

	END_MARKER

__memory_setup_table_end:

	.end

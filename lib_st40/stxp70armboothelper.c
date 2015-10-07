/* Synopsis: ST40 assembly code embedding STxP70 code/data to initialise the
 *           ABAP with the ARM boot address.
 *
 * Copyright (c) 2011-2013 STMicroelectronics Limited.
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
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * Conversion process:
 *	stxp70cc -mcore=stxp70v4 -P -fpic -O2 -c _stxp70armboothelper.c
 *	stxp70v4-objcopy -O binary -j .text _stxp70armboothelper.o stxp70ARMBootHelperCode.bin
 *	xxd -i stxp70ARMBootHelperCode.bin
 *
 *
 * int armBoot()
 * {
 *    // Put ARM code for jump to address read from 0x20 forward in place
 *    *(volatile unsigned int*)0xffff0000 = 0xe59ff018;
 *    *(volatile unsigned int*)0xffff0004 = 0xe59ff018;
 *    *(volatile unsigned int*)0xffff0008 = 0xe59ff018;
 *    *(volatile unsigned int*)0xffff000c = 0xe59ff018;
 *    *(volatile unsigned int*)0xffff0010 = 0xe59ff018;
 *    *(volatile unsigned int*)0xffff0014 = 0xe59ff018;
 *    *(volatile unsigned int*)0xffff0018 = 0xe59ff018;
 *    *(volatile unsigned int*)0xffff001c = 0xe59ff018;
 *
 *    // ARM boot address used for all ARM exceptions (read from base of STxP70
 *    // DMEM - put there by PBL).
 *
 *    *(volatile unsigned int*)0xffff0020 = *(volatile unsigned int*)(0x810000);
 *    *(volatile unsigned int*)0xffff0024 = *(volatile unsigned int*)(0x810000);
 *    *(volatile unsigned int*)0xffff0028 = *(volatile unsigned int*)(0x810000);
 *    *(volatile unsigned int*)0xffff002c = *(volatile unsigned int*)(0x810000);
 *    *(volatile unsigned int*)0xffff0030 = *(volatile unsigned int*)(0x810000);
 *    *(volatile unsigned int*)0xffff0034 = *(volatile unsigned int*)(0x810000);
 *    *(volatile unsigned int*)0xffff0038 = *(volatile unsigned int*)(0x810000);
 *    *(volatile unsigned int*)0xffff003c = *(volatile unsigned int*)(0x810000);
 *
 *    // So we know the STxP70 ran
 *    *(volatile unsigned int*)0x810004 = 0xb007b007;
 *
 *    // FIXME: Should be able to remove this loop and have the STxP70 stop itself
 *    while (1)
 *    { }
 *
 *    // Disable STxP70 instruction fetches
 *    *(volatile unsigned int*)(0x8b5100) &= ~1;
 * }
 */

#include "bootm_for_arm.h"

const unsigned char stxp70ARMBootHelperCode_bin[] = {
  0x0c, 0x00, 0x01, 0x61, 0x00, 0xc0, 0x0c, 0x00, 0x01, 0x61, 0x00, 0xc0,
  0x0c, 0x00, 0x01, 0x61, 0x00, 0xc0, 0x0c, 0x00, 0x01, 0x61, 0x00, 0xc0,
  0x8e, 0x09, 0x01, 0x7f, 0x67, 0xf9, 0x01, 0x81, 0x45, 0x40, 0x01, 0x78,
  0x80, 0xc0, 0x45, 0x40, 0xfd, 0x79, 0x7f, 0xc0, 0x45, 0x40, 0xf9, 0x79,
  0x7f, 0xc0, 0x45, 0x40, 0xf5, 0x79, 0x7f, 0xc0, 0x45, 0x40, 0xf1, 0x79,
  0x7f, 0xc0, 0x45, 0x40, 0xed, 0x79, 0x7f, 0xc0, 0x45, 0x40, 0xe9, 0x79,
  0x7f, 0xc0, 0x45, 0x40, 0xe5, 0x79, 0x7f, 0xc0, 0x35, 0x00, 0x01, 0x60,
  0x10, 0xc8, 0x35, 0x40, 0xe1, 0x79, 0x7f, 0xc0, 0x25, 0x00, 0x01, 0x60,
  0x10, 0xc8, 0x25, 0x40, 0xdd, 0x79, 0x7f, 0xc0, 0x15, 0x00, 0x01, 0x60,
  0x10, 0xc8, 0x15, 0x40, 0xd9, 0x79, 0x7f, 0xc0, 0xc5, 0x00, 0x01, 0x60,
  0x10, 0xc8, 0x7e, 0x02, 0x01, 0x7b, 0x01, 0xec, 0xc5, 0x40, 0xd5, 0x79,
  0x7f, 0xc0, 0x55, 0x00, 0x01, 0x60, 0x10, 0xc8, 0x55, 0x40, 0xd1, 0x79,
  0x7f, 0xc0, 0x45, 0x00, 0x01, 0x60, 0x10, 0xc8, 0x45, 0x40, 0xcd, 0x79,
  0x7f, 0xc0, 0x35, 0x00, 0x01, 0x60, 0x10, 0xc8, 0x35, 0x40, 0xc9, 0x79,
  0x7f, 0xc0, 0x25, 0x00, 0x01, 0x60, 0x10, 0xc8, 0x25, 0x40, 0xc5, 0x79,
  0x7f, 0xc0, 0x15, 0x40, 0x05, 0x60, 0x10, 0xc8, 0x0c, 0x00, 0x01, 0x61,
  0x00, 0xc0, 0x08, 0x00, 0x01, 0x60, 0x00, 0xc0, 0x0c, 0x00, 0x01, 0x61,
  0x00, 0xc0
};

const unsigned int stxp70ARMBootHelperCode_bin_len = 206;
/*
 * sjis.c - Shift-JIS handling functions
 *
 * Copyright (c) 1996
 *	Department of Mathematical and Computing Sciences,
 *	Tokyo Institute of Technology.  All rights reserved.
 *
 * $Id: sjis.c,v 2.0 1996/06/10 08:59:57 ushijima Exp $
 */


/*
 * Symbolic constants
 */

#define JIS_OFFSET		0x2121

#define SJIS1_PART1_BEGIN	0x81
#define SJIS1_PART1_END		0x9f
#define SJIS1_PART1_SIZE	(SJIS1_PART1_END - SJIS1_PART1_BEGIN + 1)

#define SJIS1_PART2_BEGIN	0xe0
#define SJIS1_PART2_END		0xef
#define SJIS1_PART2_SIZE	(SJIS1_PART2_END - SJIS1_PART2_BEGIN + 1)

#define SJIS2_PART1_BEGIN	0x40
#define SJIS2_PART1_END		0x7e
#define SJIS2_PART1_SIZE	(SJIS2_PART1_END - SJIS2_PART1_BEGIN + 1)

#define SJIS2_PART2_BEGIN	0x80
#define SJIS2_PART2_END		0x9e
#define SJIS2_PART2_SIZE	(SJIS2_PART2_END - SJIS2_PART2_BEGIN + 1)

#define SJIS2_PART3_BEGIN	0x9f
#define SJIS2_PART3_END		0xfc
#define SJIS2_PART3_SIZE	(SJIS2_PART3_END - SJIS2_PART3_BEGIN + 1)


/*
 * ja_sjis2jis - convert Shift-JIS character into JIS
 *
 * Requires:
 *   	C represents a JIS X 0208 character in the Shift-JIS encoding.
 *
 * Effects:
 *	Returns a 2-byte character corresponding to C in the JIS X
 *	0208 7-bit encoding.
 */

int ja_sjis2jis(c)
int c;
{
    int c1, c2;

    c1 = (c >> 8);
    c2 = c & 0xff;

    /*
     * Maps C1 into [0, 94/2 - 1].
     */
    if (c1 <= SJIS1_PART1_END) {
	c1 = c1 - SJIS1_PART1_BEGIN;
    } else {
	c1 = c1 - SJIS1_PART2_BEGIN + SJIS1_PART1_SIZE;
    }

    /*
     * Maps C2 into union of [0, 94 - 1] and [0x100, 0x100 + 94 - 1].
     */
    if (c2 <= SJIS2_PART1_END) {
	c2 = c2 - SJIS2_PART1_BEGIN;
    } else if (c2 <= SJIS2_PART2_END) {
	c2 = c2 - SJIS2_PART2_BEGIN + SJIS2_PART1_SIZE;
    } else {
	c2 = c2 - SJIS2_PART3_BEGIN + 0x100;
    }

    return (c1 << 9) + c2 + JIS_OFFSET;
}


/*
 * ja_jis2sjis - convert JIS character into Shift-JIS
 *
 * Requires:
 *   	C represents a JIS X 0208 character in the JIS X 0208 7-bit
 *	encoding.
 *
 * Effects:
 *	Returns a 2-byte character corresponding to C in the Shift-JIS
 *	encoding.
 */

int ja_jis2sjis(c)
int c;
{
    int c1, c2;

    c = c - JIS_OFFSET;
    c1 = c >> 9;
    c2 = c & 0x1ff;

    /*
     * Maps C1 into the union of SJIS1_PART1 and SJIS1_PART2.
     */
    if (c1 < SJIS1_PART1_SIZE) {
	c1 = c1 + SJIS1_PART1_BEGIN;
    } else {
	c1 = c1 - SJIS1_PART1_SIZE + SJIS1_PART2_BEGIN;
    }

    /*
     * Maps C2 into the union of SJIS2_PART1, SJIS2_PART2, and SJIS2_PART3.
     */
    if (c2 < SJIS2_PART1_SIZE) {
	c2 = c2 + SJIS2_PART1_BEGIN;
    } else if (c2 < SJIS2_PART1_SIZE + SJIS2_PART2_SIZE) {
	c2 = c2 - SJIS2_PART1_SIZE + SJIS2_PART2_BEGIN;
    } else {
	c2 = c2 - 0x100 + SJIS2_PART3_BEGIN;
    }

    return (c1 << 8) + c2;
}

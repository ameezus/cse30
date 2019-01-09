/*
 * Filename: ignoreCaseCompare.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Compares two strings case insensitively
 * Date: Mat 30, 2015
 * Sources of Help:
 */
	.global ignoreCaseCompare
	.section ".text"

/*
 * Function name: ignoreCaseCompare()
 * Function prototype:
 *               int ignoreCaseCompare (const void *p1, const void *p2);
 * Description:  Compares two strings case insensitively
 * Parameters:
 *               arg 1: const void *p1 - 1st string to compare
 *               arg 2: const void *p2 - 2nd string
 *
 * Side Effects: None
 * Error Conditions:
 * Return Value: Positive if first string is greater, 0 if they are the same
 *		 and negative if the second string is greater
 *
 * Registers used:
 *               %i0 - arg 1
 *               %i1 - arg 2
 */

ignoreCaseCompare:
	save %sp, -96, %sp

	mov %i0, %o0		! getting params ready
	mov %i1, %o1		! for strcasecmp

	call strcasecmp		! calling strcasecmp
	nop

	mov %o0, %i0		! getting return value

	ret
	restore

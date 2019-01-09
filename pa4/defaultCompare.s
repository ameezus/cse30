/*
 * Filename: defaultCompare.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Compares two strings using strcmp
 * Date: May 31, 2015
 * Sources of Help:  None
 */
	.global defaultCompare
	.section ".text"

/*
 * Function name: defaultCompare()
 * Function prototype:
 *               int defaultCompare (const void *p1, const void *p2);
 * Description:  Compares two strings using strcmp
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

defaultCompare:
	save %sp, -96, %sp

	mov %i0, %o0		! getting params ready
	mov %i1, %o1		! for strcmp 

	call strcmp		! calling strcmp
	nop

	mov %o0, %i0		! returning value from strcmp

	ret
	restore

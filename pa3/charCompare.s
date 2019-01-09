/*
 * Filename: charCompare.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function compates 2 pointers to characters.
 * Date: May 18, 2015
 * Sources of Help:  None
 */
	.global charCompare
	.section ".text"

/*
 * Function name: charCompare()
 * Function prototype:
 *               int charCompare (const void * lhs, const void *rhs);
 * Description:  This function compates 2 pointers to characters.
 * Parameters:
 *               arg 1: const void *lhs: first char
 *               arg 2: const void *rhs: second char
 *
 * Side Effects: None
 * Error Conditions: None
 * Return Value: -1 if the first is smaller and 1 if the first is larger. 0
 *		 if they are the same
 *
 * Registers used:
 *               %i0 - arg 1 -- first value
 *               %i1 - arg 2 -- second value
 */

charCompare:
	ldub [%o0], %o0		! loading pointer
	ldub [%o1], %o1		! loading pointer

	cmp %o0, %o1		! comparing chars
	be same			! if they are the same
	nop

	cmp %o0, %o1
	bl firstSmall		! if the first is smaller
	nop

	cmp %o0, %o1
	bg secondSmall		! if the second is smaller
	nop

same:				! return 0 if theyre the same
	mov %g0, %o0
	retl
	nop

firstSmall:			! return -1 if the first is smaller
	mov -1, %o0
	retl
	nop

secondSmall:			! return 1 if the second is smaller
	mov 1, %o0
	retl
	nop

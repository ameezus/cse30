/*
 * Filename: numOfDigits.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This is used to calculate how many digits are passed into it.
 * Date: April 13, 2015
 * Sources of Help: None
 */	
	.global numOfDigits	! Declares "numOfDigits" to be globally usable
	.section ".text"	! Text segment begins here

MIN_BASE = 2
MAX_BASE = 36

/*
 * Function name: numOfDigits()
 * Function prototype: int numOfDigits(long num, int base);
 * Description: counts the number of base digits in its argument
 *       uses checkRange()
 * Parameters:
 *    arg 1: long num -- long to count number of base digits from
 *    arg 2: int base -- base in which to count number of digits
 *
 * Side Effects: none, only returns a value
 * Error Conditions: None
 * Return Value: number of base digits in the argument; can be zero
 *        0 if base is out of range
 *
 * Registers Used:
 *    %i0 - arg 1 -- the long argument to count number of base digits from
 *    %i1 - arg 2 -- the base in which to count the number of digits
 *
 *    %l0 - local var -- result of check range
 *    %l1 - local var -- counter to keep track of number of base digits
 *
 *    %o0 - param 1 -- holds MIN_BASE for comparisons
 *    %o1 - param 2 -- holds MAX_BASE for comparisons
 *    %o2 - param 3 -- value to check if it is in range using checkRange()
 */

numOfDigits:			! num of digits branch
	save %sp, -96, %sp	! save callers window

	mov 0, %l1		! l1 is counter
	
	mov %i1, %o2		! put base into %o2 for use with checkRange()
	mov MIN_BASE - 1, %o0	! put MIN_BASE into o0
	mov MAX_BASE + 1, %o1	! put MAX_BASE into o1

	call checkRange		! call on checkRange with o0, o1, o2
	nop

	mov %o0, %l0		! l0 is the result of check range

	cmp %l0, 0		
	bne baseInRange		! if o0 is not equal to 0 then call on
				! in range branch
	nop

	mov -1, %i0		! if not in range then put -1 into i0
	ba endCheck		! call on endCheck branch
	nop

baseInRange:			! inRange branch
	cmp %i0, 0	
	bne numNotZero		! if i0 does not equal 0 then call on
				! numNotZero branch
	nop

	mov 1, %i0
	ba endCheck		! else call on endCheck

numNotZero:			! numNotZero branch
	cmp %i0, 0
	be endWhile		! if i0 equals 0 then call on endWhile branch
	nop

	mov %i0, %o0		! if not equal then move i0 into o0
	mov %i1, %o1		! and move i1 into o1
	call .div		! then divide o0/o1
	nop

	mov %o0, %i0		! move o0 into i0 

	add %l1, 1, %l1		! iterate counter

	call numNotZero		! call on inRange branch
	nop

endWhile:			! endWhile branch
	mov %l1, %i0		! move l1 into i0
	ba endCheck		! call on endCheck branch
	nop

numIsZero:			! numIsZero branch
	mov 1, %i0		! move 1 into i0
	ba endCheck		! call on endCheck branch

endCheck:			! endCheck branch
	ret
	restore

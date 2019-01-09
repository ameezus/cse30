/*
 * Filename: checkRange.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This file has the checkRange function which checks if a valule
 *		is within the range that is passed along with the value.
 * Date: April 13, 2015
 * Sources of Help: None
 */ 

	.global checkRange	! Declares "checkRange" to be a globally usable
				! symbol
	.section ".text"	! Text symbol begins here

/*
 * Function name: checkRange()
 * Function prototype:
 *               int checkRange( long minRange, long maxRange, long value );
 * Description:  function determines whether or not the value passed in is
                 within the range of the min and max values
 * Parameters:
 *               arg 1: long minRange - Minimum value that arg 1 can be
 *               arg 2: long maxRange - Maximum value that arg 1 can be
 *		 arg 3: long value - Number to check in range
 *
 * Side Effects: None
 * Error Conditions: If not in range, handle error message in main.
 * Return Value: 0 if not in range, non-zero value for in range.
 *
 * Registers used:
 *               %i0 - arg 1 -- Minimum Value
 *               %i1 - arg 2 -- Maximum value
 * 		 %i2 - arg 3 -- Number to check and used for return
 *
 */

checkRange:			! check range brnach
	save %sp, -96, %sp	! save caller's window

	cmp %i2, %i0		
	bg else_if		! check if num is greater than min value
	nop

	ba outRange		! else go to out of range branch
	nop

else_if:
	cmp %i2, %i1		! else if branch
	bl inRange		! check if num is less than max value
				! if it is go to in range branch
	nop

	ba outRange		! else go to out of range branch
	nop

outRange:			! out of range branch
	mov 0, %i0		! if num is out of range move 0 into i0
	ba endCheck		! go to endCheck branch
	nop

inRange:			! in range brancg
	mov 1, %i0		! if num is in range move 1 into i0
	ba endCheck		! go to end check branch
	nop

endCheck:			! end check branch
	ret
	restore

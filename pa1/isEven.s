/*
 * Filename: isEven.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Descriptions: This file determines if a number is even or not
 * Date: April 12, 2015
 * Sources of Help: CSE Lab Tutors
 */

	.global isEven		! global variable that can be called from other files

	.section ".text"	! Text segment begins


/*
 * Function name: isEven()
 * Function prototype: isEven( long value );
 * Description: Takes in a long parameter and checks if it is even.
 * Parameters:
 * Side Effects: None
 * Error Conditions: None
 * Return Value: 0 if odd, 1 if even
 *
 * Registers used:
 *    
 */

isEven:
	save %sp, -96, %sp 	! Save window

	and %i0, 1, %i0		! Results in 1 if odd and 0 if even
	xor %i0, 1, %i0		! Results in 0 if odd and 1 if even

	ret 			! Return subroutine
	restore 		! Restore window

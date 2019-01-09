/*
 * Filename: printChar.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This file will print the character argument to stdout
 * Date: April 19, 2014
 * Sources of Help: None
 */

	.global printChar          ! Allows printChar to be used globally

	.section ".data"           ! Starts data section

fmt:				   ! sets up format
	.asciz "%c"

	.section ".text"	   ! Starts text section

/*
 * Function name: printChar()
 * Function prototype: void printChar(char ch);
 * Description: prints the char arg to stdout
 * Parameters:
 *    arg 1: char printed out
 * Side Effects: char is printed
 * Error Conditions: none
 * Return Value: none
 *
 * Registers Used:
 *    %i0 - arg 1 - char passed in to this function
 *    %o0 - param 1 to printf() - format string
 *    %o1 - param 2 to printf() - copy of arg that was passed in
 */

printChar:
	save %sp, -96, %sp	! save window

	set fmt, %o0		! send 1st parameter to o0
	call printf		! call printf
	mov %i0, %o1		! move i0 into o1

	ret
	restore

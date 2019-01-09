/*
 * Filename: printUsage.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function prints the usage message to stderr
 * Date: May 30, 2015
 * Sources of Help:  None
 */
	.global		printUsage
	.section	".text"

/* Function name: printUsage()
 * Function prototype:
 *               void printUsage (const char *programName)
 * Description:  This function prints the usaage to stderr
 * Parameters:
 *               arg 1: const char* programName
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 *
 * Registers used:
 *               %i0 - arg 1 -- program name
 */

printUsage:
	save %sp, -96, %sp

	set standardOut, %o0	! setting stdout into o0
	set longUsage, %o1	! setting longUsage into o1

	ld [%o0], %o0		! loading pointers
	ld [%o1], %o1		! loadind pointers
	
	mov %i0, %o2		! moving the program name into o2

	call fprintf		! call fprintf
	nop

	ret
	restore

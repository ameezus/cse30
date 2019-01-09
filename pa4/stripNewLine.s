/*
 * Filename: stripNewLine.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function usser strchr to look for a newline character
 *		and changes it to a null character if it finds one
 * Date: May 18, 2015
 * Sources of Help:  None
 */
	.global 	stripNewLine
	.section 	".text"

/*
 * Function name: stripNewLine()
 * Function prototype:
 *               strip newLine (char *str)
 * Description: This function uses strchr to look for a newline character
 *		and changes it to a null character if it finds one
 * Parameters:
 *               arg 1: char *str: char * to look for a newline in
 *
 * Side Effects: None
 * Error Conditions: None
 * Return Value: none
 *
 * Registers used:
 *               %i0 - arg 1 -- char *str
 */

stripNewLine:
	save %sp, -96, %sp

	mov %i0, %o0		! move str into o0
	set '\n', %o1		! set newline into o1
	
	call strchr		! call strchr
	nop

	cmp %o0, %g0		! cmp out to null char
	be end
	nop
	
	set '\0', %l0		! set null char into l0
	stb %l0, [%o0]		! store null chare

end:
	ret
	restore

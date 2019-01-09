/* 
 * Filename: parseRotateValue.s 
 * Author: Ameer Muhtaseb 
 * Userid: cs30xdw 
 * Description: This module is responsible for the parsing of the rotation
 *		value.
 * Date: April 26, 2015
 * Sources of Help: 
 */ 
	.global parseRotateValue
	.section ".text"

ENDPTR_OFFSET = 4
BASE = 10

/* 
 * Function name: parseRotateValue() 
 * Function prototype: 
 *               int parseRotateValue( char *str, long *rotateValue );
 * Description: Responsible for parsing the rotate value 
 * Parameters: 
 *               arg 1: char *str - string converted to long 
 *               arg 2: long *rotateValue - value to be parsed 
 * 
 * Side Effects: None 
 * Error Conditions: 
 * Return Value: None 
 * 
 * Registers used: 
 *               %i0 - arg 1 
 *               %i1 - arg 2 
 * 
 * 		 %l0 - converted string
 * 		 %l1 - first 4 chars of passphrase 
 * 		 %l2 - second key 
 *		 %l3 - last 4 chars of passphrase 
 */ 

parseRotateValue:
	save %sp, - (92 + ENDPTR_OFFSET) & -8, %sp

	mov %i0, %o0			! moving parameters into output
	add %fp, -ENDPTR_OFFSET, %o1	! for strtol call
	mov BASE, %o2

	call strtol			! strtol call
	nop

	mov %o0, %l0 			! move result to l0

	ld [%fp - ENDPTR_OFFSET], %l1	! load end pointer offset into l1
	ldub [%l1], %l1			! load end pointer offset
	
	cmp %l1, %g0			! compare to zero
	bne endptrError
	nop

	set errno, %l2 			! where to find errorno in memory
	ld [%l2], %l2			! load errno
	
	cmp %l2, %g0			! check for errno errors
	bne errnoError
	nop
	
	ba contBounds			! if no errno errors
	nop

endptrError:
	set ENDPTR_ERR_G, %l5		! move end point error into return
	ld [%l5], %l5
	mov %l5, %i0
	
	ret	
	restore

errnoError: 
	set ERANGE_ERR_G, %l6		! move erange error into return
	ld [%l6], %l6
	mov %l6, %i0
	
	ret
	restore

contBounds:
	set MIN_ROTATE_G, %l3		! set min rotate into l3
	ld [%l3], %l3			! load l3 then compare to 
	cmp %l3, %l0
	bge boundError			! checling for bound error
	nop

	set MAX_ROTATE_G, %l4
	ld [%l4], %l4
	cmp %l4, %l0
	ble boundError			! checking for bound error
	nop

	st %l0, [%i1]			! storing l0
	mov %g0, %i0
	
	ret
	restore

boundError:
	set BOUND_ERR_G, %l7		! moving bound error into return
	ld [%l7], %l7
	mov %l7, %i0
	
	ret
	restore

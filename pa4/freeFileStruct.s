/*
 * Filename: freeFileStrucr.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Frees all memory allocated within a struct file.
 * Date: May 31, 2015
 * Sources of Help:  None
 */

	.global freeFileStruct
	.section ".text"

/*
 * Function name: freeFileStruct()
 * Function prototype:
 *               int freeFileStruct (const struct file* file);
 * Description:  Frees all memory allocated within a struct file
 * Parameters:
 *               arg 1: const struct file* file - file to free memory from
 *
 * Side Effects: None
 * Error Conditions:
 * Return Value: The number of times free is called
 *
 * Registers used:
 *               %i0 - arg 1
 */

freeFileStruct:
	save 	%sp, -96, %sp

	ld	[%i0], %l0	! load params
	ld	[%i0 + 4], %l1

	mov 	%g0, %l2	! move 0 into l2 for counter

	cmp	%l1, %l2	! if 
	ble	endLoop
	nop
	

startLoop:
	ld	[%l0], %o0	! load param again

	call	free		! call free
	nop
	
	add	%l0, 4, %l0	! move to next byte
	
	inc	%l2

	cmp 	%l1, %l2	! compare
	bg	startLoop
	nop


endLoop:
	ld 	[%i0], %o0	! load
	
	call	free		! call free
	nop
	
	inc	%l2		! increment counter

	mov	%l2, %i0	! get return value
	
	ret
	restore

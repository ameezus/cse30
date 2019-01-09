/* 
 * Filename: mycrypt.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function does the encrypting/decrypting of the data using
 *		the keys and masks we got from the user. In a loop, read up a 
 *		block of data (BUFSIZ bytes at a time) from inFile with fread()
 *		While there is more data to read (fread() returns a 0 to 
 *		indicate it did not read up any items
 * Date: 5/1/15
 * Sources of Help: Lab Tutors 
 */
	.global mycrypt
	.section ".text"

/*
 * Function name: mycrypt()
 * Function prototype: void mycrypt(FILE *inFile, unsigned long mask[], 
 *     				    int rotateValue);
 * Description: While there is more data to read (fread() returns a 0
 * 		to indicate it did not read up any items) perform the 
 * 		follow. Encrypt 8 byte chunks of the data with the 
 * 		64-bit mask (XOR first 4 bytes of data with mask[0] 
 * 		and the second 4 bytes of data with mask[1]). Rotate 
 * 		the 64-bit mask with the rotation key using rotate().
 * Paramenters:
 * arg 1: FILE *inFile - file to read from 
 * arg 2: unsigned long mask[] - the mask to encypt
 * arg 3: rotateValue - the value to rotate the mask
 *
 * Side Effects: encrypts the file
 * Error Confitions: none
 * Return Value: none
 * Registers Used: 
 * %i0 - file to read from
 * %i1 - the mask to encrypt
 * %i2 - the value to rotate the mask
 * %l0 - buffer amount
 * %l1 - amount of bits that were XORed
 * %l2 - loaded bytes
 * %l3 - loaded mask
 * %l4 - Offset for the next byte
 * %l5 - Offset for the next byte
 * %l6 - counter for the one byte Xoring
 * %l7 - offset for one byte XOR
 */

BUFFSIZE = 1024
EIGHT = 8
ONE = 1
FOUR = 4


mycrypt:
	
	save %sp, -(92 + BUFFSIZE) & -EIGHT, %sp
	add %fp, -BUFFSIZE, %o0
	set ONE, %o1
	set BUFFSIZE, %o2
	mov %i0, %o3

	call fread
	nop

	mov %o0, %l0 		! negative buffer amount
	mov %g0, %l1 		
	mov %g0, %l6 		

	cmp %l0, %g0
	be endMC
	nop

moreDataToRead:
	
	cmp %l0, EIGHT		!check if there is more data to read
	bl oneByteXOR
	nop

fourByteXOR:
	
	add -BUFFSIZE, %l1, %l5	! four byte xor algorithm
	add %fp, %l5 , %l4
	
	ld [%l4], %l2
	ld [%i1], %l3

	xor %l2, %l3, %o0
	st %o0, [%l4]

	ld [%l4 + FOUR], %l2
	ld [%i1 + FOUR], %l3

	xor %l2, %l3, %o0
	st %o0, [%l4 + FOUR]

	mov %i1, %o0
	mov %i2, %o1

	call rotate
	nop
	
	add %l1, EIGHT, %l1

	sub %l0, EIGHT, %l0

	cmp %l0, EIGHT
	bge fourByteXOR
	nop

	cmp %l0, %g0
	be contMC
	nop

oneByteXOR:
	
	add -BUFFSIZE, %l1, %l5 !one byte xor algorithm
	add %fp, %l5, %l4
	
	ldub [%l4], %l2
	
	add %l6, %i1, %l7
	
	ldub [%l7], %l3

	xor %l2, %l3, %o0
	
	stb %o0, [%l4]
	
	inc %l6
	inc %l1
	dec %l0

	cmp %l0, %g0		!compare to 0
	bne oneByteXOR
	nop

contMC:
	add %fp, -BUFFSIZE, %o0	!prepare output parameters
	
	mov %l1, %o1
	
	set ONE, %o2
	set standardOut, %o3
	
	ld [%o3], %o3

	call fwrite		!output to user
	nop

	add %fp, -BUFFSIZE, %o0	!prepare output paramters
	
	set ONE, %o1
	set BUFFSIZE, %o2
	
	mov %i0, %o3

	call fread		!read next amount
	nop

	mov %o0, %l0
	mov %g0, %l1

	cmp %l0, %g0
	bne moreDataToRead
	nop

endMC:
	ret
	restore

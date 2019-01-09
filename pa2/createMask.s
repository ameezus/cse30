/* 
 * Filename: createMask.s 
 * Author: Ameer Muhtaseb 
 * Userid: cs30xdw 
 * Description: This module creates a 32-bit mask values. 
 * Date: April 26, 2015 
 * Sources of Help: 
 */ 

	.global createMask         ! declares createMask for global use 

	.section ".text"           ! start data 

/* 
 * Function name: createMask() 
 * Function prototype: 
 *               void createMask (unsigned long keys[], char passphrase[], 
 				  unsigned long mask[]); 
 * Description: Creates the two 32-bit masks 
 * Parameters: 
 *               arg 1: unsigned long keys[] - holds keys to mask 
 *               arg 2: char passphrase[] - provides chars to mask 
 *               arg 3: unsigned long mask[] - holds the bytes for the mask 
 * 
 * Side Effects: None 
 * Error Conditions: 
 * Return Value: None 
 * 
 * Registers used: 
 *               %i0 - arg 1 
 *               %i1 - arg 2 
 *               %i2 - arg 3 
 * 
 * 		 %l0 - first key 
 * 		 %l1 - first 4 chars of passphrase 
 * 		 %l2 - second key 
 *		 %l3 - last 4 chars of passphrase 
 */ 

createMask:
	save %sp, -96, %sp
	
	ld [%i0], %l0		! load first long key into l0 
	ld [%i1], %l1		! load first 4 chars into l1 

	xor %l0, %l1, %o0	! xor l0 and l1 

	st %o0, [%i2]		! stor o0 into mask array 

	ld [%i0 + 4], %l2	! load 2nd long key into l2 
	ld [%i1 + 4], %l3	! load last 4 chars into l3 
 
	xor %l2, %l3, %o1	! xor l2 and l3 

	st %o1, [%i2 + 4]	! stor o1 into end of mask array 

	ret 
	restore

/*
 * Filename: rotate.s
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function rotates the current 64 bit mask
 * Date: April 26, 2015
 * Sources of Help:
 */

	.global rotate			! allows global use

	.section ".text"		! starts text segment


mostSigBit = 0x80000000
leastSigBit = 0x00000001
SIXBIT_MASK = 0x0000003F
rightShift = 31
leastShift = 1

 /*
 * Function name: rotate()
 * Function prototype:
 *              void rotate (unsigned long mask[], int rorateCnt);
 * Description: Rotates the 64 but mask by rotateCnt places
 * Parameters:
 *               arg 1: unsigned long mask[] - mask that is rotated
 *               arg 2: int rotate - rotation counter
 *
 * Side Effects: None
 * Error Conditions: 
 * Return Value: None
 *
 * Registers used:
 *    %i0 - arg 1 -- first bank
 *    %i1 - arg 2 -- second bank
 *    %l2 - temporary location for the final correct amount
 *    %l3 - temporary location for the final correct amount
 *    %l6 - stores the lower limit
 */

rotate:
   save  %sp, -96, %sp

   ld [%i0], %l1      		! load inputs              
   ld [%i0+4], %l2

   set   mostSigBit, %l3
   and   %l3, %i1, %l3          ! getting MSB

   srl   %l3, rightShift, %l3   ! shifting right

   cmp   %l3, %g0
   bne   rightRot               ! goes to right rotate
   nop

   set   SIXBIT_MASK, %l4       ! gets rotate's sign
   and   %l4, %i1, %l4

   cmp   %l4, %g0		! if there are no more rotates
   be end                           
   nop

leftRot:
   dec   %l4			! decrement

   set   mostSigBit, %l5

   and   %l5, %l2, %l6
   srl   %l6, rightShift, %l6   ! shift right with LSB     
   and   %l5, %l1, %l0
  
   srl   %l0, rightShift, %l0          
   sll   %l1, leastShift, %l1	! shift right then shift left 2 times
   sll   %l2, leastShift, %l2
   
   or %l6, %l1, %l1               
   or %l0, %l2, %L2

   cmp   %l4, %g0		! checks if counter is 0 yet
   bg leftRot                    
   nop

   ba end
   nop

rightRot:
   neg   %i1
   and   SIXBIT_MASK, %i1, %l4  ! getting signed bit
   cmp   %l4, %g0		! checking if counter is 0
   be end
   nop

loopCont:
   dec   %l4			! decrement

   set   leastSigBit, %l5

   and   %l5, %l2, %l0
   sll   %l0, rightShift, %l0   ! shift right with LSB 
   and   %l5, %l1, %l6
   
   sll   %l6, rightShift, %l6
   srl   %l1, leastShift, %l1   ! shift right then left two times
   srl   %l2, leastShift, %l2
   
   or %l0, %l1, %l1             ! or-ing twice
   or %l6, %l2, %l2
   
   cmp   %l4, %g0               ! checks if counter is 0
   bg loopCont
   nop

end:
   st %l1, [%i0]                ! prepares bank for output   
   st %l2, [%i0+4]

   ret
   restore

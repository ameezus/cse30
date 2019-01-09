/*
 * Filename: displayX
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This assembly module will perfrom the actual outputting of
 *		individual characters.
 * Date: 15 October 2014
 * Sources of Help:  Help from a tutor in the CSE lab
 */

  .global displayX      !Declares the symbol to be globally visible so

  .section ".data"      !start data segment

  .section ".text"      !start text segment

 /*
 * Funtion name: displayX()
 * Funtion prototype: void displayX( long size, long xChar,
 *                    long fillerChar, long borderChar );
 * Description: Prints out X character 
 * Parameters:
 *      arg 1: long size - size of the X
 *      arg 2: long xChar - char for the X
 *      arg 3: long fillerChar - char for the filler
 *      arg 4: long borderChar - char for the border
 *
 * Side Effects: None.
 * Error Conditions: None.
 * Return value: None
 *
 * Registers used.
 *    %i0 -  arg 1: long size -- size of the pattern.
 *    %i1 -  arg 2: long xChar - character to be printed.
 *    %i2 -  long fillerChar - character to be filled in xchar
 *    %i3 -  long borderChar - border to be printed
 *
 *    %l0 - # of rows
 *    %l1 - numOfDigits
 *    %l2 - numOfDigits*2 + size
 *    %l3 - # of cols
 */

displayX:
	save %sp, -96, %sp	! start window

	NL = "\n"
	BASE = 10

	mov %i0, %o0		! move size into o0
	mov BASE, %o1		! move base to o1

	clr %l0			! clear l0 for row

	call numOfDigits	! call num of digits with o0 and o1
	nop

	mov %o0, %l1		! move numOfDigits to l1

	mov %l1, %o0
	mov 2, %o1		! multiply by 2
	call .mul
	nop

	mov %o0, %l2		! move numOfDigits*2 to l2

	add %i0, %l2, %l2	! add size to l2

	cmp %l0, %l1		! compare row to numOfDigits
	bge displaySideBorder
	nop

displayTopBorder:
	clr %l3			! clear l3 for # of cols

	cmp %l3, %l2		! compare # of cols to numOfDigits*2
	bge printNL
	nop

displayTB2:			! inner for loop of displayTopBorder
	
	mov %i3, %o0		! move border char into o0
	
	call printChar		! print border char

	inc %l3			! increment # of cols

	cmp %l3, %l2		! comparer # of cols to numOfDigits
	bl displayTB2		! recall inner loop of displayTopBorrder
	nop

printNL:			! print new line branch 
				! (after end of displayTB2)

	mov NL, %o0		! new line character
	call printChar

	inc %l0			! increment # of rows
	cmp %l0, %l1		! compare # of rows to numOfDigits
	bl displayTopBorder
	nop


displaySideBorder:
	clr %l0			! clear row

	cmp %l0, %i0		! compare row to size
	bge endBorderLoop
	nop

endDSB:				! end display side border
	
	clr %l4			! clear border count

	cmp %l4, %l1		! compare border count to num of digits
	bge endprintBC
	nop

printBorderChar:		

	mov %i3, %o0		! move filler char inro o0
	call printChar
	nop

	inc %l4			! increment border count
	
	cmp %l4, %l1		! compare border count to num of digits
	bl printBorderChar
	nop

endprintBC:
	clr %l3			! clear # of cols
	
	cmp %l3, %i0		! compare # of cols to size
	bge printBC3
	nop

printBC2:			 !goes from col to size

      sub %i0, %l3, %l2          ! l2 = size-col
      sub %l2, 1, %l2            ! l2 = size-col-1

      cmp %l0, %l3               ! compare # of rows and # of cols
      be printXChar
      nop

      cmp %l0, %l2               !row = size-col-1
      be printXChar
      nop

printTheFiller:           ! else statement
      
      mov %i2, %o0	  ! move filler char into o0
      call printChar
      nop

      ba endIf
      nop

printXChar:                    ! if statement
      
      mov %i1, %o0	       ! move X char into o0
      call printChar
      nop

endIf:

	inc %l3			! increment # of cols
	cmp %l3, %i0		! compare # of cols to size
	bl printBC2
	nop

printBC3:
	
	clr %l4			! clear border count

	cmp %l4, %l1		! compare border count to numOfDgits
	bge printNL2
	nop

createBC:
	
	mov %i3, %o0		! move border char into o0
	call printChar
	nop

	inc %l4			! increment border count

	cmp %l4, %l1
	bl createBC
	nop

printNL2:

	mov NL, %o0
	call printChar
	nop

	inc %l0			! increment row count
	cmp %l0, %i0		! compare rowcount to size
	bl endDSB
	nop

endBorderLoop:
	
	clr %l0			! clear row count

	mov %l1, %o0		! move num of digits into o0
	mov 2, %o1
	call .mul
	nop

	mov %o0, %l2

	add %i0, %l2, %l2	! add size and l2 into l2

	cmp %l0, %l1		! compare # of rows to numOfDigits
	bge endprintBB
	nop

printBottomBorder:

	clr %l3			! clear # of cols
	
	cmp %l3, %l2		! compare # of cols to numOfDgits*2 + size
	bge endprintBB2
	nop

printBB2:

	mov %i3, %o0
	call printChar
	nop
	
	inc %l3			! increment # of cols
	cmp %l3, %l2		! compare # of cols to numOfDgits*2 + size
	bl printBB2
	nop

endprintBB2:
	mov NL, %o0
	call printChar
	nop

	inc %l0			! increment # of rows

	cmp %l0, %l1		! compare # of rows to num of digits
	bl printBottomBorder
	nop

endprintBB:
	ret
	restore

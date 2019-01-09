/*
 * Filename: testnumOfDigits.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Unit test program to test the function numOfDigits.
 * Date: April 13, 2015
 * Sources of Help: None
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For numOfDigits() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * int numOfDigits( long minRange, long maxRange, long value );
 *
 * Returns non-zero if value is within minRange and maxRange, exclusive.
 * Returns 0 otherwise.
 *
 * Precondition: Assume minRange is less than or equal to maxRange.
 */

void
testnumOfDigits()
{
    printf( "Testing numOfDigits()\n" );

    TEST(numOfDigits(10,0) == -1);
    TEST(numOfDigits(154,-1) == -1 );
    TEST(numOfDigits(0,5) == 1 );
    TEST(numOfDigits(4,40) == -1);
    
    printf( "Finished running tests on numOfDigits()\n" );
}

int
main()
{
    testnumOfDigits();

    return 0;
}

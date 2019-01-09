/*
 * Filename: testisEven.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Unit test program to test the function isEven.
 * Date: April 13, 2015
 * Sources of Help: None
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For isEven() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * int isEven( long minRange, long maxRange, long value );
 *
 * Returns non-zero if value is within minRange and maxRange, exclusive.
 * Returns 0 otherwise.
 *
 * Precondition: Assume minRange is less than or equal to maxRange.
 */

void
testisEven()
{
    printf( "Testing isEven()\n" );

    /* Test for 0,-1,2,3 */
    TEST(isEven(0));
    TEST(!isEven(-1));
    TEST(isEven(2));
    TEST(!isEven(3));
    
    /* Test MIN and MAX int values */
    TEST(isEven( LONG_MIN ));
    TEST(!isEven( LONG_MAX ));

    printf( "Finished running tests on isEven()\n" );
}

int
main()
{
    testisEven();

    return 0;
}

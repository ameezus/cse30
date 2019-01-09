/*
 * Filename: testcheckRange.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Unit test program to test the function checkRange.
 * Date: April 13, 2015
 * Sources of Help: None
 */ 

#include <stdlib.h>	/* For rand() function prototype */
#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For checkRange() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * int checkRange( long minRange, long maxRange, long value );
 *
 * Returns non-zero if value is within minRange and maxRange, exclusive.
 * Returns 0 otherwise.
 *
 * Precondition: Assume minRange is less than or equal to maxRange.
 */

void
testcheckRange()
{
    printf( "Testing checkRange()\n" );

    /* Test around 0 */
    TEST( checkRange( 0, 0, -1 ) == 0 );
    TEST( checkRange( 0, 0, 0 ) == 0 );
    TEST( checkRange( 0, 0, 1 ) == 0 );

    /* Test around a negative range */
    TEST( checkRange( -99, -90, -100 ) == 0 );
    TEST( checkRange( -99, -90, -99 ) == 0 );
    TEST( checkRange( -99, -90, -90 ) == 0 );
    TEST( checkRange( -99, -90, -89 ) == 0 );

    TEST( checkRange( -99, -90, -95 ) != 0 );
    TEST( checkRange( -99, -90, -91 ) != 0 );

    /* Test around a positive range */
    TEST( checkRange( 100, 101, 99) == 0 );
    TEST( checkRange( 100, 101, 100 ) == 0 );
    TEST( checkRange( 100, 101, 101 ) == 0 );
    TEST( checkRange( 100, 101, 102 ) == 0 );

    TEST( checkRange( 100, 102, 101 ) != 0 );
    TEST( checkRange( 90, 100, 95 ) != 0 );

    /* Test MIN and MAX int values with range of size 0. */
    TEST( checkRange( LONG_MIN, LONG_MIN, LONG_MIN ) == 0 );
    TEST( checkRange( LONG_MAX, LONG_MAX, LONG_MAX ) == 0 );

    printf( "Finished running tests on checkRange()\n" );
}

int
main()
{
    testcheckRange();

    return 0;
}

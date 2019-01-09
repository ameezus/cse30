#include "test.h"       /* For TEST() macro and stdio.h */
#include <stdlib.h>     /* For rand() function prototype */
#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For rotate() function prototype */

void
testcreateMask()
{
    unsigned long key[2];
    unsigned long mask[2];

    printf( "Testing rotate()\n" );

    /*
     * Test with rotateCnt of 0 - should be no change.
     */
    key[0] = 0x00000000;
    key[1] = 0x00000000;

    createMask( key,"00000000",mask);
    TEST( mask[0] == 808464432 && mask[1] == 808464432 );

    key[0] = 0x11113333;
    key[1] = 0x22224444;

    createMask( key,"12341234",mask);
    printf ("%ul", mask[0]);
    printf ("%ul", mask[1]);
    TEST( mask[0] == 539164679 && mask[1] == 319846256 ); 

    printf( "Finished running tests on rotate()\n" );

}

int
main()
{
    testcreateMask();

    return 0;
}

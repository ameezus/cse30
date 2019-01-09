/*
 * Filename: printDueDate.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Example C routine to print out the due date info
 *              (month day, year) using a pointer to a structiure.
 *              Called from main()
 * Date: April 5, 2015
 * Sources of Help:  None
 */

#include <stdio.h>
#include "pa0_strings.h"
#include "pa0.h"

/*
 * Function name: printDueDate()
 * Function prototype:
 *    void printDueDate( const struct DueDate *dueDate );
 * Description: Prints to stdout the month, day, and year members of a
 *              struct DueDate node.
 * Parameters:
 *      arg1: struct DueDate *dueDate -- pointer to the
 *            DueDate struct which should be printed.
 * Side Effects: Outputs the due date of the assignment
 * Error Conditions: Checks to make sure arg1 is not NULL.
 *                   No checks to ensure struct data are correct type/values.
 * Return Value: None.
 */

void printDueDate( const struct DueDate *dueDate ) {
	if (dueDate != NULL)
		(void) printf( STR_DUEDATE, dueDate->month, dueDate->day, dueDate->year );
}

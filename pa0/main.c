/*
 * Filename: main.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Example C program for pa0. It calls a couple of functions
 *              written in assembly and C as example of functions calls and
 *              parameter passing in C and SPARC assembly (also known as
 *              the language's and architecture's calling conventions).
 * Date: April 5, 2014
 * Sources of help: none
 */

/*
 * Header files included here.
 * Std C Lib header files first, then local headers.
 */

/* Standard C Library headers used angle brackets < > */
#include <stdlib.h>
#include <stdio.h>

/* Local headers use double quote " " */
#include "pa0.h"
#include "pa0_strings.h"

/*
 * Function name: main()
 * Function prototype: int main( int argc, char *argv[] );
 *                              or
 *                     int main( void ); if no command line processing.
 * Description: C main driver which calls C and SPARC assembly routines to
 *              print a greeting, assignment due date, and the square of the
 *              numnber entered at the command line.
 * Parameters: int containing the number to square
 * Side Effects: Outputs greeting, assignment due date, and square of a number
 * Error Conditions: None.
 * Return Value: 0 indicating successful execution.
 */

int
main( int argc, char *argv[] ) {
  struct DueDate dueDate;    /* Structure to hold assignment due date */
  int argVal = 0;            /* Value to square from command line */

  /*
   * We decremnt argc because of the name of the program is the first
   * argument which we do not want to count.
   */
  --argc;

  if( argc != EXPECTED_ARGS ) {

    /* Error messages are printed to stderr */
    (void) fprintf(
        stderr,
        argc < EXPECTED_ARGS ? STR_ERR_MISSING_ARG : STR_ERR_EXTRA_ARG,
        argv[0] );

    (void) fprintf( stderr, STR_ERR_USAGE, argv[0] );

    return EXIT_FAILURE;
  }

  /*
   * strtol() offers error checking/handling. See man strtol
   */
  argVal = atol( argv[1] );

  /*
   * Update the assignment due date. Make sure only the first letter in
   * the month name is capitalized. E.g. December, January, etc.
   */
  dueDate.day   = 7;
  dueDate.year  = 2015;
  dueDate.month = "April";

  /*
   * Print the greeting message
   */
   printWelcome( STR_WELCOME_QUARTER );

  /*
   * Print assignment due date
   * printDueDate() takes the address of the DueDate struct
   * (a pointer to the DueDate struct)
   */
   printDueDate( &dueDate );

  /*
   * Now sqaure the input and print the result
   */
  (void) printf( STR_SQUARENUM, argVal, squareNum( argVal ) );

  return EXIT_SUCCESS;
}

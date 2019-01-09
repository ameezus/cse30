/*
 * Filename: pa0.h
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Function prototypes and defines for PA0
 * Date: April 5, 2015
 * Sourcers of help: none
 */

#ifndef PA0_H
#define PA0_H

#define EXPECTED_ARGS 1

/* User-defined types usef in PA0 */

struct DueDate {
  const char *month;
  unsigned int day;
  unsigned int year;
};

/* Function prototypes for the C and assembly routines used in PA0 */

void printDueDate( const struct DueDate *dueDate );
void printWelcome( const char *string );

int squareNum( int num );

#endif /* PA0_H */

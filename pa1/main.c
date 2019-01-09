/*
 * Filename: main.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Descriptions: This files handles the input, output and errors of the
 *                program.
 * Date: April 12, 2015
 * Sources of Help: CSE Lab Tutors
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pa1.h"
#include "pa1_strings.h"

int main (int argc, char *argv[]) {
  
  long Xsize = atoi(argv[1]);
  long Xchar = atoi(argv[2]);
  long fillerChar = atoi(argv[3]);
  long borderChar = atoi(argv[4]);
  
  long error = 0;

  char *p;

  errno = 0;

  //checking for correct number of inputs
  if (argc !=5){
    (void) fprintf (stderr, STR_USAGE, argv[0], X_SIZE_MIN, X_SIZE_MAX,
                    ASCII_MIN, ASCII_MAX, ASCII_MIN, ASCII_MAX, 
                    ASCII_MIN, ASCII_MAX);

    return EXIT_FAILURE;
  }

  errno = 0;
  //convert size variable and check if size is valid
  Xsize = strtol (argv[1], &p, BASE);

  if (*p != NULL) {

    (void) fprintf(stderr, STR_NOTINT, argv[1]);
    error = 1;
   
  } else if (!checkRange (X_SIZE_MIN - 1, X_SIZE_MAX + 1, Xsize)) {
      
      (void) fprintf(stderr, STR_ERR_XSIZE_RANGE, Xsize, X_SIZE_MIN, X_SIZE_MAX);
      error = 1;
   
   } else if (!isEven (Xsize)) {
      
      (void) fprintf (stderr, STR_ERR_XSIZE_EVEN, Xsize);
      error = 1;
   }

  errno = 0;
  //convert Xchar and check if Xchar is valid
  Xchar =strtol (argv[2], &p, BASE);

  if (*p != NULL) {
    
    (void) fprintf(stderr, STR_NOTINT, argv[2]);
    error = 1;
    
  } else if (!checkRange (ASCII_MIN - 1, ASCII_MAX + 1, Xchar)) {
      
      (void) fprintf (stderr, STR_ERR_XCHAR_RANGE, Xchar, 
                      ASCII_MIN, ASCII_MAX);
      error = 1;
  }

  errno = 0;
  //convert filler char and check if filler char is valid
  fillerChar = strtol (argv[3], &p, BASE);

  if (*p != NULL) {
    
    (void) fprintf(stderr, STR_NOTINT, argv[3]);
    error = 1;
    
   } else if (!checkRange(ASCII_MIN - 1, ASCII_MAX + 1, fillerChar)) {
      
      (void) fprintf(stderr, STR_ERR_FILLERCHAR_RANGE, fillerChar,
                     ASCII_MIN, ASCII_MAX);
       error = 1;
   } else if (Xchar == fillerChar) {
    
      (void) fprintf (stderr, STR_ERR_XCHAR_FILLERCHAR_DIFF, Xchar,
                      fillerChar);
      error = 1;
   }

  errno = 0;
  //conver border char and check if border char is valid
  borderChar = strtol (argv[4], &p, BASE);

  if (*p != NULL){
    (void) fprintf(stderr, STR_NOTINT, argv[4]);
    error = 1;
  } else if (!checkRange(ASCII_MIN - 1, ASCII_MAX + 1, borderChar)) {
      
      (void) fprintf(stderr, STR_ERR_BORDERCHAR_RANGE, borderChar,
                     ASCII_MIN, ASCII_MAX);
      error = 1;
  } else if (Xchar == borderChar) {
      
      (void) fprintf(stderr, STR_ERR_XCHAR_BORDERCHAR_DIFF, Xchar,
                     borderChar);
      error = 1;

  } 

  //if no errors were found run the program
  if (!error) { 
    
    displayX(Xsize, Xchar, fillerChar, borderChar);
  
  } else { //else exit failure
  
       (void) putchar('\n');
       return EXIT_FAILURE;
    }
  
  return EXIT_SUCCESS; //Exit as a success
}

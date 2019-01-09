/*
 * Filename: parseInout.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This module is responsible for parsing the specified
 * 		input file.
 * Date: May 1, 2015
 * Sources of Help:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa2.h"
#include "pa2_strings.h"

/*
 * Function name: parseInput()
 * Function prototype: int parseKey (char *str, FILE **inFile);
 * Description: Parses the specified input file
 * Parameters:
 *    arg 1: char *str - string to compare to "-"
 *    arg 2: FILE, **inFile - file to read in from
 *
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */

int parseInput (char *str, FILE **inFile){
	//check if "-" matches the string to read in from file
  if (strcmp (str, "-")){

    *inFile = stdin;
    return EXIT_SUCCESS;

  } else {
    //if string doesnt match "-" then read in from the file
    *inFile = fopen (str, "r");

    //if file is null return FILE_ERR
    if (*inFile == NULL){
      return FILE_ERR;
    }

    return EXIT_SUCCESS;
  }
}

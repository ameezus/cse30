/*
 * Filename: makeFileColBuffer.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Fills char buffer with the source string. 
 * Date: May 31, 2015
 * Sources of Help:  None
 */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "pa4.h"
#include "pa4_strings.h"

/*
 * Function name: makeFileColBuffer()
 * Function prototype:
 *               void makeFileColBuffer (char *s1, const char *s2, 
 *                                       const int n);
 * Description: Fills char buffer with the source string.
 * Parameters:
 *               arg 1: char *s1 - char buffer
 *               arg 2: const char *s2 - source string
 *               arg 3: const int n - max length of char buffer
 *
 * Side Effects: None
 * Error Conditions:
 * Return Value: None.
 */

void makeFileColBuffer(char* s1, const char* s2, int n){
  int count = 0;
  
  //copying chars
  while (s2[count] != NULL){
    s1[count] = s2[count];
    count++;
  }
  //copying spaces
  while (count < n){
    s1[count] = ' ';
    count++;
  }
  //last char is null
  s1[count] = NULL;
}

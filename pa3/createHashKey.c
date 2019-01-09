/*
 * Filename: createAnagramHeader.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function copies each character from src to key and makes 
 *              each lower case using tolower(), then it sort the 
 *              characters using qsort() and the passed in comparison 
 *              function compare
 * Date: May 18, 2015
 * Sources of Help:  None
 */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

/*
 * Function name: createAnagramHeader()
 * Function prototype:
 *      struct anagramHeader * createAnagramHeader (const char *key);
 * Description: This function copies each character from src to key and makes 
 *              each lower case using tolower(), then it sort the 
 *              characters using qsort() and the passed in comparison 
 *              function compare
 * Parameters:
 *      arg1; char *key: char* to copy src to
 *      arg2; char *src: char* to copy into key
 *      arg3; int (*compare) (const void *, const void *))
 * Error Conditions: None
 * Return Value: NONE
 */

void createHashKey (char *key, const char *src,
                    int (*compare)(const void *, const void *)){
  //gets src's length
  int strlength = strlen (src);
  int count = 0;
  
  //copies src into key along with making everything lower case
  while (count < strlength){
    key[count] = tolower(src[count]);
    count++;
  }
  
  //sets last array element to NULL
  key[count] = NULL;

  //sorts characters
  qsort (key, count, sizeof(char), compare);
 
}

/*
 * Filename: parseKey.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This module is responsible for parsing either of the key
 *              values. If the string is parsed successfully then key will
 *              be set and it will return zero.
 * Date: April 27, 2015
 * Sources of Help:
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "pa2.h"
#include "pa2_strings.h"

/*
 * Function name: parseKey()
 * Function prototype: int parseKey (char *str, unsigned long *key)
 * Description: Responsible for parsing the key values
 * Parameters:
 *    arg 1: char *str - string converted to long
 *    arg 2: unsigned long key - key to be parsed
 *
 * Side Effects: None
 * Error Conditions: If errno != 0 then return ERANGE_ERR or if endptr is not
 *                   null return ENDPTR_ERR
 * Return Value: Zero if successfull
 */
int parseKey (char *str, unsigned long *key){
  
  char *endptr;
  
  //converting string to unsigned long
  unsigned long newKey = strtoul (str, &endptr, DEF_BASE);

  if (errno) {//checking errno
    return ERANGE_ERR;
  } 

  if (*endptr != NULL){//checking endptr
    return ENDPTR_ERR;
  }

  *key = (unsigned long) newKey;
  
  return EXIT_SUCCESS;
}

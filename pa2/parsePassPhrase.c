/*
 * Filename: parsePassPhrase.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This module is responsible for parsing the passphrase
 * Date: May 1, 2015
 * Sources of Help:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa2.h"
#include "pa2_strings.h"

/*
 * Function name: parsPassPhrase()
 * Function prototype: int parsePassPhrase (char *str, char *passphrase)
 * Description: Parses passphrase
 * Parameters:
 *    arg 1: char *str - string that is converted to long
 *    arg 2: char *passphrase - passphrase that is copied
 *
 * Side Effects: Parses passphrase
 * Error Conditions: None
 * Return Value: If successful, return zero. If string is too short return
 *               LENGTH_ERR
 */
 
int parsePassPhrase (char *str, char *passphrase){
  
  //check if string contains at least PASS_PHRASE_SIZE chars
  if (strlen(str) >= PASS_PHRASE_SIZE){
    //copy the first PASS_PHRASE_SIZE characters
    passphrase = strncpy (passphrase, str, PASS_PHRASE_SIZE);
 
  } else {
    //if string is too short
    return LENGTH_ERR;
  }

  return EXIT_SUCCESS;
}

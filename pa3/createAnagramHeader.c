/*
 * Filename: createAnagramHeader.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function allocates memory for one struct anagramHeader
 *              using malloc and initializes its values. Then it sets key by
 *              using strncpy and then sets the anagrams pointer to NULL and
 *              numElements to 0.
 * Date: May 18, 2015
 * Sources of Help:  None
 */
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "pa3.h"

/*
 * Function name: createAnagramHeader()
 * Function prototype:
 *      struct anagramHeader * createAnagramHeader (const char *key);
 * Description: Allocates memory for one struct anagramHeader
 *              using malloc and initializes its values. Then it sets key by
 *              using strncpy then sets anagrams to NULL and numElements to 0
 * Parameters:
 *      arg1; const char * key: the value to set in the key section of the
 *            anagramHeader
 * Error Conditions: Checks if malloc fails and if it does it returns NULL
 * Return Value: Returns NULL if malloc fails and if not returns a pointer
 *               to the struct
 */

struct anagramHeader* createAnagramHeader(const char *key){
  struct anagramHeader * head;
  
  //allocating memory for one struct anagramHeader
  head = (struct anagramHeader *)malloc (sizeof(struct anagramHeader));
  
  //NULL check
  if (head == NULL){
    return NULL;
  }
  
  //copying paramter key into anagramHeader key
  char * err = strncpy(head -> key, key, MAX_WORD_LENGTH);
  
  //set numElements to 0 and anagrams to NULL
  head -> numElements = 0;
  head -> anagrams = NULL;
  
  //NULL CHECK
  if (err == NULL){
    return NULL;
  }
  
  return head;
}

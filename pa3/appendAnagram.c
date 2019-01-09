/*
 * Filename: appendAnagram.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function allocates additional memory at the end of the
 *              struct and copies the struct anagram into the new memory
 * Date: May 18, 2015
 * Sources of Help:  Tutor
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa3.h"

/*
 * Function name: appendAnagram()
 * Function prototype:
 *      appendAnagram (struct anagramHeader *head, struct anagram *anagram)
 * Description: Allocates new memory and copies struct anagram into that
 *              new memory using realloc and memcpy
 * Parameters:
 *      arg1: struct anagramHeader *head: struct where the new memory
 *            points to
 *      arg2: struct anagram anagram: the struct copied into the new mem
 * Side Effects: No output, errno is used for error handeling
 * Error Conditions: If realloc fails then it returns -1
 * Return Value: If all is successful then it returns thenumber of elements
 *               in the array
 */

int appendAnagram (struct anagramHeader *head, struct anagram *anagram){
  //allocating additional memory at the end of struct anagram
  struct  anagram * ptrLoc = realloc (head->anagrams, 
                    sizeof(struct anagram) * (head -> numElements + 1));
  
  //null check
  if (ptrLoc == NULL){
    return -1;
  }
  
  //give pointer location to head -> anagrams
  head -> anagrams = ptrLoc;
  
  //using memcpy to copy the struct anagram that is passed into the
  //newly allocated memory at the end of the array
  void * memResult;
  memResult = memcpy(&(head->anagrams[head->numElements++]), anagram, 
         sizeof(struct anagram));
  
  //null check
  if (memResult == NULL){
    return -1;
  }

  return (head -> numElements);
}

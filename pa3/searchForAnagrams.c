/*
 * Filename: searchForAnagrams.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function reads in a word from stdin and sees if it has a
 *               match then it should be printed. if not then it should print
 *               no anagrams were found.
 * Date: May 18, 2015
 * Sources of Help:  None
 */

#include <stdlib.h>
#include <stdio.h>
#include <search.h>
#include <string.h>
#include "pa3_strings.h"
#include "pa3.h"

/*
 * Function name: searchForAnagrams()
 * Function prototype:
 *      void searchForAnagrams ()
 * Description: This function reads in a word from stdin and sees if it has a
 *               match then it should be printed. if not then it should print
 *               no anagrams were found.
 * Parameters:
 *      none
 * Error Conditions: None
 * Return Value: NONE
 */

void searchForAnagrams(){
  char word [MAX_WORD_LENGTH + 1];
  char key [MAX_WORD_LENGTH + 1];

  ENTRY entry, *found;
  //print out that youre searching for anagrams
  int err = fprintf (stdout, STR_SEARCH);

  //while there are words to get
  while (fgets(word, MAX_WORD_LENGTH + 1, stdin)){
    //strip a new line
    stripNewLine (word);
    createHashKey(key, word, charCompare);
    entry.key = key;
    //if you find a match
    if ((found = hsearch (entry, FIND)) != NULL){
      //print there is a match
      /* LINTED */
      printAnagrams ((struct anagramHeader *) found -> data, word);
    } else {
      //else print there is no match
      err = fprintf (stdout, STR_NO_ANAGRAMS_FOUND);
    }
 
    err = fprintf (stdout, STR_NEW_LINE);
    err = fprintf (stdout, STR_SEARCH);
  }

  err = fprintf (stdout, STR_NEW_LINE);

  if (err < 0){
   return;
  }
}

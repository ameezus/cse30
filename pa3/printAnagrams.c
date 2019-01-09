/*
 * Filename: printAnagrams.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function must print out each word in the struct anagram
 *              array pointed to within head. It must not print any words that
 *              match the word passed in
 * Date: May 18, 2015
 * Sources of Help:  Tutors
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa3_strings.h"
#include "pa3.h"

/*
 * Function name: printAnagrams()
 * Function prototype:
 *      void printAnagrams (struct anagramHeader *head, char *word)
 * Description: This function must print out each word in the struct anagram
 *              array pointed to within head. It must not print any words that
 *              match the word passed in
 * Parameters:
 *      arg1; struct anagramHeader *head: array which elmnts are printed from
 *      arg2; char *word: word to check if elements match it
 * Error Conditions: None
 * Return Value: NONE
 */

void printAnagrams (struct anagramHeader *head, char *word){
  int count = 0, err, firstElem = 0;
  
  struct anagram ang = head -> anagrams[count];
  //comparing the two words
  if ((strcmp (ang.word, word) != 0) || head -> numElements != 1){
    //printing that anagrams were found
    err = fprintf (stdout, STR_ANAGRAMS_FOUND);
    
    while (count < head -> numElements){
      ang = head -> anagrams[count];
      //comparing words again
      if (strcmp (ang.word, word)){
        if (firstElem != 1){
          //printing first word found
          err = fprintf (stdout, STR_FIRST_ANAGRAM_WORD, ang.word);
          firstElem = 1;
        } else {
        //printing the other words
        err = fprintf (stdout, STR_ANAGRAM_WORD, ang.word);
        }
        }

        count++;
        }
  //if no anagrams are found print that message
  } else if ((strcmp (ang.word, word) == 0) && head -> numElements == 1) {
    err = fprintf (stdout, STR_NO_ANAGRAMS_FOUND);
    firstElem = 1;

    if (err < 0){
      return;
    }
  }
}

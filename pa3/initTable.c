/*
 * Filename: initTable.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function initializes the table by reading lines in from 
 *              the file and inserting the words into the hashtable created
 *             
 * Date: May 18, 2015
 * Sources of Help:  None
 */
#include <stdlib.h>
#include <stdio.h>
#include <search.h>
#include <string.h>
#include "pa3.h"

/*
 * Function name: intiTable()
 * Function prototype:
 *      initTable (FILE *file)
 * Description:
 *      This function reads one line of the file at a time using fgets() and
 *      inserts the word into the hash table using hsearch. If an ENTRY with
 *      the same key is already inserted in the table the word must append to
 *      to the anagrams array associated with tthat entry using appendAnagram
 *      If tthere is not already an entry then struct anagramHeader must be
 *      allocated and a corresponding ENTRY inserted into thetable before.
 * Parameters:
 *      arg1; FILE *file: file to read in from
 * Error Conditions: If createAnagramHeader, appendAnagram, or hsearch fail
 *                   return -1
 * Return Value: If all ^ succeed then return the number of words inserted
 */

int initTable (FILE* file){
  char word [MAX_WORD_LENGTH + 1];
  char key [MAX_WORD_LENGTH + 1];
  
  int count = 0, appendRes;

  ENTRY entry, *found;
  //while there are still words to get
  while (fgets(word, MAX_WORD_LENGTH + 1, file) != NULL){
    
    //strip one line
    stripNewLine(word);
    createHashKey(key, word, charCompare);
    
    entry.key = key;
    
    struct anagram ang;
    //copy the word stripped into word
    char * err = strcpy (ang.word, word);
    //NULL check
    if (err == NULL){
      return -1;
    }
    //insert into table
    if ((found = hsearch (entry, FIND)) != NULL){
      /* LINTED */
      struct anagramHeader *head = (struct anagramHeader*) found -> data;
      appendRes = appendAnagram (head, &ang);
      //checking if appendAnagram failed or not
      if (appendRes == -1){
        return -1;
      }

    } else {
      
      struct anagramHeader * head;
      head = createAnagramHeader (key);
      if (head == NULL){
        return -1;
      }
      //call to appendAnagram
      appendRes = appendAnagram (head, &ang);
      if (appendRes == -1){
        return -1;
      }
      //assiggn ley and head to entry
      entry.key = head -> key;
      entry.data = (void *) head;
      
      //insert into table
      found = hsearch (entry, ENTER);
      //NULL check
      if (found == NULL){
        return -1;
      }
    }
    
    count++;
  }

  return count;
}

/*
 * Filename: makeResults.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Generates a resultList based on the lcsList. Dynamically
 *              grows the resultList by calling appendResult.
 * Date: May 31, 2015
 * Sources of Help:  None
 */

#include <stdlib.h>
#include <stdio.h>
#include "pa4.h"
#include "pa4_strings.h"
#include <errno.h>

/*
 * Function name: makeResults()
 * Function prototype:
 *               int makeResults (const struct file *f1, const file* f2,
                     const struct lcsList* list, struct resultList* results);
 * Description:  Generates a resultList based on the lcsList. Dynamically
 *               grows the resultList by calling appendResult.
 * Parameters:
 *               arg 1: const struct file *f1 - first file
 *               arg 2: const struct file *f2 - second file
 *               arg 3: const struct lcsList *list - lcsList
 *               arg 4: struct resultList* results - struct to append to
 *
 * Side Effects: None
 * Error Conditions:
 * Return Value: 0 if successful or errno if fails
 */

int makeResults (const struct file* f1, const struct file* f2, 
                 const struct lcsList* list, struct resultList* results){
  //initializing all positoins, counter, and return value.
  int pos1 = 0, pos2 = 0, LCSPos = 0, count = 0;
  int one = 1, zero = 0, returnVal = 0;
  results -> startPtr = 0;
  errno = 0;

  //infinite loop
  while (one > zero){
    //initializing distances
    int dist1 = list->startPtr[LCSPos].f1Line - pos1;
    int dist2 = list->startPtr[LCSPos].f2Line - pos2;
    //if first and second file distances are both 0
    if(dist1 == 0 && dist2 == 0){
      //if LCSPos is full then break
      if(LCSPos == list->numElems -1){
        break;
      }
      //append result
      returnVal = appendResult (&(results -> startPtr), f1, f2, pos1, pos2, TYPE_SAME, count); 
      pos1++;
      pos2++;
      LCSPos++;
    //if file 1 distance is 0 and file 2 dist is greater than 0
    }else if (dist1 == 0 && dist2 > 0){
      //append resulr
      returnVal = appendResult (&(results -> startPtr), NULL, f2, pos1, pos2, TYPE_ADD, count); 
      pos2++;
    //if file 1 distance is greater than 0 and file 2 distance is 0
    }else if (dist1 > 0 && dist2 == 0){
      //append result
      returnVal = appendResult (&results -> startPtr, f1, NULL, pos1, pos2, TYPE_DELETE, count); 
      pos1++;
    //if both file distances are greater than 0
    }else if (dist1 > 0 && dist2 > 0){
      //append result
      returnVal = appendResult (&results->startPtr, f1, f2, pos1, pos2, TYPE_CHANGE, count); 
      pos1++;
      pos2++;
    }
    
    count++;
  }
  //set count into numResults
  results->numResults = count;
  
  if (returnVal != 0){
    return errno;
  }else{ 
    return 0;
  }
}

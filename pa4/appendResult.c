/*
 * Filename: appendResult.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Appends new struct to a dynamic array of struct results
 * Date: May 31, 2015
 * Sources of Help:  None
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa4.h"
#include "pa4_strings.h"
#include <errno.h>

/*
 * Function name: appendResult()
 * Function prototype:
 *               int appendResult (struct result** results, const struct 
                        file* f1, const struct file* f2, int file1Pos, 
                        int file2Pos, unsigned int type, int count);
 * Description:  Appends new struct to dynamic array of struct results
 * Parameters:
 *               arg 1: struct result** results - address of the startPtr in
 *                             existing resultList
 *               arg 2: const struct file* f1 - first file
 *               arg 3: const struct file* f2 - second file
 *               arg 4: int file1Pos - file 1 position
 *               arg 5: int file2Pos - file 2 position
 *               arg 6: unsigned int type - type of file 
 *               arg 7: int count - counter variable
 *
 * Side Effects: None
 * Error Conditions:
 * Return Value: 0 if successful or errno if fails
 */

int appendResult(struct result **results, const struct file *f1, 
    const struct file *f2, int pos1, int pos2, 
    unsigned int type, int count){

  struct result res1;

  errno = 0;
  //checks if first file is null
  if (f1 == NULL){
    
    res1.str1 = EMPTY;

  }else {
    //if not null set startPtr
    res1.str1 = f1 -> startPtr[pos1];
  }
  //checks if second file is null
  if (f2 == NULL){
    res1.str2 = EMPTY;

  }else{
    //if not null set start ptr
    res1.str2 = f2 -> startPtr[pos2]; 
  }
  //assigning positions and type into res1
  res1.f1Line = pos1;
  res1.f2Line = pos2;
  res1.type = type;
  //reallocation  of more moemory for res2
  struct result * res2 = realloc( *results, sizeof(struct result) * (count + 1));
  //checking if res 2 is null
  if (res2 == NULL){
    return errno;
  }

  *results = res2;
  //moving memory into res2
  (void) memmove((&res2[count]), &res1, sizeof(struct result));

  return 0; 
}
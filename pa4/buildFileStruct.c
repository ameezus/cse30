/*
 * Filename: buildFileStruct.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Builds the fp struct using stripnewLine, realloc,memmove,
 *              and memset
 * Date: May 31, 2015
 * Sources of Help:  None
 */

#include <stdlib.h>
#include <stdio.h>
#include "pa4.h"
#include <string.h>
#include "pa4_strings.h"
#include <errno.h>

/*
 * Function name: defaultCompare()
 * Function prototype:
 *               int defaultCompare (const void *p1, const void *p2);
 * Description:  Builds the fp struct using stripnewLine, realloc,memmove,
 *              and memset
 * Parameters:
 *               arg 1: const char* name - name of fp to open
 *               arg 2: struct fp* fp - fp struct
 *
 * Side Effects: None
 * Error Conditions:
 * Return Value: O upon success or errno upon failure.
 */

int buildFileStruct (const char* name, struct file * file){
  errno = 0;
  FILE * fp = fopen (name, FILE_OPEN_MODE); //opening fp
  
  if(fp == NULL){ //checking if fp exists
    return errno;
  }
  
  char buffer[BUFSIZ];
  int lineCount = 0;

  if(fp == NULL){ //checking if fp exists
    return errno;
  }

  while (fgets(buffer, BUFSIZ, fp)){ //reading in from fp
    
    stripNewLine(buffer); //stripping lines from buffer
    
    //reallocation of memory for the fp
    file -> startPtr = realloc (file -> startPtr, sizeof(char*) * (lineCount +1));
    //allocating memory off buffer length + 1
    file -> startPtr[lineCount] = malloc (strlen(buffer) +1);
    //moving memory over
    (void) memmove (file -> startPtr[lineCount], buffer, strlen(buffer) +1);
    
    (void) memset(buffer, NULL, BUFSIZ);
    
    lineCount++;
  }

  file -> numLines = lineCount;
  (void) fclose (fp);//closing fp

  return 0; 
}

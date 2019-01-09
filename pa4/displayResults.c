/*
 * Filename: displayResults.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Display results of differences from the resultList
 * Date: May 31, 2015
 * Sources of Help:  None
 */

#include <stdlib.h>
#include <stdio.h>
#include "pa4.h"
#include "pa4_strings.h"

/*
 * Function name: displayResults()
 * Function prototype:
 *               void displayResults (const struct resultList* results, 
                     struct displayOpts display);
 * Description: Fills char buffer with the source string.
 * Parameters:
 *               arg 1: const struct resultList * results
 *               arg 2: struct displayOpts display
 *
 * Side Effects: None
 * Error Conditions:
 * Return Value: None.
 */

void displayResults (const struct resultList* results, 
                     struct displayOpts display){
  
  int count = 0;
  //declaring lines
  char line1 [BUFSIZ], line2 [BUFSIZ], type [7];

  while (count < (results -> numResults)){
    //expanding tabs
    expandTabs(line1, results -> startPtr[count].str1, 
              (display.width - SYMBOL_WIDTH) / 2);
    
    expandTabs(line2, results -> startPtr[count].str2,
              (display.width - SYMBOL_WIDTH) / 2);
    //making file column buffers
    makeFileColBuffer(line1, line1, (display.width - SYMBOL_WIDTH) / 2);
    
    makeSymbolColBuffer(type, results ->startPtr[count].type, SYMBOL_WIDTH+1);

    count++;
    
    //flag checking
    if ((display.displayMode & D_FLAG) != 0) {
      
      if ((results->startPtr[count - 1 ].type == TYPE_DELETE)){
        continue;
      }
    //flag checking
    }else if ((display.displayMode & S_LOWER_FLAG) != 0) {
      
      if ((results->startPtr[count - 1].type == TYPE_SAME)){
        continue;
      }
    }
    //flag checking
    if ((display.displayMode & L_FLAG) != 0) { 
      if (results -> startPtr[count-1].type == TYPE_SAME){
        (void) fprintf (stdout, "%s\n", line1);
        continue;
      }
    }
    
    (void) fprintf(stdout, "%s%s%s\n",line1, type, line2);
  }
}

/*
 * Filename: makeSymbolColBuffer.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Fills a char buffer with the string that corresponds to
 *              type passed in. 
 * Date: May 31, 2015
 * Sources of Help:  None
 */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "pa4.h"
#include "pa4_strings.h"

/*
 * Function name: makeSymbolColBuffer()
 * Function prototype:
 *               void makeSymbolColBuffer (char *s1, unsigned int type,
                                           int n);
 * Description:  Fills a char buffer with the string that corresponds to 
 *               the type passed in
 * Parameters:
 *               arg 1: char *s1 - char buffer
 *               arg 2: unsigned int type - type passed in
 *               arg 3: int n - max length of buffer
 *
 * Side Effects: None
 * Error Conditions:
 * Return Value: None
 *
 * Registers used:
 *               %i0 - arg 1
 *               %i1 - arg 2
 */

void makeSymbolColBuffer (char *s1, unsigned int type, int n){
  
  if (type == TYPE_ADD){ //checking for add type
    
    (void) snprintf(s1, n, STR_ADD);
  
  }else if (type ==TYPE_DELETE){ //checking for delete type
    
    (void) snprintf(s1, n, STR_DELETE);
  
  }else if (type == TYPE_CHANGE){ //checking for change type
    
    (void) snprintf(s1, n, STR_CHANGE);
  
  }else if (type == TYPE_SAME){ //checking for same type
    
    (void) snprintf(s1, n, STR_SAME);
  }

  
  
}

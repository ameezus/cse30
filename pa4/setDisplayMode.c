/*
 * Filename: setDisplayMode.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Sets values of the struct displayOpts according to the command
 *              line args passed in by the user.
 * Date: May 31, 2015
 * Sources of Help:  None
 */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "pa4.h"
#include "pa4_strings.h"

/*
 * Function name: setDisplayMode()
 * Function prototype: int setDisplayMode( int argc, char* argv[],
                              struct displayOpts* display);
 *               
 * Description:  Sets values of the struct displayOpts according to the command
 *              line args passed in by the user.
 * Parameters:
 *               arg 1: int argc - number of args
 *               arg 2: char * argv[]
 *               arg 3: struct displayOpts* display - dislpay opts struct
 *               
 * Side Effects: None
 * Error Conditions:
 * Return Value: 0 if successful or errno if fails
 */

int setDisplayMode( int argc, char* argv[], struct displayOpts* display ){
  
  int a, three = 3, width = 0;
  char * endPtr;
  // setting width and displayMode
  display -> width = DEFAULT_WIDTH;
  display -> displayMode = 0x0;
  
  //infinite loop
  while (1 < three){
    
    int optIndex = 0;
    //declaring struct
    static struct option options[] = {
      
      {STR_D_LONG, no_argument, 0, 'd'},
      {STR_I_LONG, no_argument, 0, 'i'},
      {STR_L_LONG, no_argument, 0, 'l'},
      {STR_S_LOWER_LONG, no_argument, 0, 's'},
      {STR_W_LOWER_LONG, required_argument, 0, 'w'},
      {STR_H_LONG, no_argument, 0, 'h'},
      {0, 0, 0, 0}
    };
    //getting operator
    a = getopt_long(argc, argv, "dilsw:", options, &optIndex);
    if (a == -1)
      break;
    //switch cases for args
    switch (a){
      case 'd':
        display -> displayMode = display -> displayMode | D_FLAG;
        break;
      case 'i':
        display -> displayMode = display -> displayMode | I_FLAG;
        break;
      case 'l':
        display -> displayMode = display -> displayMode | L_FLAG;
        break;
      case 's':
        display -> displayMode = display -> displayMode | S_LOWER_FLAG;
        break;
      case 'w':
        //getting width
        width = strtol (optarg, &endPtr, 10);
        if (width >= MIN_WIDTH && width <= MAX_WIDTH){
          display -> width = width;
        }else{
          display -> displayMode = ERR_FLAG;
          return VALUE_ERR;
        }
        break;
      case 'h':
        display -> displayMode = display -> displayMode | H_FLAG;
        return 0;
      default:
        display -> displayMode = ERR_FLAG;
        return INVALID_OPT_ERR;
    }
  }
  //checking if greater than 2
  if (argc - optind > 2){
    
    display -> displayMode = ERR_FLAG; 
    return EXTRA_OP_ERR;
  //less than 2
  }else if (argc - optind < 2){
    
    display -> displayMode = ERR_FLAG; 
    return MISSING_OP_ERR;
  }
  //flag checks
  if ((display -> displayMode & S_LOWER_FLAG) != 0 &&  
      (display -> displayMode & D_FLAG) != 0 ){
    
    display -> displayMode =  ERR_FLAG;
    return EXCLUSION_ERR;
  }
  
  return 0;
}

/*
 * Filename: main.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: Driver of the program
 * Date: May 31, 2015
 * Sources of Help:  None
 */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa4.h"
#include "pa4_strings.h"
#include "lcs.h"

/*
 * Function name: main()
 * Function prototype:
 *               int main (int argc, char *argv[]);
 * Description:  Driver
 * Parameters:
 *               arg 1: int argc
 *               arg 2: char * argv[] 
 *
 * Side Effects: None
 * Error Conditions:
 * Return Value: 0 if successful or errno if fails
 */

int main( int argc, char* argv[] ){
  
  struct displayOpts disOpt;
  
  int disMode = setDisplayMode(argc, argv, &disOpt);

  struct file file1;
  file1.startPtr = NULL;
  struct file file2;
  file2.startPtr = NULL;
  //switch statements for errors
  switch (disMode){
    
    case INVALID_OPT_ERR:
      //print err msgs
      (void) fprintf (stderr, STR_ERR_USE_HELP, argv[0], argv[1]);
      exit (EXIT_FAILURE);
    
    case EXTRA_OP_ERR:
      //print err msgs
      (void) fprintf (stderr, STR_ERR_EXTRA_OPERAND, argv[0], argv[1]);
      (void) fprintf (stderr, STR_ERR_USE_HELP, argv[0], argv[0]);
      exit (EXIT_FAILURE);
      
    case MISSING_OP_ERR:
      //print err msgs
      (void) fprintf (stderr, STR_ERR_MISSING_OPERAND, argv[0], argv[1]);
      (void) fprintf (stderr, STR_ERR_USE_HELP, argv[0], argv[0]);
      exit (EXIT_FAILURE);
    
    case VALUE_ERR:
      //print err msgs
      (void) fprintf (stderr, STR_ERR_INVALID_WIDTH, argv[0]);
      (void) fprintf (stderr, STR_ERR_USE_HELP, argv[0], argv[0]);
      exit (EXIT_FAILURE);
    
    case EXCLUSION_ERR:
      //print err msgs
      (void) fprintf (stderr, STR_ERR_MUTUAL_EXL, argv[0]);
      (void) fprintf (stderr, STR_ERR_USE_HELP, argv[0], argv[0]);
      exit(EXIT_FAILURE);
    
    default:
      //help flag
      if (disOpt.displayMode == H_FLAG){
        printUsage (argv[0]);
        exit (EXIT_SUCCESS);
      }
      break;
  }
  //building file struct
  int buildRes = buildFileStruct(argv[argc-2], &file1);
  
  if (buildRes != 0){
    
    char buff[BUFSIZ];
    (void) snprintf (buff, BUFSIZ, STR_ERR_BAD_FILE, argv[0], argv[argc - 2]);
    perror (buff);

  }
  //building file struct
  buildRes = buildFileStruct(argv[argc-1], &file2);
  
  if (buildRes != 0){
    
    char buff[BUFSIZ];
    (void) snprintf (buff, BUFSIZ, STR_ERR_BAD_FILE, argv[0], argv[argc - 1]);
    perror (buff);

  }
  if (buildRes != 0){
    exit(EXIT_FAILURE);
  }

  struct lcsList * list;
  //finding LCS's
  if((disOpt.displayMode & I_FLAG) != 0){
    
    (void) findLCS (&file1, &file2, &list, ignoreCaseCompare);
  
  }else{
    
    (void) findLCS (&file1, &file2, &list, defaultCompare);
  }

  struct resultList results;
  //making the results after files are compated
  (void) makeResults (&file1, &file2, list, &results);
  //displaying results
  (void) displayResults (&results, disOpt);
  //freeing everything
  free (list-> startPtr);
  free (list);
  (void) freeFileStruct (&file1);
  (void) freeFileStruct (&file2);

  return 0;
}

/*
 * Filename: main.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This function drives the program to run the anagrams program
 * Date: May 18, 2015
 * Sources of Help:  None
 */
#include <stdlib.h>
#include <stdio.h>
#include "pa3.h"
#include "pa3_strings.h"
#include <string.h>
#include <search.h>

#define ONE 1
#define N_ONE -1

/*
 * Function name: main()
 * Function prototype:
 *      int main (int argc, char * argv[])
 * Description: This function drives the program bt checking for expected
 *              # of args, reading the file passed in from the command line,
 *              creating the hashtable, filling the tbale, interacting with
 *              the user and then finally destroying the table
 * Parameters:
 *      arg1; int argc
 *      arg2; char * argv[]
 * Error Conditions: if it encounters and error call exit(EXIT_FAILURE)
 * Return Value: Returns 0 otherwise
 */

int main (int argc, char * argv[]){
  int err;
  //checking for correct number of args
  if (argc != EXPECTED_ARGS + ONE){
    printUsage(argv[0]);
    exit (EXIT_FAILURE);
  }
  //reading in from file
  FILE * file;
  file =  fopen (argv[ONE], "r");
  //checking if file is null
  if (file == NULL){
    perror (STR_ERR_FOPEN);
    err = fprintf (stderr, STR_ONE_NEW_LINE);
    exit (EXIT_FAILURE);
  }
  //creating hash table
  err = hcreate (HASH_TABLE_SIZE);
  //checking if anything was inserted
  if (err == 0){
    perror (STR_ERR_HCREATE);
    err = fprintf (stderr, STR_ONE_NEW_LINE);
    exit (EXIT_FAILURE);
  }
  //initiliaizing table
  err = initTable (file);
  //checking if table initialized correctly
  if (err == N_ONE){
    err = fprintf (stderr, STR_ERR_DB_CREATE);
    exit (EXIT_FAILURE);
  }
  //checking if table closed correctly
  err = fclose (file);
  if (err != 0){
    exit (EXIT_FAILURE);
  }
  //searching for anagrams
  searchForAnagrams();
  //destroying table
  hdestroy();
  
  return 0;
}

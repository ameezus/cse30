/*
 * Filename: main.c
 * Author: Ameer Muhtaseb
 * Userid: cs30xdw
 * Description: This module is responsible for driving the program. It 
 *              will call on all the necessary functions in order to
 *              perform the encryption/decryption.
 * Date: 5/2/15
 * Sources of Help: Lab tutors 
 */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "pa2.h"
#include "pa2_strings.h"

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5


/*
 * Function name: main()
 * Function prototype: int main( int argc, char *argv[]);
 * Description:  It will properly parse all of the command line arguments, 
 *               create the mask, perform the encryption/decryption, and 
 *               close the file. If any errors arise it will skip creating the
 *               mask and encryption/decryption, but will be responsible for 
 *               all of the error printing. 
 * Parameters: int argc, 
 *             the number of args,
 *             argv[] the arguments passed
 * Side Effects: encrypts file or text given by user
 * Error Conditions: If errors arise then from any of the parsings then
 *                   an error will arise.
 *                
 * Return Value: 0 for success and 1 for failure
 */

int main (int argc, char * argv[]) {
  (void) setvbuf (stdout, NULL, _IONBF, 0);

  //checking for correct # of args
  if(argc != EXPECTED_ARGS + ONE){
    
    (void) fprintf (stderr, STR_USAGE, argv[0], MIN_ROTATE,
                   MAX_ROTATE);
    
    return EXIT_FAILURE;
  }

  int errCount = 0;

  char passphrase[] = "ff"; 
  long retVal = parsePassPhrase(argv[ONE], passphrase);

  //if length is not 8 chars
  if(retVal == LENGTH_ERR){
    
    (void) fprintf (stderr, STR_ERR_BAD_PASSPHRASE, PASS_PHRASE_SIZE);
    
    errCount++;
  }


  //key parsing
  unsigned long key1;
  retVal = parseKey (argv[TWO], &key1);

  if (retVal == ENDPTR_ERR){
  
    (void) fprintf (stderr, STR_ERR_NOTINT, argv[TWO]);
    
    errCount++;
  
  }else if (retVal == ERANGE_ERR){
    
    // errno !=0
    char buff[BUFSIZ];
    snprintf(buff,BUFSIZ, STR_ERR_CONVERTING, argv[TWO], DEF_BASE);
    
    perror(buff);
    
    errCount++;
  }

  //key parse 2
  unsigned long  key2;
  retVal = parseKey(argv[THREE], &key2);

  if (retVal == ENDPTR_ERR){
    
    (void) fprintf(stderr, STR_ERR_NOTINT, argv[THREE]);
    
    errCount++;
  
  }else if(retVal == ERANGE_ERR){
    
    char buff[BUFSIZ];
    snprintf(buff ,BUFSIZ, STR_ERR_CONVERTING, argv[THREE], DEF_BASE);
    
    perror(buff);
    
    errCount++;
  }

  //parse rotation value
  long rotationVal;
  retVal = parseRotateValue(argv[FOUR], &rotationVal);

  if (retVal == BOUND_ERR){
    
    (void) fprintf(stderr, STR_ERR_BAD_ROT, MIN_ROTATE, MAX_ROTATE);
    
    errCount++;
  
  } else if (retVal == ENDPTR_ERR){
    
    (void) fprintf(stderr, STR_ERR_NOTINT, argv[FOUR]);
    
    errCount++;
  
  } else if(retVal == ERANGE_ERR){
    
    //errno !=0
    char buff[BUFSIZ];
    snprintf(buff,BUFSIZ, STR_ERR_CONVERTING, argv[FOUR], DEF_BASE);
    
    perror(buff);
    
    errCount++;
  }

  //open file
  FILE * inFile; 
  retVal = parseInput(argv[FIVE], &inFile);

  if (retVal == FILE_ERR){
    
    char buff[BUFSIZ];
    snprintf (buff,BUFSIZ, STR_ERR_BAD_FILE, argv[FIVE]);
    
    perror (buff);
    
    errCount++;
  }

  //error counter printer
  if (errCount > 0){
    
    (void) fprintf(stderr, STR_ERR_NUM_ERRORS, errCount);
    
    return EXIT_FAILURE;
  }

  unsigned long key[TWO];
  key[0] = key1;
  key[ONE] = key2;
  unsigned long mask[TWO];

  createMask (key, passphrase, mask);

  mycrypt (inFile, mask, (int)rotationVal);

  //closing file
  fclose(inFile);

  return EXIT_SUCCESS;
}

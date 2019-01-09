#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "pa3.h"

testcreateHashKey(){
  char key[MAX_WORD_LENGTH];
  char source[] = "edbca";

  createHashKey (key, source, charCompare);
  TEST(strcmp(key, "abcde") == 0);
  fprintf (stderr, "%s", key);
}

int main(){
  (void) fprintf(stderr, "Staring test_createHashKey");

  testcreateHashKey();

  (void) fprintf(stderr, "Done.\n");

  return 0;

}

#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

teststripNewLine(){
  char str[] = "word\n";

  stripNewLine (str);

  TEST(strcmp(str, "word")== 0);
}

int main (int argc, char *argv[]){
  (void) fprintf(stderr, "Staring test_stripNewLine");

  teststripNewLine();

  (void) fprintf(stderr, "Done.\n");

  return 0;
}

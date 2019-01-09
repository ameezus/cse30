#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "test.h"
#include "pa3.h"

void testappendAnagram(){
  struct anagram agm;
  struct anagramHeader head;

  strcpy (head.key,"key");
  head.numElements = 0;
  strcpy (agm.word, "word");

  TEST (appendAnagram(&head, &agm) == 1);

  strcpy(agm.word, "word2");
  TEST(appendAnagram(&head, &agm) == 2);
}

int main(int argc, char *argv[]){
  (void) fprintf (stderr, "Starting test appendAnagram.\n");

  testappendAnagram();

  (void) fprintf (stderr, "Done.\n");

  return 0;
}

#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include "pa3.h"
#include <strings.h>

testcreateAnagramHeader(){
  char key[] ="key";

  struct anagramHeader* head = createAnagramHeader(key);

  TEST( strcmp(head->key,key) == 0);
  fprintf(stderr, "%s", head->key);
  TEST( head->anagrams == NULL);
  TEST( head->numElements == 0);
}

int main() {
  (void) fprintf (stderr, "Starting test createAnagramHeader.c\n");

  testcreateAnagramHeader();

  (void) fprintf (stderr, "Done\n");

  return 0;
}

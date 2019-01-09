#include "pa2.h"
#include "test.h"
#include <stdlib.h>
#include <limits.h>

void testparseKey(){
  
  unsigned long * key;
  long retVal;

  printf ("Testing rotate()\n");

  retVal = parseKey ("aaa", key);
  TEST (retVal == ENDPTR_ERR);

  retVal = parseKey ("65l", key);
  TEST (retVal == ENDPTR_ERR);

  retVal = parseKey ("5g78", key);
  TEST (retVal == ENDPTR_ERR);

  retVal = parseKey ("2257", key);
  TEST (retVal == 0 && *key == 2257);

  retVal = parseKey ("-2", key);
  TEST (retVal == 0 && *key == -2);

  retVal = parseKey ("9999999999999", key);
  TEST (retVal == ERANGE_ERR);
}

int main(){
  testparseKey();
  return 0;
}

#include "pa2.h"
#include "test.h"
#include <stdlib.h>
#include <limits.h>

void testparseRotateValue(){
  
  unsigned long * key;
  long retVal;

  printf ("Testing rotate()\n");

  retVal = parseRotateValue ("aaa", key);
  TEST (retVal == ENDPTR_ERR);

  retVal = parseRotateValue ("65l", key);
  TEST (retVal == ENDPTR_ERR);

  retVal = parseRotateValue ("5g78", key);
  TEST (retVal == ENDPTR_ERR);

  retVal = parseRotateValue ("2257", key);
  TEST (retVal == BOUND_ERR);

  retVal = parseRotateValue ("-2", key);
  TEST (retVal == 0 && *key == -2);

  retVal = parseRotateValue ("9999999999999", key);
  TEST (retVal == ERANGE_ERR);
}

int main(){
  testparseRotateValue();
  return 0;
}

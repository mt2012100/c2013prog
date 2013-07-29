#include <stdio.h>
#include <string.h>
#include "bitstring.h"

void test(const char *data, int size) {

  struct bitstring bstr, bstr_cp ;
  char input[100] ;
  char output[100] ;
  int idx ;

  printf("Input string:%s\n", data) ;

  strcpy(input, data) ;
  bstr = create_bitstring(size, input) ;
  printf("Output: %s\n", print_bitstring(bstr,output)) ;

  /* Testing get bit */
  for (idx = 0 ; idx < size ; idx++) 
    printf("Bit %d is %d\n", idx, get_bit(bstr, idx)) ;

  /* Testing copy */
  bstr_cp =  copy_bitstring( bstr );
  printf("Input = %s\nOutput = %s\n", print_bitstring(bstr, output),
	 print_bitstring(bstr_cp, output));

  printf("\n\n") ;
  return ;
}

int main() {

  test("101010", 10) ;
  test("1000001000", 20) ;
  test("1000001000", 5) ;

  return 0 ;
}


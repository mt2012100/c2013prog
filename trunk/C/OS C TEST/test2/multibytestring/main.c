#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "multibytestring.h"

int main(void) {
  char* example1 = "\x74\xc3\xa9\x68\x00" ;
  char* example2 = "\x44\xc3\x80\x00" ;
  char* example3 = "\x74\xc3\xa9\x73\x00" ;
  char* example4 = "\xE6\xB0\xB4\xE8\xB0\x83\xE6\xAD\x8C\xE5\xA4\xB4" ;
  char* example_dbcs = "\x74\x00\xc3\xa9\x68\x00\x00\x00" ;
  char* example_cat = "\x74\x00\xc3\xa9\x68\x00\x44\x00\xc3\x80\x00\x00" ;
  char *test1 ;
  
  printf("Test case 1: %s\n", example1) ;
  printf("Test case 2: %s\n", example2) ;
  printf("Test case 3: %s\n", example3) ;
  printf("Test case 4: %s\n", example4) ;
  printf("\n") ;

  struct multibytestring *mbs = create_mbs(example1) ;
  struct multibytestring *mbs_test1 = initialize_mbs() ;
  struct multibytestring *mbs_test2 = create_mbs(example4) ;
  struct multibytestring *mbs_cat = create_mbs(example2) ;
  
  printf("Running test on create_mbs on test case 1.\n") ;
  assert(bytewise_equal(mbs->data, example_dbcs, CHARSIZE*mbs->size)) ;
  assert(strlen(example1)==mbs->size) ;
  
  printf("Running test on mbstoascii on test case 1.\n") ;
  test1 = mbstoascii(mbs) ;
  assert(bytewise_equal(test1, example1, 5)) ;

  printf("Running test on mbstrcpy on test cases 1 and 4.\n") ;
  mbstrcpy(mbs_test1, mbs_test2) ;
  assert(mbs_test1->size==mbs_test2->size) ;
  assert(mbstrcmp(mbs_test1, mbs_test2)) ;

  printf("Running test on mbstrcat on test cases 1 and 2.\n") ;
  mbstrcpy(mbs_test1, mbs) ;
  mbstrcat(mbs_test1, mbs_cat) ;
  assert(bytewise_equal(example_cat, mbs_test1->data, CHARSIZE*mbs_test1->size)) ;

  printf("Running test on create_mbs on test case 3.\n") ;
  assert(mbstrncmp(mbs, create_mbs(example3), 2)) ;
  assert(!(mbstrncmp(mbs, create_mbs(example3), 3))) ;

  printf("\n") ;
  return 0;
}

/* EOF */

/*
 * Implementation of Two-byte character strings (DBCS).
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "multibytestring.h"

/* Helper functions */
/* Create a new multibyte from a byte character */
char* create_multibyte(char c) {
  
  char *dest = (char*)malloc(sizeof(char)*(CHARSIZE+1)) ;
  int idx ;

  dest[0] = c ;
  for (idx = 1 ; idx <= CHARSIZE ; idx++)
    dest[idx] = '\0' ;

  return dest ;
}

/* Bytewise comparison of 2 strings */
int bytewise_equal(char *c1, char *c2, int ssize) {
  int idx ;

  for (idx = 0 ; idx < ssize ; idx++)
    if (c1[idx] != c2[idx]) return 0 ;

  return 1 ;
}

/* Print buffer in hex */
void print_mbs_hex(struct multibytestring *mbs) {
  
  int nbytes = CHARSIZE*mbs->size, idx ;
  printf("Size %d : ", mbs->size) ;
  if (mbs->data)
    for (idx = 0 ; idx < nbytes ; idx++)
      printf("%x ", mbs->data[idx]) ;
  printf("\n") ;

  return ;
}

/* Initialize multibyte string */
struct multibytestring* initialize_mbs(void) {
  struct multibytestring *dest = (struct multibytestring*)
    malloc (sizeof(struct multibytestring)) ;

  dest->size = 0 ;
  dest->data = NULL ;

  return dest ;
}

/* Create/conversion functions*/
/* Create a new multibytestring */
struct multibytestring* create_mbs(char *istr) {

  struct multibytestring *dest = NULL ;
  int idx = 0, midx ;
  int ssize = strlen(istr), mbsize = 0, nbytes ;
  char *mbyte, *final = NULL, *tmp ;

  while (idx < ssize) {
    mbyte = NULL ;

    if (isascii(istr[idx])) {
      mbyte = create_multibyte(istr[idx++]) ;

    } else if (idx < ssize-1) {
      mbyte = (char*) malloc (sizeof(char)*(CHARSIZE+1)) ; 
      for (midx = 0 ; midx < CHARSIZE ; midx++)
	mbyte[midx] = istr[idx++] ;
      mbyte[CHARSIZE] = '\0' ;
    }
    if (mbyte) {
      tmp = final ;
      nbytes = CHARSIZE*mbsize ;
      final = (char*)malloc((nbytes+CHARSIZE+1)*sizeof(char)) ;

      for (midx = 0 ; midx < nbytes ; midx++)
	final[midx] = tmp[midx] ;
      free(tmp) ;

      for (midx = 0 ; midx <= CHARSIZE ; midx++)
	final[nbytes+midx] = mbyte[midx] ;

      free(mbyte) ;
      mbsize++ ;
    }
  }

  if (mbsize) {
    dest = (struct multibytestring*) malloc(sizeof(struct multibytestring)) ;
    dest->size = mbsize+1 ;
    nbytes = CHARSIZE*mbsize ;

    dest->data = (char*)malloc(sizeof(char)*(nbytes+CHARSIZE)) ;
    for (idx = 0 ; idx < nbytes ; idx++)
      dest->data[idx] = final[idx] ;
    for (idx = 0 ; idx < CHARSIZE ; idx++)
      dest->data[idx+nbytes] = '\0' ;
    free(final) ;
      
  }
  return dest ;
}

/* Convert to ascii */
char* mbstoascii(struct multibytestring *mbs) {

  int idx, cidx, nbytes ;
  char *substr ;
  char *dest = (mbs->size==0) ? NULL : (char*) malloc(sizeof(char)*mbs->size) ;

  if (mbs->size == 0) return NULL ;
  substr = (char*) malloc(sizeof(char)*(CHARSIZE+1)) ;
  
  for (idx = 0 ; idx < mbs->size ; idx++) {
    nbytes = idx*CHARSIZE ;
    for (cidx = 0 ; cidx < CHARSIZE ; cidx++)
      substr[cidx] = mbs->data[nbytes+cidx] ;
    substr[CHARSIZE] = '\0' ;

    if (!idx) strcpy(dest, substr) ;
    else strcat(dest, substr) ;
  }

  free(substr) ;
  return dest ;
}


/* String functions */
/* Copy function */
struct multibytestring* mbstrcpy(struct multibytestring *s1, const struct multibytestring *s2) {

  int nbytes, idx ;

  if (s1->size) 
    free(s1->data) ;

  s1->size = s2->size ;
  nbytes = CHARSIZE*s1->size ;
  s1->data = (char*) malloc(sizeof(char)*nbytes) ;

  for (idx = 0 ; idx < nbytes ; idx++)
    s1->data[idx] = s2->data[idx] ;

  return s1 ;
}

/* Concatenate function */
struct multibytestring* mbstrcat(struct multibytestring *s1, 
				 const struct multibytestring *s2) {

  int n1bytes, n2bytes, idx, bidx ;
  char *temp_s1_data ;

  n1bytes = CHARSIZE*(s1->size-1) ;
  n2bytes = CHARSIZE*(s2->size) ;
  temp_s1_data = s1->data ;
  s1->data = (char*)malloc(sizeof(char)*(n1bytes+n2bytes)) ;
  for (idx = 0 ; idx < n1bytes ; idx++)
    s1->data[idx] = temp_s1_data[idx] ;
  for (bidx = n1bytes, idx = 0 ; idx < n2bytes ; idx++, bidx++)
    s1->data[bidx] = s2->data[idx] ;
  free(temp_s1_data) ;
  s1->size += s2->size-1 ;

  return s1 ;
}

/* Compare functions */
int mbstrcmp(struct multibytestring *s1,
	     struct multibytestring *s2) {

  if (s1->size != s2->size) return 0 ;
  return (bytewise_equal(s1->data, s2->data, CHARSIZE*s1->size)) ;
}

/* Compare functions by number of characters */
int mbstrncmp(struct multibytestring *s1,
	      struct multibytestring *s2, 
	      int n) {

  int nbytes ;
  if (s1->size != s2->size) return 0 ;
  nbytes = (n <= s1->size) ? CHARSIZE*n : CHARSIZE*s1->size ;
  return (bytewise_equal(s1->data, s2->data, nbytes)) ;
}

/* EOF */

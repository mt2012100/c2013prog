/*
 * Copyright (c) 2006, 2008 Alexey Vatchenko <av@bsdua.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Modified by: Jaya Sreevalsan-Nair
 * Date: Jan 17, 2011.
 *
 */

#include<stdlib.h>
#include<string.h>
#include "dynmemory.h"

int main(void) {
  struct dynmemory dm;
  char *p;
  int error;
  size_t len;
  
  /*
   * Initialize vpool object.
   * Use 1024 bytes allocation block.
   * `dm' buffer will have no limits (actually, SIZE_MAX).
   */
  dynmemory_init(&dm, 1024, 0);
  
  /*
   * Allocate 100 bytes at the end of buffer.
   */
  p = (char*) dynmemory_expand(&dm, UINT_MAX, 100);
  if (p != NULL)
    memset(p, 'A', 100);

  /*
   * Insert 3 bytes ("BBB") starting from position 2
   * into the buffer.
   */
  p = dynmemory_insert(&dm, 2, "BBB", 3);
  
  /*
   * Truncate buffer. Leave 5 bytes starting from position 3.
   */
  error = dynmemory_truncate(&dm, 3, 5, DM_INCLUDE);
  
  /*
   * Access data
   */
  if (dm.dm_off != 0) {
    p = (char*) (dm.dm_buf) ;
    len = dm.dm_off ;
    
    /*
     * *** do whatever you want with the buffer.
     * But remember! The pointer is valid until
     * you make dynmemory_expand(), dynmemory_insert(), 
     * dynmemory_truncate()
     */
  }
  
  /*
   * Free resources allocated by pool.
   */
  dynmemory_final(&dm);
  exit(0);
}
   

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

/*
 * File: dynmemory.c
 * Missing code is indicated by comments marked as "ADD MISSING CODE HERE"
 *
 */

#include <sys/types.h>

#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "dynmemory.h"
#define SIZE_MAX 0xffffffff

/* Move data to the pointer returned by (re|m)alloc */
static void dynmemory_shift(struct dynmemory *dm_ptr) {

  if (dm_ptr->dm_buf != dm_ptr->dm_basebuf) {
    /* ADD MISSING CODE HERE */
    /* Move the dm_ptr->dm_buf to dm_ptr->dm_basebuf and
     * update dm_buf
     */

  }
  return ;
}

/* For adding datasize to dm_ptr, update the actual increase possible in *size.
 * Ensure that the current size of data in buffer is preserved if datasize is 
 * not large enough.
 */
static int dynmemory_new_size(struct dynmemory *dm_ptr, size_t datasize, size_t *size) {
  
  size_t need;
  size_t rem;
  size_t extra_need ;
  
  need = datasize+dm_ptr->dm_size ;
  if (need <= dm_ptr->dm_size) {
    /* ADD MISSING CODE HERE */
    /* Assign value for size */
    return 0 ;
  }
  
  /* Check limit of new requested size */
  if (need > dm_ptr->dm_limit)
    return (EFBIG) ;
  
  /* Check limit of new size aligned to block size */
  /* When the needed memory is aligned as blocks, rem is
   * the remaining memory from need that does not fit in 
   * a block.
   */
  /* ADD MISSING CODE HERE */
  /* Assign value to rem */
  rem = ;
  if (rem != 0) {
    /* Allowance for an additional block */
    extra_need = need+dm_ptr->dm_blksize-rem ;

    /* Cap the needed memory to dm_limit after 
     * adding allowance */
    /* ADD MISSING CODE HERE */
    need = ;
  }
  
  *size = need;
  return 0;
}

static int dynmemory_resize(struct dynmemory *dm_ptr, size_t datasize) {

  char *newloc;
  size_t size;
  int error;
  
  error = dynmemory_new_size(dm_ptr, datasize, &size);
  if (error != 0)
    return (error);
  
  /* Increase the size */
  if (size > dm_ptr->dm_size) {
    newloc = (char*) malloc(size);
    if (newloc == NULL)
      return (ENOMEM);
    
    /* ADD MISSING CODE HERE */
    /* Move dm_ptr->base_buf to newloc using memory routines;
     * and release memory allocated by the current base_buf */

    dm_ptr->dm_basebuf = newloc ;
    dm_ptr->dm_buf = newloc;
    dm_ptr->dm_size = size;
  } else {
    if ((dm_ptr->dm_size - dm_ptr->dm_off) -
	(dm_ptr->dm_buf - dm_ptr->dm_basebuf) < datasize)
    dynmemory_shift(dm_ptr);
  }

  return (0);
}

void dynmemory_init(struct dynmemory *dm_ptr, size_t blksize, size_t limit) {

  dm_ptr->dm_basebuf = NULL ;
  dm_ptr->dm_buf = NULL;
  dm_ptr->dm_size = 0;
  
  dm_ptr->dm_blksize = (blksize == 0) ? 4096 : blksize;	
  dm_ptr->dm_limit = (limit == 0) ? SIZE_MAX : limit;
  
  dynmemory_wipe(dm_ptr) ;
  return ;
}

void dynmemory_final(struct dynmemory *dm_ptr) {

  /* ADD MISSING CODE HERE */
  /* Release allocated memory in dm_ptr */

  return ;
}

void dynmemory_reset(struct dynmemory *dm_ptr) {
 
  dynmemory_final(dm_ptr) ;
  dynmemory_init(dm_ptr, dm_ptr->dm_blksize, dm_ptr->dm_limit) ;
  return ;
}

void dynmemory_wipe(struct dynmemory *dm_ptr) {
 
  dm_ptr->dm_off = 0 ;
  dm_ptr->dm_lasterr = 0;
  return ;
}

void* dynmemory_insert(struct dynmemory *dm_ptr, size_t where, void *data, size_t datasize) {

  char *ret = dynmemory_expand(dm_ptr, where, datasize) ;
  if (ret != NULL) {
    /* ADD MISSING CODE HERE */
    /* Move data to appropriate location */
  }
  return (ret);
}

void* dynmemory_expand(struct dynmemory *dm_ptr, size_t where, size_t size) {

  char *ret;
  size_t diff_where ;
  
  /* ADD MISSING CODE HERE */
  /* Finding error on memory resize of dm_ptr for size */
  dm_ptr->dm_lasterr = ;
  if (dm_ptr->dm_lasterr != 0) 
    return (NULL);
  
  /*
   * If ``where'' is greater than or equal to offset then
   * we are appending data to the end of the buffer.
   */
  /* ADD MISSING CODE HERE */
  where = ;
  diff_where = dm_ptr->dm_off - where ;

  ret = (char*)dm_ptr->dm_buf + where;
  if (diff_where > 0)
    memmove(ret + size, ret, diff_where) ;
  dm_ptr->dm_off += size;
    
  return (ret);
}

int dynmemory_truncate(struct dynmemory *dm_ptr,
		      size_t where, size_t size, enum dynmemory_trunc how) {

  /* Check if caller wants to remove more data than we have */
  if (where >= dm_ptr->dm_off ||
      size > dm_ptr->dm_off || dm_ptr->dm_off - size < where) {
    dm_ptr->dm_lasterr = ERANGE;
    return (dm_ptr->dm_lasterr);
  }
  
  if (how == DM_EXCLUDE) {
    if (where == 0) {
      /*
       * Optimization.
       * Don't move data, just adjust pointer.
       */
      dm_ptr->dm_buf += size;
    } else {
      memmove((char*)dm_ptr->dm_buf + where,
	      (char*)dm_ptr->dm_buf + where + size,
	      dm_ptr->dm_off - size - where);
    }
    dm_ptr->dm_off -= size;
  } else {
    dm_ptr->dm_buf += where;
    dm_ptr->dm_off = size;
  }
  
  dm_ptr->dm_lasterr = 0;
  return (0);
}


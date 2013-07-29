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
 * Dynmemory: implementation of pool of data with a variable size.
 * Dynmemory is an auto-resizeable buffer (dynamic array). It automatically 
 * takes care about memory allocation, boundary checking, pointer 
 * manipulations and etc.
 */

#ifndef _DYNMEMORY_H_
#define _DYNMEMORY_H_

#include <sys/types.h>
#include <sys/cdefs.h>
#include <limits.h>

struct dynmemory {
  void	*dm_basebuf;	/* pointer returned by (re|m)alloc() */
  void	*dm_buf;	/* actual data starts here */
  size_t dm_off;        /* size of data offset */
  size_t dm_size;       /* size of data in buffer */
  
  size_t dm_blksize;    /* Block size */
  size_t dm_limit;      /* Capacity of the buffer */
  int dm_lasterr;       /* Last error logged */
};

enum dynmemory_trunc {DM_EXCLUDE, DM_INCLUDE};

void dynmemory_init(struct dynmemory *dm_ptr, size_t blksize, size_t limit);
void dynmemory_final(struct dynmemory *dm_ptr);

void dynmemory_reset(struct dynmemory *dm_ptr);
void dynmemory_wipe(struct dynmemory *dm_ptr);

void* dynmemory_insert(struct dynmemory *dm_ptr,
	               size_t where, void *data, size_t datasize);
void* dynmemory_expand(struct dynmemory *dm_ptr, size_t where, size_t size);

int dynmemory_truncate(struct dynmemory *dm_ptr,
	      	       size_t where, size_t size, enum dynmemory_trunc how);

#endif 

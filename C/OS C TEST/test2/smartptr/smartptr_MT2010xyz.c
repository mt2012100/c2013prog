/*
 * File: smartptr.c
 * Description: Contains the implementation stubs for auto-pointer implementation in C language
 * Missing code is indicated by comments marked as "ADD MISSING CODE HERE"
 */

#include <stdio.h>
#include <malloc.h>
#include "smartptr.h"

/* Programs would never use malloc() function.
 * Instead, they create a new pointer using ptr_create by passing the type of the pointer to be created 
 * See sample main program for example
 */
struct smart_ptr ptr_create( enum ptr_type_t ptr_type )
{
	struct smart_ptr newptr;
	
	switch( ptr_type ){
		case INT_PTR: 
			/* ADD MISSING CODE HERE */
		        /* Initialize the newptr */
			newptr.auto_ptr = (struct _autoptr *)malloc(sizeof (struct _autoptr));
			newptr.auto_ptr->local_ptr =malloc(sizeof(int)); 
			newptr.auto_ptr->ref_count =1;
			newptr.auto_ptr->ptr_type =ptr_type;
			newptr.ptr_status =PTR_VALID;
			fprintf(stderr, "Ref count for %p is %d\n", newptr.auto_ptr->local_ptr, newptr.auto_ptr->ref_count);

		case FLOAT_PTR: 
			/* ADD MISSING CODE HERE */
		        /* Initialize the newptr */

			newptr.auto_ptr = (struct _autoptr *)malloc(struct _autoptr);
			newptr.auto_ptr->local_ptr = malloc(sizeof(float));
			newptr.auto_ptr->ref_count =1;
			newptr.auto_ptr->ptr_type =ptr_type;
			newptr.ptr_status =PTR_VALID;
			fprintf(stderr, "Ref count for %p is %d\n", newptr.auto_ptr->local_ptr, newptr.auto_ptr->ref_count);

		default:
			fprintf(stderr, "Invalid pointer type encountered\n");
			newptr.auto_ptr = NULL;
			newptr.ptr_status = PTR_INVALID;
			break;
	}
	return newptr;
}

/* Programs would never use direct pointers for passing them to other functions; 
 * instead they should always create copies of pointers using ptr_reference
 * See sample main program for example
 */
struct smart_ptr copy_ptr( struct smart_ptr ptr )
{
	struct smart_ptr newptr;

	if( ptr.ptr_status == PTR_INVALID ){
		fprintf(stderr, "Invalid pointer encountered in copy_ptr()\n");
		newptr.auto_ptr = NULL;
		newptr.ptr_status = PTR_INVALID;
	}
	else{
                    newptr=ptr;
                   newptr.auto_ptr->ref_count++;
		/* ADD MISSING CODE HERE */
	        /* Copy ptr */

		fprintf(stderr, "Ref count for %p is %d\n", newptr.auto_ptr->local_ptr, newptr.auto_ptr->ref_count);
	}
	return newptr;
}

/* Programs would never be able to extract values directly using * operator
 * Instead, they will call the appropriate getvalue function
 * It is the callers responsibility to call the correct getobject function
 * depending upon the data type.  Return value is undefined if pointer is not valid
 * See sample main program for example
 */
int getobject_int( struct smart_ptr ptr )
{
	int retval;
	int *int_ptr;
	
	if( ptr.ptr_status == PTR_INVALID || ptr.auto_ptr->ptr_type != INT_PTR ){
		fprintf(stderr, "Invalid pointer encountered in getobject_int()\n");
		retval = 0xFFFF;
	}
	else{
		/* ADD MISSING CODE HERE */
	        /* Retrieve the data */
		int_ptr = (int*)ptr.autoptr->local_ptr;
		retval = *int_ptr;
	}
	return retval;
}

float getobject_float( struct smart_ptr ptr )
{
	float retval;
	float *float_ptr;
	
	if( ptr.ptr_status == PTR_INVALID || ptr.auto_ptr->ptr_type != FLOAT_PTR ){
		fprintf(stderr, "Invalid pointer encountered in getobject_float()\n");
		retval = 0xFFFF;
	}
	else{
		/* ADD MISSING CODE HERE */
	        /* Retrieve the data */
		float_ptr = (float*)ptr.autoptr->local_ptr
		retval = *int_ptr;
	}
	return retval;
}

/* Programs would never be able to set values directly using * operator
 * Instead, they will call the appropriate setobject function
 * It is the callers responsibility to call the correct setobject function
 * depending upon the data type.  
 * See sample main program for example
 */
void setobject_int( struct smart_ptr ptr, int value )
{
	int *int_ptr;
	
	if( ptr.ptr_status == PTR_INVALID || ptr.auto_ptr->ptr_type != INT_PTR ){
		fprintf(stderr, "Invalid pointer encountered in setobject_int()\n");
	}
	else{
		/* ADD MISSING CODE HERE */
	        /* Set the data */
		int_ptr = (int*)ptr.autoptr->local_ptr;
		*int_ptr = value; 
	}
}

/* Programs would never be able to set values directly using * operator
 * Instead, they will call the appropriate setobject function
 * It is the callers responsibility to call the correct setobject function
 * depending upon the data type.  
 * See sample main program for example
 */
void setobject_float( struct smart_ptr ptr, float value )
{
	float *float_ptr;
	
	if( ptr.ptr_status == PTR_INVALID || ptr.auto_ptr->ptr_type != FLOAT_PTR ){
		fprintf(stderr, "Invalid pointer encountered in setobject_int()\n");
	}
	else{
		/* ADD MISSING CODE HERE */
	        /* Set the data */
		float_ptr =(float*)ptr.autoptr->local_ptr; 
		*float_ptr = value;
	}
}

/* Pointers would never call free() function
 * Instead they will call the release() function whenever they are done using the pointer
 * See sample main program for example
 */
void ptr_release( struct smart_ptr ptr )
{
	if( ptr.ptr_status == PTR_INVALID ){
		fprintf(stderr, "Invalid pointer encountered in release()\n");
	}
	else{
                 ptr.auto_ptr->ref_count--;
		/* Decrement the reference count first */
		/* ADD MISSING CODE HERE */

		fprintf(stderr, "Ref count for %p is %d\n", ptr.auto_ptr->local_ptr, ptr.auto_ptr->ref_count);
		
		/* Free the pointer if the reference count has become zero */
		if( ptr.auto_ptr->ref_count == 0 ){
			/* ADD MISSING CODE HERE */
		        /* Clean up */
		}
	}
}

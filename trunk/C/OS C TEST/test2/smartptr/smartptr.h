/*
 * File: smartptr.h
 * Description: Contains the header declarations for auto-pointer implementation in C language
 */
 
/* Enumeration declaration for the different types of pointers supported */
/* This can be easily extended to user-defined data types as well */

enum ptr_type_t {INT_PTR, FLOAT_PTR};
enum ptr_status_t {PTR_VALID, PTR_INVALID};

/* Structure declaration for the auto-pointer abstraction */
struct smart_ptr{
		struct _autoptr *auto_ptr;
                enum ptr_status_t ptr_status; /* States validity of the pointer */
};

/* Internal representation of smart pointer using the concept of auto-pointers similar to C++ */
struct _autoptr{
	enum ptr_type_t ptr_type;       /* Type of the pointer depending on data type it is storing */
        void *local_ptr;                /* Pointer to the data */
	int ref_count;                  /* A counter that keeps track of the number of copies of the pointer */
};

/* Programs would never use malloc() function.
 * Instead, they create a new pointer using ptr_create by passing the type of the pointer to be created 
 * See sample main program for example
 */
struct smart_ptr ptr_create( enum ptr_type_t ptr_type );

/* Programs would never use direct pointers for passing them to other functions; 
 * instead they should always create copies of pointers using ptr_reference
 * See sample main program for example
 */
struct smart_ptr copy_ptr( struct smart_ptr ptr );

/* Programs would never be able to extract values directly using * operator
 * Instead, they will call the appropriate getobject function
 * It is the callers responsibility to call the correct getobject function
 * depending upon the data type. 
 * See sample main program for example
 */
int getobject_int( struct smart_ptr ptr );
float getobject_float( struct smart_ptr ptr );

/* Programs would never be able to assign values directly using * operator
 * Instead, they will call the appropriate setobject function
 * It is the callers responsibility to call the correct setobject function
 * depending upon the data type. 
 * See sample main program for example
 */
void setobject_int( struct smart_ptr ptr, int value );
void setobject_float( struct smart_ptr ptr, float value );

/* Pointers would never call free() function
 * Instead they will call the release() function whenever they are done using the pointer
 * See sample main program for example
 */
void ptr_release( struct smart_ptr ptr );


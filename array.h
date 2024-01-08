/*array.h - Array Library

Use of array:
    #include "array.h"

What's defined:

--------------------------------------------------------------------------------------------

Current Array Library Version - 1.00

Advantages:
    PORTABLE (Uses one file)
    DOCUMENTED (Lots of documentation)
    WRITTEN IN C (FAST)

Preprocessed statements:
    ARRAY_VERSION : the version of the array library

*/

#define ARRAY_VERSION 1.00

#ifndef _CONSOLE_H
#define _CONSOLE_H



#define string char*
#define anything void*
#define unsigned_long unsigned long
#define unsigned_int unsigned int


#define array_max 100

#define new_arrtype(type) struct arr_##type {\
  type value[array_max];\
 int len;\
};\
typedef struct arr_##type arr_##type;


#define arr_size(arr) arr->len



// #define arr() {0, 0}
#define arr_new(type) __builtin_malloc(sizeof(struct arr_##type))



#define arr_push(arr, val) \
arr->value[arr->len++] = val;

#define arr_get(arr, idx) arr->value[idx]

#define arr_eq(arr, normalArray) __builtin_memcpy(arr->value, normalArray, sizeof(normalArray)); arr->len = sizeof(normalArray)/sizeof(normalArray[0]);

#define arr_set(arr, idx, val) arr->value[idx] = val; if(idx >= arr->len && idx != 0) {arr->len = idx;};

#define arr_map(arr, fun) for (int i=0; i<=arr->len; i++){ \
    arr->value[i] = fun(arr->value[i]); \
}

#define arr_last(arr) arr->value[arr_size(arr)-1]

#define arr_first(arr) arr->value[0]

#define arr_empty(arr) arr_size(arr) == 0 ? 1 : 0

#define arr_destroy(arr) __builtin_free(arr);


#define arr_fill(arr, val) for (int i=0; i<=array_max; i++){ \
    arr->value[i] = val; \
}

#define arr_remove(arr, idx) arr->value[idx] = __builtin_malloc(sizeof(arr->value[idx])); arr->len-=1; for(int i=idx; i<=arr->len; i++){arr->value[i] = arr->value[i+1];};

#define arr_extend(arr1, arr2) for (int i=0; i<=arr2->len-1; i++) {arr_push(arr1, arr2->value[i]);}; 

#define arr_insert(arr, idx, val) for (int i=idx; i<=arr->len; i++) {arr->value[i+1] = arr->value[i];}; arr_set(arr, idx, val); ;

#define arr_clear(arr) arr->len = 0; __builtin_free(arr->value); __builtin_memcpy(arr->value,  __builtin_malloc(sizeof(arr->value)), sizeof(arr->value));



new_arrtype(int);
new_arrtype(string);
new_arrtype(anything);
new_arrtype(double);
new_arrtype(float);
new_arrtype(unsigned_long);
new_arrtype(unsigned_int);

new_arrtype(long);


#endif
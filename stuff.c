#include "array.h"
#include <stdio.h>

int main(){
    arr_string *arr = arr_new(string);
    arr_string *arr2 = arr_new(string);
    // arr_fill(arr, "Look");
    arr_push(arr2, "H");
    // arr_map(arr, ^(string a){
        // return "None";
    // });
    arr_extend(arr, arr2)
    printf("%s", arr_first(arr));
    arr_destroy(arr);
}
#include <stdbool.h>
#include <stddef.h>

bool check_if_in(unsigned int item, unsigned char *array, size_t length){
    int i;
    for (i = 0; i < length; i++){
        if(array[i] == item){
            return true;
        }
    }
    return false;
}
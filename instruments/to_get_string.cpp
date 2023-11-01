#include "to_get_string.h"
#include <iostream>
using std::cin;

char* to_get_string(int* len) {

    bool flag = true;
    *len = 0;           
    int capacity = 1;  

    char* s = new char[1];
    char* sPtr = s;
m1:
    char c = cin.get();; 
    if ((*len == 0) && (flag)) {
        flag = false;
        goto m1;
    }

   
    while (c != '\n') {
        s[(*len)++] = c; 

       
        if (*len >= capacity) {
            char* tmp = new char[*len];
            char* tmpPtr = tmp;
            for (int i = 0; i < *len; i++) {
                *tmpPtr = *sPtr;
                sPtr++;
                tmpPtr++;
            }
            delete[] s;
            capacity *= 2;          
            s = new char[capacity]; 
            sPtr = s;
            tmpPtr = tmp;
            for (int i = 0; i < capacity; i++) {
                *sPtr = *tmpPtr;
                tmpPtr++;
                sPtr++;
            }
            delete[] tmp;
            sPtr = s;
        }
        c = cin.get();        
    }

    s[*len] = '\0';    

    return s;           
}
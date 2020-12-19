//Compiler v[0.0.1]
//Astably.

#include"cmpfa.h"

#ifdef __CMPFA_DEBUB
    buffer* buffer = buffer_init(1024);
    FILE* file = buffer_get_file("LOG_CMPFA.txt");
    if(buffer == NULL && file == NULL){
        cmpfa_error_id = _CMPFA_ERROR_INITIALIZATION;
    }
#endif

int8_t initialization(const char* str)
{
    if(str != NULL){
        static FILE* token = fopen(str, "r");
        if(token != NULL){
            #ifdef __CMPFA_DEBUB
            
            #endif
            return _CMPFA_SUCСESSFUL_INITIALIZATION;
        }
        else{
            return _CMPFA_ERROR_INITIALIZATION;
        }
    }
}

void read(FILE* file)
{
}



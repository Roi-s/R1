//Compiler v[0.0.1]
//Astably.
/*Log
* 19.12.2020 create.
*/

#ifndef __COMPILER_FOR_APP__
#define __COMPILER_FOR_APP__

//CONFIGURATION
#define __CMPFA_INCLUDE_DEFOLT_LIBRARIES
#define __CMPFA_DEBUB
#define _CMPFA_SUCСESSFUL_INITIALIZATION 0x1
//

#ifdef __CMPFA_INCLUDE_DEFOLT_LIBRARIES
    #include <stdlib.h>
    #include <stdint.h>
    #include <stdio.h> 
    #include"logger.h"

#endif //__CMPFA_INCLUDE_DEFOLT_LIBRARIES

typedef enum __cmpfa_error
{
    _CMPFA_ERROR_INITIALIZATION = -1,
    _CMPFA_ATTEMPT_TO_INIT_ZERO_BYTES = -2,
    _CMPFA_ATTEMPT_TO_ALLOCATE_ZERO_BYTES = -3,
    _CMPFA_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY = -4,
    _CMPFA_OUT_OF_MEMORY = -5,
}__cmpfa_error;

static int16_t cmpfa_error_id = 0;

int8_t initialization(const char* str);

void read(FILE* file);

#endif //__COMPILER_FOR_APP__



























/*
int main(void)
{
    uint16_t t;
    uint_fast32_t n;
    //uint_fast32_t a = 6;
    //uint_fast32_t b = 10;
    //uint_fast32_t c = 14; 
    scanf("%u", &t);
    while(t > 0){
        --t;
        scanf("%u", &n);
        if(n > 30){
           if(n == 36 || n == 40 || n == 44){
               printf("6 10 15 %u\n", n - 31);
            }
            else{
                printf("6 10 14 %u\n", n - 30);
            }
        }
        else{
            printf("NO\n");
            return 0;
        }
    }
}
*/

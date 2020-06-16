//
//Version 0.0.1
//
//
//-----------------------------------------------------------------------------------------------------------------------------
#ifndef __STACK_ALLOCATOR_H__


#include <stdint.h>


static int8_t stack_buffer_ERROR_ID = 0;


typedef enum _stack_buf_error {
    _ATTEMPT_TO_INIT_ZERO_BYTES = -4,
    _ATTEMPT_TO_ALLOCATE_ZERO_BYTES = -3,
    _ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY = -2,
    _OUT_OF_MEMORY = -1,
    //_ATTEMPT_TO_DELETE_A_NONEXISTENT_ENTITY,

}__stack_buf_error;

typedef struct __stack_buffer
{
    uint8_t* _mem;
    uint32_t _size;
    uint32_t _offset;
}__stack_buffer;

void* stack_buf_init(uint32_t size);

void* stack_buf_alloc(__stack_buffer* buffer, uint32_t* object, uint32_t size);

void stack_buf_set(__stack_buffer* buffer, uint32_t object);

void stack_buf_free(__stack_buffer* buffer);

void stact_buf_set_error(int8_t* id);

void stack_buf_get_error(int8_t* id);

void test();
#endif // !__STACK_ALLOCATOR.H




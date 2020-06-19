//
//Version 0.0.2
//
//

#include "stack_allocator.h"

void* stack_buf_init(uint32_t size)
{
    static __stack_buffer* buffer;
    if (size == 0) {
        //printf("ERROR SIZE = 0 IN INIT");
        stack_buffer_ERROR_ID = _ATTEMPT_TO_INIT_ZERO_BYTES;
        return NULL;
    }
    else {
        buffer = (__stack_buffer*)malloc(sizeof(__stack_buffer));
        buffer->_offset = 0;
        buffer->_size = size;
        buffer->_mem = malloc(size * sizeof(uint32_t));
        //buffer->_mem = (uint8_t*)malloc(size);
    }
    return buffer;
}

void* stack_buf_alloc(__stack_buffer* buffer, uint32_t* object, uint32_t size)
{
    if (size == 0) {
        stack_buffer_ERROR_ID = _ATTEMPT_TO_ALLOCATE_ZERO_BYTES;
        return NULL;
    }
    else if (buffer == NULL) {
        stack_buffer_ERROR_ID = _ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
        return NULL;
    }
    else if((buffer->_offset + size) <= buffer->_size) {
        const uint32_t c_offset = buffer->_offset;
        uint8_t* ptr = buffer->_mem + c_offset;
        buffer->_offset += size;
        if (object != NULL) {
            *object = c_offset;
            return (void*)ptr;
        }
        else {
            stack_buffer_ERROR_ID = _ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
            return NULL;
        }
    }
    stack_buffer_ERROR_ID = _OUT_OF_MEMORY;
    return NULL;
}

void stack_buf_set(__stack_buffer* buffer, uint32_t object)
{
    if (buffer == NULL) {
        stack_buffer_ERROR_ID = _ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
        //printf("\nERROR_ID: %i\n", stack_buffer_ERROR_ID);
        //exit(_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY);
    }
    else {
        buffer->_offset = object;
    }
}

void stack_buf_free(__stack_buffer* buffer)
{
    if (buffer == NULL) {
        stack_buffer_ERROR_ID = _ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
        //printf("\nERROR_ID: %i\n", stack_buffer_ERROR_ID);
    }
    else {
        stack_buf_set(buffer, 0);
        free(buffer->_mem);
        free(buffer);
    }
}

void stact_buf_set_error(int8_t* id)
{
    stack_buffer_ERROR_ID = *id;
}

void stack_buf_get_error(int8_t* id)
{
    printf("\nERROR_ID: ", *id);
}

void test()
{

    __stack_buffer* buf = stack_buf_init(20);
    uint32_t b = 0, c = 0;
    char* a = &b;
    uint32_t* t = &c;
    a = stack_buf_alloc(buf, a, 3);
    stack_buf_set(buf, 3);
    t = stack_buf_alloc(buf, t, 3);
    if (t != NULL) {
        for (int i = 0; i < 3; ++i) {
            a[i] = 'a';
            t[i] = 10;
        }
        for (int i = 0; i < 3; ++i) {
            printf("%c\n", a[i]);
        }
        for (int i = 0; i < 3; ++i) {
            printf("%i\n", t[i]);
        }
    }
    else {
        printf("\nERROR: %i\n", stack_buffer_ERROR_ID);
    }
    stack_buf_free(buf);
}
#ifndef __C_VECTORS_H__
#define __C_VECTORS_H__

//CONFIGUARE
//----------------------------------------------------------------------------------------
#define __VECTOR_INCLUDE_DEFAULT_LIBRARIES        //stdio.h, stdio.h
//#define __VECTOR_CPP__
#define _VECTOR_INT8_T 1
#define _VECTOR_INT16_T 2
#define _VECTOR_INT32_T 3
#define _VECTOR_INT64_T 4
#define _VECTOR_FLOAT_T 5
#define _VECTOR_DOUBLE_T 6

#define CAT(X, Y) X##_##Y
#define _GET_NAME(name, type) CAT(name, type)
#define _GET_FUNCTION(name, type) CAT(name, type)
//----------------------------------------------------------------------------------------

#ifdef __VECTOR_INCLUDE_DEFAULT_LIBRARIES
	#include <stdint.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <math.h>
#endif

static int8_t _vector_error_id = 0;

typedef enum __vector_error
{
	_VECTOR_ATTEMPT_TO_INIT_ZERO_BYTES = -4,
    _VECTOR_ATTEMPT_TO_ALLOCATE_ZERO_BYTES = -3,
    _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY = -2,
    _VECTOR_OUT_OF_MEMORY = -1,
}__vector_error;

#endif // __C_VECTORS_H__

#ifndef TEMPLATE
#define TEMPLATE
#ifdef T 

	#ifdef __VECTOR_CPP__
		void operator+(_GET_NAME(__vector2, T)* result, _GET_NAME(__vector2, T)* left, _GET_NAME(__vector2, T)* right);
		void operator+(_GET_NAME(__vector3, T)* result, _GET_NAME(__vector3, T)* left, _GET_NAME(__vector3, T)* right);
		void operator+(_GET_NAME(__vector4, T)* result, _GET_NAME(__vector4, T)* left, _GET_NAME(__vector4, T)* right);
		void operator+(_GET_NAME(__vector5, T)* result, _GET_NAME(__vector5, T)* left, _GET_NAME(__vector5, T)* right);
	#endif

	typedef struct _GET_NAME(__vector2, T)
	{
		#define _VECTOR2_SIZE 2
		T x;
		T y;
	}_GET_NAME(__vector2, T);

	typedef struct _GET_NAME(__vector3, T)
	{
		#define _VECTOR3_SIZE 3
		T x;
		T y;
		T z;
	}_GET_NAME(__vector3, T);

	typedef struct _GET_NAME(__vector4, T)
	{
	 	#define _VECTOR4_SIZE 4
		T x;
		T y;
		T z;
		T t;
	}_GET_NAME(__vector4, T);

	typedef struct _GET_NAME(__vector5, T)
	{
		#define _VECTOR5_SIZE 5
		T x;
		T y;
		T z;
		T t;
		T w;
	}_GET_NAME(__vector5, T);

	_GET_FUNCTION(__vector2, T)* _GET_NAME(__vector2_create, T)();
	_GET_FUNCTION(__vector3, T)* _GET_NAME(__vector3_create, T)();
	_GET_FUNCTION(__vector4, T)* _GET_NAME(__vector4_create, T)();
	_GET_FUNCTION(__vector5, T)* _GET_NAME(__vector5_create, T)();

	void _GET_NAME(_vector2_init, T)(_GET_NAME(__vector2, T)* left, T param1, T param2);
	void _GET_NAME(_vector3_init, T)(_GET_NAME(__vector3, T)* left, T param1, T param2, T param3);
	void _GET_NAME(_vector4_init, T)(_GET_NAME(__vector4, T)* left, T param1, T param2, T param3, T param4);  
	void _GET_NAME(_vector5_init, T)(_GET_NAME(__vector5, T)* left, T param1, T param2, T param3, T param4, T param5);

	double _GET_NAME(_vector2_norm, T)(_GET_NAME(__vector2, T)* left);	 
	double _GET_NAME(_vector3_norm, T)(_GET_NAME(__vector3, T)* left);
	double _GET_NAME(_vector4_norm, T)(_GET_NAME(__vector4, T)* left);
	double _GET_NAME(_vector5_norm, T)(_GET_NAME(__vector5, T)* left);

	_GET_FUNCTION(__vector2, double)* _GET_NAME(_vector2_normalize, T)(_GET_NAME(__vector2, T)* left);
	_GET_FUNCTION(__vector3, double)* _GET_NAME(_vector3_normalize, T)(_GET_NAME(__vector3, T)* left);
	_GET_FUNCTION(__vector4, double)* _GET_NAME(_vector4_normalize, T)(_GET_NAME(__vector4, T)* left);
	_GET_FUNCTION(__vector5, double)* _GET_NAME(_vector5_normalize, T)(_GET_NAME(__vector5, T)* left);

	void _GET_NAME(_vector2_add, T)(_GET_NAME(__vector2, T)* result, _GET_NAME(__vector2, T)* left, _GET_NAME(__vector2, T)* right);
	void _GET_NAME(_vector3_add, T)(_GET_NAME(__vector3, T)* result, _GET_NAME(__vector3, T)* left, _GET_NAME(__vector3, T)* right);
	void _GET_NAME(_vector4_add, T)(_GET_NAME(__vector4, T)* result, _GET_NAME(__vector4, T)* left, _GET_NAME(__vector4, T)* right);
	void _GET_NAME(_vector5_add, T)(_GET_NAME(__vector5, T)* result, _GET_NAME(__vector5, T)* left, _GET_NAME(__vector5, T)* right);
	


#endif
#undef TEMPLATE
#endif


 




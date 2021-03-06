#ifndef __C_VECTORS_H__
#define __C_VECTORS_H__

//CONFIGUARE
//----------------------------------------------------------------------------------------
#define __VECTOR_INCLUDE_DEFAULT_LIBRARIES
//----------------------------------------------------------------------------------------

// MACRO FUNCTION        
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

	typedef struct _GET_NAME(__vector2, T)
	{
		T x;
		T y;
	}_GET_NAME(__vector2, T);

	typedef struct _GET_NAME(__vector3, T)
	{
		T x;
		T y;
		T z;
	}_GET_NAME(__vector3, T);

	typedef struct _GET_NAME(__vector4, T)
	{
		T x;
		T y;
		T z;
		T t;
	}_GET_NAME(__vector4, T);

	typedef struct _GET_NAME(__vector5, T)
	{
		T x;
		T y;
		T z;
		T t;
		T w;
	}_GET_NAME(__vector5, T);

	_GET_FUNCTION(__vector2, T)* _GET_NAME(vector2_create, T)();
	_GET_FUNCTION(__vector3, T)* _GET_NAME(vector3_create, T)();
	_GET_FUNCTION(__vector4, T)* _GET_NAME(vector4_create, T)();
	_GET_FUNCTION(__vector5, T)* _GET_NAME(vector5_create, T)();

	void _GET_NAME(vector2_init, T)(_GET_NAME(__vector2, T)* left, T param1, T param2);
	void _GET_NAME(vector3_init, T)(_GET_NAME(__vector3, T)* left, T param1, T param2, T param3);
	void _GET_NAME(vector4_init, T)(_GET_NAME(__vector4, T)* left, T param1, T param2, T param3, T param4);  
	void _GET_NAME(vector5_init, T)(_GET_NAME(__vector5, T)* left, T param1, T param2, T param3, T param4, T param5);

	double _GET_NAME(vector2_norm, T)(_GET_NAME(__vector2, T)* left);	 
	double _GET_NAME(vector3_norm, T)(_GET_NAME(__vector3, T)* left);
	double _GET_NAME(vector4_norm, T)(_GET_NAME(__vector4, T)* left);
	double _GET_NAME(vector5_norm, T)(_GET_NAME(__vector5, T)* left);

	_GET_FUNCTION(__vector2, double)* _GET_NAME(vector2_normalize, T)(_GET_NAME(__vector2, T)* left);
	_GET_FUNCTION(__vector3, double)* _GET_NAME(vector3_normalize, T)(_GET_NAME(__vector3, T)* left);
	_GET_FUNCTION(__vector4, double)* _GET_NAME(vector4_normalize, T)(_GET_NAME(__vector4, T)* left);
	_GET_FUNCTION(__vector5, double)* _GET_NAME(vector5_normalize, T)(_GET_NAME(__vector5, T)* left);

	void _GET_NAME(vector2_add, T)(_GET_NAME(__vector2, T)* result, _GET_NAME(__vector2, T)* left, _GET_NAME(__vector2, T)* right);
	void _GET_NAME(vector3_add, T)(_GET_NAME(__vector3, T)* result, _GET_NAME(__vector3, T)* left, _GET_NAME(__vector3, T)* right);
	void _GET_NAME(vector4_add, T)(_GET_NAME(__vector4, T)* result, _GET_NAME(__vector4, T)* left, _GET_NAME(__vector4, T)* right);
	void _GET_NAME(vector5_add, T)(_GET_NAME(__vector5, T)* result, _GET_NAME(__vector5, T)* left, _GET_NAME(__vector5, T)* right);
	
	void _GET_NAME(vector2_free, T)(_GET_NAME(__vector2, T)* left);
	void _GET_NAME(vector3_free, T)(_GET_NAME(__vector3, T)* left);
	void _GET_NAME(vector4_free, T)(_GET_NAME(__vector4, T)* left);
	void _GET_NAME(vector5_free, T)(_GET_NAME(__vector5, T)* left);


#endif
#undef TEMPLATE
#endif







//#include "Vectors.h"
//#include "template.h"

#ifndef TEMPLATE
#define TEMPLATE
#ifdef T 
	
	#ifdef __VECTOR_CPP__
		void operator+(_GET_NAME(__vector2, T)* result, _GET_NAME(__vector2, T)* left, _GET_NAME(__vector2, T)* right)
		{
			void _GET_NAME(_vector2_add, T)(result, left, right);
		}
		void operator+(_GET_NAME(__vector3, T)* result, _GET_NAME(__vector3, T)* left, _GET_NAME(__vector3, T)* right)
		{
			void _GET_NAME(_vector3_add, T)(result, left, right);
		}
		void operator+(_GET_NAME(__vector4, T)* result, _GET_NAME(__vector4, T)* left, _GET_NAME(__vector4, T)* right)
		{
			void _GET_NAME(_vector4_add, T)(result, left, right);
		}
		void operator+(_GET_NAME(__vector5, T)* result, _GET_NAME(__vector5, T)* left, _GET_NAME(__vector5, T)* right)
		{
			void _GET_NAME(_vector5_add, T)(result, left, right);
		}
	#endif

	_GET_FUNCTION(__vector2, T)* _GET_NAME(__vector2_create, T)() 
	{
		static _GET_NAME(__vector2, T)* vector;
		vector = malloc(sizeof(_GET_NAME(__vector2, T)));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
				return vector;
			
		}
	}

	_GET_FUNCTION(__vector3, T)* _GET_NAME(__vector3_create, T)()
	{
		static _GET_NAME(__vector3, T)* vector;
		vector = malloc(sizeof(_GET_NAME(__vector3, T)));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
				return vector;
			
		}
	}

	_GET_FUNCTION(__vector4, T)* _GET_NAME(__vector4_create, T)()
	{
		static _GET_NAME(__vector4, T)* vector;
		vector = malloc(sizeof(_GET_NAME(__vector4, T)));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
				return vector;
			
		}
	}

	_GET_FUNCTION(__vector5, T)* _GET_NAME(__vector5_create, T)()
	{
		static _GET_NAME(__vector5, T)* vector;
		vector = malloc(sizeof(_GET_NAME(__vector5, T)));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
				return vector;
		}
	}


	void _GET_NAME(_vector2_init, T)(_GET_NAME(__vector2, T)* left, T param1, T param2)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			left->x = param1;
			left->y = param2;
		}
	}
	void _GET_NAME(_vector3_init, T)(_GET_NAME(__vector3, T)* left, T param1, T param2, T param3)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			left->x = param1;
			left->y = param2;
			left->z = param3;
		}
	}
	void _GET_NAME(_vector4_init, T)(_GET_NAME(__vector4, T)* left, T param1, T param2, T param3, T param4)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			left->x = param1;
			left->y = param2;
			left->z = param3;
			left->t = param4;
		}
	} 
	void _GET_NAME(_vector5_init, T)(_GET_NAME(__vector5, T)* left, T param1, T param2, T param3, T param4, T param5)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			left->x = param1;
			left->y = param2;
			left->z = param3;
			left->t = param4;
			left->w = param5;
		}
	}

	double _GET_NAME(_vector2_norm, T)(_GET_NAME(__vector2, T)* left)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			return sqrt((left->x)*(left->x) + (left->y)*(left->y));
		}
	}
	double _GET_NAME(_vector3_norm, T)(_GET_NAME(__vector3, T)* left)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			return sqrt((left->x)*(left->x) + (left->y)*(left->y) + (left->z)*(left->z));
		}
	}
	double _GET_NAME(_vector4_norm, T)(_GET_NAME(__vector4, T)* left)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			return sqrt((left->x)*(left->x) + (left->y)*(left->y) + (left->z)*(left->z) + (left->t)*(left->t));
		}
	}
	double _GET_NAME(_vector5_norm, T)(_GET_NAME(__vector5, T)* left)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			return sqrt((left->x)*(left->x) + (left->y)*(left->y) + (left->z)*(left->z) + (left->t)*(left->t)
				       + (left->w)*(left->w));
		}
	}

	_GET_FUNCTION(__vector2, double)* _GET_NAME(_vector2_normalize, T)(_GET_NAME(__vector2, T)* left)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
			return NULL;
		}
		else{
			double norm = _GET_NAME(_vector2_norm, T)(left);
			__vector2_double* result = __vector2_create_double();
			if(result == NULL){
				_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
				return NULL;
			}
			else {
				if(norm == 0){
					_vector2_init_double(result, 0.0, 0.0);
				}
				else{
					_vector2_init_double(result, (left->x/norm), (left->y/norm));
					return result;
				}
			}
		}
	}
	_GET_FUNCTION(__vector3, double)* _GET_NAME(_vector3_normalize, T)(_GET_NAME(__vector3, T)* left)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
			return NULL;
		}
		else{
			double norm = _GET_NAME(_vector3_norm, T)(left);
			__vector3_double* result = __vector3_create_double();
			if(result == NULL){
				_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
				return NULL;
			}
			else {
				if(norm == 0){
					_vector3_init_double(result, 0.0, 0.0, 0.0);
				}
				else {
					_vector3_init_double(result, (left->x/norm), (left->y/norm), (left->z/norm));
				}
				return result;
			}
		}
	}
	_GET_FUNCTION(__vector4, double)* _GET_NAME(_vector4_normalize, T)(_GET_NAME(__vector4, T)* left)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
			return NULL;
		}
		else{
			double norm = _GET_NAME(_vector4_norm, T)(left);
			__vector4_double* result = __vector4_create_double();
			if(result == NULL){
				_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
				return NULL;
			}
			else {
				if(norm == 0){
					_vector4_init_double(result, 0.0, 0.0, 0.0, 0.0);
				}
				else{
					_vector4_init_double(result, (left->x/norm), (left->y/norm), (left->z/norm), (left->t/norm));
				}
				return result;
			}
		}
	}
	_GET_FUNCTION(__vector5, double)* _GET_NAME(_vector5_normalize, T)(_GET_NAME(__vector5, T)* left)
	{
		if(left == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
			return NULL;
		}
		else{
			double norm = _GET_NAME(_vector5_norm, T)(left);
			__vector5_double* result = __vector5_create_double();
			if(result == NULL){
				_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
				return NULL;
			}
			else {
				if(norm == 0){
					_vector5_init_double(result, 0.0, 0.0, 0.0, 0.0, 0.0);
				}
				_vector5_init_double(result, (left->x/norm), (left->y/norm), (left->z/norm), (left->t/norm), (left->w/norm));
				return result;
			}
		}
	}

	void _GET_NAME(_vector2_add, T)(_GET_NAME(__vector2, T)* result, _GET_NAME(__vector2, T)* left, _GET_NAME(__vector2, T)* right)
	{
		if(left == NULL || right == NULL || result == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
				result->x = left->x + right->x;
				result->y = left->y + right->y; 
		}
	}
	void _GET_NAME(_vector3_add, T)(_GET_NAME(__vector3, T)* result, _GET_NAME(__vector3, T)* left, _GET_NAME(__vector3, T)* right)
	{
		if(left == NULL || right == NULL || result == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			result->x = left->x + right->x;
			result->y = left->y + right->y;
			result->z = left->z + right->z;
		}
	}
	void _GET_NAME(_vector4_add, T)(_GET_NAME(__vector4, T)* result, _GET_NAME(__vector4, T)* left, _GET_NAME(__vector4, T)* right)
	{
		if(left == NULL || right == NULL || result == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			result->x = left->x + right->x;
			result->y = left->y + right->y;
			result->z = left->z + right->z;
			result->t = left->t + right->t;
		}
	}
	void _GET_NAME(_vector5_add, T)(_GET_NAME(__vector5, T)* result, _GET_NAME(__vector5, T)* left, _GET_NAME(__vector5, T)* right)
	{
		if(left == NULL || right == NULL || result == NULL){
			_vector_error_id = _VECTOR_ATTEMPT_TO_ACCESS_A_NONEXISTENT_ENTITY;
		}
		else{
			result->x = left->x + right->x;
			result->y = left->y + right->y;
			result->z = left->z + right->z;
			result->t = left->t + right->t;
			result->w = left->w + right->w;
		}
	}

	
	#undef T
#endif
#undef TEMPLATE
#endif






/*
#define T
#ifdef T 
	#define T

	__vector2* _vector2_create()
	{
		static __vector2* vector;
		vector = malloc(sizeof(__vector2));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR2_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
		}

	__vector3* _vector3_create()
	{
		static __vector3* vector;
		vector = malloc(sizeof(__vector3));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR3_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	__vector4* _vector4_create()
	{
		static __vector4* vector;
		vector = malloc(sizeof(__vector4));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR4_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	__vector5* _vector5_create()
	{
		static __vector5* vector;
		vector = malloc(sizeof(__vector5));
		if(vector == NULL){
		_vector_error_id = _VECTOR_OUT_OF_MEMORY;
		return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR5_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	#undef T
	#endif

#ifdef T 
	#define T uint8_t

	__vector2* _vector2_create()
	{
		static __vector2* vector;
		vector = malloc(sizeof(__vector2));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR2_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
		}

	__vector3* _vector3_create()
	{
		static __vector3* vector;
		vector = malloc(sizeof(__vector3));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR3_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	__vector4* _vector4_create()
	{
		static __vector4* vector;
		vector = malloc(sizeof(__vector4));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR4_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	__vector5* _vector5_create()
	{
		static __vector5* vector;
		vector = malloc(sizeof(__vector5));
		if(vector == NULL){
		_vector_error_id = _VECTOR_OUT_OF_MEMORY;
		return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR5_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	#undef T
	#endif

#ifdef T 
	#define T uint64_t

	__vector2* _vector2_create()
	{
		static __vector2* vector;
		vector = malloc(sizeof(__vector2));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR2_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
		}

	__vector3* _vector3_create()
	{
		static __vector3* vector;
		vector = malloc(sizeof(__vector3));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR3_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	__vector4* _vector4_create()
	{
		static __vector4* vector;
		vector = malloc(sizeof(__vector4));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR4_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	__vector5* _vector5_create()
	{
		static __vector5* vector;
		vector = malloc(sizeof(__vector5));
		if(vector == NULL){
		_vector_error_id = _VECTOR_OUT_OF_MEMORY;
		return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR5_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	#undef T
	#endif

#ifdef T 
	#define T float

	__vector2* _vector2_create()
	{
		static __vector2* vector;
		vector = malloc(sizeof(__vector2));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR2_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
		}

	__vector3* _vector3_create()
	{
		static __vector3* vector;
		vector = malloc(sizeof(__vector3));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR3_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	__vector4* _vector4_create()
	{
		static __vector4* vector;
		vector = malloc(sizeof(__vector4));
		if(vector == NULL){
			_vector_error_id = _VECTOR_OUT_OF_MEMORY;
			return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR4_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	__vector5* _vector5_create()
	{
		static __vector5* vector;
		vector = malloc(sizeof(__vector5));
		if(vector == NULL){
		_vector_error_id = _VECTOR_OUT_OF_MEMORY;
		return NULL;
		}
		else{
			vector->_data = malloc(_VECTOR5_SIZE*sizeof(T));
			if(vector->_data == NULL){
				_vector_error_id = _VECTOR_OUT_OF_MEMORY;
				return NULL;
			}
			else{
				return vector;
			}
		}
	}

	#undef T
	#endif
#undef T

*/
#ifndef __TEMPLATES_H_
#define __TEMPLATES_H_

#define T double //Defolt type
#ifdef T 
	#include"Vectors.h"
	#include"Vectors.c"
	#undef T
#endif
#define T uint64_t
#ifdef T 
	#include"Vectors.h"
	#include"Vectors.c"
	#undef T
#endif
#define T uint8_t
#ifdef T 
	#include"Vectors.h"
	#include"vectors.c"
	#undef T 
#endif
#define T float	
#ifdef T 
	#include"Vectors.h"
	#include"vectors.c"
	#undef T 
#endif

#endif 
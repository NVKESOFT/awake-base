#ifndef METH_H
#define METH_H
/*
#include <math.h>

#ifdef METH_NO_INLINE
#define METHF static
#else
#define METHF static inline
#endif
*/
typedef struct {
	int x;
	int y;
} mth_vec2i;

typedef struct {
	float x;
	float y;
} mth_vec2f;

typedef struct {
	int x;
	int y;
	int z;
} mth_vec3i;

typedef struct {
	float x;
	float y;
	float z;
} mth_vec3f;

typedef struct {
	int x;
	int y;
	int z;
	int w;
} mth_vec4i;

typedef struct {
	float x;
	float y;
	float z;
	float w;
} mth_vec4f;

#endif

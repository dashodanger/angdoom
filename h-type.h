/* File: h-type.h */

#pragma once

#include <stdbool.h>
#include <stdint.h>

/*** Pointers to Functions of special types (for various purposes) ***/

/* A generic function takes a user data and a special data */
typedef int	(*func_gen)(void *, void *);

/* An equality testing function takes two things to compare (bool) */
typedef bool (*func_eql)(void *, void *);

/* A comparison function takes two things and to compare (-1,0,+1) */
typedef int32_t	(*func_cmp)(void *, void *);

/* A hasher takes a thing (and a max hash size) to hash (0 to siz - 1) */
typedef uint32_t (*func_hsh)(void *, uint32_t);

/* A key extractor takes a thing and returns (a pointer to) some key */
typedef void * (*func_key)(void *);
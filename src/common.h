#ifndef COMMON_H_
#define COMMON_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#define COMPILE_ASSERT(expr) static_assert(expr, #expr)
#define arraysize(a) (sizeof (a) / sizeof *(a))


#endif // COMMON_H_

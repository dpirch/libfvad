#ifndef COMMON_H_
#define COMMON_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

// replacements for WebRTC's various assert-like macros
#define COMPILE_ASSERT(expr) static_assert(expr, #expr)
#define RTC_DCHECK(expr) assert(expr)
#define RTC_DCHECK_GT(a,b) assert((a) > (b))
#define RTC_DCHECK_LT(a,b) assert((a) < (b))
#define RTC_DCHECK_LE(a,b) assert((a) <= (b))

#define arraysize(a) (sizeof (a) / sizeof *(a))


#endif // COMMON_H_

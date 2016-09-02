/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */


/*
 * This header file includes all of the fix point signal processing library (SPL) function
 * descriptions and declarations.
 * For specific function calls, see bottom of file.
 */

#ifndef WEBRTC_SPL_SIGNAL_PROCESSING_LIBRARY_H_
#define WEBRTC_SPL_SIGNAL_PROCESSING_LIBRARY_H_

#include "../common.h"

// Macros specific for the fixed point implementation
#define WEBRTC_SPL_WORD16_MAX       32767
#define WEBRTC_SPL_WORD16_MIN       -32768
#define WEBRTC_SPL_WORD32_MAX       (int32_t)0x7fffffff
#define WEBRTC_SPL_WORD32_MIN       (int32_t)0x80000000

#define WEBRTC_SPL_MUL(a, b) \
    ((int32_t) ((int32_t)(a) * (int32_t)(b)))


// inline functions:
#include "spl_inl.h"

int16_t WebRtcSpl_GetScalingSquare(int16_t* in_vector,
                                   size_t in_vector_length,
                                   size_t times);

// Divisions. Implementations collected in division_operations.c and
// descriptions at bottom of this file.
int32_t WebRtcSpl_DivW32W16(int32_t num, int16_t den);
// End: Divisions.

int32_t WebRtcSpl_Energy(int16_t* vector,
                         size_t vector_length,
                         int* scale_factor);


/************************************************************
 *
 * RESAMPLING FUNCTIONS AND THEIR STRUCTS ARE DEFINED BELOW
 *
 ************************************************************/

/*******************************************************************
 * resample_fractional.c
 * Functions for internal use in the other resample functions
 *
 * Includes the following resampling combinations
 * 48 kHz -> 32 kHz
 *
 ******************************************************************/

void WebRtcSpl_Resample48khzTo32khz(const int32_t* In, int32_t* Out, size_t K);

/*******************************************************************
 * resample_48khz.c
 *
 * Includes the following resampling combinations
 * 48 kHz ->  8 kHz
 *
 ******************************************************************/

typedef struct {
  int32_t S_48_24[8];
  int32_t S_24_24[16];
  int32_t S_24_16[8];
  int32_t S_16_8[8];
} WebRtcSpl_State48khzTo8khz;

void WebRtcSpl_Resample48khzTo8khz(const int16_t* in, int16_t* out,
                                   WebRtcSpl_State48khzTo8khz* state,
                                   int32_t* tmpmem);

void WebRtcSpl_ResetResample48khzTo8khz(WebRtcSpl_State48khzTo8khz* state);

/************************************************************
 * END OF RESAMPLING FUNCTIONS
 ************************************************************/


#endif  // WEBRTC_SPL_SIGNAL_PROCESSING_LIBRARY_H_

//
// WebRtcSpl_GetSizeInBits(...)
//
// Returns the # of bits that are needed at the most to represent the number
// specified by the |value| parameter.
//
// Input:
//      - value     : Input value
//
// Return value     : Number of bits needed to represent |value|
//

//
// WebRtcSpl_NormW32(...)
//
// Norm returns the # of left shifts required to 32-bit normalize the 32-bit
// signed number specified by the |value| parameter.
//
// Input:
//      - value     : Input value
//
// Return value     : Number of bit shifts needed to 32-bit normalize |value|
//

//
// WebRtcSpl_NormU32(...)
//
// Norm returns the # of left shifts required to 32-bit normalize the unsigned
// 32-bit number specified by the |value| parameter.
//
// Input:
//      - value     : Input value
//
// Return value     : Number of bit shifts needed to 32-bit normalize |value|
//

//
// WebRtcSpl_GetScalingSquare(...)
//
// Returns the # of bits required to scale the samples specified in the
// |in_vector| parameter so that, if the squares of the samples are added the
// # of times specified by the |times| parameter, the 32-bit addition will not
// overflow (result in int32_t).
//
// Input:
//      - in_vector         : Input vector to check scaling on
//      - in_vector_length  : Samples in |in_vector|
//      - times             : Number of additions to be performed
//
// Return value             : Number of right bit shifts needed to avoid
//                            overflow in the addition calculation
//

//
// WebRtcSpl_DivW32W16(...)
//
// Divides a int32_t |num| by a int16_t |den|.
//
// If |den|==0, (int32_t)0x7FFFFFFF is returned.
//
// Input:
//      - num       : Numerator
//      - den       : Denominator
//
// Return value     : Result of the division (as a int32_t), i.e., the
//                    integer part of num/den.
//

//
// WebRtcSpl_Energy(...)
//
// Calculates the energy of a vector
//
// Input:
//      - vector        : Vector which the energy should be calculated on
//      - vector_length : Number of samples in vector
//
// Output:
//      - scale_factor  : Number of left bit shifts needed to get the physical
//                        energy value, i.e, to get the Q0 value
//
// Return value         : Energy value in Q(-|scale_factor|)
//


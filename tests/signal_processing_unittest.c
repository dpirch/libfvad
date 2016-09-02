/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "../src/signal_processing/signal_processing_library.h"
#include "test.h"
#include <string.h>


#ifdef TEST_SPL_MACRO
void test_main() {
    // Macros with inputs.
    int B = 21;
    int a = -3;
    int b = WEBRTC_SPL_WORD32_MAX;

    EXPECT_EQ(-63, WEBRTC_SPL_MUL(a, B));
    EXPECT_EQ(-2147483645, WEBRTC_SPL_MUL(a, b));

}
#endif // TEST_SPL_MACRO


#ifdef TEST_SPL_INLINE
void test_main() {

    int32_t a32 = 111121;

    EXPECT_EQ(17, WebRtcSpl_GetSizeInBits(a32));

    EXPECT_EQ(0, WebRtcSpl_NormW32(0));
    EXPECT_EQ(31, WebRtcSpl_NormW32(-1));
    EXPECT_EQ(0, WebRtcSpl_NormW32(WEBRTC_SPL_WORD32_MIN));
    EXPECT_EQ(14, WebRtcSpl_NormW32(a32));

    EXPECT_EQ(0, WebRtcSpl_NormU32(0u));
    EXPECT_EQ(0, WebRtcSpl_NormU32(0xffffffff));
    EXPECT_EQ(15, WebRtcSpl_NormU32(a32));

}
#endif // TEST_SPL_INLINE


#ifdef TEST_SPL_MATH_OPERATIONS
void test_main() {

    int32_t num = 117;
    int32_t den = -5;


    EXPECT_EQ(-23, WebRtcSpl_DivW32W16(num, (int16_t)den));
}
#endif // TEST_SPL_MATH_OPERATIONS


#ifdef TEST_SPL_SIGNAL_PROCESSING
void test_main() {

    const size_t kVectorSize = 4;
    int A[] = {1, 2, 33, 100};
    // const int16_t kHanning[4] = { 2399, 8192, 13985, 16384 };
    int16_t b16[kVectorSize];

    // int16_t bTmp16[kVectorSize];

    int bScale = 0;

    for (size_t kk = 0; kk < kVectorSize; ++kk) {
        b16[kk] = A[kk];
    }

    for (size_t kk = 0; kk < kVectorSize; ++kk) {
        b16[kk] = A[kk];
    }
    EXPECT_EQ(11094 , WebRtcSpl_Energy(b16, kVectorSize, &bScale));
    EXPECT_EQ(0, bScale);
}
#endif // TEST_SPL_SIGNAL_PROCESSING



#ifdef TEST_SPL_RESAMPLE_48
void test_main() {

  // The test resamples 3*kBlockSize number of samples to 2*kBlockSize number
  // of samples.
  #define kBlockSize 16

  // Saturated input vector of 48 samples.
  const int32_t kVectorSaturated[3 * kBlockSize + 7] = {
     -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
     -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
     -32768, -32768, -32768, -32768, -32768, -32768, -32768, -32768,
     32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
     32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
     32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
     32767, 32767, 32767, 32767, 32767, 32767, 32767
  };

  // All values in |out_vector| should be |kRefValue32kHz|.
  const int32_t kRefValue32kHz1 = -1077493760;
  const int32_t kRefValue32kHz2 = 1077493645;

  // After bit shift with saturation, |out_vector_w16| is saturated.

  //const int16_t kRefValue16kHz1 = -32768;
  //const int16_t kRefValue16kHz2 = 32767;
  // Vector for storing output.
  int32_t out_vector[2 * kBlockSize];
  // int16_t out_vector_w16[2 * kBlockSize];

  WebRtcSpl_Resample48khzTo32khz(kVectorSaturated, out_vector, kBlockSize);

  // Comparing output values against references. The values at position
  // 12-15 are skipped to account for the filter lag.
  for (size_t i = 0; i < 12; ++i) {
    EXPECT_EQ(kRefValue32kHz1, out_vector[i]);
    //EXPECT_EQ(kRefValue16kHz1, out_vector_w16[i]);
  }
  for (size_t i = 16; i < 2 * kBlockSize; ++i) {
    EXPECT_EQ(kRefValue32kHz2, out_vector[i]);
    //EXPECT_EQ(kRefValue16kHz2, out_vector_w16[i]);
  }
}
#endif

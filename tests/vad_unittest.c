/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "vad_unittest.h"
#include "../include/fvad.h"


// Returns true if the rate and frame length combination is valid.
bool ValidRatesAndFrameLengths(int rate, int frame_length) {
  if (rate == 8000) {
    if (frame_length == 80 || frame_length == 160 || frame_length == 240) {
      return true;
    }
    return false;
  } else if (rate == 16000) {
    if (frame_length == 160 || frame_length == 320 || frame_length == 480) {
      return true;
    }
    return false;
  } else if (rate == 32000) {
    if (frame_length == 320 || frame_length == 640 || frame_length == 960) {
      return true;
    }
    return false;
  } else if (rate == 48000) {
    if (frame_length == 480 || frame_length == 960 || frame_length == 1440) {
      return true;
    }
    return false;
  }

  return false;
}


#ifdef TEST_VAD_API
void test_main() {
  // This API test runs through the APIs for all possible valid and invalid
  // combinations.

  VadInst* handle = NULL;
  int16_t zeros[kMaxFrameLength] = { 0 };

  // Construct a speech signal that will trigger the VAD in all modes. It is
  // known that (i * i) will wrap around, but that doesn't matter in this case.
  int16_t speech[kMaxFrameLength];
  for (int16_t i = 0; i < kMaxFrameLength; i++) {
    speech[i] = (i * i);
  }

  // NULL instance tests
  EXPECT_EQ(-1, fvad_Create(NULL));
  EXPECT_EQ(-1, fvad_Init(NULL));
  EXPECT_EQ(-1, fvad_set_mode(NULL, kModes[0]));
  EXPECT_EQ(-1, fvad_Process(NULL, kRates[0], speech, kFrameLengths[0]));

  // fvad_Create()
  ASSERT_EQ(0, fvad_Create(&handle));

  // Not initialized tests
  EXPECT_EQ(-1, fvad_Process(handle, kRates[0], speech, kFrameLengths[0]));
  EXPECT_EQ(-1, fvad_set_mode(handle, kModes[0]));

  // fvad_Init() test
  ASSERT_EQ(0, fvad_Init(handle));

  // fvad_set_mode() invalid modes tests. Tries smallest supported value
  // minus one and largest supported value plus one.
  EXPECT_EQ(-1, fvad_set_mode(handle, -1));
  EXPECT_EQ(-1, fvad_set_mode(handle, 4));

  // fvad_Process() tests
  // NULL speech pointer
  EXPECT_EQ(-1, fvad_Process(handle, kRates[0], NULL, kFrameLengths[0]));
  // Invalid sampling rate
  EXPECT_EQ(-1, fvad_Process(handle, 9999, speech, kFrameLengths[0]));
  // All zeros as input should work
  EXPECT_EQ(0, fvad_Process(handle, kRates[0], zeros, kFrameLengths[0]));
  for (size_t k = 0; k < kModesSize; k++) {
    // Test valid modes
    EXPECT_EQ(0, fvad_set_mode(handle, kModes[k]));
    // Loop through sampling rate and frame length combinations
    for (size_t i = 0; i < kRatesSize; i++) {
      for (size_t j = 0; j < kFrameLengthsSize; j++) {
        if (ValidRatesAndFrameLengths(kRates[i], kFrameLengths[j])) {
          EXPECT_EQ(1, fvad_Process(handle,
                                         kRates[i],
                                         speech,
                                         kFrameLengths[j]));
        } else {
          EXPECT_EQ(-1, fvad_Process(handle,
                                          kRates[i],
                                          speech,
                                          kFrameLengths[j]));
        }
      }
    }
  }

  fvad_Free(handle);
}
#endif // TEST_VAD_API


#ifdef TEST_VAD_VALID_RATES
void test_main() {
  // This test verifies valid and invalid rate/frame_length combinations. We
  // loop through some sampling rates and frame lengths from negative values to
  // values larger than possible.
  #define kNumRates 12
  const int kRates[kNumRates] = {
    -8000, -4000, 0, 4000, 8000, 8001, 15999, 16000, 32000, 48000, 48001, 96000
  };

  #define kNumFrameLengths 13
  const int kFrameLengths[kNumFrameLengths] = {
    -10, 0, 80, 81, 159, 160, 240, 320, 480, 640, 960, 1440, 2000
  };

  for (int i = 0; i < kNumRates; i++) {
    for (int j = 0; j < kNumFrameLengths; j++) {
      if (ValidRatesAndFrameLengths(kRates[i], kFrameLengths[j])) {
        EXPECT_EQ(0, fvad_ValidRateAndFrameLength(kRates[i],
                                                       kFrameLengths[j]));
      } else {
        EXPECT_EQ(-1, fvad_ValidRateAndFrameLength(kRates[i],
                                                        kFrameLengths[j]));
      }
    }
  }
}
#endif // TEST_VAD_VALID_RATES

// TODO(bjornv): Add a process test, run on file.


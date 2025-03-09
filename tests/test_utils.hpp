#pragma once

#include "catch.hpp"
#include <cmath>

// Utility functions for testing audio modules

// Compare floating point values with a tolerance
inline bool approxEqual(float a, float b, float epsilon = 1e-6f) {
  return std::fabs(a - b) < epsilon;
}

// Simulate a few samples of processing
inline void processSamples(std::function<void()> process, int numSamples = 10) {
  for (int i = 0; i < numSamples; i++) {
    process();
  }
}

// Utility to check if value is within expected range
inline bool inRange(float value, float min, float max) {
  return value >= min && value <= max;
}
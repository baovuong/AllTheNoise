/*
  ==============================================================================

    WhiteNoiseGeneration.h
    Created: 24 Mar 2021 1:01:12am
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include "NoiseGeneration.h"

class WhiteNoiseGeneration : public NoiseGeneration
{
public:
  ~WhiteNoiseGeneration() {}
  void generate(float *buffer, float level);
};
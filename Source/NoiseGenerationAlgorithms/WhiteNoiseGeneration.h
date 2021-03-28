/*
  ==============================================================================

    WhiteNoiseGeneration.h
    Created: 24 Mar 2021 1:01:12am
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "NoiseGeneration.h"

class WhiteNoiseGeneration : public NoiseGeneration
{
public:
  ~WhiteNoiseGeneration() {}
  void generate(juce::Random *random, float *buffer, int numSamples, float level);
};
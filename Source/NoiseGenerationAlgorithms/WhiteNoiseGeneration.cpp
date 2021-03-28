/*
  ==============================================================================

    WhiteNoiseGeneration.cpp
    Created: 24 Mar 2021 1:01:12am
    Author:  bvuong

  ==============================================================================
*/

#include "WhiteNoiseGeneration.h"

void WhiteNoiseGeneration::generate(juce::Random *random, float *buffer, int numSamples, float level)
{
  for (auto sample = 0; sample < numSamples; ++sample)
  {
    auto noise = random->nextFloat() * 2.0f - 1.0f;
    buffer[sample] = noise * level;
  }
}
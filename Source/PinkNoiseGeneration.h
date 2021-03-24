/*
  ==============================================================================

    PinkNoiseGeneration.h
    Created: 24 Mar 2021 5:10:08pm
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "NoiseGeneration.h"

class PinkNoiseGeneration : public NoiseGeneration
{
public:
  ~PinkNoiseGeneration() { 
    delete random;
  }
  void generate(float *buffer, int numSamples, float level);

private:
  juce::SharedResourcePointer<juce::Random> random;
};
/*
  ==============================================================================

    BrownNoiseGeneration.h
    Created: 25 Mar 2021 11:50:07pm
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include "NoiseGeneration.h"

class BrownNoiseGeneration : public NoiseGeneration
{
public:
  BrownNoiseGeneration(float step = 0.2f, float dist = 0.5f);
  ~BrownNoiseGeneration() {}
  void generate(juce::Random *random, float *buffer, int numSamples, float level);
private:
  float step;
  float dist;
};
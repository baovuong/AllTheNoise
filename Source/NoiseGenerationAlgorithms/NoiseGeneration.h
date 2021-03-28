/*
  ==============================================================================

    NoiseGeneration.h
    Created: 24 Mar 2021 12:50:50am
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class NoiseGeneration
{
public:
    virtual ~NoiseGeneration() {}
    virtual void generate(juce::Random *random, float *buffer, int numSamples, float level) = 0;
};
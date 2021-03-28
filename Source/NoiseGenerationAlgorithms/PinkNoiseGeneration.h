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
    PinkNoiseGeneration(int rowSize = 10);
    ~PinkNoiseGeneration() {}
    void generate(juce::Random *random, float *buffer, int numSamples, float level);

    // setters
    void rowSize(int value);

private:
    int _rowSize;
};
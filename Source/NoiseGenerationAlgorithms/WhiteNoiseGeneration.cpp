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
    auto numHold = (int) ((numSamples / 4) * _holdTime);
    auto currentNoise = random->nextFloat() * 2.0f - 1.0f;

    for (auto sample = 0; sample < numSamples; ++sample)
    {
        if (numHold == 0 ||  sample % numHold == 0)
            currentNoise = random->nextFloat() * 2.0f - 1.0f;
        buffer[sample] = currentNoise * level;

    }
}

void WhiteNoiseGeneration::holdTime(float value)
{
    _holdTime = value;
}
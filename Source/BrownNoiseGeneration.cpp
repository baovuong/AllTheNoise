/*
  ==============================================================================

    BrownNoiseGeneration.cpp
    Created: 25 Mar 2021 11:50:07pm
    Author:  bvuong

  ==============================================================================
*/

#include "BrownNoiseGeneration.h"

void BrownNoiseGeneration::generate(juce::Random *random, float *buffer, int numSamples, float level)
{
  // random walk algorithm
  auto step = 0.2f;
  auto position = 0.0f;
  auto dist = 0.5f;
  
  for (auto sample = 0; sample < numSamples; sample++)
  {
    if (random->nextFloat() > dist) 
    {
      position += step;
      position = juce::jmax(-1.0f, position);
    }
    else 
    {
      position -= step;
      position = juce::jmin(1.0f, position);
    }
    buffer[sample] = position * level;
  }
}
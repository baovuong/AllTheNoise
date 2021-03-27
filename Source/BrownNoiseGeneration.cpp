/*
  ==============================================================================

    BrownNoiseGeneration.cpp
    Created: 25 Mar 2021 11:50:07pm
    Author:  bvuong

  ==============================================================================
*/

#include "BrownNoiseGeneration.h"

BrownNoiseGeneration::BrownNoiseGeneration(float step, float dist)
{
  this->step = step;
  this->dist = dist;
}

void BrownNoiseGeneration::generate(juce::Random *random, float *buffer, int numSamples, float level)
{
  // random walk algorithm
  auto position = 0.0f;
  
  for (auto sample = 0; sample < numSamples; sample++)
  {
    position = random->nextFloat() > this->dist 
      ? juce::jmax(-1.0f, position + this->step) 
      : juce::jmin(1.0f, position - this->step);
    buffer[sample] = position * level;
  }
}
/*
  ==============================================================================

    PinkNoiseGeneration.cpp
    Created: 24 Mar 2021 2:29:45pm
    Author:  bvuong

  ==============================================================================
*/

#include "PinkNoiseGeneration.h"


float nextValue(juce::Random *random, int rowSize)
{
  float bound = 1.0f / rowSize;
  return random->nextFloat() * 2 * bound - bound;
}

PinkNoiseGeneration::PinkNoiseGeneration(int rowSize)
{
  this->rowSize = rowSize;
}

void PinkNoiseGeneration::generate(juce::Random *random, float *buffer, int numSamples, float level)
{
  // implementation of the Voss algorithm
  int max_key = (1 << this->rowSize) - 1;
  int key = 0;
  float white_values[this->rowSize];

  for (int i = 0; i < this->rowSize; i++)
    white_values[i] = nextValue(random, this->rowSize) * level;

  int last_key = key;
  float sum;

  for (int sample = 0; sample < numSamples; sample++)
  {
    key++;
    if (key > max_key)
      key = 0;

    int diff = last_key ^ key;
    sum = 0;
    for (int i = 0; i < this->rowSize; i++)
    {
      if (diff & (1 << i))
        white_values[i] = nextValue(random, this->rowSize)  * level;
      sum += white_values[i];
    }
    buffer[sample] = sum;
  }
}
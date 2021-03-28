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
  this->_rowSize = rowSize;
}

void PinkNoiseGeneration::generate(juce::Random *random, float *buffer, int numSamples, float level)
{
  // implementation of the Voss algorithm
  int max_key = (1 << this->_rowSize) - 1;
  int key = 0;
  float white_values[this->_rowSize];

  for (int i = 0; i < this->_rowSize; i++)
    white_values[i] = nextValue(random, this->_rowSize) * level;

  int last_key = key;
  float sum;

  for (int sample = 0; sample < numSamples; sample++)
  {
    key++;
    if (key > max_key)
      key = 0;

    int diff = last_key ^ key;
    sum = 0;
    for (int i = 0; i < this->_rowSize; i++)
    {
      if (diff & (1 << i))
        white_values[i] = nextValue(random, this->_rowSize)  * level;
      sum += white_values[i];
    }
    buffer[sample] = sum;
  }
}


// setters
void PinkNoiseGeneration::rowSize(int value)
{
  this->_rowSize = value;
}
/*
  ==============================================================================

    PinkNoiseGeneration.cpp
    Created: 24 Mar 2021 2:29:45pm
    Author:  bvuong

  ==============================================================================
*/

#include "PinkNoiseGeneration.h"

void PinkNoiseGeneration::generate(float *buffer, int numSamples, float level)
{
  // implementation of the Voss algorithm
  int max_key = 0x1f;
  int key = 0;
  float white_values[5];

  for (int i = 0; i < 5; i++)
    white_values[i] = (random->nextFloat() * 2.0f - 1.0f) * level;

  int last_key = key;
  float sum;

  for (int sample = 0; sample < numSamples; sample++)
  {
    key++;
    if (key > max_key)
      key = 0;

    int diff = last_key ^ key;
    sum = 0;
    for (int i = 0; i < 5; i++)
    {
      if (diff & (1 << i))
        white_values[i] = (random->nextFloat() * 2.0f - 1.0f) * level;
      sum += white_values[i];
    }
    buffer[sample] = sum;
  }
}
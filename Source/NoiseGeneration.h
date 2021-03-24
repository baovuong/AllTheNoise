/*
  ==============================================================================

    NoiseGeneration.h
    Created: 24 Mar 2021 12:50:50am
    Author:  bvuong

  ==============================================================================
*/

#pragma once

class NoiseGeneration
{
public:
  virtual ~NoiseGeneration() {}
  virtual void generate(float *buffer, float level) = 0;
};
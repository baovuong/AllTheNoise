/*
  ==============================================================================

    DecibelSlider.cpp
    Created: 28 Mar 2021 12:41:58am
    Author:  bvuong

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DecibelSlider.h"

//==============================================================================
DecibelSlider::DecibelSlider()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
}

DecibelSlider::~DecibelSlider()
{
}

juce::String DecibelSlider::getTextFromValue(double value)
{
    return juce::Decibels::toString(value);
}

double DecibelSlider::getValueFromText(const juce::String &text)
{
    auto minusInfinitydB = -100.0;

    auto decibelText = text.upToFirstOccurrenceOf("dB", false, false).trim(); // [1]

    return decibelText.equalsIgnoreCase("-INF") ? minusInfinitydB
                                                : decibelText.getDoubleValue(); // [2]
}

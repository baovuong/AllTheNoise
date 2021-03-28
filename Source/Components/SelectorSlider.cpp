/*
  ==============================================================================

    SelectorSlider.cpp
    Created: 28 Mar 2021 11:18:49am
    Author:  bvuong

  ==============================================================================
*/

#include "SelectorSlider.h"

SelectorSlider::SelectorSlider()
{

}

SelectorSlider::~SelectorSlider()
{

}

juce::String SelectorSlider::getTextFromValue (double value)
{
    auto index = (int) value;
    return this->options[index];
}

double SelectorSlider::getValueFromText (const juce::String& text)
{
    return this->options.indexOf(text);
}

void SelectorSlider::addOption(const juce::String& option)
{
    this->options.add(option);

    // update slider range
    if (this->options.size() > 1)
        setRange(0,this->options.size()-1, 1);
}
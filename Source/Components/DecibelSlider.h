/*
  ==============================================================================

    DecibelSlider.h
    Created: 28 Mar 2021 12:41:58am
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class DecibelSlider  : public juce::Slider
{
public:
    DecibelSlider();
    ~DecibelSlider() override;
    
    juce::String getTextFromValue (double value) override;
    double getValueFromText (const juce::String& text) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DecibelSlider)
};

/*
  ==============================================================================

    SelectorSlider.h
    Created: 28 Mar 2021 11:18:49am
    Author:  bvuong

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

//==============================================================================
/*
*/
class SelectorSlider  : public juce::Slider
{
public:
    SelectorSlider();
    ~SelectorSlider() override;
    
    juce::String getTextFromValue (double value) override;
    double getValueFromText (const juce::String& text) override;

    void addOption(const juce::String& option);

private:
    juce::StringArray options;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SelectorSlider)
};

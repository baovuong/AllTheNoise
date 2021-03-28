/*
  ==============================================================================

    GlobalPanelComponent.h
    Created: 27 Mar 2021 8:22:27pm
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class GlobalPanelComponent  : public juce::Component, public juce::Slider::Listener, public juce::ChangeBroadcaster
{
public:
    GlobalPanelComponent();
    ~GlobalPanelComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override;

    // getting values
    float getVolume();
    int getColorType();

private:

    juce::Label volumeLabel;
    juce::Label colorTypeLabel;

    juce::Slider colorTypeSlider;
    juce::Slider volumeSlider;

    juce::StringArray colorNames;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GlobalPanelComponent)
};

/*
  ==============================================================================

    WhiteNoisePanelComponent.h
    Created: 27 Mar 2021 8:21:59pm
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class WhiteNoisePanelComponent  : public juce::Component, public juce::ChangeBroadcaster, public juce::Slider::Listener
{
public:
    WhiteNoisePanelComponent();
    ~WhiteNoisePanelComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override;

    float getHoldTime();


private:
    juce::Label panelLabel;
    juce::Label holdTimeLabel;

    juce::Slider holdTimeKnob;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WhiteNoisePanelComponent)
};

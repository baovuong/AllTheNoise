/*
  ==============================================================================

    BrownNoisePanelComponent.h
    Created: 27 Mar 2021 8:22:13pm
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class BrownNoisePanelComponent  : public juce::Component, public juce::Slider::Listener, public juce::ChangeBroadcaster
{
public:
    BrownNoisePanelComponent();
    ~BrownNoisePanelComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override;

    float getStepSize();
    float getDistribution();

private:
    juce::Label panelLabel;
    juce::Label stepSizeLabel;
    juce::Label distributionLabel;
    
    juce::Slider stepSizeKnob;
    juce::Slider distributionKnob;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BrownNoisePanelComponent)
};

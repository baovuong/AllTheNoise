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
class WhiteNoisePanelComponent  : public juce::Component
{
public:
    WhiteNoisePanelComponent();
    ~WhiteNoisePanelComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Label panelLabel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WhiteNoisePanelComponent)
};

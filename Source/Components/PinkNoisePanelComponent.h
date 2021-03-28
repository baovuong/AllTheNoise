/*
  ==============================================================================

    PinkNoisePanelComponent.h
    Created: 27 Mar 2021 8:20:58pm
    Author:  bvuong

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class PinkNoisePanelComponent  : public juce::Component
{
public:
    PinkNoisePanelComponent();
    ~PinkNoisePanelComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PinkNoisePanelComponent)
};

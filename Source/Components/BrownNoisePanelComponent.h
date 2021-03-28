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
class BrownNoisePanelComponent  : public juce::Component
{
public:
    BrownNoisePanelComponent();
    ~BrownNoisePanelComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BrownNoisePanelComponent)
};

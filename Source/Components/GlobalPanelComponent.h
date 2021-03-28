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
class GlobalPanelComponent  : public juce::Component
{
public:
    GlobalPanelComponent();
    ~GlobalPanelComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GlobalPanelComponent)
};

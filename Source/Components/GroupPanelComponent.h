/*
  ==============================================================================

    GroupPanelComponent.h
    Created: 28 Mar 2021 6:41:19pm
    Author:  vqbao

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class GroupPanelComponent  : public juce::Component
{
public:
    GroupPanelComponent();
    ~GroupPanelComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void addPanel(juce::Component& panel);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GroupPanelComponent)
};

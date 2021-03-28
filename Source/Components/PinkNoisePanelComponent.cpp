/*
  ==============================================================================

    PinkNoisePanelComponent.cpp
    Created: 27 Mar 2021 8:20:58pm
    Author:  bvuong

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PinkNoisePanelComponent.h"

//==============================================================================
PinkNoisePanelComponent::PinkNoisePanelComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

PinkNoisePanelComponent::~PinkNoisePanelComponent()
{
}

void PinkNoisePanelComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("PinkNoisePanelComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void PinkNoisePanelComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

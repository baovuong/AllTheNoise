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

    addAndMakeVisible(panelLabel);
    panelLabel.setText("Pink", juce::dontSendNotification);
    panelLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(numRowKnob);
    numRowKnob.setRange(1, 10, 1);
    numRowKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    numRowKnob.addListener(this);

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

    // g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    // g.setColour (juce::Colours::grey);
    // g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    // g.setColour (juce::Colours::white);
    // g.setFont (14.0f);
    // g.drawText ("PinkNoisePanelComponent", getLocalBounds(),
    //             juce::Justification::centred, true);   // draw some placeholder text
}

void PinkNoisePanelComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    juce::Grid grid;

    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;

    grid.templateRows = { Track(Fr(1)) };
    grid.templateColumns = { Track(Fr(1)), Track(Fr(1)) };

    grid.items = {
        juce::GridItem(panelLabel), juce::GridItem(numRowKnob)
    };

    grid.performLayout(getLocalBounds());
}

int PinkNoisePanelComponent::getNumRows()
{
    return (int)numRowKnob.getValue();
}

void PinkNoisePanelComponent::sliderValueChanged(juce::Slider* slider)
{
    sendChangeMessage();
}
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
    panelLabel.setFont (juce::Font (32.0f, juce::Font::bold));
    panelLabel.setJustificationType(juce::Justification::left);


    addAndMakeVisible(numRowKnob);
    numRowKnob.setRange(1, 10, 1);
    numRowKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    numRowKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    numRowKnob.addListener(this);

    addAndMakeVisible(numRowLabel);
    numRowLabel.setText("Noise Layers", juce::NotificationType::dontSendNotification);
    numRowLabel.attachToComponent(&numRowKnob, false);
    numRowLabel.setJustificationType(juce::Justification::centred);
}

PinkNoisePanelComponent::~PinkNoisePanelComponent()
{
}

void PinkNoisePanelComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
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
        juce::GridItem(panelLabel).withMargin(juce::GridItem::Margin(0,0,0,20)), 
        juce::GridItem(numRowKnob).withMargin(juce::GridItem::Margin(22,0,8,0))
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
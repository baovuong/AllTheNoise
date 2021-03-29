/*
  ==============================================================================

    BrownNoisePanelComponent.cpp
    Created: 27 Mar 2021 8:22:13pm
    Author:  bvuong

  ==============================================================================
*/

#include <JuceHeader.h>
#include "BrownNoisePanelComponent.h"

//==============================================================================
BrownNoisePanelComponent::BrownNoisePanelComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    addAndMakeVisible(panelLabel);
    panelLabel.setText("Brown", juce::dontSendNotification);
    panelLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(stepSizeKnob);
    stepSizeKnob.setRange(0, 1);
    stepSizeKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    stepSizeKnob.addListener(this);

    addAndMakeVisible(distributionKnob);
    distributionKnob.setRange(0, 1);
    distributionKnob.setValue(0.5);
    distributionKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    distributionKnob.addListener(this);
}

BrownNoisePanelComponent::~BrownNoisePanelComponent()
{
}

void BrownNoisePanelComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    //g.setColour (juce::Colours::grey);
    //g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    //g.setColour (juce::Colours::white);
    //g.setFont (14.0f);
    //g.drawText ("BrownNoisePanelComponent", getLocalBounds(),
    //            juce::Justification::centred, true);   // draw some placeholder text
}

void BrownNoisePanelComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    juce::Grid grid;

    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;

    grid.templateRows = { Track(Fr(1)) };
    grid.templateColumns = { Track(Fr(1)), Track(Fr(1)), Track(Fr(1)) };

    grid.items = {
        juce::GridItem(panelLabel), juce::GridItem(stepSizeKnob), juce::GridItem(distributionKnob)
    };

    grid.performLayout(getLocalBounds());
}

void BrownNoisePanelComponent::sliderValueChanged(juce::Slider* slider)
{
    sendChangeMessage();
}

float BrownNoisePanelComponent::getStepSize()
{
    return stepSizeKnob.getValue();
}

float BrownNoisePanelComponent::getDistribution()
{
    return distributionKnob.getValue();
}

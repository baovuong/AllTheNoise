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
    panelLabel.setJustificationType(juce::Justification::left);

    addAndMakeVisible(stepSizeKnob);
    stepSizeKnob.setRange(0, 1);
    stepSizeKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    stepSizeKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    stepSizeKnob.addListener(this);

    addAndMakeVisible(stepSizeLabel);
    stepSizeLabel.setText("Step Size", juce::NotificationType::dontSendNotification);
    stepSizeLabel.attachToComponent(&stepSizeKnob, false);
    stepSizeLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(distributionKnob);
    distributionKnob.setRange(0, 1);
    distributionKnob.setValue(0.5);
    distributionKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    distributionKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    distributionKnob.addListener(this);

    addAndMakeVisible(distributionLabel);
    distributionLabel.setText("Distribution", juce::NotificationType::dontSendNotification);
    distributionLabel.attachToComponent(&distributionKnob, false);
    distributionLabel.setJustificationType(juce::Justification::centred);
}

BrownNoisePanelComponent::~BrownNoisePanelComponent()
{
}

void BrownNoisePanelComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
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
        juce::GridItem(panelLabel).withMargin(juce::GridItem::Margin(0,0,0,20)), 
        juce::GridItem(stepSizeKnob).withMargin(juce::GridItem::Margin(22,0,8,0)), 
        juce::GridItem(distributionKnob).withMargin(juce::GridItem::Margin(22,0,8,0))
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

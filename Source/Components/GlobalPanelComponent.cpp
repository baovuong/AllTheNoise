/*
  ==============================================================================

    GlobalPanelComponent.cpp
    Created: 27 Mar 2021 8:22:27pm
    Author:  bvuong

  ==============================================================================
*/

#include <JuceHeader.h>
#include "GlobalPanelComponent.h"

//==============================================================================
GlobalPanelComponent::GlobalPanelComponent()
{
    addAndMakeVisible(volumeSlider);
    volumeSlider.setRange(-100, 0);
    volumeSlider.setValue (juce::Decibels::gainToDecibels (-50));
    volumeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    volumeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 200, 20);
    volumeSlider.addListener(this);

    addAndMakeVisible(volumeLabel);
    volumeLabel.setText("Volume", juce::dontSendNotification);
    volumeLabel.attachToComponent(&volumeSlider, false);
    volumeLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(colorTypeSlider);
    colorTypeSlider.addOption("White");
    colorTypeSlider.addOption("Pink");
    colorTypeSlider.addOption("Brown");
    colorTypeSlider.addOption("Grey");
    colorTypeSlider.addOption("Blue");
    colorTypeSlider.addOption("Violet");
    colorTypeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    colorTypeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 200, 20);
    colorTypeSlider.addListener(this);

    addAndMakeVisible(colorTypeLabel);
    colorTypeLabel.setText("Color", juce::dontSendNotification);
    colorTypeLabel.attachToComponent(&colorTypeSlider, false);
    colorTypeLabel.setJustificationType(juce::Justification::centred);
}

GlobalPanelComponent::~GlobalPanelComponent()
{
}

void GlobalPanelComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
}

void GlobalPanelComponent::resized()
{
    juce::Grid grid;

    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;

    grid.templateRows = { Track(Fr(1)), Track(Fr(1)) };
    grid.templateColumns = { Track(Fr(1)) };

    grid.items = {
        juce::GridItem(colorTypeSlider).withMargin(juce::GridItem::Margin(25)),
        juce::GridItem(volumeSlider).withMargin(juce::GridItem::Margin(25))
    };

    grid.performLayout(getLocalBounds());
}

void GlobalPanelComponent::sliderValueChanged(juce::Slider* slider)
{
    sendChangeMessage();
}

float GlobalPanelComponent::getVolume()
{
    return juce::Decibels::decibelsToGain ((float) volumeSlider.getValue());
}

int GlobalPanelComponent::getColorType()
{
    return (int)colorTypeSlider.getValue();
}

/*
  ==============================================================================

    WhiteNoisePanelComponent.cpp
    Created: 27 Mar 2021 8:21:59pm
    Author:  bvuong

  ==============================================================================
*/

#include <JuceHeader.h>
#include "WhiteNoisePanelComponent.h"

//==============================================================================
WhiteNoisePanelComponent::WhiteNoisePanelComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    addAndMakeVisible(panelLabel);
    panelLabel.setText("White", juce::dontSendNotification);
    panelLabel.setFont (juce::Font (32.0f, juce::Font::bold));
    panelLabel.setJustificationType(juce::Justification::left);

    addAndMakeVisible(holdTimeKnob);
    holdTimeKnob.setRange(0, 1);
    holdTimeKnob.setValue(0.5);
    holdTimeKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    holdTimeKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    holdTimeKnob.addListener(this);

    addAndMakeVisible(holdTimeLabel);
    holdTimeLabel.setText("Hold Time", juce::NotificationType::dontSendNotification);
    holdTimeLabel.attachToComponent(&holdTimeKnob, false);
    holdTimeLabel.setJustificationType(juce::Justification::centred);

}

WhiteNoisePanelComponent::~WhiteNoisePanelComponent()
{
}

void WhiteNoisePanelComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
}

void WhiteNoisePanelComponent::resized()
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
        juce::GridItem(holdTimeKnob).withMargin(juce::GridItem::Margin(22,0,8,0))

    };

    grid.performLayout(getLocalBounds());
}

void WhiteNoisePanelComponent::sliderValueChanged(juce::Slider* slider)
{
    sendChangeMessage();
}

float WhiteNoisePanelComponent::getHoldTime()
{
    return holdTimeKnob.getValue();
}
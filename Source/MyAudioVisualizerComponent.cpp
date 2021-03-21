/*
  ==============================================================================

    MyAudioVisualizerComponent.cpp
    Created: 21 Mar 2021 12:47:11pm
    Author:  vqbao

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MyAudioVisualizerComponent.h"

//==============================================================================
MyAudioVisualizerComponent::MyAudioVisualizerComponent() : juce::AudioVisualiserComponent(2)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setBufferSize(512);
    setSamplesPerBlock(256);
    setColours(juce::Colours::black, juce::Colours::indianred);

}

MyAudioVisualizerComponent::~MyAudioVisualizerComponent()
{
}

void MyAudioVisualizerComponent::paint (juce::Graphics& g)
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
    g.drawText ("MyAudioVisualizerComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void MyAudioVisualizerComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

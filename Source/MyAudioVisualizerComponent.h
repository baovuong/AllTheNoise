/*
  ==============================================================================

    MyAudioVisualizerComponent.h
    Created: 21 Mar 2021 12:47:11pm
    Author:  vqbao

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MyAudioVisualizerComponent  : public juce::AudioVisualiserComponent
{
public:
    MyAudioVisualizerComponent();
    ~MyAudioVisualizerComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyAudioVisualizerComponent)
};

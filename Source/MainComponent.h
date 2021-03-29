#pragma once

#include <JuceHeader.h>

#include "NoiseGenerationAlgorithms/NoiseGeneration.h"
#include "NoiseGenerationAlgorithms/WhiteNoiseGeneration.h"
#include "NoiseGenerationAlgorithms/PinkNoiseGeneration.h"
#include "NoiseGenerationAlgorithms/BrownNoiseGeneration.h"

#include "Components/WhiteNoisePanelComponent.h"
#include "Components/PinkNoisePanelComponent.h"
#include "Components/BrownNoisePanelComponent.h"
#include "Components/GlobalPanelComponent.h"
#include "Components/GroupPanelComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent, public juce::ChangeListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

    void changeListenerCallback(juce::ChangeBroadcaster* source) override;

    enum noiseType { white, pink, brown, grey, blue, violet };

private:
    //==============================================================================
    // Your private member variables go here...juce-framework/JUCEjuce-framework/JUCEjuce-framework/JUCE

    juce::Random random;

    GlobalPanelComponent globalPanel;
    GroupPanelComponent groupPanel;
    PinkNoisePanelComponent pinkNoisePanel;
    BrownNoisePanelComponent brownNoisePanel;
    WhiteNoisePanelComponent whiteNoisePanel;
    
    NoiseGeneration *noiseGeneration;
    juce::SharedResourcePointer<WhiteNoiseGeneration> whiteNoiseGeneration;
    juce::SharedResourcePointer<PinkNoiseGeneration> pinkNoiseGeneration;
    juce::SharedResourcePointer<BrownNoiseGeneration> brownNoiseGeneration;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

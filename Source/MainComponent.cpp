#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.

    noiseGeneration = whiteNoiseGeneration;
    
    addAndMakeVisible(globalPanel);
    globalPanel.addChangeListener(this);

    addAndMakeVisible(groupPanel);

    groupPanel.addPanel(&whiteNoisePanel);
    groupPanel.addPanel(&pinkNoisePanel);
    groupPanel.addPanel(&brownNoisePanel);

    pinkNoisePanel.addChangeListener(this);
    brownNoisePanel.addChangeListener(this);

    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (0, 2);
    }
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()

    //visualizer.clear();
    juce::String message;
    message << "Preparing to play audio...\n";
    message << "samplesPerBlockExpected = " << samplesPerBlockExpected << "\n";
    message << "sampleRate = " << sampleRate;
    juce::Logger::getCurrentLogger()->writeToLog(message);
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!
    auto level = (float) globalPanel.getVolume();

    for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
    {
        auto *buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
        noiseGeneration->generate(&random, buffer, bufferToFill.numSamples, level);
    }
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

    juce::Grid grid;

    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;

    grid.templateRows = { Track(Fr(1)) };
    grid.templateColumns = { Track(Fr(2)), Track(Fr(1)) };

    grid.items = { 
        juce::GridItem(groupPanel), juce::GridItem(globalPanel)
    };
    grid.performLayout(getLocalBounds());
}

void MainComponent::changeListenerCallback(juce::ChangeBroadcaster* source)
{
    if (source == &globalPanel)
    {
        // update color type
        switch (globalPanel.getColorType())
        {
        case 0:
            // White
            noiseGeneration = whiteNoiseGeneration;
            break;
        case 1:
            // Pink
            noiseGeneration = pinkNoiseGeneration;
            break;
        case 2:
            // Brown
            noiseGeneration = brownNoiseGeneration;
            break;
        case 3:
            // Grey
            break;
        case 4:
            // Blue
            break;
        case 5:
            // Violet
            break;
        default:
            break;
        }
    }
    else if (source == &pinkNoisePanel)
    {
        // update pink noise parameters
        pinkNoiseGeneration->rowSize(pinkNoisePanel.getNumRows());
    }
    else if (source == &brownNoisePanel)
    {
        // update brown noise parameters
        brownNoiseGeneration->dist(brownNoisePanel.getDistribution());
        brownNoiseGeneration->step(brownNoisePanel.getStepSize());
    }
}

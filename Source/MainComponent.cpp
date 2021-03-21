#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    
    addAndMakeVisible(colorSlider);
    colorSlider.setRange(0, 5, 1);
    colorSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    colorSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, getWidth() / 4, 20);
    colorSlider.addListener(this);

    addAndMakeVisible(ampSlider);
    ampSlider.setRange(0.0, 1.0);
    ampSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, getWidth() / 4, 20);
    ampSlider.addListener(this);

    addAndMakeVisible(colorLabel);
    colorLabel.setText("Color", juce::dontSendNotification);
    colorLabel.attachToComponent(&colorSlider, false);
    colorLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(ampLabel);
    ampLabel.setText("Volume", juce::dontSendNotification);
    ampLabel.attachToComponent(&ampSlider, false);
    ampLabel.setJustificationType(juce::Justification::centred);

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
    auto level = (float) ampSlider.getValue();

    for (auto channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel)
    {
        auto *buffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);

        for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            auto noise = random.nextFloat() * 2.0f - 1.0f;
            buffer[sample] = noise * level;
        }
    }

    //visualizer.pushBuffer(bufferToFill);
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

    auto upperCorner = 40;
    auto width = getWidth() / 3 - 20;
    auto height = getHeight() / 2 - 45;

    colorSlider.setBounds(upperCorner, upperCorner, width, height);
    ampSlider.setBounds(upperCorner, colorSlider.getBounds().getBottom() + 30, width, height);
}

void MainComponent::sliderValueChanged(juce::Slider* slider)
{
}

/*
  ==============================================================================

    GroupPanelComponent.cpp
    Created: 28 Mar 2021 6:41:19pm
    Author:  vqbao

  ==============================================================================
*/

#include <JuceHeader.h>
#include "GroupPanelComponent.h"

//==============================================================================
GroupPanelComponent::GroupPanelComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

GroupPanelComponent::~GroupPanelComponent()
{
    panels.clear(false);
}

void GroupPanelComponent::paint (juce::Graphics& g)
{
}

void GroupPanelComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    juce::FlexBox fb;
    fb.flexDirection = juce::FlexBox::Direction::column;
    fb.flexWrap = juce::FlexBox::Wrap::wrap;                        // [2]
    fb.justifyContent = juce::FlexBox::JustifyContent::flexStart;      // [3]
    fb.alignContent = juce::FlexBox::AlignContent::flexStart;          // [4]
    
    for (auto *panel : this->panels) 
        fb.items.add(juce::FlexItem(*panel).withMinHeight(getHeight()/this->panels.size()).withMinWidth(getWidth()).withFlex(1));
    
    fb.performLayout(getLocalBounds().toFloat());

}

void GroupPanelComponent::addPanel(juce::Component *panel)
{
    addAndMakeVisible(*panel);
    this->panels.add(panel);
}

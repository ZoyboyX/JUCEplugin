#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class SampleJucePluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SampleJucePluginAudioProcessorEditor (SampleJucePluginAudioProcessor&);
    ~SampleJucePluginAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SampleJucePluginAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SampleJucePluginAudioProcessorEditor)
};


// PluginEditor.cpp
#include "PluginEditor.h"

SampleJucePluginAudioProcessorEditor::SampleJucePluginAudioProcessorEditor (SampleJucePluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 300);
}

SampleJucePluginAudioProcessorEditor::~SampleJucePluginAudioProcessorEditor() {}

void SampleJucePluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::darkgrey);
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Sample JUCE Plugin", getLocalBounds(), juce::Justification::centred, 1);
}

void SampleJucePluginAudioProcessorEditor::resized() {}

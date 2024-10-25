/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "LowerPanel.h"

//==============================================================================
/**
*/

//creating a custom component by definiting a new struct and inheriting from the component class
//this will serve as a lower panel to house some controls

//struct LowerPanel : juce::Component {
//
//
//    void paint(juce::Graphics& g) {
//        g.fillAll(juce::Colours::darkgrey);
//    }
//
//};

class ConvolutionAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    ConvolutionAudioProcessorEditor(ConvolutionAudioProcessor&);
    ~ConvolutionAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ConvolutionAudioProcessor& audioProcessor;
    juce::Image background;

    // Arrow buttons for cycling systems
    juce::ArrowButton leftArrowButton{"left", 0.5, juce::Colours::floralwhite};
    juce::ArrowButton rightArrowButton{"right", 0.0, juce::Colours::floralwhite};

    // Other components...
    juce::ImageComponent logo;
    juce::ComboBox systemSelector;

    //using Attachments to link the UI components to the APVTS
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> outputLevelAttachment;
    //std::unique_ptr<juce::AudioProcessorValueTreeState::>refLevelAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> bypassAttachment;

    
    LowerPanel lowerPanel;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ConvolutionAudioProcessorEditor)



};

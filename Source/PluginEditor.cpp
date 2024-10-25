/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"




//==============================================================================
ConvolutionAudioProcessorEditor::ConvolutionAudioProcessorEditor (ConvolutionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    //setResizable(true, true); // Make the editor resizable
    //setResizeLimits(400, 300, 800, 600); // Set the limits for resizing
    setSize (660, 543); //initial window size

    // Add components to the editor
    
    addAndMakeVisible(leftArrowButton);
    addAndMakeVisible(rightArrowButton);
    addAndMakeVisible(logo);
    addAndMakeVisible(systemSelector);

    //Create the attachments to link UI to parameters
    outputLevelAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "outputLevel", lowerPanel.getKnob());
    bypassAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.apvts, "outputLevel", lowerPanel.getBypass());


 
    addAndMakeVisible(lowerPanel);
   
    resized(); //fix for buttons not appearing when application opened

   

}

ConvolutionAudioProcessorEditor::~ConvolutionAudioProcessorEditor()
{
}

//==============================================================================
void ConvolutionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    // default code commented out
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    //g.setColour (juce::Colours::white);
    //g.setFont ((15.0f));
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);

    
    background = juce::ImageCache::getFromMemory(BinaryData::testimagethree_jpg, BinaryData::testimagethree_jpgSize);
    g.drawImageWithin(background, 0, 0, getWidth(), getHeight(), juce::RectanglePlacement::stretchToFit);

}

void ConvolutionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto bounds = getLocalBounds();
    auto lowerPanelHeight = getHeight() * 0.2;
    // Define the lower panel bounds
    leftArrowButton.setBoundsRelative(0.05f, 0.4f, 0.05f, 0.05f);
    rightArrowButton.setBoundsRelative(0.9f, 0.4f, 0.05f, 0.05f);
    systemSelector.setBoundsRelative(0.85f, 0.1f, 0.1f, 0.05f);
    lowerPanel.setBounds(bounds.removeFromBottom(lowerPanelHeight));
    juce::Rectangle a = getScreenBounds();
    juce::Rectangle b = lowerPanel.getLocalBounds();

    
    

    
   
}





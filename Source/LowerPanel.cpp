/*
  ==============================================================================

    LowerPanel.cpp
    Created: 30 Aug 2024 10:53:58pm
    Author:  ivanp

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LowerPanel.h"


//==============================================================================
LowerPanel::LowerPanel()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

     //Add these components to the lower Panel
    
    addAndMakeVisible(knob);
    addAndMakeVisible(refLevel);
    addAndMakeVisible(bypass);
    addAndMakeVisible(l_bypass);
    addAndMakeVisible(l_refLevel);



    // Adjust the knob's text box style to bring it closer and display 2 decimal places

 
    knob.setNumDecimalPlacesToDisplay(2); // Set 2 decimal places for the display
    l_bypass.attachToComponent(&bypass,false);
    l_refLevel.attachToComponent(&refLevel, false);

    // Bypass and Ref Level Labels: Make them non-editable and center them above the components
    l_bypass.setJustificationType(juce::Justification::topLeft);
    l_refLevel.setJustificationType(juce::Justification::centred);

    // Set up the refLevelLabel
    refLevel.setText("1.00", juce::dontSendNotification); // Initial value as a string
    refLevel.setJustificationType(juce::Justification::centred);
    refLevel.setEditable(true, true, false); // Editable on single click
    refLevel.onTextChange = [this]()
        {
            // You can add any callback functionality here if you want to respond to text changes.
        };
    

}

LowerPanel::~LowerPanel()
{
}

void LowerPanel::paint (juce::Graphics& g)
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

void LowerPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    
    //x,y, width, height
    refLevel.setBoundsRelative(0.66f, 0.5f, 0.2f, 0.25f);
    knob.setBoundsRelative(0.4f, 0.17f, 0.2f, 0.8f);
    bypass.setBoundsRelative(0.25f, 0.5f, 0.25f, 0.25f);

    int h = knob.getParentHeight(); //rn 108

}

//getters for UI elements

juce::Slider& LowerPanel::getKnob() {
    return knob;
}

juce::Slider& LowerPanel::getBypass() {
    return bypass;
}

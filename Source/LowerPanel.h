/*
  ==============================================================================

    LowerPanel.h
    Created: 30 Aug 2024 10:53:58pm
    Author:  ivanp

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class LowerPanel  : public juce::Component
{
public:
    LowerPanel();
    ~LowerPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    juce::Slider& getKnob();
    juce::Slider& getBypass();
    
  

private:

    juce::Slider knob{ juce::Slider::SliderStyle::RotaryVerticalDrag,juce::Slider::TextEntryBoxPosition::NoTextBox };
    juce::Label refLevel;
    juce::ToggleButton bypass;
   
    juce::Label l_bypass{ "bypass", "Bypass"};
    juce::Label l_refLevel{ "refLevel", "Reference Level"}; //lil dangerous perhaps?

    



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LowerPanel)
};

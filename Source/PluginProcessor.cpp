/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ConvolutionAudioProcessor::ConvolutionAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                    //initialisation using member initialiser lists
                       ), apvts(*this, nullptr, "parameters", createParameterLayout())
#endif
{
}

ConvolutionAudioProcessor::~ConvolutionAudioProcessor()
{
}

//==============================================================================
const juce::String ConvolutionAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ConvolutionAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ConvolutionAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ConvolutionAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double ConvolutionAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ConvolutionAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ConvolutionAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ConvolutionAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String ConvolutionAudioProcessor::getProgramName (int index)
{
    return {};
}

void ConvolutionAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void ConvolutionAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void ConvolutionAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ConvolutionAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void ConvolutionAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool ConvolutionAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* ConvolutionAudioProcessor::createEditor()
{
    return new ConvolutionAudioProcessorEditor (*this);
}

//==============================================================================
void ConvolutionAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void ConvolutionAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}


//implement the createParameterLayout() function here
juce::AudioProcessorValueTreeState::ParameterLayout ConvolutionAudioProcessor::createParameterLayout()
{
    //creating a vector to hold pointers to AudioParamter Objects
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;

    //calling make_unique to create a pointer to an object of type AudioParameterFloat
    //this is then passed into push_back method
    params.push_back(std::make_unique<juce::AudioParameterFloat>("refLevel", "Reference Level", 0.0f, 1.0f, 0.5f)); // ID, name, min, max, default

    params.push_back(std::make_unique<juce::AudioParameterChoice>("system", "System Select", impulseResponses, 0));

    params.push_back(std::make_unique<juce::AudioParameterBool>("bypass", "Bypass", false));

    return juce::AudioProcessorValueTreeState::ParameterLayout();
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ConvolutionAudioProcessor();
}

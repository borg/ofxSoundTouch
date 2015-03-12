//
//  ofxSoundTouch.cpp
//  example-audiowaveform
//
//  Created by Andreas Borg on 30/12/2014.
//
//

#include "ofxSoundTouch.h"


ofxSoundTouch::ofxSoundTouch(){

};

ofxSoundTouch::~ofxSoundTouch(){

};

void ofxSoundTouch::setup(int channels,int rate){
    
    soundtouch.setChannels(channels);
    
    soundtouch.setSampleRate(rate);
    
    
}


void ofxSoundTouch::setRate(float newRate){
    soundtouch.setRate( newRate);
};

/// Sets new tempo control value. Normal tempo = 1.0, smaller values
/// represent slower tempo, larger faster tempo.
void ofxSoundTouch::setTempo(float newTempo){
    soundtouch.setTempo( newTempo);
};

/// Sets new rate control value as a difference in percents compared
/// to the original rate (-50 .. +100 %)
void ofxSoundTouch::setRateChange(float newRate){
    soundtouch.setRateChange( newRate);

};

/// Sets new tempo control value as a difference in percents compared
/// to the original tempo (-50 .. +100 %)
void ofxSoundTouch::setTempoChange(float newTempo){
    soundtouch.setTempoChange( newTempo);

};

/// Sets new pitch control value. Original pitch = 1.0, smaller values
/// represent lower pitches, larger values higher pitch.
void ofxSoundTouch::setPitch(float newPitch){
    soundtouch.setPitch( newPitch);
    
};

/// Sets pitch change in octaves compared to the original pitch
/// (-1.00 .. +1.00)
void ofxSoundTouch::setPitchOctaves(float newPitch){
    soundtouch.setPitchOctaves( newPitch);

};

/// Sets pitch change in semi-tones compared to the original pitch
/// (-12 .. +12)
void ofxSoundTouch::setPitchSemiTones(int newPitch){
    soundtouch.setPitchSemiTones( newPitch);

};

void ofxSoundTouch::setPitchSemiTones(float newPitch){
    soundtouch.setPitchSemiTones( newPitch);
};

/// Sets the number of channels, 1 = mono, 2 = stereo
void ofxSoundTouch::setChannels(uint numChannels){
    soundtouch.setChannels( numChannels);
};

/// Sets sample rate.
void ofxSoundTouch::setSampleRate(uint srate){
    soundtouch.setSampleRate( srate);

};





void ofxSoundTouch::flush(){
    soundtouch.flush();
};

/// Adds 'numSamples' pcs of samples from the 'samples' memory position into
/// the input of the object. Notice that sample rate _has_to_ be set before
/// calling this function, otherwise throws a runtime_error exception.
void ofxSoundTouch::putSamples(
                        const SAMPLETYPE *samples,  ///< Pointer to sample buffer.
                        uint numSamples                         ///< Number of samples in buffer. Notice
///< that in case of stereo-sound a single sample
///< contains data for both channels.
){
    soundtouch.putSamples(samples,numSamples);
};



/// Output samples from beginning of the sample buffer. Copies requested samples to
/// output buffer and removes them from the sample buffer. If there are less than
/// 'numsample' samples in the buffer, returns all that available.
///
/// \return Number of samples returned.
uint ofxSoundTouch::receiveSamples(SAMPLETYPE *output, ///< Buffer where to copy output samples.
                            uint maxSamples                 ///< How many samples to receive at max.
){
    return soundtouch.receiveSamples(output,maxSamples);
};

/// Adjusts book-keeping so that given number of samples are removed from beginning of the
/// sample buffer without copying them anywhere.
///
/// Used to reduce the number of samples in the buffer when accessing the sample buffer directly
/// with 'ptrBegin' function.
uint ofxSoundTouch::receiveSamples(uint maxSamples   ///< Remove this many samples from the beginning of pipe.
){
   return soundtouch.receiveSamples(maxSamples);
};




/// Clears all the samples in the object's output and internal processing
/// buffers.
void ofxSoundTouch::clear(){
    soundtouch.clear();
};

/// Changes a setting controlling the processing system behaviour. See the
/// 'SETTING_...' defines for available setting ID's.
///
/// \return 'TRUE' if the setting was succesfully changed
BOOL  ofxSoundTouch::setSetting(int settingId,   ///< Setting ID number. see SETTING_... defines.
                int value        ///< New setting value.
){
    return soundtouch.setSetting(settingId,value);
};

/// Reads a setting controlling the processing system behaviour. See the
/// 'SETTING_...' defines for available setting ID's.
///
/// \return the setting value.
int  ofxSoundTouch::getSetting(int settingId    ///< Setting ID number, see SETTING_... defines.
) const{

    return soundtouch.getSetting(settingId );
};

/// Returns number of samples currently unprocessed.
uint ofxSoundTouch::numUnprocessedSamples() const{
    return soundtouch.numUnprocessedSamples();
};



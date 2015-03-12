//
//  ofxSoundTouch.h
//  example-audiowaveform
//
//  Created by Andreas Borg on 30/12/2014.
//
//

#ifndef __example_audiowaveform__ofxSoundTouch__
#define __example_audiowaveform__ofxSoundTouch__

#include "ofMain.h"
#include "SoundTouch.h"


//tell soundtouch to use float samples
#define SOUNDTOUCH_FLOAT_SAMPLES

using namespace soundtouch;

class ofxSoundTouch{
public:
    ofxSoundTouch();
    ~ofxSoundTouch();
    SoundTouch soundtouch;
    void setup(int channels=2,int rate = 44100);
    
    void setRate(float newRate);
    
    /// Sets new tempo control value. Normal tempo = 1.0, smaller values
    /// represent slower tempo, larger faster tempo.
    void setTempo(float newTempo);
    
    /// Sets new rate control value as a difference in percents compared
    /// to the original rate (-50 .. +100 %)
    void setRateChange(float newRate);
    
    /// Sets new tempo control value as a difference in percents compared
    /// to the original tempo (-50 .. +100 %)
    void setTempoChange(float newTempo);
    
    /// Sets new pitch control value. Original pitch = 1.0, smaller values
    /// represent lower pitches, larger values higher pitch.
    void setPitch(float newPitch);
    
    /// Sets pitch change in octaves compared to the original pitch
    /// (-1.00 .. +1.00)
    void setPitchOctaves(float newPitch);
    
    /// Sets pitch change in semi-tones compared to the original pitch
    /// (-12 .. +12)
    void setPitchSemiTones(int newPitch);
    void setPitchSemiTones(float newPitch);
    
    /// Sets the number of channels, 1 = mono, 2 = stereo
    void setChannels(uint numChannels);
    
    /// Sets sample rate.
    void setSampleRate(uint srate);
    
    
    void flush();
    
    /// Adds 'numSamples' pcs of samples from the 'samples' memory position into
    /// the input of the object. Notice that sample rate _has_to_ be set before
    /// calling this function, otherwise throws a runtime_error exception.
    virtual void putSamples(
                            const SAMPLETYPE *samples,  ///< Pointer to sample buffer.
                            uint numSamples                         ///< Number of samples in buffer. Notice
    ///< that in case of stereo-sound a single sample
    ///< contains data for both channels.
    );
    
    /// Clears all the samples in the object's output and internal processing
    /// buffers.
    virtual void clear();
    
    /// Changes a setting controlling the processing system behaviour. See the
    /// 'SETTING_...' defines for available setting ID's.
    ///
    /// \return 'TRUE' if the setting was succesfully changed
    BOOL setSetting(int settingId,   ///< Setting ID number. see SETTING_... defines.
                    int value        ///< New setting value.
    );
    
    /// Reads a setting controlling the processing system behaviour. See the
    /// 'SETTING_...' defines for available setting ID's.
    ///
    /// \return the setting value.
    int getSetting(int settingId    ///< Setting ID number, see SETTING_... defines.
    ) const;
    
    /// Returns number of samples currently unprocessed.
    virtual uint numUnprocessedSamples() const;
    
    
    /// Output samples from beginning of the sample buffer. Copies requested samples to
    /// output buffer and removes them from the sample buffer. If there are less than
    /// 'numsample' samples in the buffer, returns all that available.
    ///
    /// \return Number of samples returned.
    virtual uint receiveSamples(SAMPLETYPE *output, ///< Buffer where to copy output samples.
                                uint maxSamples                 ///< How many samples to receive at max.
    );
    
    /// Adjusts book-keeping so that given number of samples are removed from beginning of the
    /// sample buffer without copying them anywhere.
    ///
    /// Used to reduce the number of samples in the buffer when accessing the sample buffer directly
    /// with 'ptrBegin' function.
    virtual uint receiveSamples(uint maxSamples   ///< Remove this many samples from the beginning of pipe.
    );
    
    
};

#endif /* defined(__example_audiowaveform__ofxSoundTouch__) */

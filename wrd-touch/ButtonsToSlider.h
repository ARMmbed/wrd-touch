/* mbed
 * Copyright (c) 2006-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __BUTTONS_TO_SLIDER__
#define __BUTTONS_TO_SLIDER__

#include "wrd-touch/AnalogButton.h"

class ButtonsToSlider
{
public:
    ButtonsToSlider(const uint32_t* channelMap, uint32_t channelsInUse);
    ~ButtonsToSlider();

    /*  Register callback functions
    */
    void setCallOnPress(FunctionPointer callback);
    void setCallOnChange(FunctionPointer callback);
    void setCallOnRelease(FunctionPointer callback);

    template <typename T>
    void setCallOnPress(T* object, void (T::*member)(void))
    {
        callOnPress.attach(object, member);
    }

    template <typename T>
    void setCallOnChange(T* object, void (T::*member)(void))
    {
        callOnChange.attach(object, member);
    }

    template <typename T>
    void setCallOnRelease(T* object, void (T::*member)(void))
    {
        callOnRelease.attach(object, member);
    }

    void calibrate(FunctionPointer callback);

    template <typename T>
    void calibrate(T* object, void (T::*member)(void))
    {
        calibrateCallback.attach(object, member);
        internalCalibrate();
    }

    void cancelCalibration(void);

    uint32_t getLocation() const;
    int32_t getSpeed() const;
    int32_t getAcceleration() const;

    bool isPressed() const;

    uint32_t getTimestamp(void) const;

    void setIdleFrequency(uint32_t freqHz);
    void setActiveFrequency(uint32_t freqHz);

    void pause();
    void resume();

private:
    void sliderPressTask(void);
    void sliderReleaseTask(void);

    void internalCalibrate(void);

    void calibrateDoneTask(void)
    {
        if (calibrateCallback)
        {
            calibrateCallback.call();
            calibrateCallback.clear();
        }
    }

    AnalogButton** buttons;
    uint32_t* channelMap;
    const uint32_t channelsInUse;

    uint32_t location;
    int32_t speed;
    int32_t acceleration;
    bool pressed;
    uint32_t eventTimestamp;

    FunctionPointer callOnPress;
    FunctionPointer callOnChange;
    FunctionPointer callOnRelease;

    FunctionPointer calibrateCallback;
};


#endif // __BUTTONS_TO_SLIDER__

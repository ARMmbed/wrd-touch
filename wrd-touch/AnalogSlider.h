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

#ifndef __ANALOG_SLIDER_H__
#define __ANALOG_SLIDER_H__

#include "mbed-drivers/mbed.h"

using namespace mbed::util;

class AnalogSlider
{
public:
    AnalogSlider(const uint32_t* channelMap, uint32_t channelsInUse);
    ~AnalogSlider();

    uint32_t getLocation()
    {
        return location;
    }

    int32_t getSpeed()
    {
        return speed;
    }

    int32_t getAcceleration()
    {
        return acceleration;
    }

    bool isPressed()
    {
        return pressed;
    }

    void setIdleFrequency(uint32_t freqHz);
    void setActiveFrequency(uint32_t freqHz);

    /*  Register callback functions
    */
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

    void setCallOnPress(FunctionPointer _callOnPress)
    {
        callOnPress = _callOnPress;
    }

    void setCallOnChange(FunctionPointer _callOnChange)
    {
        callOnChange = _callOnChange;
    }

    void setCallOnRelease(FunctionPointer _callOnRelease)
    {
        callOnRelease = _callOnRelease;
    }

    void calibrate(bool calibrateWhenActive, bool useNewValues, FunctionPointer callback)
    {
        calibrateCallback = callback;

        calibrate(calibrateWhenActive, useNewValues);
    }

    template <typename T>
    void calibrate(bool calibrateWhenActive, bool useNewValues, T* object, void (T::*member)(void))
    {
        calibrateCallback.attach(object, member);

        calibrate(calibrateWhenActive, useNewValues);
    }

    void pause();
    void resume();

private:
    void sliderPressTask(void);
    void sliderReleaseTask(void);

    void calibrate(bool calibrateWhenActive, bool useNewValues);

    void calibrateDoneTask(void)
    {
        if (calibrateCallback)
        {
            calibrateCallback.call();
            calibrateCallback.clear();
        }
    }

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


#endif // __ANALOG_SLIDER_H__


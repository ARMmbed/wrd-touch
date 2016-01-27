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

#ifndef __ANALOG_SLIDER_NOT_PRESENT_H__
#define __ANALOG_SLIDER_NOT_PRESENT_H__

#include "mbed-drivers/mbed.h"

using namespace mbed::util;

class AnalogSliderNotPresent
{
public:
    AnalogSliderNotPresent(const uint32_t* channelMap, uint32_t channelsInUse)
    {
        (void) channelMap;
        (void) channelsInUse;
    }

    /*  Register callback functions
    */
    void setCallOnPress(FunctionPointer callback)
    {
        (void) callback;
    }

    template <typename T>
    void setCallOnPress(T* object, void (T::*member)(void))
    {
        (void) object;
        (void) member;
    }

    void setCallOnChange(FunctionPointer callback)
    {
        (void) callback;
    }

    template <typename T>
    void setCallOnChange(T* object, void (T::*member)(void))
    {
        (void) object;
        (void) member;
    }

    void setCallOnRelease(FunctionPointer callback)
    {
        (void) callback;
    }

    template <typename T>
    void setCallOnRelease(T* object, void (T::*member)(void))
    {
        (void) object;
        (void) member;
    }

    void calibrate(FunctionPointer callback)
    {
        (void) callback;
    }

    template <typename T>
    void calibrate(T* object, void (T::*member)(void))
    {
        (void) object;
        (void) member;
    }

    void cancelCalibration(void)
    { }

    uint32_t getLocation(void) const
    {
        return 0;
    }

    int32_t getSpeed(void) const
    {
        return 0;
    }

    int32_t getAcceleration(void) const
    {
        return 0;
    }

    bool isPressed(void) const
    {
        return false;
    }

    uint32_t getTimestamp(void) const
    {
        return 0;
    }

    void setIdleFrequency(uint32_t freqHz)
    {
        (void) freqHz;
    }

    void setActiveFrequency(uint32_t freqHz)
    {
        (void) freqHz;
    }

    void pause(void)
    { }

    void resume(void)
    { }
};

#endif // __ANALOG_SLIDER_NOT_PRESENT_H__

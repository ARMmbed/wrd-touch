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

#ifndef __ANALOG_BUTTON_H__
#define __ANALOG_BUTTON_H__

#include "mbed-drivers/mbed.h"

#if YOTTA_CFG_HARDWARE_WRD_TOUCH_PRESENT
#include "wrd-touch/AnalogButtonImplementation.h"
#else
#include "wrd-touch/AnalogButtonNotPresent.h"
#endif

using namespace mbed::util;

class AnalogButton
{
public:
    AnalogButton(uint32_t channel, bool multipleUpdates = false)
        :   button(channel, multipleUpdates)
    {}

    void fall(FunctionPointer callback)
    {
        button.fall(callback);
    }

    template <typename T>
    void fall(T* object, void (T::*member)(void))
    {
        FunctionPointer fp(object, member);
        fall(fp);
    }

    void rise(FunctionPointer callback)
    {
        button.rise(callback);
    }

    template <typename T>
    void rise(T* object, void (T::*member)(void))
    {
        FunctionPointer fp(object, member);
        rise(fp);
    }

    void calibrate(FunctionPointer callback)
    {
        button.calibrate(callback);
    }

    template <typename T>
    void calibrate(T* object, void (T::*member)(void))
    {
        FunctionPointer fp(object, member);
        calibrate(fp);
    }

    void cancelCalibration(void)
    {
        button.cancelCalibration();
    }

    int32_t getValue(void) const
    {
        return button.getValue();
    }

    int32_t getMinValue(void) const
    {
        return button.getMinValue();
    }

    int32_t getMaxValue(void) const
    {
        return button.getMaxValue();
    }

    bool isPressed(void) const
    {
        return button.isPressed();
    }

    uint32_t getTimestamp(void) const
    {
        return button.getTimestamp();
    }

    void setIdleFrequency(uint32_t freqHz)
    {
        button.setIdleFrequency(freqHz);
    }

    void setActiveFrequency(uint32_t freqHz)
    {
        button.setActiveFrequency(freqHz);
    }

    void pause(void)
    {
        button.pause();
    }

    void resume(void)
    {
        button.resume();
    }

private:
#if YOTTA_CFG_HARDWARE_WRD_TOUCH_PRESENT
    AnalogButtonImplementation button;
#else
    AnalogButtonNotPresent button;
#endif
};

#endif // __ANALOG_BUTTON_H__

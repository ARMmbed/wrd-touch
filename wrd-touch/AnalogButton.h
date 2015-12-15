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

#include "core-util/FunctionPointer.h"

using namespace mbed::util;

class AnalogButton
{
public:
    AnalogButton(uint32_t channel);
    ~AnalogButton();

    void fall(FunctionPointer& onPress)
    {
        onPressHandler = onPress;
    }

    void rise(FunctionPointer& onRelease)
    {
        onReleaseHandler = onRelease;
    }

    template <typename T>
    void fall(T* object, void (T::*member)(void))
    {
        FunctionPointer callback(object, member);

        fall(callback);
    }

    template <typename T>
    void rise(T* object, void (T::*member)(void))
    {
        FunctionPointer callback(object, member);

        rise(callback);
    }

    int32_t getValue(void);
    int32_t getMinValue(void);
    int32_t getMaxValue(void);

private:
    void onPressTask()
    {
        if (onPressHandler)
        {
            onPressHandler.call();
        }
    }

    void onReleaseTask()
    {
        if (onReleaseHandler)
        {
            onReleaseHandler.call();
        }
    }

    uint32_t channel;
    FunctionPointer onPressHandler;
    FunctionPointer onReleaseHandler;
};

#endif // __ANALOG_BUTTON_H__

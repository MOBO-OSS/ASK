/* ==================================================================
* Copyright (c) 2020,xxxx.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the
* distribution.
* 3. All advertising materials mentioning features or use of this software
* must display the following acknowledgement:
* This product includes software developed by the xxx Group. and
* its contributors.
* 4. Neither the name of the Group nor the names of its contributors may
* be used to endorse or promote products derived from this software
* without specific prior written permission.
* 5. Licensed under the GNU General Public License v3.0;
* you may not use this file except in compliance with the License.
*
* THIS SOFTWARE IS PROVIDED BY xxx,GROUP AND CONTRIBUTORS
* ===================================================================
* Author: Mobo
* Mail: mobojingjiniao@126.com
*/
#pragma once
#include "TypesRedefine.hpp"
#include "stdlib.h"
#include <string>

template<typename DataType, int Length = 20, bool ShowWaring = 0>
class RingBuffer
{
private:
    DataType datas[Length];
    int head = 0;
    int tail = 0;

public:
    bool IsFull()
    {
        return (tail + 1) % Length == head;
    }

    bool IsEmpty()
    {
        return tail == head;
    }

    bool Push(DataType data)
    {
        if (IsFull() && ShowWaring) {
            head = (head + 1) % Length;
            warn("Ring buff is full, earse the oldest one\n");
        }

        datas[tail] = data;
        tail = (tail + 1) % Length;
        return true;
    }

    bool Pop(DataType& data)
    {
        if (IsEmpty())
            return false;

        data = datas[head];
        head = (head + 1) % Length;
        return true;
    }

    bool Front(DataType& data)
    {
        if (IsEmpty())
            return false;

        data = datas[head];
        return true;
    }

    // bool Iterator(DataType& data){

    // }

    bool Back(DataType& data)
    {
        if (IsEmpty())
            return false;

        data = datas[tail];
        return true;
    }



    int Size()
    {
        if (tail >= head)
            return tail - head;
        else
            return tail + Length - head;
    }

};

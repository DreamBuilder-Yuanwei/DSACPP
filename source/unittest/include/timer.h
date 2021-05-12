/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <ctime>

class Timer {
 private:
    clock_t start_time, end_time;
 public:
    Timer() { start_time = clock(); }
    void reset() { start_time = clock(); }

    // 返回ms
    double spend_time_micro() {
        end_time = clock();
        return (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;
    }

    // 返回s
    double spend_time() {
        end_time = clock();
        return (double)(end_time - start_time) / CLOCKS_PER_SEC;
    }
};

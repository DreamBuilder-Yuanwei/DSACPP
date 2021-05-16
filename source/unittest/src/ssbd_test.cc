/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include <cstdio>
#include <cstdlib>
#include "include/timer.h"
#include "include/unittest.h"
#include "include/small_set_big_data.h"

void ssbg_test() {
    Timer timer;
    __int32_t result = ssbd();
    printf("function ssbd--result: %d, spend time: %.3lfms\n", result, timer.spend_time_micro());
    return;
}

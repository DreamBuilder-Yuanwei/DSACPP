/******************************************************************************************
 * Data Structures Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include <ctime>
#include <cstdlib>
#include "bitmap.h"


// 小集合+大数据问题：
// 给定一个长度为len的数组A, 试统计A中包含了[0,range)范围内的哪些数值, 并打印其个数
__int32 ssbd() {
    srand(time(NULL));
    Bitmap bm(range);s
    for (__int64 i = 0; i < len; i++)
        bm.set(rand() % range);
    __int32 count = 0;
    for (__int32 i = 0; i < range; i++)
        if (bm.test(i))
            count++;
    return count;
}


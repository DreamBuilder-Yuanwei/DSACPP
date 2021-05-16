/******************************************************************************************
 * Data Structures Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include "include/eratosthenes.h"

void eratosthenes(Bitmap *bm, int n) {
    bm->set(0);
    bm->set(1);
    for (int i = 0; i * i < n; i++)
        if (!bm->test(i))
            for (int j = i * i; j < n; j += i)
                bm->set(j);
    return;
}
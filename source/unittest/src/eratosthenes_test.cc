/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include "include/bitmap.h"
#include "include/unittest.h"
#include "include/eratosthenes.h"

void eratosthenes_test() {
    int n = 0;
    scanf("%d", &n);
    Bitmap bm(n);
    eratosthenes(&bm, n);
    for (int i = 0; i < n; i++)
        if (false == bm.test(i))
            printf("%d%c", i, " \n"[i < n - 1]);
    return;
}

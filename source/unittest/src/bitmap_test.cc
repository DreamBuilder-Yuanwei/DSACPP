/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include <cassert>
#include <cstring>
#include "include/bitmap.h"

void bitmap_test() {
    Bitmap bm(32);
    bm.set(2);
    bm.set(22);
    bm.set(42);
    assert(true == bm.test(2));
    assert(true == bm.test(22));
    assert(true == bm.test(42));
    assert(false == bm.test(0));
    assert(false == bm.test(256));

    bm.clear(22);
    assert(false == bm.test(22));

    char filepath[128] = {0};
    scanf("%s", filepath);
    bm.dump(filepath);

    char *s = bm.bits2string(33);
    printf("%s\n", s);
    delete [] s;
    s = NULL;

    Bitmap bm2(filepath, 256);
    s = bm2.bits2string(258);
    printf("%s\n", s);
    delete [] s;
    s = NULL;

    return;
}

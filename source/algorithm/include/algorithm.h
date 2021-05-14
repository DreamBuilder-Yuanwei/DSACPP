/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

#define max(a, b) (((a) > (b)) ? (a) : (b))

template<typename T> void swap(T & a, T & b) {
    T temp = a;
    a = b;
    b = temp;
    return;
}

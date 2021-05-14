/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

template<typename T>
struct Decrease{
    void operator()(T &e) { e--;}
};

template<typename T> void increase(T &e) { e++; }

void lcs_test();
void vector_test();

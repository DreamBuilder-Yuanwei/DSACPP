/******************************************************************************************
 * Data Structures Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "include/list.h"

// 类型T必须重载了++运算符
template<typename T>
struct INCRECE {
    T & operator() (T & e) {
        e++;
    }
};

// 打印元素为char类型的列表
template<typename T>void printList(List<T> const &, void (*vist) (T &));

void listTest();

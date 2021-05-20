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

// 最长公共子序列(LCS)算法的测试函数
void lcs_test();
// 向量的测试函数
void vector_test();
// 位图的测试函数
void bitmap_test();
// 小集合+大数据算法测试函数
void ssbg_test();
// eratosthenes筛法求素数测试
void eratosthenes_test();
// 求逆序对算法的测试函数
void inversion_test();
// 列表接口的测试函数
void list_test();

/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/
#pragma once

#include "include/algorithm.h"

// 问题：计算一个序列A在区间[lo, hi)中的逆序对数目
// 接口规范：
//     输入：A-T类型数组
//     返回：A数组中逆序对数目
//     其它：类型T应是已经重载<号的可比较类型
// 以下为各接口的声明部分

// 基于起泡排序计算逆序对数目
template<typename T>
int getInversionBubbleSort(T *A, int lo, int hi);

// 基于插入排序计算逆序对数目
template<typename T>
int getInversionInsertionSort(T *A, int lo, int hi);

// 基于归并排序计算逆序对数目
template<typename T>
int getInversionMergeSort(T *A, int lo, int hi);

// 基于树状数组计算逆序对数目
template<typename T>
int getInversionTreeShapAraay(T *A, int lo, int hi);


// 以下为各接口的定义部分(建议将##模板##函数的声明和定义都放在同一个头文件下)

// 基于起泡排序计算逆序对数目
// 起泡排序中, 元素交换的总次数便是逆序对的总数目
// (因为每次交换恰好让逆序对数目减少1, 最终有序时逆序对数为0)
template<typename T>
int getInversionBubbleSort(T *A, int lo, int hi) {
    int invNum = 0, last = hi - 1;
    while (lo < hi) {
        for (int i = lo; i < last; i++)
            if (A[i + 1] < A[i]) {
                swap(A[i], A[i + 1]);
                last = i;
                invNum++;
            }
        hi = last;
    }
    return invNum;
}

// 基于插入排序计算逆序对数目
// 插入排序中, 当前位置的元素与其待插入位置之间的间隔便是该元素的逆序对数
// 所有元素的逆序对数的和便是整个序列包含的逆序对总数
template<typename T>
int getInversionInsertionSort(T *A, int lo, int hi) {
    int invNum = 0;
    for (int i = lo + 1; i < hi; i++) {
        T e = A[i];
        for (int j = i - 1; j >= lo; j--) {
            if (A[j] < e) {
                A[j + 1] = A[j];
                invNum++;
            } else {
                A[j + 1] = e;
            }
        }
    }
    return invNum;
}

// 基于二路归并算法计算前后两子序列之间的逆序对数目
template<typename T>
int getInversionBetween(T *A, int lo, int mid, int hi) {
    int invNum = 0;
    int lb = mid - lo, lc = hi - mid;
    T *B = new T[lb], *C = A + lo;
    for (int i = 0; i < lb; i++) B[i] = A[i];
    int i = 0, j = 0, k = 0;
    while (j < lb && k < lc) {
        if (B[j] <= C[k]) {
            A[i++] = B[j];
        } else {
            A[i++] = C[k];
            invNum += lb - j;  // B[j, lb)中的元素都比C[k]大
        }
    }
    while (j < lb) A[i++] = B[j];
    delete [] B;
    return invNum;
}

// 基于归并排序计算逆序对数目
template<typename T>
int getInversionMergeSort(T *A, int lo, int hi) {
    int mid = (lo + hi) >> 1;
    int invL = getInversionMergeSort(A, lo, mid);
    int invR = getInversionMergeSort(A, mid, hi);
    int invB = getInversionBetween(A, lo, mid, hi);
    return invL + invR + invB;
}

// 基于树状数组计算逆序对数目
// 待实现
template<typename T>
int getInversionTreeShapAraay(T *A, int lo, int hi) {
    return 0;
}

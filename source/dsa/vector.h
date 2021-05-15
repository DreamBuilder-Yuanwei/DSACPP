/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <cstdlib>
#include <cstring>
#include "include/algorithm.h"

using Rank = int;
#define DEFAULT_CAPACITY 3

template <typename T>
class Vector {
 private:
    int _size;  // size of vector
    int _capacity;  // capacity of vector
    T *_elem;  // data domain

 protected:
    // 数据拷贝
    void copyFrom(T const* A, Rank lo, Rank hi);
    void expand();  // 扩容
    void shrink();  // 缩容
    void merge(Rank lo, Rank mid, Rank hi);  // 二路归并
    void mergeSort(Rank lo, Rank hi);  // 归并排序
    Rank binSearchA(T const& e, Rank lo, Rank hi) const;  // 二分查找A版本
    Rank binSearchB(T const& e, Rank lo, Rank hi) const;  // 二分查找B版本
    Rank binSearchC(T const& e, Rank lo, Rank hi) const;  // 二分查找C版本

 public:
    // 构造
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _size++)
            _elem[_size] = v;
    }
    // 从数组中整体拷贝
    Vector(T const* A, int n) {
        copyFrom(A, 0, n);
    }
    // 从数组中区间拷贝
    Vector(T const* A, Rank lo, Rank hi) {
        copyFrom(A, lo, hi);
    }
    // 从向量中整体拷贝
    Vector(Vector<T> const& V) {
        copyFrom(V._elem, 0, V._size);
    }
    // 从向量中区间拷贝
    Vector(Vector<T> const& V, Rank lo, Rank hi) {
        copyFrom(V._elem, lo, hi);
    }
    // 析构
    ~Vector() {
        delete [] _elem;
    }
    // 获取向量规模
    int size() const { return _size; }
    // 判断向量是否为空
    bool empty() const { return 0 == _size; }
    // 判断两向量是否相等
    bool operator==(Vector<T> const& b) const;
    // 获取数据域
    T const* _carray() const { return _elem; }
    // 重载=号
    Vector<T>& operator=(Vector<T> const& v) {
        copyFrom(v._carray(), 0, v.size());
	return *this;
    }
    // 判断向量是否有序
    bool sorted() const;
    // 重载下标运算符
    T& operator[](Rank r);  // 左值
    const T& operator[](Rank r) const;  // 右值
    // 删除秩为r的元素
    T remove(Rank r);
    // 删除[lo, hi)范围的元素
    int remove(Rank lo, Rank hi);
    // 在秩r处插入元素e
    Rank insert(Rank r, T const& e);
    // 在向量末尾插入元素e
    Rank insert(T const& e);
    // 置乱
    void unsort() { unsort(0, _size); }  // 整体置乱
    void unsort(Rank lo, Rank hi);  // 区间置乱
    // 去重
    int deduplicate();  // 无序向量去重
    int uniquify();  // 有序向量去重
    // 查找
    Rank find(T const& e) const { return find(e, 0, _size); }  // 无序向量整体查找
    Rank find(T const& e, Rank lo, Rank hi) const;  // 无序向量区间查找
    Rank search(T const& e) const { return search(e, 0, _size); }  // 有序向量整体查找
    Rank search(T const& e, Rank lo, Rank hi) const;  // 有序向量区间查找
    // 排序
    void sort(Rank lo, Rank hi) { mergeSort(lo, hi); }  // 区间排序
    void sort() { sort(0, _size); }  // 整体排序
    // 遍历
    void traverse(void(*) (T&));  // 函数指针
    template<typename VST> void traverse(VST);  // 函数对象
};  // Vector

// 从A[lo, hi)中拷贝数据到_elem
template<typename T> void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
    _elem = new T[_capacity = max(DEFAULT_CAPACITY, (hi - lo) << 1)];
    memset(_elem, 0, _capacity);
    for (_size = 0; _size < hi - lo; _size++) _elem[_size] = A[lo + _size];
}

// 扩容
template<typename T> void Vector<T>::expand() {
    if (_size < _capacity) return;  // 尚有剩余空间, 不必扩容
    _capacity = max(_capacity, DEFAULT_CAPACITY);
    T *old_elem = _elem;
    _elem = new T[_capacity <<= 1];  // 申请一段两倍于当前容量的空间
    memset(_elem, 0, _capacity);  // 将该段空间内容初始化为0
    // 旧空间中的数据转移到新空间
    for (int i = 0; i < _size; i++) _elem[i] = old_elem[i];
    delete [] old_elem;  // 释放旧空间资源
}

// 缩容
template<typename T> void Vector<T>::shrink() {
    // 装填因子(load factor)高于25%, 不必缩容
    if (_capacity < 4 * _size) return;
    T *old_elem = _elem;
    // 申请一段0.5倍于当前容量的空间
    _elem = new T[_capacity = max(_capacity >> 1, DEFAULT_CAPACITY)];
    memset(_elem, 0, _capacity);
    // 将旧空间中的数据转移至新空间
    for (int i = 0; i < _size; i++) _elem[i] = old_elem[i];
    delete [] old_elem;  // 释放旧空间
}

// 二路归并
template<typename T> void Vector<T>::merge(Rank lo, Rank mid, Rank hi) {
    int lb = mid - lo, lc = hi - mid;
    T *A = _elem + lo, *C = _elem + mid, *B = new T[lb];
    for (int i = 0; i < lb; i++) B[i] = A[i];
    int i = 0, j = 0, k = 0;
    while (j < lb && k < lc)
        if (B[j] <= C[k]) A[i++] = B[j++];
        else
            A[i++] = C[k++];
    while (j < lb) A[i++] = B[j++];
    delete [] B;
}

// 归并排序
template<typename T> void Vector<T>::mergeSort(Rank lo, Rank hi) {
    if (hi - lo < 2) return;
    Rank mid = (lo + hi) >> 1;
    mergeSort(lo, mid);  // 对[lo, mid)中的元素进行归并排序
    mergeSort(mid, hi);  // 对[mid, hi)中的元素进行归并排序
    merge(lo, mid, hi);  // 二路归并
}

// 二分查找版本A
// 在[lo, hi)内查找元素e
// 成功-返回元素e的秩, 失败-返回-1
template<typename T>
Rank Vector<T>::binSearchA(T const& e, Rank lo, Rank hi) const {
    while (lo < hi) {
        Rank mid = (lo + hi) >> 1;
        if (e < _elem[mid]) hi = mid;
        else if (_elem[mid] < e) lo = mid + 1;
        else
            return mid;
    }
    return -1;
}

// 二分查找版本B
// 在[lo, hi)内查找元素e
// 返回最后一个不大于e的元素的秩
template<typename T>
Rank Vector<T>::binSearchB(T const& e, Rank lo, Rank hi) const {
    while (lo + 1 < hi) {
        Rank mid = (lo + hi) >> 1;
        e < _elem[mid] ? hi = mid : lo = mid;
    }
    return _elem[lo] <= e ? lo : -1;
}

// 二分查找版本C
// 在[lo, hi)内查找元素e
// 返回最后一个不大于e的元素的秩
template<typename T>
Rank Vector<T>::binSearchC(T const& e, Rank lo, Rank hi) const {
    while (lo < hi) {
        Rank mid = (lo + hi) >> 1;
        e < _elem[mid] ? hi = mid : lo = mid + 1;
    }
    return lo - 1;
}

// 判断两向量是否相等
template<typename T>bool Vector<T>::operator==(Vector<T> const& v) const {
    if (_size != v.size()) return false;
    for (int i = 0; i < _size; i++)
        if (_elem[i] != v[i]) return false;
    return true;
}

// 判断向量是否有序
template<typename T>bool Vector<T>::sorted() const {
    for (int i = 1; i < _size; i++)
        if (_elem[i] < _elem[i - 1]) return false;
    return true;
}

// 重载下标运算符, 可作为左值
template<typename T> T& Vector<T>::operator[](Rank r) {
    return _elem[r];
}

// 重载下标运算符, 只能作为右值
template<typename T> T const& Vector<T>::operator[](Rank r) const {
    return _elem[r];
}

// 删除秩为r的元素
template<typename T> T Vector<T>::remove(Rank r) {
    T e = _elem[r];
    remove(r, r + 1);
    return e;
}

// 删除[lo, hi)区间内的元素
template<typename T> int Vector<T>::remove(Rank lo, Rank hi) {
    while (hi < _size) _elem[lo++] = _elem[hi++];
    _size = lo;
    shrink();
    return hi - lo;
}

// 在秩r处插入元素e
template<typename T> Rank Vector<T>::insert(Rank r, T const& e) {
    expand();
    for (int i = _size; i > r; i--) _elem[i] = _elem[i - 1];
    _elem[r] = e;
    return r;
}

// 在向量末尾插入元素e
template<typename T> Rank Vector<T>::insert(T const& e) {
    return insert(_size, e);
}

// 区间内置乱
template<typename T> void Vector<T>::unsort(Rank lo, Rank hi) {
    T *A = _elem + lo;
    for (int i = hi - lo; i > 0; i--) A[i - 1] = A[rand() % i];
}

// 无序向量去重
template<typename T> int Vector<T>::deduplicate() {
    int old_size = _size, i = 0;
    while (i < _size)
        if (-1 != find(_elem[i], 0, i)) remove(i);
        else
            i++;
    return old_size - _size;
}

// 有序向量去重(高效)
template<typename T> int Vector<T>::uniquify() {
    int old_size = _size;
    _size = 0;
    for (int i = 1; i < _size; i++)
        if (_elem[_size] != _elem[i]) _elem[++_size] = _elem[i];
    return old_size - ++_size;
}

// 无序向量区间查找
// 在区间[lo, hi)内查找元素e
// 成功-返回元素e的秩, 失败-返回-1
template<typename T> Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
    for (int i = hi - 1; i >= lo; i--)
        if (e == _elem[i]) return i;
    return -1;
}

// 有序向量区间查找
// 在区间[lo, hi)内查找元素e
// 返回最后一个不大于e的元素的秩
template<typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const {
    return binSearchC(e, lo, hi);
}

// 遍历-函数指针
template<typename T> void Vector<T>::traverse(void(*vist) (T&)) {
    for (int i = 0; i < _size; i++) vist(_elem[i]);
}
// 遍历-函数对象
template<typename T> template<typename VST> void Vector<T>::traverse(VST vist) {
    for (int i = 0; i < _size; i++) vist(_elem[i]);
}

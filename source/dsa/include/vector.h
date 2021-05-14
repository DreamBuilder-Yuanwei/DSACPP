/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

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
    int size() { return _size; }
    // 判断向量是否为空
    bool empty() { return 0 == _size; }
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
    // 遍历
    void traverse(void(*) (T&));  // 函数指针
    template<typename VST> void traverse(VST&);  // 函数对象
};  // Vector


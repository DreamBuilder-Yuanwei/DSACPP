/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/
#pragma once

#include <cstdio>
#include <cstdlib>
#include "include/algorithm.h"
#include "include/list_node.h"

// 双向列表
template<typename T> class List {
 private:
    int _size;  // 大小
    ListNodePosi<T> header, trailer;  // 头尾哨兵节点 the sentinels

 protected:
    void init();  // 列表初始化
    void clear();  // 清空列表

    // 拷贝节点到当前列表
    void copyNodes(ListNodePosi<T>, int);

 public:
    // constructor
    List() { init(); }

    // 将列表l复制到当前列表, 深拷贝
    List(List<T> const& l) {
        init();
        copyNodes(l.first(), l.size());
    }
    List(ListNodePosi<T> p, int const& n) {
        init();
        copyNodes(p, n);
    }

    // destructor
    ~List() {
        clear();
        delete header;
        header = NULL;
        delete trailer;
        trailer = NULL;
    }

    // 获取列表的大小
    int size() const { return _size; }

    // 返回列表首节点的位置
    ListNodePosi<T> first() const {
        return 0 == _size ? NULL : header->succ;
    }

    // 返回列表末节点的位置
    ListNodePosi<T> last() const {
        return 0 == _size ? NULL : trailer->pred;
    }

    // 判空
    bool empty() const { return 0 == _size; }

    // 判断位置p是否合法
    bool valid(ListNodePosi<T> p) const {
        return NULL != p && header != p && trailer != p;
    }

    // 对列表中起始于位置p, 宽度为n的区间做选择排序
    void selectionSort(ListNodePosi<T> p, int n);

    // 选择列表中始于位置p, 宽度为n的区间中的最大元素
    ListNodePosi<T> selectMax(ListNodePosi<T> p, int n);

    // 对列表中起始于位置p, 宽度为n的区间做插入排序
    void insertionSort(ListNodePosi<T> p, int n);

    // 对列表中起始于位置p, 宽度为n的区间做归并排序
    void mergeSort(ListNodePosi<T> p, int n);

    // 将列表中起始于位置p的n个元素与列表L中起始于位置q的m个元素归并
    ListNodePosi<T> merge(ListNodePosi<T> p, int n, List<T> &L, ListNodePosi<T> q, int m);

    // 插入为首节点
    ListNodePosi<T> insertAsFirst(T const& e) {
        _size++;
        return header->insertAsSucc(e);
    }

    // 插入为末节点
    ListNodePosi<T> insertAsLast(T const& e) {
        _size++;
        return trailer->insertAsPred(e);
    }

    // 在位置p前插入
    ListNodePosi<T> insertBefore(T const& e, ListNodePosi<T> p) {
        _size++;
        return p->insertAsPred(e);
    }

    // 在位置p后插入
    ListNodePosi<T> insertAfter(ListNodePosi<T> p, T const& e) {
        _size++;
        return p->insertAsSucc(e);
    }

    T remove(ListNodePosi<T>);  // 删除节点并返回该节点数据
    bool disorder() const;  // 判断列表是否有序

    // 在整个列表中查找元素e
    // 成功-返回最后一个等于e的元素的位置, 失败-返回NULL
    ListNodePosi<T> find(T const& e) const { return find(e, _size, trailer); }

    // 在位置p之后n个元素中查找元素e
    // 成功-返回最后一个等于e的元素的位置, 失败-返回NULL
    ListNodePosi<T> find(T const& e, ListNodePosi<T> p, int n) const;

    // 在位置p之前n个元素中查找元素e
    // 成功-返回最后一个等于e的元素的位置, 失败-返回NULL
    ListNodePosi<T> find(T const& e, int n, ListNodePosi<T> p) const;

    // 查找
    // 成功-返回最后一个不大于e的元素的位置, 有可能返回header
    ListNodePosi<T> search(T const& e) const {
        return search(e, _size, trailer);
    }

    // 查找
    // 成功-返回最后一个不大于e的元素的位置, 有可能返回header
    ListNodePosi<T> search(T const& e, ListNodePosi<T> p, int n) const;

    // 查找
    // 成功-返回最后一个不大于e的元素的位置, 有可能返回header
    ListNodePosi<T> search(T const& e, int n, ListNodePosi<T> p) const;

    // 对当前无序列表去重
    // 返回被去除元素的个数
    int deduplicate();

    // 对当前有序列表去重
    // 返回被去除元素的个数
    int uniquify();

    // 遍历列表并操作各节点的数据成员
    void traverse(void (* vist)(T &));
    template<typename VST> void traverse(VST vist);

    // 重载下标运算符[]
    T & operator[] (Rank r);

    // 重载=
    List<T> & operator= (List<T> const& l);  // 可作为左值
    List<T> const& operator= (List<T> const& l) const;  // 作为右值

    // 重载==
    bool operator== (List<T> const& l) const;
};  // List

// 列表初始化
template<typename T> void List<T>::init() {
    _size = 0;  // 规模为0
    header = new ListNode<T>;   // 创建头哨兵节点
    trailer = new ListNode<T>;  // 创建尾哨兵节点

    // 设置头尾哨兵节点的前驱和后继
    header->pred = NULL;
    header->succ = trailer;
    trailer->pred = header;
    trailer->succ = NULL;
    return;
}

// 重载下标运算符[]
template<typename T> T & List<T>::operator[] (Rank r) {
    ListNodePosi<T> p = first();
    while (0 < r--) p = p->succ;
    return p->data;
}

// 清空列表
template<typename T> void List<T>::clear() {
    ListNodePosi<T> p = first(), q = NULL;
    while (valid(p)) {
        q = p->succ;
        delete p;
        _size--;
        p = q;
    }
    return;
}

// 拷贝从位置p开始的n个节点到当前列表
template<typename T> void List<T>::copyNodes(ListNodePosi<T> p, int n) {
    while (n--) {
        insertAsLast(p->data);
        p = p->succ;
    }
    return;
}

// 删除位置p处的节点
// 返回其数值
template<typename T> T List<T>::remove(ListNodePosi<T> p) {
    T e = p->data;
    p->succ->pred = p->pred;
    p->pred->succ = p->succ;
    delete p;
    p = NULL;
    _size--;
    return e;
}

// 判断当前列表是否有序
template<typename T> bool List<T>::disorder() const {
    if (_size < 2) return true;  // 空列表或者只有一个节点的列表自然有序
    ListNodePosi<T> p = first(), q = p->succ;
    while (valid(q)) {
        if (q->data < p->data) return false;  // 出现逆序对时, 立即返回false
        p = q;
        q = q->succ;
    }
    return true;  // 不存在逆序对, 列表有序
}

// 查找
// 成功-返回最后一个等于e的元素的位置, 失败-返回NULL
template<typename T>
ListNodePosi<T> List<T>::find(T const& e,
    ListNodePosi<T> p, int n) const {
    while (0 < n--)
        if (e == (p = p->succ)->data) return p;
    return NULL;
}

// 查找
// 成功-返回最后一个等于e的元素的位置, 失败-返回NULL
template<typename T>
ListNodePosi<T> List<T>::find(T const& e,
    int n, ListNodePosi<T> p) const {
    while (0 < n--)
        if (e == (p = p->pred)->data) return p;
    return NULL;
}

// 查找
// 成功-返回最后一个不大于e的元素的位置, 有可能返回header
template<typename T>
ListNodePosi<T> List<T>::search(T const& e, ListNodePosi<T> p, int n) const {
    do {
        p = p->succ;
        n--;
    } while (-1 < n && p->data <= e);
    return p->pred;
}

// 查找
// 成功-返回最后一个不大于e的元素的位置, 有可能返回header
template<typename T>
ListNodePosi<T> List<T>::search(T const& e, int n, ListNodePosi<T> p) const {
    do {
        p = p->pred;
        n--;
    } while (-1 < n && e < p->data);
    return p;
}

// 对当前无序列表去重
// 返回被去除元素的个数
template<typename T> int List<T>::deduplicate() {
    if (_size < 2) return 0;  // 平凡列表自然无重复
    int old_size = _size;
    ListNodePosi<T> p = first();
    for (Rank r = 0; p != trailer; p = p->succ)
        if (ListNodePosi<T> q = find(p->data, r, p))
            remove(q);
        else
            r++;
    return old_size - _size;
}

// 对当前有序列表去重
// 返回被去除元素的个数
template<typename T> int List<T>::uniquify() {
    if (_size < 2) return 0;  // 平凡列表自然无重复
    int old_size = _size;
    ListNodePosi<T> p = first();
    ListNodePosi<T> q = NULL;
    while (trailer != (q = p->succ))
        if (p->data == q->data)
            remove(q);
        else
            p = q;
    return old_size - _size;
}

// 遍历列表并操作各节点的数据成员
template<typename T> void List<T>::traverse(void (* vist)(T &)) {
    ListNodePosi<T> p = first();
    while (valid(p)) {
        vist(p->data);
        p = p->succ;
    }
    return;
}

template<typename T> template<typename VST>
 void List<T>::traverse(VST vist) {
    ListNodePosi<T> p = first();
    while (valid(p)) {
        vist(p->data);
        p = p->succ;
    }
    return;
}

// 选择列表中始于位置p, 宽度为n的区间中的最大元素
template<typename T>
ListNodePosi<T> List<T>::selectMax(ListNodePosi<T> p, int n) {
    ListNodePosi<T> q = p;
    while (0 < --n)
        if (q->data <= (p = p->succ)->data) q = p;
    return q;
}

// 对列表中起始于位置p, 宽度为n的区间做选择排序
template<typename T> void List<T>::selectionSort(ListNodePosi<T> p, int n) {
    ListNodePosi<T> head = p->pred, tail = p;
    for (int i = 0; i < n; i++)
        tail = tail->succ;
    while (1 < n) {
        ListNodePosi<T> q = selectMax(head->succ, n);
        swap(q->data, (tail = tail->pred)->data);
        n--;
    }
    return;
}

// 对列表中起始于位置p, 宽度为n的区间做插入排序
template<typename T> void List<T>::insertionSort(ListNodePosi<T> p, int n) {
    for (int r = 0; r < n; r++) {
        insertAfter(search(p->data, r, p), p->data);
        p = p->succ;
        remove(p->pred);
    }
    return;
}

// 对列表中起始于位置p, 宽度为n的区间做归并排序
template<typename T> void List<T>::mergeSort(ListNodePosi<T> p, int n) {
    if (n < 2) return;
    ListNodePosi<T> q = p;
    int k = n >> 1;
    for (int i = 0; i < k; i++) q = q->succ;
    mergeSort(p, k);
    mergeSort(q, n - k);
    merge(p, k, *this, q, n - k);
    return;
}

// 将列表中起始于位置p的n个元素与列表L中起始于位置q的m个元素归并
template<typename T>
ListNodePosi<T> List<T>::merge(ListNodePosi<T> p, int n, List<T> &L, ListNodePosi<T> q, int m) {
    ListNodePosi<T> head = p->pred;
    while ((0 < m) && (q != p)) {
        if ((0 < n) && (p->data <= q->data)) {
            if (q == (p = p->succ)) break;
            n--;
        } else {
            insertBefore(L.remove((q = q->succ)->pred), p);
            m--;
        }
    }
    return head->succ;
}

// 重载=
template<typename T>
List<T> & List<T>::operator= (List<T> const& l) {
    clear();  // 先释放原有空间
    copyNodes(l.first(), l.size());  // 拷贝
    return *this;
}

template<typename T>
List<T> const& List<T>::operator= (List<T> const& l) const {
    init();
    copyNodes(l.first(), l.size());
    return *this;
}

// 重载==
template<typename T>
bool List<T>::operator== (List<T> const& l) const {
    if (_size != l.size()) return false;
    ListNodePosi<T> p = first(), q = l.first();
    while (valid(p) && valid(q)) {  // 前提为类型T重载了!=号
        if (p->data != q->data) return false;
	p = p->succ;
	q = q->succ;
    }
    return true;
}

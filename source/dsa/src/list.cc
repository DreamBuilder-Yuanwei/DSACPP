/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include "include/list.h"

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
}

// 清空列表
template<typename T> void List<T>::clear() {
    ListNodePosi<T> p = header->succ, q;
    while (p != trailer) {
        q = p->succ;
        delete p;
        p = q;
    }
    _size = 0;  // 更新规模为0
}

// 拷贝从位置p开始的n个节点到当前列表
template<typename T> void List<T>::copyNodes(ListNodePosi<T> p, int n) {
    while (n-- && NULL != p) {
        trailer->insertAsPred(p->data);
        p = p->succ;
        _size++;
    }
}

// 删除位置p处的节点
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
    ListNodePosi<T> p = header->succ, q = p->succ;
    while (q != trailer) {
        if (q->data < p->data) return false;  // 出现逆序对时, 立即返回false
        p = q;
        q = q->succ;
    }
    return true;  // 不存在逆序对, 列表有序
}

// 在当前有序列表中查找
// 返回最后一个不大于e的元素的位置
// 失败返回NULL
// n > 0 向后, n < 0 向前, n == 0 非法 返回失败
template<typename T> ListNodePosi<T>
 List<T>::findSorted(T const& e, ListNodePosi<T> p, int n) const {
    if (0 == n || !valid(p)) return NULL;
    int k = 1;
    if (n < 0) {  // 统一从后往前查找, 方便返回最后一个不大于e的元素的位置
        k = -n;
    } else {
        while (k < n && valid(p)) {
            p = p->succ;
            k++;
        }
        if (!valid(p)) {
            k--;
            p = p->pred;
        }
    }
    while (k-- && valid(p)) {
        if (p->data <= e) return p;  // 命中, 返回
        p = p->pred;
    }
    return NULL;  // 查找失败
}

// 在当前无序列表中查找
// 返回最后一个等于e的元素的位置
// 失败返回NULL
// n > 0 向后, n < 0 向前, n == 0 非法 返回失败
template<typename T> ListNodePosi<T> List<T>::findUnsorted(T const& e,
 ListNodePosi<T> p, int n) const {
    if (0 == n || !valid(p)) return NULL;
    int k = 1;
    if (n < 0) {  // 统一从后往前查找, 方便返回最后一个等于e的元素的位置
        k = -n;
    } else {
        while (k < n && valid(p)) {
            p = p->succ;
            k++;
        }
        if (!valid(p)) {
            k--;
            p = p->pred;
        }
    }
    while (k-- && valid(p)) {
        if (p->data == e) return p;  // 命中, 返回
        p = p->pred;
    }
    return NULL;  // 查找失败
}

// 对当前有序列表去重
// 最后保留重复元素中位置最靠后的元素
// 返回被去除元素的个数
template <typename T> int List<T>::deduplicateSorted() const {
    int old_size = _size;
    ListNodePosi<T> p = header->succ, q = p->succ;
    while (q != trailer) {
        if (p->data == q->data) remove(p);  // 应该删除p而非q所指向的元素
        p = q;
        q = q->succ;
    }
    return old_size - _size;
}

// 对当前无序列表去重
// 最后保留重复元素中位置最靠前的元素
// 返回被去除元素的个数
template <typename T> int List<T>::deduplicateUnsorted() const {
    int old_size = _size;
    ListNodePosi<T> p = header->succ, q = NULL;
    while (p != trailer) {
        if (NULL != findUnsorted(p->data, header->succ, p - header->succ + 1)) {
            q = p;
            remove(p);  // 应该删除p而非q所指向的元素
        }
        p = q->succ;
    }
    return old_size - _size;
}

// 遍历列表并操作各节点的数据成员
template<typename T> void List<T>::traverse(void (* vist)(T & e)) {
    ListNodePosi<T> p = header->succ;
    while (p != trailer) {
        vist(p->data);
        p = p->succ;
    }
}

template<typename T> template<typename VST>
 void List<T>::traverse(VST const& vist) {
     ListNodePosi<T> p = header->succ;
     while (p != trailer) {
         vist(p->data);
         p = p->succ;
     }
}

// 重载下标运算符[]
// 下标支持负数
// eg:
// Assume we have a list l = [0, 1, 2, 3]
// l[-1] == 3
// l[3] == 3
template<typename T> T& List<T>::operator[] (Rank r) {
    if (r < 0 - _size || _size <= r) exit(-1);
    if (r < 0) r = _size + r;
    ListNodePosi<T> p = header->succ;
    while (r--) p = p->succ;
    return p->data;
}
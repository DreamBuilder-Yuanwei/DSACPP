/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <cstdlib>

using Rank = int;  // Rank
template<typename T> struct ListNode;  // declaration of class ListNode
template<typename T> using ListNodePosi = ListNode<T>*;  // position of ListNode

// 列表节点类
// usage:
// ListNode<int> l1;
// ListNode<int> l2(0);
// ListNode<int> l3(0, l1.pred, l2.succ);
// l2.insertAsPred(1);
// L3.insertAsSucc(2);
template<typename T> struct ListNode {
    T data;                // 数据成员
    ListNodePosi<T> pred;  // 前驱 predececcor
    ListNodePosi<T> succ;  // 后继 succeccor

    // constructor
    ListNode() {}
    ListNode(T const & e, ListNodePosi<T> p = NULL, ListNodePosi<T> s = NULL)
     : data(e), pred(p), succ(s) {}

    // insert as predececcor
    ListNodePosi<T> insertAsPred(T const&);

    // insert as succeccor
    ListNodePosi<T> insertAsSucc(T const&);
};

/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include "include/list_node.h"

// 插入为当前节点的前驱
template<typename T> ListNodePosi<T> ListNode<T>::insertAsPred(T const& e) {
    ListNodePosi<T> p = new ListNode(e, pred, this);
    pred->succ = p;
    pred = p;
    return p;
}

// 插入为当前节点的后继
template<typename T> ListNodePosi<T> ListNode<T>::insertAsSucc(T const& e) {
    ListNodePosi<T> p = new ListNode(e, this, succ);
    succ->pred = p;
    succ = p;
    return p;
}

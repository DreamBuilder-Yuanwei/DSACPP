/******************************************************************************************
 * Data Structures Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/
#pragma once

#include <cstdlib>
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

    // 插入为首节点
    ListNodePosi<T> insertAsFirst(T const& e) {
        header->insertAsSucc(e);
        _size++;
	return header->succ;
    }

    // 插入为末节点
    ListNodePosi<T> insertAsLast(T const& e) {
        trailer->insertAsPred(e);
        _size++;
	return trailer->pred;
    }

    // 在位置p前插入
    ListNodePosi<T> insertBefore(T const& e, ListNodePosi<T> p) {
        p->insertAsPred(e);
        _size++;
	return p->pred;
    }

    // 在位置p后插入
    ListNodePosi<T> insertAfter(ListNodePosi<T> p, T const& e) {
        p->insertAsSucc(e);
        _size++;
	return p->succ;
    }

    T remove(ListNodePosi<T>);  // 删除节点并返回该节点数据
    bool disorder() const;  // 判断列表是否有序

    // 在当前有序列表中查找
    // 返回最后一个不大于e的元素的位置
    // 失败返回NULL
    // n > 0 向后, n < 0 向前, n == 0 非法 返回失败
    ListNodePosi<T> findSorted(T const&,
     ListNodePosi<T> p = first(), int n = size()) const;

    // 在当前无序列表中查找
    // 返回最后一个等于e的元素的位置
    // 失败返回NULL
    // n > 0 向后, n < 0 向前, n == 0 非法 返回失败
    ListNodePosi<T> findUnsorted(T const&,
     ListNodePosi<T> p = first(), int n = size()) const;

    // 在当前列表(不区分是否有序)中查找
    ListNodePosi<T> find(T const& e,
     ListNodePosi<T> p = first(), int n = size()) const {
        return true == disorder() ?
        findUnsorted(e, p, n) : findSorted(e, p, n);
    }

    // 对当前有序列表去重
    // 返回被去除元素的个数
    int deduplicateSorted() const;

    // 对当前无序列表去重
    // 返回被去除元素的个数
    int deduplicateUnsorted() const;

    // 对当前列表去重(不区分是否有序)
    int deduplicate() {
        return true == disorder() ? deduplicateSorted() : deduplicateUnsorted();
    }

    // 遍历列表并操作各节点的数据成员
    void traverse(void (* vist)(T &));
    template<typename VST> void traverse(VST const& vist);

    // 重载下标运算符[]
    T & operator[] (Rank r);
};

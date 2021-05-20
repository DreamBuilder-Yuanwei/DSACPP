/******************************************************************************************
 * Data Structures Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "include/list.h"
#include "include/unittest.h"

#define MAX_LEN 25
#define MAX_VALUE 520

void list_test() {
    srand(time(NULL));  // 设置随机数种子

    List<int> l1;  // 创建空列表
    assert(l1.size() == 0);
    assert(l1.first() == NULL && l1.last() == NULL);
    assert(l1.empty() == true);

    // 插入接口测试
    int e = rand() % (MAX_VALUE + 1);
    l1.insertAsFirst(e);
    assert(l1.first()->data == e);
    assert(l1.size() == 1);
    assert(l1[0] == e);
    e = rand() % (MAX_VALUE + 1);
    l1.insertAsLast(e);
    assert(l1.last()->data == e);
    assert(l1.size() == 2);
    assert(l1[1] == e);
    e = rand() % (MAX_VALUE + 1);
    l1.insertBefore(e, l1.first());
    assert(l1.first()->data == e);
    assert(l1.size() == 3);
    assert(l1[0] == e);
    e = rand() % (MAX_VALUE + 1);
    l1.insertAfter(l1.last(), e);
    assert(l1.last()->data == e);
    assert(l1.size() == 4);
    assert(l1[3] == e);

    // 往列表尾部插入随机元素
    for (int i = 0; i < MAX_LEN; i++)
        l1.insertAsLast(rand() % (MAX_VALUE + 1));
    assert(l1.size() == MAX_LEN + 4);
    // 并将其打印
    printf("The random list:\n");
    ListNodePosi<int> p = l1.first();
    while (l1.valid(p)) {
        printf("%4d ", p->data);
        p = p->succ;
    }
    printf("\nprint end!\n");

    // 测试列表构造函数
    // l1 == l2 == l3 == l4 == l5
    List<int> l2(l1);
    List<int> l3(l1.first(), l1.size());
    List<int> l4;
    l4 = l1;
    List<int> l5(l4);
    assert(l2 == l1 && l3 == l1 && l4 == l1 && l5 == l1);

    // 测试删除接口
    e = l1.remove(l1.first());
    assert(e == l2[0] && l1[0] == l2[1]);
    assert(l1.size() == l2.size() - 1);

    // 测试排序接口
    // l1 == l2 == l3 sorted
    // l4 == l5 unsorted
    l1.insertAsFirst(e);
    l1.selectionSort(l1.first(), l1.size());
    l2.insertionSort(l2.first(), l2.size());
    l3.mergeSort(l3.first(), l3.size());
    
    // 打印排序后的列表
    printf("The sorted list:\n");
    p = l3.first();
    while (l3.valid(p)) {
        printf("%4d ", p->data);
        p = p->succ;
    }
    printf("\n");

    assert(l1.disorder() == true);
    assert(l2.disorder() == true);
    assert(l3.disorder() == true);
    assert(l4.disorder() == false);
    assert(l5.disorder() == false);
    assert(l1 == l2 && l1 == l3);
    // 打印排序后的列表
    printf("The sorted list:\n");
    p = l1.first();
    while (l1.valid(p)) {
        printf("%4d ", p->data);
        p = p->succ;
    }
    printf("\n");

    // 测试selectMax接口
    p = l1.selectMax(l1.first(), l1.size());
    assert(p == l1.last());
    p = l2.selectMax(l2.first(), l2.size());
    assert(p == l2.last());
    p = l3.selectMax(l3.first(), l3.size());
    assert(p == l3.last());

    // 测试merge接口
    l1.merge(l1.first(), l1.size(), l4, l4.first(), l4.size());
    assert(l1.size() == l2.size() + l5.size());
    assert(l4.size() == 0 && l4.empty() == true);
    // 打印归并后的列表
    printf("The merged list:\n");
    p = l1.first();
    while (l1.valid(p)) {
        printf("%4d ", p->data);
        p = p->succ;
    }
    printf("\n");

    // l1 merged
    // l2 == l3 sorted
    // l4 == l5 unsorted
    l4 = l5;

    // 测试traverse接口
    l1.traverse(increase);
    printf("The increased list:\n");
    p = l1.first();
    while (l1.valid(p)) {
        printf("%4d ", p->data);
        p = p->succ;
    }
    printf("\n");
    l1.traverse(Decrease<int>());

    // 测试查找接口
    p = l2.search(l4[l4.size() - 1]);
    assert(p->data == l4[l4.size() - 1]);
    p = l2.search(l4[l4.size() - 1], l2.first(), l2.size());
    assert(p->data == l4[l4.size() - 1]);
    p = l4.find(l2[l2.size() - 1]);
    assert(p->data == l2[l2.size() - 1]);
    p = l4.find(l2[l2.size() - 1], l4.first(), l4.size());
    assert(p->data == l2[l2.size() - 1]);

    // 测试去重接口
    int num1 = l4.deduplicate();
    printf("The deduplicated list:\n");
    p = l4.first();
    while (l4.valid(p)) {
        printf("%4d ", p->data);
        p = p->succ;
    }
    printf("\n");
    int num2 = l2.uniquify();
    printf("The uniquified list:\n");
    p = l2.first();
    while (l2.valid(p)) {
        printf("%4d ", p->data);
        p = p->succ;
    }
    printf("\n");
    assert(num1 == num2);
    l1.uniquify();
    assert(l1 == l2);

    return;
}

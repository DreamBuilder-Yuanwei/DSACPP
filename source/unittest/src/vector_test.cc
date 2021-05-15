/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "include/unittest.h"
#include "include/timer.h"
#include "vector.h"

const int test_len = 99;
const int max_data = 999;
int A[test_len];

void vector_test() {
    printf("vector_test begin!------>\n");
    srand(time(NULL));  // 设置随机数种子
    // 随机生成长度为test_len的数组A
    for (int i = 0; i < test_len; i++) A[i] = rand() % test_len;
    // 显示A中各元素, 格式：|序号 : 数值|
    printf("A is an array of type int with %d elements:\n", test_len);
    for (int i = 0; i < test_len; i++) printf("|%d : %4d| ", i, A[i]);
    printf("\n");

    // 测试构造函数
    Vector<int> v0(3, 0, 0);
    assert(v0.size() == 0 && v0.empty() == true);
    Vector<int> v1(A, test_len);
    assert(v1.size() == test_len && v1.empty() == false);
    int r1 = rand() % test_len, r2 = rand() % test_len;
    assert(A[r1] == v1[r1] && A[r2] == v1[r2]);
    Vector<int> v2(A, 5, 15);
    assert(v2.size() == 15 - 5 && v1.empty() == false);
    Vector<int> v3 = v1;
    assert(v3 == v1);
    
    // 输出v1
    printf("v1 is a vector of type int with %d elements:\n", v1.size());
    for (int i = 0; i < v1.size(); i++) printf("|%d : %4d| ", i, v1[i]);
    printf("\n");

    // 测试删除接口
    int e = v3.remove(0);
    assert(e == v3[0] && v3[0] == v1[1] && v3.size() == v1.size() - 1);
    int k = v3.remove(0, 20);
    assert(k == 20);

    // 测试插入接口
    v3.insert(0, -1);
    assert(v3[0] == -1);
    v3.insert(999);
    assert(v3[v3.size() - 1] == 999);

    v2 = v3 = v1;

    // 测试排序接口
    v1.sort();
    assert(v1.sorted() == true);
    // 输出排序后的v1
    printf("v1 is a sorted vector of type int with %d elements:\n", v1.size());
    for (int i = 0; i < v1.size(); i++) printf("|%d : %4d| ", i, v1[i]);
    printf("\n");

    // 测试置乱接口
    v1.unsort();
    assert(v1.sorted() == false);
    // 输出置乱后的v1
    printf("v1 is a unsorted vector of type int with %d elements:\n", v1.size());
    for (int i = 0; i < v1.size(); i++) printf("|%d : %4d| ", i, v1[i]);
    printf("\n");

    // 测试去重接口
    v2.sort();
    Timer timer;
    int d1 = v1.deduplicate();
    printf("deduplicate unsorted vector, spend time: %.3lfms, result:\n", timer.spend_time_micro());
    for (int i = 0; i < v1.size(); i++) printf("|%d : %4d| ", i, v1[i]);
    printf("\n");
    timer.reset();
    int d2 = v2.uniquify();
    printf("uniquify sorted vector, spend time: %.3lfms, result:\n", timer.spend_time_micro());
    for (int i = 0; i < v2.size(); i++) printf("|%d : %4d| ", i, v2[i]);
    printf("\n");
    assert(d1 == d2);

    v1 = v2 = v3;
    // 测试查找接口
    e = rand() % max_data;
    int r = v1.find(e);
    assert(e == v1[r]);
    v2.sort();
    r = v2.search(e);
    assert(e == v2[r]);

    // 测试遍历接口
    v1.traverse(increase);
    printf("vector increase, result:\n");
    for (int i = 0; i < v1.size(); i++) printf("|%d : %4d| ", i, v1[i]);
    printf("\n");
    v3.traverse(Decrease<int>());
    printf("vector decrease, result:\n");
    for (int i = 0; i < v3.size(); i++) printf("|%d : %4d| ", i, v3[i]);
    printf("\n");

    printf("<------vector_test end!\n");

    return;
}

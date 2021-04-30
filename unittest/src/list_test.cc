/******************************************************************************************
 * Data Structures Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include "list_test.h"
#include <assert.h>
#include <cstdio>

void printChar(char & c) {
    printf("%c ", c);
}

void printInt(int & c) {
    printf("%d ", c);
}

template<typename T> void printList(List<T> const & l, void(*vist)) {
    l.traverse(vist);
    printf("\n");
}

void listTest() {
    List<char> l;

    assert(true == l.empty());
    l.insertAsFirst('D');  // D
    l.insertAsLast('r');  // Dr
    assert(2 == l.size());
    assert('D' == l.first()->data);
    assert('r' == l.last()->data);

    ListNodePosi<char> p = l.insertAfter(l.first(), 'r');  // Drr
    p = l.insertAfter(p, 'e');  // Drer
    ListNodePosi<char> q = l.insertBefore('e', l.last());  // Dreer
    p = l.insertAfter(p, 'a');  // Dreaer
    p = l.insertAfter(p, 'm');  // Dreamer
    printList(l, printChar);

    List<char> l1 = l;
    List<char> l2(p, 3);
    printList(l1, printChar);
    printList(l2, printChar);

    assert('m' == l.remove(p));
    assert(6 == l.size());

    l.deduplicate();
    printList(l, printChar);

    List<int> l3;
    l3.insertAsFirst(1);
    l3.insertAsFirst(2);
    l3.insertAsFirst(5);
    l3.insertAsFirst(3);
    l3.insertAsFirst(4);
    l3.insertAsFirst(4);

    assert(false == l3.disorder());
    l3.deduplicateUnsorted();
    printList(l3, printInt);
    l3.find(3, l3.first(), 5);
    assert(1 == l3[0]);
    assert(5 == l3[2]);
}
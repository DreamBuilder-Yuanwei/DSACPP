/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "include/timer.h"
#include "include/inversion.h"
#include "include/unittest.h"

void intversion_test() {
    int n = 0, max = 0;
    printf("Please define the length and the biggest data of the random sequence.\nlength = ");
    scanf("%d", &n);
    printf("biggest one = %d");
    scanf("%d", &max);
    char *A = new char[n];
    memset(A, 0, n);
    srand(max);
    printf("now generate sequence randomly...\n");
    for (int i = 0; i < n; i++) {
        A[i] = rand() % (max + 1);
        printf("%6d", A[i]);
    }
    printf("\n");
    Timer timer;
    int inv1 = getInversionBubbleSort(A, 0, n);
    printf("getInversionBubbleSort: result-%d, spend time-%.3lfms\n", inv1, timer.spend_time_micro());
    
    srand(max);
    for (int i = 0; i < n; i++)
        A[i] = rand() % (max + 1);
    timer.reset();
    int inv2 = getInversionInsertionSort(A, 0, n);
    printf("getInversionInsertionSort: result-%d, spend time-%.3lfms\n", inv2, timer.spend_time_micro());
    
    srand(max);
    for (int i = 0; i < n; i++)
        A[i] = rand() % (max + 1);
    timer.reset();
    int inv3 = getInversionMergeSort(A, 0, n);
    printf("getInversionInsertionSort: result-%d, spend time-%.3lfms\n", inv3, timer.spend_time_micro());

    delete [] A;
    return;
}

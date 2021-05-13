/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include <cstdio>
#include <cstring>
#include "include/lcs_test.h"
#include "include/timer.h"
#include "include/longest_common_subsequence.h"

char A[max_len], B[max_len], lcs[max_len];
int table[max_len + 1][max_len + 1];

void lcs_test() {
    scanf("%s %s", A, B);
    printf("A = %s, B = %s\n", A, B);
    int lenA = strlen(A), lenB = strlen(B);

    Timer timer;
    int result_R = LCS_R(A, lenA, B, lenB);
    double t = timer.spend_time_micro();
    printf("function: LCS_R, result: %d, spend time: %.3lfms\n", result_R, t);

    memset(table, -1, sizeof(table));
    timer.reset();
    int result_M = LCS_M(A, lenA, B, lenB, table);
    get_LCS(A, lenA, B, lenB, table, lcs);
    t = timer.spend_time_micro();
    printf("function: LCS_M, result: %d - %s, spend time: %.3lfms\n",
        result_M, lcs, t);

    memset(lcs, 0, sizeof(lcs));
    memset(table, 0, sizeof(table));
    timer.reset();
    int result_I = LCS_I(A, lenA, B, lenB, table, lcs);
    t = timer.spend_time_micro();
    printf("function: LCS_I, result: %d - %s, spend time: %.3lfms\n",
        result_I, lcs, t);

    return;
}

/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include <cstdio>
#include "include/longest_common_subsequence.h"
#include "include/algorithm.h"

// 递归版
// 返回最长公共子序列长度
int LCS_R(char A[], int lenA, char B[], int lenB) {
    if (lenA == 0 || lenB == 0) return 0;
    if (A[lenA - 1] == B[lenB - 1]) return 1 + LCS_R(A, lenA - 1, B, lenB - 1);
    return max(LCS_R(A, lenA - 1, B, lenB), LCS_R(A, lenA, B, lenB - 1));
}

// 记忆策略
// table[lenA][lenB]中记录各子问题的解, 初始值为-1
// 返回最长公共子序列长度
int LCS_M(char A[], int lenA, char B[], int lenB, int table[][max_len + 1]) {
    if (lenA == 0 || lenB == 0) return table[lenA][lenB] = 0;
    if (A[lenA - 1] == B[lenB - 1]) {
        if (-1 == table[lenA][lenB])
            return table[lenA][lenB] = 1 + LCS_M(A, lenA - 1, B, lenB - 1, table);
    }
    if (-1 == table[lenA - 1][lenB])
        table[lenA - 1][lenB] = LCS_M(A, lenA - 1, B, lenB, table);
    if (-1 == table[lenA][lenB - 1])
        table[lenA][lenB - 1] = LCS_M(A, lenA, B, lenB - 1, table);
    return table[lenA][lenB] = max(table[lenA - 1][lenB], table[lenA][lenB - 1]);
}

// 从记忆策略记录的表中获取LCS
void get_LCS(char A[], int lenA, char B[], int lenB, int table[][max_len + 1],
    char lcs[max_len]) {
   
    /* debuging	
    printf("%3c", ' ');
    for (int i = 0; i < lenB; i++)
	printf("%3c", B[i]);
    printf("\n");
    */

    int ma = -1, mp = -1;
    for (int i = 1; i < lenA + 1; i++) {
	// printf("%3c", A[i - 1]);
        for (int j = 1; j <lenB + 1; j++) {
	    // printf("%3d", table[i][j]);
	    if (A[i - 1] == B[j - 1]) {
                if (ma < table[i][j]) {
		    ma = table[i][j];
		    mp = i + j;
		    lcs[table[i][j] - 1] = A[i - 1];
		} else if (ma == table[i][j]) {
		    if (i + j < mp) {
		        mp = i + j;
			lcs[table[i][j] - 1] = A[i - 1];
		    }
		}
	    }
        }
	// printf("\n");
    }
}

// 动态规划
// dp[lenA + 1][lenB + 1]中记录各子问题的解, 初始值为0
// lsc[max_len]用于存储计算出来的LCS
// 状态转移方程：
//     dp[i][j] = 1 + dp[i - 1][j - 1], A[i - 1] == B[j - 1]时
//     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]), A[i - 1] != B[j - 1]时
// 返回最长公共子序列长度
int LCS_I(char A[], int lenA, char B[], int lenB, int dp[][max_len + 1],
    char lcs[max_len]) {
    int ma = -1, mp = -1;
    for (int i = 1; i < lenA + 1; i++) {
        for (int j = 1; j < lenB + 1; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (ma < dp[i][j]) {
	       	    ma = dp[i][j];
		    mp = i + j;
		    lcs[dp[i][j] - 1] = A[i - 1];
		} else if (ma == dp[i][j]) {
		    if (i + j < mp) {
		        mp = i + j;
		        lcs[dp[i][j] - 1] = A[i - 1];
		    }
		}
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[lenA][lenB];
}

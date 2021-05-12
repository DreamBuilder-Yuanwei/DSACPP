/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

const int max_len = 50;

int LCS_R(char A[], int lenA, char B[], int lenB);
int LCS_M(char A[], int lenA, char B[], int lenB, int table[][max_len]);
int LCS_I(char A[], int lenA, char B[], int lenB, int dp[][max_len + 1]);

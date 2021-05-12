/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

const int max_len = 50;

int LCS_R(char[], int, char[], int);
int LCS_M(char[], int, char[], int, int[][max_len]);
void get_LCS(char[], int, char[], int, int[][max_len], char[max_len]);
int LCS_I(char[], int, char[], int, int[][max_len + 1], char[max_len]);

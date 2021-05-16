/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "include/bitmap.h"

void Bitmap::init(int n) {
    M = new char[ N = (n + 7) / 8 ];
    memset(M, 0, N);
    return;
}

void Bitmap::expand(int k) {
    if (k < 8 * N) return;
    char *old_M = M;
    int n = N;
    init(k << 1);
    memcpy(M, old_M, n);
    delete[] old_M;
    return;
}

void Bitmap::set(int k) {
    expand(k);
    M[k >> 3] |= (0x80 >> (k & 0x07));
    return;
}
void Bitmap::clear(int k) {
    expand(k);
    M[k >> 3] &= ~(0x80 >> (k & 0x07));
    return;
}
bool Bitmap::test(int k) {
    expand(k);
    return M[k >> 3] & (0x80 >> (k & 0x07));
}
void Bitmap::dump(char *filepath) {
    FILE *fp = fopen(filepath, "w");
    fwrite(M, sizeof(char), N, fp);
    fclose(fp);
}
char *Bitmap::bits2string(int n) {
    expand(n - 1);
    char *s = new char[n + 1];
    s[n] = '\0';
    for (int i = 0; i < n; i++) s[i] = test(i) ? '1' : '0';
    return s;
}

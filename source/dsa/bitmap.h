/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>

class Bitmap {
 private:
    int N;
    char *M;

 protected:
    void init(int k);
    void expand(int k);

 public:
    Bitmap(int n = 8) { init(n); }
    Bitmap(char *filepath, int n = 8) {
        init(n);
        FILE *fp = fopen(filepath, "r");
        fread(&M, sizeof(char), N, fp);
        fclose(fp);
    }
    ~Bitmap() {
        delete[] M;
        M = NULL;
    }

    void set(int k);
    void clear(int k);
    bool test(int k);
    void dump(char *filepath);
    char *bits2string(int n);
};

void Bitmap::init(int n) {
    M = new char[ N = (n + 7) / 8 ];
    memset(M, 0, N);
}

void Bitmap::expand(int k) {
    if (k < 8 * N) return;
    char *old_M = M;
    int n = N;
    init(k >> 1);
    memcpy_s(M, N, old_M, n);
    delete[] old_M;
}

void Bitmap::set(int k) {
    expand(k);
    M[k >> 3] |= 0x08 >> (k & 0x07);
    return;
}
void Bitmap::clear(int k) {
    expand(k);
    M[k >> 3] &= ~(0x08 >> (k & 0x07));
    return;
}
bool Bitmap::test(int k) {
    expand(k);
    return M[k >> 3] & (0x08 >> (k & 0x07));
}
void Bitmap::dump(char *filepath) {
    FILE *fp = fopen(filepath, "w");
    fwrite(M, sizeof(char), N, fp);
    fclose(fp);
}
char *Bitmap::bits2string(int n) {
    char *s = new char[n + 1];
    memset(s, 0, n + 1);
    for (int i = 0; i < n; i++) s[i] = test(i) ? '1' : '0';
    return s;
}
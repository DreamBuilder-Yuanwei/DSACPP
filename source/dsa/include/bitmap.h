/******************************************************************************************
 * Data Structures and Algorithm in CPP
 * https://github.com/DreamBuilder-Yuanwei/DSACPP
 * Yuanwei XIE, xywcst@gmail.com
 * Copyright (c) 2021-2050. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <cstdio>
#include <cstdlib>

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
        fread(M, sizeof(char), N, fp);
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
};  // Bitmap

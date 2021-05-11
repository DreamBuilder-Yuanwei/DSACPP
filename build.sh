#!/bin/bash

### author: xywcst@gmail.com
### dir strcuture:
# |-source
# |    |-algorithm
# |        |-include
# |        |-src
# |        |-problems
# |        |-Makefile
# |    |-dsa
# |         |-include
# |         |-src
# |         |-Makefile
# |    |-unittest
# |         |-_input
# |         |-_output
# |         |-include
# |         |-src
# |         |-main.cc
# |         |-Makefile
# |    |-Makefile
# |-build.sh
# |-README.md
# |-LICENCE
# |-.gitignore

# make sure this script response to relative call
cd $(dirname $0)

### common utility function
function my_exit(){
    echo "[script] ------------------------------------>start"
    echo "[script] ops, script will exit with code $1"
    echo "[script] exit code info :"
    echo "[script] 0 - normal exist with no errors"
    echo "[script] 64 - unknown error"
    echo "[script] 65 - file not exist"
    echo "[script] 66 - folder not exist"
    echo "[script] 67 - param error"
    echo "[script] 68 - broken symbolic link"
    echo "[script] 69 - build failed"
    echo "[script] <------------------------------------end"
    exit $1
}
function check_file_exist(){
    if [ -f $1 ]
    then
        # echo "[script] file $1 is exist"
        return 0
    else
        echo "[script] file $1 is not exist"
        my_exit 65
    fi
}
function check_dir_exist(){
    if [ -d $1 ]
    then
        # echo "[script] folder $1 is exist"
        return 0
    else
        echo "[script] folder $1 is not exist"
        my_exit 66
    fi
}

### prepare work directory
function prepare_dir() {
    mkdir target
    mkdir target/bin
    mkdir target/lib
}

### setup build variants
function setup_build_variants() {
    MY_PWD=$(pwd)
    MY_SOURCE_DIR=$MY_PWD/source
    MY_DSACPP_BIN=$MY_SOURCE_DIR/unittest/dsacpp
    MY_DSA_SO=$MY_SOURCE_DIR/dsa/libdsa.so
    MY_ALGORITHM_SO=$MY_SOURCE_DIR/algorithm/libalgorithm.so
    MY_TARGET_DIR=$MY_PWD/target
    MY_BIN_DIR=$MY_TARGET_DIR/bin
    MY_LIB_DIR=$MY_TARGET_DIR/lib
}

### build
function build() {
    make -C $MY_SOURCE_DIR all
}

### clean
function clean() {
    make -C $MY_SOURCE_DIR clean
    rm -rf $MY_TARGET_DIR
}

### inject
function inject() {
    cp $MY_DSACPP_BIN $MY_BIN_DIR
    cp $MY_DSA_SO $MY_ALGORITHM_SO $MY_LIB_DIR
    export 
}

### main
function main() {
    
}
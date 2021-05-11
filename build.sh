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
    echo "[log] ------------------------------------>start"
    echo "[log] ops, script will exit with code $1"
    echo "[log] exit code info :"
    echo "[log] 0 - normal exist with no errors"
    echo "[log] 64 - unknown error"
    echo "[log] 65 - file not exist"
    echo "[log] 66 - folder not exist"
    echo "[log] 67 - param error"
    echo "[log] 68 - broken symbolic link"
    echo "[log] 69 - build failed"
    echo "[log] <------------------------------------end"
    exit $1
}
function check_file_exist(){
    if [ -f $1 ]
    then
        return 0
    else
        echo "[log] file $1 doesn't exist"
        my_exit 65
    fi
}
function check_dir_exist(){
    if [ -d $1 ]
    then
        return 0
    else
        echo "[log] folder $1 doesn't exist"
        my_exit 66
    fi
}

### prepare work directory
function prepare_dir() {
    echo "[log] prepare work directory"
    mkdir -p target
    mkdir -p target/bin
    mkdir -p target/lib
}

### create log file
function create_log_file() {
    echo "[log] create log file when log file doesn't exist"
    if [ -f $1 ]
    then
        return 0
    else
        echo "[log] start to create log file: $1"
        touch $1
    fi
}

### setup build variants
function setup_variants() {
    echo "[log] setup build variants"
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
    echo "[log] `date +"%F %T"` start building..."
    make -C $MY_SOURCE_DIR all > $MY_TARGET_DIR/build.log 2>&1
    if [ $? == 0 ]
    then
        echo "[log] `date +"%F %T"` build success !!!"
    else
        echo "[log] `date +"%F %T"` build failed !!!"
        my_exit 69
    fi
}

### clean
function clean() {
    echo "[log] `date +"%F %T"` start cleaning..."
    rm -rf $MY_TARGET_DIR
    make -C $MY_SOURCE_DIR clean
    if [ $? == 0 ]
    then
        echo "[log] `date +"%F %T"` clean success !!!"
    else
        echo "[log] `date +"%F %T"` clean failed !!!"
        my_exit 69
    fi
}

### inject
function inject() {
    echo "[log] `date +"%F %T"` start injecting..."
    check_file_exist $MY_DSACPP_BIN
    check_dir_exist $MY_BIN_DIR
    cp -rf $MY_DSACPP_BIN $MY_BIN_DIR
    check_file_exist $MY_DSA_SO
    check_file_exist $MY_ALGORITHM_SO
    check_dir_exist $MY_LIB_DIR
    cp -rf $MY_DSA_SO $MY_ALGORITHM_SO $MY_LIB_DIR
    export LD_LIBRARY_PATH=$MY_LIB_DIR:$LD_LIBRARY_PATH
}

### main
function main() {
    # check param count
    if [ ! $# == 1 ]
    then 
        echo "[log] usage: $0 [build|clean]"
        echo "[log] example : $0 build"
        echo "[log] ----------------------------------------------------------------"
        echo "[log] build            build target"
        echo "[log] clean            clean build temp"
        echo ""
        echo ""
        my_exit 67
    fi
    setup_variants
    prepare_dir
    create_log_file
    case $1 in
    build)
        echo "[log] try to build"
        build
        inject
        ;;
    clean)
        echo "[log] try to clean"
        clean
        ;;
    *)
        echo "[log] default try to build"
        build
        inject
        ;;
    esac
}

### run main
main $*
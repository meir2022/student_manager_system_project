#pragma once
#ifndef __HEADER_H__
#define __HEADER_H__

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INITIAL_GRADE -5
#define CHUNK 11

typedef enum {
    OVERCONDITION,
    UNDERCONDITION,
    EQUAL,
    NOTEQUAL
} mode;

typedef struct student {
    int c_language : 9;
    int computer_network : 9;
    int cs_fundementals : 9;
    float average;
    char* fname;
    char* lname;
    char ID[10];
    char course[17];
    char* error;
    struct student* next;
}student;


#endif // !__HEADER_H__

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
    char* ID;
    char* course;
    char* error;
    struct student* next;
}student;

//----------------------------------------------------------------------------------------------------
// fileOps 
// input :file name from user ,and the head of valid list to read from file to linked list 
// second head (headB) for invalid lists 
// 
// this function handle with file and scan line by line and creates linked list from it
//----------------------------------------------------------------------------------------------------
void  fileOps(char* fileName, struct student** head, struct student** headB);
//----------------------------------------------------------------------------------------------------
// scanLineDinamically
// input : file buffer type
//
// this function scan unlimited line by chunks and allocate memory to it 
//----------------------------------------------------------------------------------------------------
char* scanLineDinamically(FILE* type);
//----------------------------------------------------------------------------------------------------
// toLowerStr
// input : string from function
//
// this function takes a string and return it in lower case
//----------------------------------------------------------------------------------------------------
void  toLowerStr(char* str);
//----------------------------------------------------------------------------------------------------
// createStruct 
// intput : string from function
//
// this function takes a string break it to struct fielde and return a new struct 
//----------------------------------------------------------------------------------------------------
struct student* createStruct(char* line);
//----------------------------------------------------------------------------------------------------
// validateNewStruct
// input : ptr to new struct , head of valid list , headB of invalid list from function
//
// this function sort structs into valid list or error list
//----------------------------------------------------------------------------------------------------
void  validateNewStruct(struct student** newStudent, struct student** head, struct student** headB);
//----------------------------------------------------------------------------------------------------
// isalphaStr
// input : string from function 
//
// this function checks a string if only alphabet charachters shows inside it
//----------------------------------------------------------------------------------------------------
int   isalphaStr(char* str);
//----------------------------------------------------------------------------------------------------
//isDigitStr
//input : string from function
//
// this function checks a string if only numeric charachters shows inside it
//----------------------------------------------------------------------------------------------------
int   isDigitStr(char* str);
//----------------------------------------------------------------------------------------------------
// updateGrade
// input : new struct and phead of existing list from function
// 
// this function update existing student grade from new data
//----------------------------------------------------------------------------------------------------
char*  removeSpaces(char* str);
//----------------------------------------------------------------------------------------------------
// removeSpaces
// input : string from function 
// 
// this function gets a string and return it without spaces
//----------------------------------------------------------------------------------------------------
void  updateGrade(struct student* newStruct, struct student** phead);
//----------------------------------------------------------------------------------------------------
// insert
// input : head of list (valid or error) , and new struct from function
// 
// this function sort a new struct into a list in order 
//----------------------------------------------------------------------------------------------------
void  insert(struct student** head, struct student* newStudent);
//----------------------------------------------------------------------------------------------------
// printAvg
// input : head of list from both function or user
// 
// this function loop over list and print it
//----------------------------------------------------------------------------------------------------
void printTitles();
//----------------------------------------------------------------------------------------------------
//       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//----------------------------------------------------------------------------------------------------
void  printList(struct student* head);
//----------------------------------------------------------------------------------------------------
// setNewData
// input : string of query from user , and head of list from function
// 
// this function takes a new struct format from user 
//----------------------------------------------------------------------------------------------------
void  setNewData(char* inputLine, struct student** head, struct student** headB , char* fileName);
//----------------------------------------------------------------------------------------------------
// checkValidSet
// input : string from function 
// 
// this function checks input struct format include all fields required
//----------------------------------------------------------------------------------------------------
struct student* checkValidSet(char* inputSet);
//----------------------------------------------------------------------------------------------------
// writeTofile
// input : struct from function
// 
// this function convert struct to line and write it to file
//----------------------------------------------------------------------------------------------------
void  writeTofile(struct student* newStruct , char* fileName);
//----------------------------------------------------------------------------------------------------
// selectData
// input : head of list and input from user
// 
// this function gets a query from user and search for it in list and return found data
//----------------------------------------------------------------------------------------------------
void  selectData(struct student* head, char* inputLine);
//----------------------------------------------------------------------------------------------------
// selectFname
// input : head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
void  selectFname(struct student* head, int mode, char* value);
//----------------------------------------------------------------------------------------------------
// selectLname
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
void  selectLname(struct student* head, int mode, char* value);
//----------------------------------------------------------------------------------------------------
// selectID
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
void  selectID(struct student* head, int mode, char* value);
//----------------------------------------------------------------------------------------------------
// selectAverageGrade
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
void  selectAverageGrade(struct student* head, int mode, char* value);
//----------------------------------------------------------------------------------------------------
// selectCLanguage
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
void  selectCLanguage(struct student* head, int mode, char* value);
//----------------------------------------------------------------------------------------------------
// selectCsFundementals
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
void  selectCsFundementals(struct student* head, int mode, char* value);
//----------------------------------------------------------------------------------------------------
// selectComputerNetwork
// input :  head of list and condition and value from function
// 
// this function gets a parameters of query to search in list match and print found match 
//----------------------------------------------------------------------------------------------------
void  selectComputerNetwork(struct student* head, int mode, char* value);
//----------------------------------------------------------------------------------------------------
// freeList
// input :  head of list from function
// 
// this function loop on list and send each data to free it
//----------------------------------------------------------------------------------------------------
void  freeList(struct student** head);
//----------------------------------------------------------------------------------------------------
// freeNode
// input : struct from function
// 
// this function free each field of current student struct
//----------------------------------------------------------------------------------------------------
void  freeNode(struct student* tmp);

#endif // !__HEADER_H__

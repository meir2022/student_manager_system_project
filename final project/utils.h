#pragma once
#include "Header.h"

//----------------------------------------------------------------------------------------------------
// createStudentsFromFile 
// input :file name from user ,and the head of valid list to read from file to linked list 
// second head (headB) for invalid lists 
// 
// this function handle with file and scan line by line and creates linked list from it
//----------------------------------------------------------------------------------------------------
void  createStudentsFromFile(char* fileName, struct student** head, struct student** headB);
//----------------------------------------------------------------------------------------------------
// scanLineDinamically
// input : file buffer type
//
// this function scan unlimited line by chunks and allocate memory to it 
//----------------------------------------------------------------------------------------------------
char* scanLineDinamically(FILE* type);
//----------------------------------------------------------------------------------------------------
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
// toLowerStr
// input : string from function
//
// this function takes a string and return it in lower case
//----------------------------------------------------------------------------------------------------
void  toLowerStr(char* str);
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
void printTitles();  // this function doesn`t have input and print the titles of list
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
void  printList(struct student* head);
//----------------------------------------------------------------------------------------------------
// writeTofile
// input : struct from function
// 
// this function convert struct to line and write it to file
//----------------------------------------------------------------------------------------------------
void  writeTofile(struct student* newStruct , char* fileName);
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

#pragma once
#include "utils.h"
#include "Header.h"


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

#include "set func.h"

void setNewData(char* inputLine, struct student** head, struct student** headB , char* fileName)
{
    struct student* newStruct = checkValidSet(inputLine);
    while (!newStruct || newStruct->error)
    {
        puts("\nwrong insert , try again !\nfor example : \" set first name = avi , last name = iaakobi , ID = 123456789 , course = c language , grade = 100 \" ");
        puts("to go back , press 'enter'.");
        inputLine = scanLineDinamically(stdin);
        if (*inputLine == '\n')
            break;
        newStruct = checkValidSet(inputLine);
        validateNewStruct(&newStruct, head, headB);
    }
    if (*inputLine != '\n')
        writeTofile(newStruct , fileName);                     // if line checked write it into the file
    validateNewStruct(&newStruct, head, headB);
}

struct student* checkValidSet(char* inputLine) {	//this function destruct line to validate object and check existance 
    char* tempInputLine = _strdup(inputLine);
    if (!tempInputLine)
        return NULL;
    toLowerStr(tempInputLine);
    char * fnameValue, * lastName, *lnameValue, *ID, *IDValue, *course, *courseName, *grade, *gradeValue;
    removeSpaces(tempInputLine);
    tempInputLine = strtok(tempInputLine, "=");
    if (strcmp(tempInputLine, "setfirstname"))
        return NULL;
    fnameValue = strtok(NULL, ",");
    lastName = strtok(NULL, "=");
    removeSpaces(lastName);
    if (strcmp(lastName, "lastname"))
        return NULL;
    lnameValue = strtok(NULL, ",");
    ID = strtok(NULL, "=");
    if (strcmp(ID, "id"))
        return NULL;
    IDValue = strtok(NULL, ",");
    if (strlen(IDValue) != 9 || !isDigitStr(IDValue + 1))
        return NULL;
    course = strtok(NULL, "=");
    if (strcmp(course, "course"))
        return NULL;
    courseName = strtok(NULL, ",");
    
    if (strcmp(courseName, "clanguage") && strcmp(courseName, "csfundementals") && strcmp(courseName, "computernetwork")) return 0;
    grade = strtok(NULL, "=");
    
    if (strcmp(grade, "grade"))
        return NULL;
    gradeValue = strtok(NULL, " ");
    inputLine = malloc(strlen(fnameValue) + strlen(lnameValue) + strlen(IDValue) + strlen(courseName) + strlen(gradeValue) + 5);
    sprintf(inputLine, "%s, %s, %s, %s, %s", fnameValue, lnameValue, IDValue, courseName, gradeValue);
    struct student* newStruct = createStruct(inputLine);
    free(tempInputLine);
    return newStruct;
}
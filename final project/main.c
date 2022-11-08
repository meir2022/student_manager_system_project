#include "header.h"
#include "select func.h"
#include "set func.h"
#include "utils.h"



int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    char* fileName = malloc(sizeof(char)* 100);
    struct student* head = 0;
    struct student* headErrors = 0;
    createStudentsFromFile(fileName, &head, &headErrors);
    char* inputLine = NULL, *op = NULL;
    int quit = 0;
    while (!quit) {
        puts("\n\nto add a new data please enter \"set\" in this format, for example : \" set first name = avi , last name = iaakobi , ID = 123456789 , course = c language , grade = 100 \"");
        puts("to select data please enter \"select\" in this format, for example : \"first name = david\" OR \"grade > 80\" etc. ");
        puts("to print enter \"print\" . enter \"quit\" to exit : ");
        inputLine = scanLineDinamically(stdin);
        if (!strcmp(inputLine, "print\n"))
            printList(head);
        if (strstr(inputLine, "set"))
            setNewData(inputLine, &head, &headErrors , fileName);           // destruct and validate input than insert to students list
        else if (strstr(inputLine, "select"))
            selectData(head, inputLine);
        else if (!strcmp(inputLine, "quit\n"))
            quit = 1;
    }
    puts("\n bye bye!");
    freeList(&head);
    freeList(&headErrors);
    free(fileName);
    free(inputLine);
    
    return 0;
}
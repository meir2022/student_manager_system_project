#include "Header.h"


void selectFname(struct student* head, int mode, char* value) {
    struct student* temp = NULL;
    int foundSomething = 0;
    if (mode == OVERCONDITION)
        while (head) {
            if (strcmp(head->fname, value) > 0) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == UNDERCONDITION)
        while (head) {
            if (strcmp(head->fname, value) < 0) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == EQUAL)
        while (head) {
            if (!strcmp(head->fname, value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == NOTEQUAL)
        while (head) {
            if (strcmp(head->fname, value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (!foundSomething) puts("item was not found !");
};
void selectLname(struct student* head, int mode, char* value) {
    struct student* temp = NULL;
    int foundSomething = 0;
    if (mode == OVERCONDITION)
        while (head) {
            if (strcmp(head->lname, value) > 0) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == UNDERCONDITION)
        while (head) {
            if (strcmp(head->lname, value) < 0) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == EQUAL)
        while (head) {
            if (!strcmp(head->lname, value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == NOTEQUAL)
        while (head) {
            if (strcmp(head->lname, value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (!foundSomething) puts("item was not found !");
};
void selectID(struct student* head, int mode, char* value) {
    struct student* temp = NULL;
    int foundSomething = 0;
    if (mode == OVERCONDITION)
        while (head) {
            if (strcmp(head->ID, value) > 0) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == UNDERCONDITION)
        while (head) {
            if (strcmp(head->ID, value) < 0) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == EQUAL)
        while (head) {
            if (!strcmp(head->ID, value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == NOTEQUAL)
        while (head) {
            if (strcmp(head->ID, value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (!foundSomething) puts("item was not found !");
};
void selectAverageGrade(struct student* head, int mode, char* value) {
    struct student* temp = NULL;
    int foundSomething = 0;
    if (mode == OVERCONDITION)
        while (head) {
            if (head->average > atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == UNDERCONDITION)
        while (head) {
            if (head->average < atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == EQUAL)
        while (head) {
            if (head->average == atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == NOTEQUAL)
        while (head) {
            if (head->average != atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (!foundSomething) puts("item was not found !");
};
void selectCLanguage(struct student* head, int mode, char* value) {
    struct student* temp = NULL;
    int foundSomething = 0;
    if (mode == OVERCONDITION)
        while (head) {
            if (head->c_language > atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == UNDERCONDITION)
        while (head) {
            if (head->c_language < atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == EQUAL)
        while (head) {
            if (head->c_language == atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == NOTEQUAL)
        while (head) {
            if (head->c_language != atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (!foundSomething) puts("item was not found !");
};
void selectCsFundementals(struct student* head, int mode, char* value) {
    struct student* temp = NULL;
    int foundSomething = 0;
    if (mode == OVERCONDITION)
        while (head) {
            if (head->computer_network > atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == UNDERCONDITION)
        while (head) {
            if (head->computer_network < atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == EQUAL)
        while (head) {
            if (head->computer_network == atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == NOTEQUAL)
        while (head) {
            if (head->computer_network != atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (!foundSomething) puts("item was not found !");
};
void selectComputerNetwork(struct student* head, int mode, char* value) {
    int foundSomething = 0;
    struct student* temp = NULL;
    if (mode == OVERCONDITION)
        while (head) {
            if (head->computer_network > atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == UNDERCONDITION)
        while (head) {
            if (head->computer_network < atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == EQUAL)
        while (head) {
            if (head->computer_network == atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (mode == NOTEQUAL)
        while (head) {
            if (head->computer_network != atof(value)) {
                temp = head->next;
                head->next = NULL;
                printList(head);
                head->next = temp;
                foundSomething = 1;
            }
            head = head->next;
        }
    if (!foundSomething) puts("item was not found !");
};
void selectData(struct student* head, char* inputLine) {
    toLowerStr(inputLine);
    char* op = strstr(inputLine, "!=") ? "!=" : strstr(inputLine, "=") ? "=" : strstr(inputLine, ">") ? ">" : strstr(inputLine, "<") ? "<" : " ";
    char* key = strtok(inputLine, " ");                // jump over the first select word
    char* value = NULL;
    key = strtok(NULL, "!=><");
    value = strtok(NULL, "\n");
    if (!strcmp(op, "!="))
        value++;                 // if the condition has 2 charachters jump over 2nd charachter
    removeSpaces(value);
    if (!key || !op || !value)
    {
        puts("wrong insert , try again ");
        return;
    }
    if ( !isalphaStr(value) && !isDigitStr(value))
    {
        printf("invalid query , try again !");
        return;
    }
    if (!strcmp(key, "first name ") || !strcmp(key, "first name"))
    {
        if (!strcmp(op, ">")) selectFname(head, OVERCONDITION, value);
        if (!strcmp(op, "<")) selectFname(head, UNDERCONDITION, value);
        if (!strcmp(op, "=")) selectFname(head, EQUAL, value);
        if (!strcmp(op, "!="))selectFname(head, NOTEQUAL, value);
    }
    if (!strcmp(key, "last name"))
    {
        if (!strcmp(op, ">")) selectLname(head, OVERCONDITION, value);
        if (!strcmp(op, "<")) selectLname(head, UNDERCONDITION, value);
        if (!strcmp(op, "=")) selectLname(head, EQUAL, value);
        if (!strcmp(op, "!="))selectLname(head, NOTEQUAL, value);
    }
    if (!strcmp(key, "id"))
    {
        if (!strcmp(op, ">")) selectID(head, OVERCONDITION, value);
        if (!strcmp(op, "<")) selectID(head, UNDERCONDITION, value);
        if (!strcmp(op, "=")) selectID(head, EQUAL, value);
        if (!strcmp(op, "!="))selectID(head, NOTEQUAL, value);
    }
    if (!strcmp(key, "average "))
    {
        if (!strcmp(op, ">")) selectAverageGrade(head, OVERCONDITION, value);
        if (!strcmp(op, "<")) selectAverageGrade(head, UNDERCONDITION, value);
        if (!strcmp(op, "=")) selectAverageGrade(head, EQUAL, value);
        if (!strcmp(op, "!="))selectAverageGrade(head, NOTEQUAL, value);
    }
    if (!strcmp(key, "c language "))
    {
        if (!strcmp(op, ">")) selectCLanguage(head, OVERCONDITION, value);
        if (!strcmp(op, "<")) selectCLanguage(head, UNDERCONDITION, value);
        if (!strcmp(op, "=")) selectCLanguage(head, EQUAL, value);
        if (!strcmp(op, "!="))selectCLanguage(head, NOTEQUAL, value);
    }
    if (!strcmp(key, "cs fundementals "))
    {
        if (!strcmp(op, ">")) selectCsFundementals(head, OVERCONDITION, value);
        if (!strcmp(op, "<")) selectCsFundementals(head, UNDERCONDITION, value);
        if (!strcmp(op, "=")) selectCsFundementals(head, EQUAL, value);
        if (!strcmp(op, "!="))selectCsFundementals(head, NOTEQUAL, value);
    }
    if (!strcmp(key, "computer network "))
    {
        if (!strcmp(op, ">")) selectComputerNetwork(head, OVERCONDITION, value);
        if (!strcmp(op, "<")) selectComputerNetwork(head, UNDERCONDITION, value);
        if (!strcmp(op, "=")) selectComputerNetwork(head, EQUAL, value);
        if (!strcmp(op, "!="))selectComputerNetwork(head, NOTEQUAL, value);
    }
}
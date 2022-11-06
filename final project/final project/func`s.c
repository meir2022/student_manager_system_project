#include "Header.h"


void fileOps(char* fileName, struct student** head, struct student** headB) { // this function read objects from file, organize them into a list and print it
    FILE* in;
    struct student* newStruct = NULL;
    puts("please enter the name of the file you want to scan :");
    while (1) {
        int stam = scanf("%s%*c", fileName);
        in = fopen(fileName, "r+");
        if (in)
            break;
        puts("file not found . try again ");
    }
    char* line = NULL;
    while (!feof(in)) {                                                        // read file until end 
        line = scanLineDinamically(in);
        toLowerStr(line);
        newStruct = createStruct(line);
        free(line);
        validateNewStruct(&newStruct, head, headB);
    }
    printTitles();
    printList(*head);

    if (*headB) {
        puts("\nthis is an error list :");
        printList(*headB);
    }
    fclose(in);
    
    
}
char* scanLineDinamically(FILE* type) {
    char* fullstr = NULL;
    char substr[11] = { 0 };
    size_t sumlen = 0, curlen = 0;

    do {
        fgets(substr, 11, type);
        curlen = (int)strlen(substr);

        char* str = realloc(fullstr, sumlen + curlen + 1);              // resize the full string and paste the new substring in
        if (!str) return NULL;
        fullstr = str;
        strcpy(fullstr + sumlen, substr);
        sumlen += curlen;
    } while (curlen == 10 && substr[9] != '\n');                        // if the current length less than 10, i know its the end of input

    return fullstr;
}
void toLowerStr(char* str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}
struct student* createStruct(char* line) {
    struct student* newStruct = malloc(sizeof(struct student));
    newStruct->fname = malloc(strlen(line)) 
        ;
    newStruct->lname = malloc(strlen(line));
    newStruct->ID = malloc(10);
    newStruct->course = malloc(17);
    newStruct->error = NULL;
    newStruct->next = NULL;
    newStruct->c_language = -5;                        // initialize the grades array with -5, not on 0 initialize in case there is grade = 0 
    newStruct->computer_network = -5;
    newStruct->cs_fundementals = -5;
    int grade;
    char* fix = NULL;
    if (fix = strstr(line, "c language")) *(fix + 1) = '_';
    if (fix = strstr(line, "cs fundementals")) *(fix + 2) = '_';
    if (fix = strstr(line, "computer network")) *(fix + 8) = '_';
    char* pline = line;
    removeSpaces(line);
    while (*pline++) {                                             // replace each coma with space that sscanf function can handle it
        if (*pline == ',')  *pline = ' ';
    }
    int stam = sscanf(line, " %s%s%s%s%d", newStruct->fname, newStruct->lname, newStruct->ID, newStruct->course, &grade);
    char* str = realloc(newStruct->fname, strlen(newStruct->fname) + 1);
    if (!str) return NULL;
    newStruct->fname = str;
    str = realloc(newStruct->lname, strlen(newStruct->lname) + 1);  // update the size of each field according to current content 
    if (!str) return NULL;
    newStruct->lname = str;
    str = realloc(newStruct->course, strlen(newStruct->course) + 1);
    if (!str) return NULL;
    newStruct->course = str;

    if (!(strcmp((newStruct->course), "c_language")) || !(strcmp((newStruct->course), "clanguage")))               // recognize what course to update 
        newStruct->c_language = grade;

    if (!(strcmp((newStruct->course), "computer_network")) || !(strcmp((newStruct->course), "computernetwork")))
        newStruct->computer_network = grade;

    if (!(strcmp((newStruct->course), "cs_fundementals")) || !(strcmp((newStruct->course), "cs_fundementals")))
        newStruct->cs_fundementals = grade;

    int numOfTests = ((newStruct->c_language != -5) + (newStruct->computer_network != -5) + (newStruct->cs_fundementals != -5));
    
    if(numOfTests != 0)                             // avoid divided by 0
    newStruct->average = ((3- numOfTests) *5 + (newStruct->c_language + newStruct->computer_network + newStruct->cs_fundementals)) / (float)numOfTests;  // this calculate add the initial -5 for empty grade
   
    if (grade > 100 || grade < -5)
        newStruct->error = _strdup("wrong grade value ");
    return newStruct;
}
void validateNewStruct(struct student** newStudent, struct student** head, struct student** headB) {
    if (!(*newStudent)) return;
    struct student* phead = *head;                                       // loop over list to check each item wether or not equal the new item, than insert to list
    if (strlen((*newStudent)->ID) != 9 || !isDigitStr((*newStudent)->ID)) {
        (*newStudent)->error = _strdup(" wrong ID");                       // in linux remove under score before strdup function
        insert(headB, *newStudent);
        return;
    }
    if (!isalphaStr((*newStudent)->fname)) {
        (*newStudent)->error = _strdup(" wrong name");                      // in linux remove under score before strdup function
        insert(headB, *newStudent);
        return;
    }
    if (!isalphaStr((*newStudent)->lname)) {
        (*newStudent)->error = _strdup(" wrong name");                     // in linux remove under score before strdup function
        insert(headB, *newStudent);
        return;
    }
    if ((*newStudent)->error) {
        insert(headB, *newStudent);
        return;
    }
    if ((*newStudent)->c_language > 100 || (*newStudent)->c_language < -10) {
        (*newStudent)->error = _strdup("wrong grade");
        return;
    }
    if ((*newStudent)->cs_fundementals > 100 || (*newStudent)->cs_fundementals < -10) {
        (*newStudent)->error = _strdup("wrong grade");
        return;
    }
    if ((*newStudent)->computer_network > 100 || (*newStudent)->computer_network < -10) {
        (*newStudent)->error = _strdup("wrong grade");
        return;
    }
    while (phead) {
        if (strcmp(phead->ID, (*newStudent)->ID) == 0) {
            if (strcmp(phead->fname, (*newStudent)->fname) || strcmp(phead->lname, (*newStudent)->lname)) {
                (*newStudent)->error = _strdup("this ID already used");
                insert(headB, *newStudent);
                return;
            }
            updateGrade(*newStudent, &phead);
            freeNode(*newStudent);
            return;
        }
        phead = phead->next;
    }
    insert(head, *newStudent);
}
int isalphaStr(char* str) {       // loop on string to validate only alphabet characters inside
    while (*str) {
        if (!isalpha(*str) && *str != ' ')
            return 0;
        str++;
    }
    return 1;
}
int isDigitStr(char* str) {       // loop on string to validate only alphabet characters inside
    while (*str) {
        if (!isdigit(*str) && *str != ' ')
            return 0;
        str++;
    }
    return 1;
}
char* removeSpaces(char* str) {   // loop on string to romove all its spaces
    int nonSpaceCount = 0;
    for (int i = 0; str[i]; i++)                    
        if (str[i] != ' ') {
            str[nonSpaceCount] = str[i];
            nonSpaceCount++;                                
        }
    str[nonSpaceCount] = '\0';
    return str;
}
void updateGrade(struct student* newStruct, struct student** phead) {// this function updating the specific course
    if ((strcmp(newStruct->course, "c_language")) == 0)
        (*phead)->c_language = newStruct->c_language;
    if ((strcmp(newStruct->course, "computer_network")) == 0)
        ((*phead))->computer_network = newStruct->computer_network;
    if ((strcmp(newStruct->course, "cs_fundementals")) == 0)
        (*phead)->cs_fundementals = newStruct->cs_fundementals;
    int numOfTests = (((*phead)->c_language != -5) + ((*phead)->computer_network != -5) + ((*phead)->cs_fundementals != -5));
    (*phead)->average = (((3 - numOfTests) * 5) + ((*phead)->c_language + (*phead)->computer_network + (*phead)->cs_fundementals)) / (float)numOfTests;
}

void insert(struct student** head, struct student* newStudent) {				// this function find the place of current struct according the alphabet end inset to this place
    while (*head)
        if ((strcmp((*head)->lname, newStudent->lname)) > 0)          // if current struct less then new one sort according to last name alphabet
            break;
        else
            head = &((*head)->next);

    newStudent->next = *head;
    *head = newStudent;
}
void printTitles() {
    printf("\n  %10s\t%10s\t%8s\t%5s  %5s  %5s  %13s\n", "first name", "last name", "ID", "c language", "computer network", "cs fundemental", "average");
}
void printList(struct student* head) {                               // this function print the whole file average sum
    //printTitles();
    while (head) {
        for (int i = 0; i < 116; i++)
            printf("%c", 95);

        printf("\n  %-15s %-15s %-15s%9.f\t%9.f\t  %9.f\t   %10.2f ", head->fname, head->lname, head->ID, head->c_language == -5 ? sqrt(-1.0) : head->c_language, head->computer_network == -5 ? sqrt(-1.0) : head->computer_network, head->cs_fundementals == -5 ? sqrt(-1.0) : head->cs_fundementals, head->average);
        if (head->error)
            printf("\t   %s", head->error);
        puts("");
        head = head->next;
    }
}

void writeTofile(struct student* newStruct, char* fileName) {
    FILE* out = fopen(fileName, "a+");
    int grade = newStruct->c_language != -1 ? newStruct->c_language : newStruct->cs_fundementals != -1 ? newStruct->cs_fundementals : newStruct->computer_network;
    fprintf(out, "\n%s,%s,%s,%s,%d", newStruct->fname, newStruct->lname, newStruct->ID, newStruct->course, grade);
    fclose(out);
};
void freeList(struct student** head)
{
    while (*head)
    {
        struct student* tmp = *head;
        *head = (*head)->next;
        freeNode(tmp);
    }
    *head = NULL;
}
void freeNode(struct student* tmp) {
    free(tmp->fname);
    free(tmp->lname);
    free(tmp->ID);
    free(tmp->course);
    free(tmp->error);
    free(tmp);
}
#ifndef STACK_H
#define STACK_H
#include "webpage.h"
#define capacity 20

typedef struct {
    WebPage arr[capacity];
    int idxTop;
} Stack;

//Membuat stack kosong dengan IDX -1
void createStack(Stack* S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack* S, webPage val);
WebPage pop(Stack* S);



#endif
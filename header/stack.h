#ifndef STACK_H
#define STACK_H
#include "webpage.h"

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    webPage *arr; // Ukuran di malloc saat setup di main.
    int idxTop;
} Stack;

//Membuat stack kosong dengan IDX -1
void createStack(Stack* S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack* S, webPage val);
WebPage pop(Stack* S);



#endif
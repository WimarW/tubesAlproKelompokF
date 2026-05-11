#ifndef STACK_H
#define STACK_H

#include "webpage.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    webPage *arr;
    int idxTop;
    int maxSize;
} Stack;

/* I.S. sembarang, F.S. stack kosong */
void createStack(Stack *S, int maxSize);

bool isStackEmpty(Stack S);
bool isStackFull(Stack S);

/* return 1 kalau berhasil, 0 kalau stack penuh */
int push(Stack *S, webPage val);

webPage pop(Stack *S);

webPage peek(Stack S);

int sizeStack(Stack S);
void clearStack(Stack *S);

/* return 1 kalau berhasil, 0 kalau indeks di luar range */
int getElementAt(Stack S, int index, webPage *result);

void destroyStack(Stack *S);

void printTabHistory(Stack backStack, Stack forwardStack, webPage *currentPage);

#endif
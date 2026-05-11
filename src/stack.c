#include "stack.h"

void createStack(Stack *S, int maxSize) {
    S->arr = (webPage *) malloc(maxSize * sizeof(webPage));
    S->idxTop = -1;
    S->maxSize = maxSize;
}

bool isStackEmpty(Stack S) {
    return S.idxTop == -1;
}

bool isStackFull(Stack S) {
    return S.idxTop == S.maxSize - 1;
}

int push(Stack *S, webPage val) {
    if (isStackFull(*S)) return 0;
    S->idxTop++;
    S->arr[S->idxTop] = val;
    return 1;
}

webPage pop(Stack *S) {
    webPage result = S->arr[S->idxTop];
    S->idxTop--;
    return result;
}

webPage peek(Stack S) {
    return S.arr[S.idxTop];
}

int sizeStack(Stack S) {
    return S.idxTop + 1;
}

void clearStack(Stack *S) {
    S->idxTop = -1;
}

int getElementAt(Stack S, int index, webPage *result) {
    if (index < 0 || index > S.idxTop) return 0;
    *result = S.arr[index];
    return 1;
}

void destroyStack(Stack *S) {
    free(S->arr);
    S->arr = NULL;
    S->idxTop = -1;
    S->maxSize = 0;
}


void printTabHistory(Stack backStack, Stack forwardStack, webPage *currentPage) {
    int i;
    int idx = 0;

    for (i = 0; i <= backStack.idxTop; i++) {
        printf("[%d] %s\n", idx, backStack.arr[i].url);
        idx++;
    }

    if (currentPage != NULL) {
        printf("[%d] %s  <- YOU ARE HERE\n", idx, currentPage->url);
        idx++;
    }

    for (i = forwardStack.idxTop; i >= 0; i--) {
        printf("[%d] %s\n", idx, forwardStack.arr[i].url);
        idx++;
    }

    if (idx == 0) {
        printf("belum ada halaman yang pernah dibuka.\n");
    }
}
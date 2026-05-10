#include "stack.h"

void CreateStack(Stack *S) {
    S->top = -1;
}

int IsEmpty(Stack S) {
    return S.top == -1;
}

int IsFull(Stack S) {
    return S.top == MAX_STACK_SIZE - 1;
}

int Push(Stack *S, const char *url) {
    if (IsFull(*S)) return 0;
    S->top++;
    strncpy(S->data[S->top], url, MAX_URL_LENGTH - 1);
    S->data[S->top][MAX_URL_LENGTH - 1] = '\0';
    return 1;
}

int Pop(Stack *S, char *result) {
    if (IsEmpty(*S)) return 0;
    strncpy(result, S->data[S->top], MAX_URL_LENGTH - 1);
    result[MAX_URL_LENGTH - 1] = '\0';
    S->top--;
    return 1;
}

int Peek(Stack S, char *result) {
    if (IsEmpty(S)) return 0;
    strncpy(result, S.data[S.top], MAX_URL_LENGTH - 1);
    result[MAX_URL_LENGTH - 1] = '\0';
    return 1;
}

int SizeStack(Stack S) {
    return S.top + 1;
}

void ClearStack(Stack *S) {
    S->top = -1;
}

int GetElementAt(Stack S, int index, char *result) {
    if (index < 0 || index > S.top) return 0;
    strncpy(result, S.data[index], MAX_URL_LENGTH - 1);
    result[MAX_URL_LENGTH - 1] = '\0';
    return 1;
}

void PrintTabHistory(Stack backStack, Stack forwardStack, const char *currentUrl) {
    int i;
    int idx = 0;
    char url[MAX_URL_LENGTH];

    for (i = 0; i <= backStack.top; i++) {
        strncpy(url, backStack.data[i], MAX_URL_LENGTH - 1);
        url[MAX_URL_LENGTH - 1] = '\0';
        printf("[%d] %s\n", idx, url);
        idx++;
    }

    if (currentUrl != NULL && currentUrl[0] != '\0') {
        printf("[%d] %s  <- YOU ARE HERE\n", idx, currentUrl);
        idx++;
    }

    for (i = forwardStack.top; i >= 0; i--) {
        strncpy(url, forwardStack.data[i], MAX_URL_LENGTH - 1);
        url[MAX_URL_LENGTH - 1] = '\0';
        printf("[%d] %s\n", idx, url);
        idx++;
    }

    if (idx == 0) {
        printf("belum ada halaman yang pernah dibuka.\n");
    }
}
#include "../headerADT/tablist.h"
#include <stdlib.h>
#include <stdio.h>


void createTabList(TabList* L, int max){
    L->head = NULL;
    L->tail = NULL;
    L->currentSize = 0;
    L->maxSize = max;
}

Node* createNode (webPage data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->currentPage = data;
    createStack(&(newNode->forward));
    createStack(&(newNode->back));   
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addNodeToList (TabList* L, webPage page){
    if (L->currentSize < L->maxSize){
        Node* newNode = createNode(page);
        if (L->head == NULL){
            L->head = newNode;
            L->tail = newNode;
        } else {
            newNode->prev = L->tail;
            L->tail->next = newNode;
            L->tail = newNode;
        }
        L->currentSize++;
    } else {
        printf("Error: Maximum Tab Limit Reached.\n");
    }
}


//prosedur memasukan node baru di bagian akhir list
void insertAtTail(TabList* L, webPage data){
    if (L->currentSize < L->maxSize){
        Node* newNode = createNode(data);
        if (L->head == NULL){ // List Kosong
            L->head = newNode;
            L->tail = newNode;
        } else {
            newNode->prev = L->tail;
            L->tail->next = newNode;
            L->tail = newNode;
        }
        L->currentSize++;
    } else {
        printf("Error: Maximum Tab Limit Reached.\n");
    }
}
//prosedur memasukan node baru di bagian awal list
void insertAtHead(TabList* L, webPage data){
    if (L->currentSize < L->maxSize){
        Node* newNode = createNode(data);
        if (L->head == NULL){ // List Kosong
            L->head = newNode;
            L->tail = newNode;
        } else {
            newNode->next = L->head;
            L->head->prev = newNode;
            L->head = newNode;
        }
        L->currentSize++;
    } else {
        printf("Error: Maximum Tab Limit Reached.\n");
    }
}
//prosedur insert node pada posisi tertentu. Node head = posisi 1
void insertAtPosition(TabList* L, webPage data, int position){
    if (L->currentSize < L->maxSize){
        if (position>=1 && position<=L->currentSize + 1){
            if (position == 1) insertAtHead(L, data);
            else if (position == L->currentSize + 1) insertAtTail(L, data);
            else {
                Node* newNode = createNode(data);
                Node* temp = L->head;
                for (int i = 1; i < position; i++) {
                    temp = temp->next;
                }
                newNode->next = temp;
                newNode->prev = temp->prev;
                if (temp->prev != NULL) temp->prev->next = newNode;
                temp->prev = newNode;
                L->currentSize++;
            }
        } 
    } else {
        printf("Error: Maximum Tab Limit Reached.\n");
    }
}
//Menghapus node head
void deleteHead(TabList* L){
    if (L->head != NULL){
        Node* temp = L->head;
        L->head = L->head->next;
        if (L->head != NULL){
            L->head->prev = NULL;
        } else {
            L->tail = NULL;
        }
        free(temp);
        L->currentSize--;   
    }
}
void deleteAtPosition(TabList* L, int position){
    if (L->head != NULL && position>=1 && position<=L->currentSize){
        Node* curr = L->head;
        for(int i = 1; i<position; i++){
            curr = curr->next;
        }

        if(curr->next != NULL){
            curr->next->prev = curr->prev;
        } else {
            L->tail = curr->prev;
        }

        if (curr->prev != NULL){
            curr->prev->next = curr->next;
        } 
        if (curr->prev == NULL) L->head = curr->next;
        free(curr);
        L->currentSize--;
    }
}
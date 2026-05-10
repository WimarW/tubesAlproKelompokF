#ifndef QUEUE_H
#define QUEUE_H

#include "webpage.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE 100

typedef struct {
    webPage *list; //Akan di allocate secara dinamis nanti karena ada max queue sesuai dengan config
    int head;
    int tail;
}Queue;

//Membuat nilai head dan tail -1 
void createQueue(Queue *q){
    q->head = -1;
    q->tail = -1;
    q->list = (webPage*) malloc(MAX_QUEUE*sizeof(webPage));
}

bool isEmpty(Queue q){
    return q.head == -1 || q.tail == -1 || q.list == NULL;
}

bool isFull(Queue q){
    return q.tail - q.head + 1 == MAX_QUEUE;
}

int len(Queue q){
    if(isEmpty(q))return 0;
    return q.tail - q.head + 1;
}

//Menambahkan webPage pada queue di tail
void enqueue(Queue *q, webPage w){
    if(isFull(*q)){
        dequeue(q);
    }
    q->tail++;
    q->list[q->tail] = w;
}
//Menghapus webPage pada queue di head
void dequeue(Queue *q){
    q->head++;
    for(int i=0; i<len(*q); i++){
        q->list[i] = q->list[q->head+i];
    }
    q->tail = len(*q);
    q->head = 0;
}



#endif
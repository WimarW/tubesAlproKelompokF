#ifndef QUEUE_H
#define QUEUE_H

#include "webpage.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    webPage *list; //Akan di allocate secara dinamis nanti karena ada max queue sesuai dengan config
    int head;
    int tail;
}Queue;

//Membuat nilai head dan tail -1 
void createQueue(Queue *q);
bool isEmpty(Queue q);
bool isFull(Queue q);
//Menambahkan webPage pada queue di tail
void enqueue(Queue *q, webPage);
//Menghapus webPage pada queue di head
void dequeue(Queue *q);



#endif
#ifndef LIST_H
#define LIST_H

#include "webpage.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define initialSize 20

typedef int ElType;


typedef struct {
    int nEff;
    int size; // Ukuran Alokasi saat ini
    ElType* contents;// Array dinamis
} List;

//Menginisialisasi list dengan ukuran array initialSize
void createList(List* l);
void insertAt(List* l, ElType val, int idx);
void deleteAt(List* l, int idx);
bool isEmpty(List l);
bool isFull(List l);

#endif
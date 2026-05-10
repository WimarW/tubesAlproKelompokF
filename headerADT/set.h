#ifndef SET_H
#define SET_H

#include "webpage.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Kalo mau buat searchingnya lebih cepet buat setnya jadi Binary Search Tree diurutin berdasarkan Url pake strcmp(??)

typedef struct {
    int *l;
    int *r;
    webPage w;
}node;

typedef struct {
    int length;
    node *buffer; // Dialokasisakn nanti seacara dinamis karena ada max page number
}Set;

void createSet(Set* s);
bool isEmpty(Set s);
bool isFull(Set s);
int length(Set s); // return jumlah element
bool isInSet(Set *s, webPage x); //Cek apakah webPage x ada di set 

#endif
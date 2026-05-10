#ifndef SET_H
#define SET_H

#include "webpage.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 10

// Kalo mau buat searchingnya lebih cepet buat setnya jadi Binary Search Tree diurutin berdasarkan Url pake strcmp(??)

typedef struct {
    int l;
    int r;
    webPage w;
}node;

typedef struct {
    int length;
    node *buffer; // Dialokasisakn nanti seacara dinamis karena ada max page number
}Set;

void createSet(Set* s){
    s->length = 0;
    s->buffer = (node*) malloc(sizeof(node));
}
bool isEmpty(Set s){
    return s.length == 0;
}
bool isFull(Set s){
    return s.length == MAX_LEN;
}
int length(Set s){
    return s.length;
} // return jumlah element
bool isInSet(Set *s, webPage x, int idx){
    if(idx == -1)return false;
    if(s->buffer[idx].w.id == x.id) return true;
    if(s->buffer[idx].w.id < x.id)return isInSet(s, x, s->buffer[idx].l);
    return isInSet(s, x, s->buffer[idx].r);
} //Cek apakah webPage x ada di set 

void insert(Set *s, webPage x){
    if(isEmpty(*s)){
        s->buffer[0].w = x;
        s->buffer[0].l = -1;
        s->buffer[0].r = -1;
    }
    if(!isEmpty(*s) && isInSet(s, x, 0))return;
    int idx = 0;
    while(s->buffer[idx].l != -1 || s->buffer[idx].r != -1){
        if(s->buffer[idx].w.id > x.id){
            if(s->buffer[idx].l == -1){
                s->buffer = (node*) realloc(s->buffer, (s->length+1)*sizeof(node));
                s->buffer[idx].l = s->length;
                s->buffer[s->length].w = x;
                s->buffer[s->length].l = -1;
                s->buffer[s->length].r = -1;
                idx = s->length;
                s->length++;
            }else{
                idx = s->buffer[idx].l;
            }
        }else{
            if(s->buffer[idx].r == -1){
                s->buffer = (node*) realloc(s->buffer, (s->length+1)*sizeof(node));
                s->buffer[idx].r = s->length;
                s->buffer[s->length].w = x;
                s->buffer[s->length].l = -1;
                s->buffer[s->length].r = -1;
                idx = s->length;
                s->length++;
            }else{
                idx = s->buffer[idx].r;
            }
        }
    }
}

#endif
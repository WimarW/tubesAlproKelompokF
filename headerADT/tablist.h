#ifndef TABLIST_H
#define TABLIST_H

#include "webpage.h"
#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
//Kasi cara buat keep track jumlah tab karena ada max tab amount

typedef struct Node {
    webPage currentPage; // Halaman saat ini
    Stack forward; // Stack yang berisi History Tab Maju
    Stack back; // Stack yang berisi History Tab mundur
    //Pointer ke node tetangga
    struct Node* next; // Pointer to next node
    struct Node* prev; // Pointer to prev node
} Node; // Setiap Node adalah Tab sendiri

typedef struct {
    Node* head;
    Node* tail;
    int currentSize;
    int maxSize; // Diberi nilai saat setup di main
} TabList;


// =====ADT Doubly Linked List=====
// Pointer prev == Null if its head node
// Pointer next == Null if its tail node
// Membuat node dengan Node next dan prev NULL
void createTabList(TabList* L, int max);
Node* createNode(TabList* L, webPage page) 
void addNodeToList (TabList* L , webPage page); 
//prosedur memasukan node baru di bagian akhir list
void insertAtTail(TabList* L, webPage data); // Bs dikasi input webPage default atau gimana??
//prosedur memasukan node baru di bagian awal list
void insertAtHead(TabList* L, int data);
//prosedur insert node pada posisi tertentu. Node head = posisi 1
void insertAtPosition(TabList* L, int data, int position);
//Menghapus node head
void deleteHead(TabList* L);
//Menghapus node tail
void deleteTail(TabList* L);
void deleteAtPosition(TabList* L, int position);


// ====Fungsi navigasi Tab ==== TBD




#endif
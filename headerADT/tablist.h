#ifndef TABLIST_H
#define TABLIST_H

#include "webpage.h"
#include "stack.h"

//Kasi cara buat keep track jumlah tab karena ada max tab amount

typedef struct {
    webPage currentPage; // Halaman saat ini
    Stack forward; // Stack yang berisi History Tab Maju
    Stack back; // Stack yang berisi History Tab mundur
    //Pointer ke node tetangga
    struct Node* next; // Pointer to next node
    struct Node* prev; // Pointer to prev node
} Node; // Setiap Node adalah Tab sendiri


// =====ADT Doubly Linked List=====
// Pointer prev == Null if its head node
// Pointer next == Null if its tail node
// Membuat node dengan Node next dan prev NULL
Node* createNode (webPage data); 

//prosedur memasukan node baru di bagian akhir list
void insertAtTail(Node** head, webPage data); // Bs dikasi input webPage default atau gimana??
//prosedur memasukan node baru di bagian awal list
void insertAtHead(Node** head, int data);
//prosedur insert node pada posisi tertentu. Node head = posisi 1
void insertAtPosition(Node** head, int data, int position)
//Menghapus node head
void deleteHead(Node** head);
//Menghapus node tail
void deleteTail(Node** tail);

void deleteAtPosition(Node** tab);


// ====Fungsi navigasi Tab ==== TBD




#endif
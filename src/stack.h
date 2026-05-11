#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH  256
#define MAX_STACK_SIZE  1000 

typedef char ElType[MAX_URL_LENGTH];
typedef struct {
    ElType data[MAX_STACK_SIZE];
    int    top;                  
} Stack;

/**
 * CreateStack - Menginisialisasi stack menjadi kosong.
 * I.S. : S sembarang
 * F.S. : S.top = -1 (stack kosong)
 */
void CreateStack(Stack *S);

/**
 * IsEmpty - Mengecek apakah stack kosong.
 * @return 1 jika kosong, 0 jika engga
 */
int IsEmpty(Stack S);

/**
 * IsFull - Mengecek apakah stack penuh.
 * @return 1 jika penuh, 0 jika engga
 */
int IsFull(Stack S);

/**
 * Push - Menambahkan elemen ke puncak stack.
 * I.S. : Stack tidak penuh
 * F.S. : Elemen url ditambahkan di atas stack
 * @param S   pointer ke Stack
 * @param url URL yang akan di push
 * @return    1 jika berhasil, 0 jika stack penuh
 */
int Push(Stack *S, const char *url);

/**
 * Pop - Mengambil dan menghapus elemen dari puncak stack.
 * I.S. : Stack tidak kosong
 * F.S. : Elemen puncak dihapus, nilainya disalin ke result
 * @param S      pointer ke Stack
 * @param result buffer untuk menyimpan URL yang di-pop
 * @return       1 jika berhasil, 0 jika stack kosong
 */
int Pop(Stack *S, char *result);

/**
 * Peek - Melihat elemen puncak stack tanpa menghapusnya.
 * I.S. : Stack tidak kosong
 * F.S. : Nilai puncak disalin ke result, stack tidak berubah
 * @param S      Stack (by value)
 * @param result buffer untuk menyimpan URL puncak
 * @return       1 jika berhasil, 0 jika stack kosong
 */
int Peek(Stack S, char *result);

/**
 * SizeStack - Mengembalikan jumlah elemen dalam stack.
 * @return jumlah elemen (0 jika kosong)
 */
int SizeStack(Stack S);

/**
 * ClearStack - Mengosongkan seluruh isi stack.
 * I.S. : S sembarang
 * F.S. : S.top = -1 (stack kosong)
 */
void ClearStack(Stack *S);

/**
 * GetElementAt - Mengambil elemen stack pada indeks tertentu.
 * @param S      Stack (by value)
 * @param index  Indeks elemen yang ingin diambil (0 s.d. top)
 * @param result buffer untuk menyimpan URL
 * @return       1 jika valid, 0 jika indeks di luar range
 */
int GetElementAt(Stack S, int index, char *result);

/**
 * PrintStack - Mencetak isi stack dari bawah ke atas (untuk debugging / view history).
 * Format: [index] url  
 * @param backStack     Stack back (history yang sudah dikunjungi)
 * @param forwardStack  Stack forward (history setelah posisi saat ini)
 * @param currentUrl    URL halaman yang sedang aktif
 */
void PrintTabHistory(Stack backStack, Stack forwardStack, const char *currentUrl);

#endif
#ifndef MATRIX_H
#define MATRIX_H

#include "webpage.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
   int *mem; // Karena ada maxPage, ukurannya akan di malloc saat dibaca file config
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;

// ==== ADT MATRIX ====
// Set rowEff dan colEff == 0 dan malloc array 2D mem
void createMatrix(Matrix* M, int maxPage);
//Cek apakah index ada di range rowEff dan colEff 
bool isIdxEff(int i, int j, Matrix M);

// Getter Setter
int getElement(Matrix* M, int row, int col);
int setElement(Matrix* M, int row, int col, int val);

// ==== Fungsi Adjacency matrix ====
// Baca file linked_pages.csv dan buat adjacency matrix

#endif

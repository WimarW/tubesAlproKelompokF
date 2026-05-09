#ifndef MAP_H
#define MAP_H

#include "webpage.h"

#include <stdio.h>
#include <stdlib.h>

//Nanti juga hrs implement cara buat ngitung jumlah Entry krn Cache ada Maxnya

typedef struct {
    char* key; // Pake ID
    webPage page;
    struct* entryNext;
} Entry;

typedef struct {
    struct Entry* head;
} Map;


Map* createMap();
// Menambahkan atau mengubah entry
void put(Map* m, char* key, webPage page);
//Mengambil Halaman web
webPage get(Map* m, char* key);

#endif


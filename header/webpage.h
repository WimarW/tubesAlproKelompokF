#ifndef WEBPAGE_H
#define WEBPAGE_H
// Struct untuk webpage
typedef struct {
    int id;
    char *url; // Dinamis nanti di malloc saat input/diganti
    char *content; // Dinamis nanti di malloc saat input/diganti
} webPage;

#endif
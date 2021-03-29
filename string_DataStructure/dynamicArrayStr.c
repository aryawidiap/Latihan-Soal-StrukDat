/**
 * Implementasi ADT Dynamic Array
 * 
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 * 
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LEN 100 //max string length
// Struktur ADT DynamicArray

typedef struct dynamicarr_t {
    char **_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi

void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, char value[MAX_LEN+1]);
void dArray_popBack(DynamicArray *darray);
char*  dArray_back(DynamicArray *darray);
char*  dArray_front(DynamicArray *darray);
void dArray_setAt(DynamicArray *darray, unsigned index, char value[MAX_LEN+1]);
char* dArray_getAt(DynamicArray *darray, unsigned index);

// Definisi fungsi

void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (char**) malloc(sizeof(char*) * 2);
    for(int i=0; i<2; i++){
        darray->_arr[i] = (char*) malloc(sizeof(char)*(MAX_LEN+1));
    }

}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, char value[MAX_LEN+1])
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        char **newArr = (char**) malloc(sizeof(char*) * darray->_capacity);
        for(int i=0; i<darray->_capacity; i++){
            newArr[i] = (char*) malloc(sizeof(char)*(MAX_LEN+1));
        }

        for (it=0; it < darray->_size; ++it)
            strcpy(newArr[it], darray->_arr[it]);
        
        char **oldArray= darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    strcpy(darray->_arr[darray->_size++], value);
}

void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}

char* dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}

char* dArray_front(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    else return 0;
}

void dArray_setAt(
    DynamicArray *darray, unsigned index, char value[MAX_LEN+1])
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            strcpy(darray->_arr[darray->_size-1], value);
        else
            strcpy(darray->_arr[index], value);
    }
}

char* dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

/* Gunakan ini untuk mempersingkat penulisan kode */

#define d_init dArray_init
#define d_isEmpty dArray_isEmpty
#define d_pushBack dArray_pushBack
#define d_popBack dArray_popBack
#define d_back dArray_back
#define d_front dArray_front
#define d_setAt dArray_setAt
#define d_getAt dArray_getAt

/* */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Buat objek DynamicArray
    DynamicArray myArray;

    // PENTING! Jangan lupa diinisialisasi
    dArray_init(&myArray);

    // Operasi-operasi
    // myArray => [11, 14, 17, 23]
    dArray_pushBack(&myArray, "11");
    dArray_pushBack(&myArray, "14");
    dArray_pushBack(&myArray, "17");
    dArray_pushBack(&myArray, "23");
    d_setAt(&myArray, 1, "hai");
    // isi myArray => [11, 14, 17]
    dArray_popBack(&myArray);

    int i = 0;
    for (; i < myArray._size; ++i) {
        printf("%s ", dArray_getAt(&myArray, i));
    }

    printf("\n");
    while (!dArray_isEmpty(&myArray)) {
        printf("%s ", dArray_back(&myArray));
        dArray_popBack(&myArray);
    }
    printf("\n");
    
    return 0;
}
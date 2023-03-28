#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList * arrList = (ArrayList *) malloc(sizeof(ArrayList));
  arrList->data = (void **) malloc(2 * sizeof(void *));
  arrList->capacity = 2;
  arrList->size = 0;
  return arrList;
}

void resize(ArrayList * l){
  l->capacity = l->capacity * 2;
  l->data = (void **) realloc(l->data, l->capacity * sizeof(void *));
}

void append(ArrayList * l, void * data){
  if(l->size == l->capacity)
    resize(l);
  l->data[l->size] = data;
  l->size += 1;
}

void push(ArrayList * l, void * data, int i){
  if(i <= l->size){
    if(l->size == l->capacity)
      resize(l);
    for(int indx = l->size; indx > i; indx--){
      l->data[indx] = l->data[indx-1];
    }
    l->data[i] = data;
    l->size += 1;
  }
}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}

#include "arraylist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// normal array
typedef struct ArrayList {
  void **data;
  int capacity;
  int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *arrList = (ArrayList *)malloc(sizeof(ArrayList));
  arrList->data = (void **)malloc(2 * sizeof(void *));
  arrList->capacity = 2;
  arrList->size = 0;
  return arrList;
}

void resize(ArrayList *l) {
  l->capacity = l->capacity * 2;
  l->data = (void **)realloc(l->data, l->capacity * sizeof(void *));
}

void append(ArrayList *l, void *data) {
  if (l->size == l->capacity)
    resize(l);
  l->data[l->size] = data;
  l->size += 1;
}

void push(ArrayList *l, void *data, int i) {
  if (i <= l->size && i >= 0) {
    if (l->size == l->capacity)
      resize(l);
    for (int indx = l->size; indx > i; indx--) {
      l->data[indx] = l->data[indx - 1];
    }
    l->data[i] = data;
    l->size += 1;
  }
}

void *pop(ArrayList *l, int i) {
  if (i >= l->size || i < l->size * (-1) || l->size == 0)
    return NULL;
  if (i < 0)
    i = l->size + i;
  void *data = l->data[i];
  for (int indx = i; indx < l->size - 1; indx++) {
    l->data[indx] = l->data[indx + 1];
  }
  return data;
}

void *get(ArrayList *l, int i) {
  if (i >= l->size || i < l->size * (-1))
    return NULL;
  if (i >= 0)
    return l->data[i];
  return l->data[l->size + i];
}

int get_size(ArrayList *l) { return l->size; }

// remove elements
void clean(ArrayList *l) {
  free(l);
  l = createList();
}

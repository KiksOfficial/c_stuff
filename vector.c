#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
  int *data;
  size_t cap;
  size_t size;
} Vector;

Vector *init_vec(size_t initial_cap) {

  Vector *vec = malloc(sizeof(Vector));

  if (vec == NULL) {
    return NULL;
  }

  vec->data = malloc(initial_cap * sizeof(int));

  if (vec->data == NULL) {
    free(vec);
    return NULL;
  }

  vec->size = 0;
  vec->cap = initial_cap;

  return vec;
}

Vector *add_value(Vector *vec, int value) {

  if (vec->size == vec->cap) {
    size_t new_cap = vec->cap * 2;

    int *temp = realloc(vec->data, new_cap * sizeof(int));

    if (temp == NULL) {
      return NULL;
    }

    vec->data = temp;
    vec->cap = new_cap;
  }

  vec->data[vec->size] = value;
  vec->size++;

  return vec;
}

int free_vec(Vector *vec) {
  if (vec == NULL) {
    return 1;
  }
  free(vec->data);
  free(vec);
  return 0;
}

int remove_value(Vector *vec, int index) {
  if (vec == NULL || vec->size <= index) {
    return 1;
  }
  vec->data[index] = vec->data[vec->size - 1];
  vec->size--;

  return 0;
}

int display_vec(Vector *vec) {
  for (size_t i = 0; i < vec->size; i++) {
    printf("%d ", vec->data[i]);
  }
  printf("\n");
  return 0;
}

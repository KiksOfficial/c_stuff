#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int value;
  struct NODE *next;
} NODE;

int init_vector(NODE **vec) {
  *vec = NULL;
  return 0;
};

int add_value(NODE **vec, int new_value) {
  NODE *newptr = malloc(sizeof(NODE));
  if (newptr == NULL) {
    return 1;
  }
  newptr->value = new_value;
  newptr->next = *vec;
  *vec = newptr;

  return 0;
}

int print_vec(NODE *vec) {
  NODE *current = vec;
  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }

  return 0;
}

int free_vec(NODE **vec) {
  NODE *current = *vec;
  NODE *next_node;

  while (current != NULL) {
    next_node = current->next;
    free(current);
    current = next_node;
  }
  *vec = NULL;
  return 0;
}

int get_len(NODE **vec) {

  NODE *current = *vec;
  size_t sum = 0;

  while (current != NULL) {
    sum++;
    current = current->next;
  }

  printf("Len: %zu\n", sum);
  return 0;
}

int main(void) {
  NODE *vec1;

  init_vector(&vec1);

  add_value(&vec1, 10);
  add_value(&vec1, 20);
  add_value(&vec1, 30);
  print_vec(vec1);

  get_len(&vec1);

  free_vec(&vec1);

  return 0;
}

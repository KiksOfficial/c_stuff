#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  size_t capacity = 1024;
  char *buffer = malloc(capacity);

  if (argc < 3) {
    perror("grep-btw");
    free(buffer);
    buffer = NULL;
    return 1;
  }
  FILE *fptr = fopen(argv[2], "r");
  if (fptr == NULL) {
    free(buffer);
    buffer = NULL;
    return 1;
  }

  while (fgets(buffer, capacity, fptr) != NULL) {
    if (strstr(buffer, argv[1])) {
      printf("%s", buffer);
    }
  }

  fclose(fptr);
  free(buffer);
  buffer = NULL;
  return 0;
}

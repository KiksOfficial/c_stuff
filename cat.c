#include <stdio.h>

int main(int argc, char *argv[]) {

  char buffer[1024];
  if (argc < 2) {
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      printf("%s", buffer);
    }
    return 0;
  }

  for (int i = 0; i < argc; i++) {
    FILE *fptr = fopen(argv[i], "r");

    if (fptr == NULL) {
      continue;
    }

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
      printf("%s", buffer);
    }

    fclose(fptr);
  }

  return 0;
}

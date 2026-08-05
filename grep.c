#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  char buffer[1024];

  if (argc < 3) {
    printf("Not enough args\n");
    return 1;
  }
  FILE *fptr = fopen(argv[1], "r");
  if (fptr == NULL) {
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
    if (strstr(buffer, argv[2])) {
      printf("%s", buffer);
    }
  }

  fclose(fptr);
  return 0;
}

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  int in_word = 0;
  size_t lines = 0;
  size_t words = 0;
  size_t bytes = 0;

  FILE *fptr = fopen(argv[1], "r");

  if (fptr == NULL) {
    return 1;
  }

  int c;

  while (((c = fgetc(fptr)) != EOF)) {
    bytes++;

    if (c == '\n') {
      lines++;
    }
    if (isspace((unsigned char)c)) {
      in_word = 0;

    } else if (!in_word) {
      words++;
      if (c == '\n') {
        lines++;
      }
    }
  }

  fclose(fptr);
  printf("words: %zu, lines: %zu, bytes: %zu \n", words, lines, bytes);

  return 0;
}

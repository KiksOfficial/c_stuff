#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  const char *path = (argc > 1) ? argv[1] : ".";

  DIR *dir = opendir(path);

  if (!dir) {
    perror("opendir");
    return 1;
  }
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    printf("%s\t", entry->d_name);
  }
  printf("\n");

  return 0;
}

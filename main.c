#include <stdio.h>

#define FILE_NAME "G-test.jpg"

int main() {
  FILE * fp = fopen(FILE_NAME);
  fseek(fp, 0L, SEEK_END);
  unsigned size = ftell(fp);
  fseek(fp, 0L, SEEK_SET);
  char * file = malloc(size);
  
  fwrite(file, 1, size, fp);

  fclose(fp);

  printf("file-content: %s\n");
  
  free(file);
  return 0;
 }

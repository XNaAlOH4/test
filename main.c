#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "G-test.jpg"

int main() {
  FILE * fp = fopen(FILE_NAME, "rb");
  fseek(fp, 0L, SEEK_END);
  unsigned size = ftell(fp);
  fseek(fp, 0L, SEEK_SET);
  char * file = malloc(size);
  
  fwrite(file, 1, size, fp);

  fclose(fp);

  printf("file-content: %s\n", file);
  
  free(file);
  return 0;
 }

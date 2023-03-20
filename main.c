#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "G-test.jpg"

#define JPG_SIG 0xE0FFD8FF

char isJPG(char *p) {
  return JPG_SIG == *(unsigned*)p;
}

int main() {
  FILE * fp = fopen(FILE_NAME, "rb");
  fseek(fp, 0L, SEEK_END);
  unsigned size = ftell(fp);
  fseek(fp, 0L, SEEK_SET);
  char * file = malloc(size);
  
  fwrite(file, 1, size, fp);

  fclose(fp);

  printf("file size: %u\n", size);
  printf("isJPG = %d\n", isJPG(file));
  printf("file-content: %s\n", file);
  
  free(file);
  return 0;
 }

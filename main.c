#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "G-test.jpg"

#define JPG_SIG 0xE0FFD8FF
#define JPG_SOI (unsigned short) 0xFFD8
#define JPG_APP (unsigned short) 0xFFE0
#define JPG_SOF (unsigned short) 0xFFC0
#define JPG2SOF (unsigned short) 0xFFC2
#define JPG_DHT (unsigned short) 0xFFC4
#define JPG_DQT (unsigned short) 0xFFDB
#define JPG_DRI (unsigned short) 0xFFDD
#define JPG_SOS (unsigned short) 0xFFDA
#define JPG_RST (unsigned short) 0xFFD0
#define JPG_COM (unsigned short) 0xFFFE
#define JPG_EOI (unsigned short) 0xFFD9

char isJPG(char *p) {
  return JPG_SIG == JPG_SIG&*(unsigned*)p;
}

int main() {
  FILE * fp = fopen(FILE_NAME, "rb");
  fseek(fp, 0L, SEEK_END);
  unsigned size = ftell(fp);
  fseek(fp, 0L, SEEK_SET);
  unsigned char * file = malloc(size);
  
  fread(file, 1, size, fp);

  fclose(fp);

  printf("file size: %u\n", size);
  printf("isJPG = %d\n", isJPG(file));

  for(int i = 0; i < 20; i++) {
    printf("{%x,%c},", file[i], file[i]);
  }
  printf("file-content: %d,%d,%d,%d\n", file[0], file[1], file[2], file[3]);
  
  free(file);
  printf("Finished\n");
  return 0;
 }

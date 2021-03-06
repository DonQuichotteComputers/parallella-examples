#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BENCH_INIT 0
#define BENCH_MAX  1023

const unsigned char tbench[16][17]={
  { 0xFF,0xED,0xDF,0xFC,0xFF,0xF4,0xFF,0xFF,0x25,0x7E,0xEB,0xEF,0x79,0x02,0x05,0x84,0x43 },
  { 0xE5,0xFF,0xFB,0xFB,0xEF,0xFE,0xFF,0xFB,0xF5,0xFA,0x56,0xBE,0x39,0x19,0x17,0x15,0x44 },
  { 0xFE,0xBF,0xFF,0xDF,0xEC,0xFB,0xFF,0xFE,0x8D,0x1F,0xAF,0xBF,0x82,0x23,0x45,0x50,0x23 },
  { 0xFF,0xF5,0xFF,0xFF,0x6E,0xFF,0xFF,0x3B,0x5C,0x0F,0xDF,0xF7,0x32,0x79,0x03,0x97,0x23 },
  { 0xBF,0xFF,0xFF,0xF9,0x7F,0xF7,0xDE,0xDF,0x3C,0x3E,0x9D,0xFF,0x55,0x58,0x03,0x46,0x33 },
  { 0xE6,0xD7,0xDF,0xFF,0xFF,0xFF,0xEF,0xFD,0xDD,0x6E,0x5B,0x6F,0x79,0x13,0x30,0x83,0x43 },
  { 0xFE,0xFB,0xF3,0xEB,0xFF,0x7F,0xFD,0xFF,0xF9,0xE7,0xC8,0xFD,0x63,0x00,0x35,0x33,0x34 },
  { 0xEF,0xF7,0xFD,0xF7,0xFE,0xF1,0xFF,0xFF,0xF8,0xBB,0x4F,0xAF,0x27,0x50,0x62,0x30,0x13 },
  { 0xFE,0xF7,0xF7,0xF0,0xFB,0xFF,0xFF,0xFF,0xF9,0x3E,0x5F,0x4F,0x55,0x53,0x10,0x57,0x43 },
  { 0xBF,0xF6,0xDF,0xEF,0xFF,0xFE,0xBF,0xF7,0x6C,0x9E,0x9B,0xFF,0x33,0x22,0x22,0x98,0x23 },
  { 0xFF,0xEF,0x4F,0xBB,0xBF,0xBF,0xFF,0xFF,0x68,0xFC,0xEF,0xE7,0x69,0x31,0x02,0x93,0x13 },
  { 0xBB,0xFD,0xF7,0xFF,0x9F,0xFF,0xFB,0xFE,0xE1,0xFB,0xAD,0xDD,0x22,0x37,0x15,0x60,0x34 },
  { 0x7F,0xCE,0xFF,0xBD,0xFF,0xFE,0xEF,0xFF,0xE5,0x7A,0x78,0xFF,0x13,0x50,0x07,0x00,0x34 },
  { 0xFC,0xFF,0x7F,0xFE,0xDF,0xFD,0x3F,0xFF,0x64,0xFA,0xE7,0x7F,0x82,0x58,0x99,0x05,0x14 },
  { 0xFF,0x7B,0xF7,0xB3,0xFF,0xFF,0xFE,0xBF,0xB7,0x36,0xEC,0xFE,0x64,0x57,0x11,0x06,0x44 },
  { 0xFD,0xEF,0xDF,0xFB,0x7F,0xFF,0xF2,0xFF,0xF2,0x73,0x3F,0x3F,0x19,0x96,0x07,0x19,0x14 },
};

int main(void) {
	unsigned i, j;
  FILE *f;
  
  f=fopen("bin/bench.bin", "wb");
  if(f == NULL) { printf("Error writing bin/bench.bin\n"); exit(-1); }
  
  for(i=0; i<2048; i++)
    j=fwrite(tbench, 17*16, 1, f);
  fclose(f);
  
  return 0;
}

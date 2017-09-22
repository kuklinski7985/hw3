/*********************************************************************************
 *Author: Andrew Kuklinski
 *Desrcption: hw#3 memory simulation,question 2
 *Due: 9-22-2017
**********************************************************************************/
# include <stdio.h>

int main (){
  const int MAX = 8;
  unsigned char memArray[MAX];
  /*these values were provided as startng point in question*/
  memArray[0] = 0xEE;
  memArray[1] = 0x12;
  memArray[2] = 0x77;
  memArray[3] = 0xBE;
  memArray[4] = 0x66;
  memArray[5] = 0x54;
  memArray[6] = 0x33;
  memArray[7] = 0xF0;

  unsigned char orgArray[MAX];
  /*writting values into seperate array for output later*/
  for (int i=0; i<MAX; i++)
  {
    orgArray[i] = memArray[i];
  }

  /*pointer work provided in question*/
  unsigned char *ptr = memArray;

  *ptr = 0xF1 & 127;
  ptr++;
  *ptr += 17;
  ptr += 2;             
  *ptr = 15 % 4;
  ptr--;
  *ptr >>=4;
  ptr += 3;
  *ptr= (1<<5) | (4<<2);
  ptr += 2;
  *ptr = 22;

  /*output*/
  printf("         HW#3 Problem 2        \n");
  printf("  Address   | Data |Data After|\n");
  for (int i=0; i<MAX; i++)
  {
      printf(" %p | 0x%02x |   0x%02x   | \n",&memArray[i],orgArray[i],memArray[i]);
  }
 
  return 0;
}

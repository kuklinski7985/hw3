
/*********************************************************************************
 *Author: Andrew Kuklinski
 *Class: ECEN 5813 - Embedded System Programming
 *Desrcption: hw3, problem 3.3, reverse function().  accepts string and length
 *            and outputs the reverse.  3 function calls with test cases are 
 *            are provided in homework
 *Due: 9-22-2017
**********************************************************************************/

#include <stdio.h>


char reverse(char * str, int length);

void main(){
  
  printf("If your input string has action ASCII values,\n");
  printf("they are displayed in decimal form inside<>.\n");
  
  int length = 17;
  char inputArray1[] = "This is a string.";
  reverse(inputArray1, length);
  
  length = 18;
  char inputArray2[] = "some NUMmbers12345";
  reverse(inputArray2, length);
  
  length = 30;
  char inputArray3[] = "Does it reverse \n\0\t correctly?";
  reverse(inputArray3, length);
}

char reverse(char * str, int length)
{
  char *ptrHead;    //creating a pointer which points the the start of the str array
  char *ptrTail;    //createing another pointer which points to the end of the array
  ptrHead = str;   //initialize head pointer to the starting element in the str array
  ptrTail = str + (length-1); 	//initialize tail pointer to end of array.

  //creates and initializes the original array for error checking comparison
  char testArray[length];
  char *testPtr = testArray;
  
  for(int i=0; length > i ; i++)
  {
    *testPtr = *ptrHead;
    ptrHead++;
    testPtr++;
  }
  
  ptrHead = str;		//set ptrHead back to start of array
  char intermediate = '0';
  int counter = 0;		//counts the number of iterations in shifting

  //tests even and odd instances using intermediate variable
  while(!((ptrHead == ptrTail) || (ptrHead == (ptrTail -1))))
  {
    intermediate = *ptrHead;
    *ptrHead = *ptrTail;
    *ptrTail = intermediate;
    ptrHead++;
    ptrTail--;
    counter++;
    if(ptrHead == (ptrTail-1))
    {
      intermediate = *ptrHead;
      *ptrHead = *ptrTail;
      *ptrTail = intermediate; 
    }
  }
  
  ptrHead = str;
  testPtr = testArray;
  /*prints out the original string*/
  printf("\noriginal string: ");
  for(int i=0; length > i ; i++)
  {
    if ((*testPtr >=0) && (*testPtr <32))
    {
      printf("<%d>",*testPtr);
    }
    else
    {
      printf("%c",*testPtr);
    }
    testPtr++;
  }

  /*prints out the reversed string*/
  printf("\nreverse string : ");
  for(int i=0;length > i; i++)
  {
    if ((*ptrHead >=0) && (*ptrHead<32))
    {
      printf("<%d>",*ptrHead);
    }
    else
    {
      printf("%c",*ptrHead);
    }
    ptrHead++;
  }
  
  
  /*compares the flipped str array with original state of str array
    returns 1 if opposite ends dont match as being read through*/
  ptrHead = testArray;
  ptrTail = str + (length - 1);

  for(int j=0; length > j;  j++)
  {
    if(*ptrHead != *ptrTail)
    {
      printf("Array reversal failed!\n");
      return 1;
    }
    ptrHead++;
    ptrTail--;
  }
  printf("\nReversal SUCCESS!!!!!!!!!!!\n");
  return 0;		//returns 0 if no issue.
}

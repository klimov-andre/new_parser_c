typedef struct
{
    int Hello1;
    int Hello2;
    int Hello3;
}Hello;

Hello hello;

int value = 3;  



typedef enum {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    INDIGO,
    VIOLET
} colors;

#include <stdio.h>
static struct myEnum {
  int A;
  int B;
  int C;
  int D;
  int E;
  int F;
} Val = {0, 2, 10, 12, 25, 30};



int main() {
	if(value == 0)
{}

	
 

    switch (c) {
    case 1:
        //...
    case 2:
        //...
    case 3:
        //...
        //wrong: does not use all enum values, and has no default
    2+2;
    }
 
    switch(c) {
    case 4:
    i+=090999;
        //...
    case 5:
    default:
    }


	int test;
  printf("sizeof(Val)=%d\nsizeof(Val.A)=%d\n", sizeof(Val), sizeof(Val.A));
  for (test = 0; test < sizeof(Val)/sizeof(Val.A); ++test) {
    printf("test %d Val = %d\n",test, *(&Val.A+test));
  }
}

#include <stdio.h>
 
int main()
{
    printf( "Что бы сегодня посмотреть?\n" );
    printf( "1. Стрела(Arrow)\n" );
    printf( "2. Сверхъестественное(Supernatural)\n" );
    printf( "3. Ходячие мертвецы(Walking Dead)\n" );
    printf( "4. Выход\n" );
    printf( "Ваш выбор: " );
    int input;
     float a, b, c;
    char op;
 
	switch(3){
		
	}

	switch(3,5,6, x = 2) {
		for (;;);

	}

    scanf( "%d", &input );
    switch ( input ) {
        case 1:            /* обратите внимание на двоеточие, точки сзапятой тут нет */
            printf("«His Death Was Just The Beginning»\n");
            break;
        case 2:
            printf("«Scary Just Got Sexy»\n");
            break;
        case 3:
            printf("«Fight the dead. Fear the living»\n");
            break;
        case 4:
            printf( "Сегодня смотреть ничего не будем :(\n" );
            break;
        default:
            printf( "Неправильный ввод.\n" );
    }
    getchar();

    char grade = 'B';

   switch(grade) {
      case 'A' :
         printf("Excellent!\n" );
         break;
      case 'B' :
      case 'C' :
         printf("Well done\n" );
         break;
      case 'D' :
        switch ( input ) {
        case 1:            /* обратите внимание на двоеточие, точки сзапятой тут нет */
            printf("«His Death Was Just The Beginning»\n");
            break;
        case 2:
            printf("«Scary Just Got Sexy»\n");
            break;
        case 3:
            printf("«Fight the dead. Fear the living»\n");
            break;
        case 4:
            printf( "Сегодня смотреть ничего не будем :(\n" );
            break;
        default:
            printf( "Неправильный ввод.\n" );
            switch (op) {
        case '+': {
            c = a + b;
            break;
        }
        case '-': {
            c = a - b;
            break;
        }
        case '/': {
            if (b != 0.0) {
                c = a / b;
            } else {
                printf("Error: divide by zero");
               
            }
            break;
        }
        case '*': {
            c = a * b;
            break;
        }
        default:
            printf("No operation defined");
           
    }
    }
         printf("You passed\n" );
         break;
      case 'F' :
         printf("Better try again\n" );
         break;
      default :
         printf("Invalid grade\n" );
   }
   
   printf("Your grade is  %c\n", grade );

  
    scanf("%f %c %f", &a, &op, &b);
    switch (op) {
        case '+': {
            c = a + b;
            break;
        }
        case '-': {
            c = a - b;
            break;
        }
        case '/': {
            if (b != 0.0) {
                c = a / b;
            } else {
                printf("Error: divide by zero");
                switch (op) {
                    switch ( input ) {
        case 1:            /* обратите внимание на двоеточие, точки сзапятой тут нет */
            printf("«His Death Was Just The Beginning»\n");
            break;
        case 2:
            printf("«Scary Just Got Sexy»\n");
            break;
        case 3:
            printf("«Fight the dead. Fear the living»\n");
            break;
        case 4:
            printf( "Сегодня смотреть ничего не будем :(\n" );
            break;
        default:
            printf( "Неправильный ввод.\n" );
    }
        case '+': {
            c = a + b;
            break;
        }
        case '-': {
            c = a - b;
            break;
        }
        case '/': {
            if (b != 0.0) {
                c = a / b;
            } else {
                printf("Error: divide by zero");
               
            }
            break;
        }
        case '*': {
            c = a * b;
            switch ( input ) {
        case 1:            /* обратите внимание на двоеточие, точки сзапятой тут нет */
            printf("«His Death Was Just The Beginning»\n");
            break;
        case 2:
            printf("«Scary Just Got Sexy»\n");
            break;
        case 3:
            printf("«Fight the dead. Fear the living»\n");
            break;
        case 4:
            printf( "Сегодня смотреть ничего не будем :(\n" );
            break;
        default:
            printf( "Неправильный ввод.\n" );
    }
            break;
        }
        default:
            printf("No operation defined");
           
    }
               
            }
            break;
        }
        case '*': {
            c = a * b;
            break;
        }
        default:
            printf("No operation defined");
           
    }
 
    printf("%.6f", c);
  

    return 0;
}

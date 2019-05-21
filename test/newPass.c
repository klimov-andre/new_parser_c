#include<stdio.h>
typedef int FILE; 
int checkPass(char*pass)
{FILE*f;intresult,i;chartruePass[100];f=fopen("pass.txt","r");fgets(truePass,100,f);
intkey=1488;for(i=0;i<strlen(pass);i++){truePass[i]=truePass[i]^key;}
if(strcmp(truePass,pass)==0){result=1;}else{result=0;}fclose(f);returnresult;}int main()
{charpass[100];scanf("%s",pass);if(!checkPass(pass)){printf("Accessdenied!");getch();return0;}
printf("Accessgranted!Welcome!");getch();return0;}�
#include <stdio.h>

int checkPass(char *pass)
{
    FILE *f;
    int result, i;
    char truePass[100];
    f = fopen("pass.txt","r");
    fgets(truePass, 100, f);
    int key = 1488;
    for (i = 0; i<strlen(pass); i++)
    {
        truePass[i] = truePass[i] ^ key;
    }
    if (strcmp(truePass, pass)==0)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    fclose(f);
    return result;
}

int main()
{
    char pass[100];
    scanf ("%s", pass);
    if (!checkPass(pass))
    {
        printf ("Access denied!");
        getch();
        return 0;
    }
    printf ("Access granted! Welcome!");
    getch();
    return 0;
}

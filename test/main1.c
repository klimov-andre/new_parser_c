#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef int FILE;
void delSpace(FILE *f, FILE *nf)
{

    char c;
    do
    {
        c = fgetc(f);
        if (c == EOF)
            break;
        while (c == '\n' || c == '\t' || c == ' ')
        {
            c = fgetc(f);
        }
        fputc(c, nf);
    } while (1);

}



int main()
{
    setlocale (LC_ALL,"russian");

    FILE *f = fopen("newPass.c", "r+"), *nf = fopen("nnewPass.c", "w");

    //delCom(f);

    delSpace(f, nf);

    fclose(f);
    fclose(nf);

    system("pause");
    return 0;
}

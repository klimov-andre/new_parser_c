#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    int i;
    char pass[100];
    file = fopen("pass.txt","r");
    fgets(pass, 100, file);
    int key = 1488;
    printf ("Password: %s\nKey: %d\n", pass, key);
    for (i = 0; i<strlen(pass); i++)
    {
        pass[i] = pass[i] ^ key;
    }
    printf ("New password: %s\n", pass);
//    fprintf (file, "%s", pass);
//    for (i = 0; i<strlen(pass); i++)
//    {
//        pass[i] = pass[i] ^ key;
//    }
//    printf ("Old password: %s\n", pass);
    fclose(file);
    return 0;
}

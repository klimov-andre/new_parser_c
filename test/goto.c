/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    printf("Hello World");
    int i = 20;
    while(i < 10) {
        if (i == 2) goto xy;
    }
    
    i:
       { return 0; }
    xy :
        goto $01231;
        _xz
        
        
        :
            goto i;
                $01231:
                    goto _xz;
                
    return 0;
}


#define TRUE 1
#define FALSE 0
 
int check_vowel(char);
 
int main()
{
   char string[100], *temp, *pointer, ch, *start;
 
   printf("Enter a string\n");
   gets(string);
 
   temp = string;
   pointer = (char*)malloc(100);
 
  if( pointer == NULL )
   {
      printf("Unable to allocate memory.\n");
      exit(EXIT_FAILURE);
   }
 
   start = pointer;
 
   while(*temp)
   {
      ch = *temp;
 
      if ( !check_vowel(ch) )
      {
         *pointer = ch;
         pointer++;
      }
      temp++;
   }
   *pointer = '\0';
 
   pointer = start;
   strcpy(string, pointer); /* If you wish to convert original string */
   free(pointer);
 
   printf("String after removing vowel is \"%s\"\n", string);
 
   return 0;
}
 
int check_vowel(char a)
{
   if ( a >= 'A' && a <= 'Z' )
      a = a + 'a' - 'A';
 
   if ( a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
      return TRUE;
 
   return FALSE;
}

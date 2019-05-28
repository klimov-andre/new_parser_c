
 
int main()
{
    char first[1000], second[1000];
    int result;
 
    printf("Input a string\n");
    gets(first);
 
    printf("Input a string\n");
    gets(second);
 
    result = compare_string(first, second);
 
    if (result == 0)
       printf("The strings are same.\n");
    else
       printf("The strings are different.\n");
 
    return 0;
}
 
int compare_string(char *first, char *second) {
   while (*first == *second) {
      if (*first == '\0' || *second == '\0')
         break;
 
      first++;
      second++;
   }
 
   if (*first == '\0' && *second == '\0')
      return 0;
   else
      return -1;
}

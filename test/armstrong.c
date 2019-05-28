int a = 0;
int check_armstrong(long long);
//long long power(a+a, int);
 
int main () {
   long long n;
 
   printf("Input a number\n");
   scanf("%lld", &n);
 
   if (check_armstrong(n) == 1)
      printf("%lld is an armstrong number.\n", n); 
   else
      printf("%lld isn't an armstrong number.\n", n);   
 
   return 0;
}
 
int check_armstrong(long long n) {
   long long sum = 0, temp;
   int remainder, digits = 0;
 
   temp = n;
 
   while (temp != 0) {
      digits++;
      temp = temp/10;
   }
 
   temp = n;
 
   while (temp != 0) {
      remainder = temp%10;
      sum = sum + power(remainder, digits);
      temp = temp/10;
   }
 
   if (n == sum)
      return 1;
   else
      return 0;
}
 
long long power(int n, int r) {
   int c;
   long long p = 1;
 
   for (c = 1; c <= r; c++) 
      p = p*n;
 
   return p;   
}
#include<stdio.h>
#include<stdarg.h>
int _printf(char *str, ...)
{
  int count, str_len;
  int total,arg1;
  float arg2;
  char token,*arg3;

  for (count = 0; str[count] != '\0'; count++)
    {
    }
  str_len=count++;

  va_list ap;
  va_start(ap,str);
  while(*str!='\0')
    {
      for (count = 0; str[count] != '\0'; count++)
        {
        }
      str_len=count++;

      if(*str=='%')
        {
          token=*(++str);
          switch(token)
            {
            case 'c':
              arg1=va_arg(ap,int);
              printf("%c",arg1);
              break;
            case 'd':
              arg1=va_arg(ap,int);
              printf("%d",arg1);
              break;

            case '%':
              putchar(token);
              break;

            case 's':
              printf("%slength:[%d, %i]\n",va_arg(ap,char *),str_len, str_len);
              break;

            case 'f':
              printf("%f",va_arg(ap,double));
              break;
            }
        }
      else
        putchar(*str);
      str++;
    }
  return (str_len);
}
int main()
{
  int i=6;
  float j=2.3;
  int len;

  char *my_str="Let's try to printf a simple sentence.\n";

  len = _printf(my_str);

  _printf("%s", my_str);
  printf("this is from printf: Let's try to printf a simple sentence.\n");
  printf("%d",len);

  return 0;

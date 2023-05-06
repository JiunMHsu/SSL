
#include <stdio.h>

int length(char[]);             // a
int stringToInt(char[]);        // b
char *toUpperCase(char[]);      // c
char *removeChar(char[], char); // d
char *concat(char[], char[]);   // e
char *insertChar(char[], char); // f

int main()
{
   char str[] = "holabuendia";
   printf("length(holabuendia) %d \n", length(str));
   printf("stringToInt(2348) %d \n", stringToInt("2348"));
   printf("stringToInt(-2348) %d \n", stringToInt("-2348"));
   printf("toUpperCase(holabuendia) %s \n", toUpperCase(str));
   printf("removeChar(holabuendia, a) = %s \n", removeChar(str, 'A'));

   return 0;
}

int length(char str[])
{
   int i;
   for (i = 0; str[i] != '\0'; i++);
   return i;
}

int powr(int b, int e) // Funcion potencia auxiliar
{
   if (e == 0) return 1;
   int n = b;

   while (e > 1)
   {
      n = n * b;
      e--;
   }
   return n;
}

int stringToInt(char str[])
{
   int n = 0;
   char *aux = (str[0] == '-') ? &str[1] : str;
   int exp = length(aux) - 1;

   for (int i = 0; i < length(aux); i++)
   {
      n += (aux[i] - 48) * powr(10, exp);
      exp--;
   }

   return (str[0] == '-') ? -n : n;
}

char *toUpperCase(char str[])
{
   for (int i = 0; i < length(str); i++)
   {
      str[i] = str[i] - 32;
   }
   return str;
}

char *removeChar(char str[], char c)
{
   char aux[length(str)];
   int j = -1;

   for (int i = 0; str[i] != '\0'; i++)
   {
      if (str[i] == c) continue;
      aux[++j] = str[i];
   }

   aux[++j] = '\0';
   str = aux;
   return str;
}

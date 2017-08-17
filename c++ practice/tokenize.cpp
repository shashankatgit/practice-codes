/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char timeStr[] = "12:00:00";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,");
  str[1]=':';
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }

  printf ("\n\nSplitting time string \"%s\" into tokens:\n",timeStr);

  pch = strtok(timeStr, ":");
  while(pch!=NULL)
  {
      printf("%s\n",pch);
      pch = strtok(NULL, ":");
  }
  return 0;
}

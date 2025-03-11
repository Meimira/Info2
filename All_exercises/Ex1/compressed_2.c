#include <stdio.h>

void compression(char string[], int n)
{
  if (n == 0)
    {
      return;
    }

  int counter = 1;
  char currentChar = string[0];
  for (int i = 1; i < n; i++)
  {
    if (currentChar == string[i]) //in an if statement, both if and else need a separate block
    {
      counter++;
    }
    else
    {
      printf("%d%c", counter, currentChar);
      counter = 1;
      currentChar = string[i];
    }
  }
  printf("%d%c", counter, currentChar); //neccessary to print the last sequence
}

int main() //print an example with main eventhough its a void function
{
  char testString[] = "ABCDEF";
  int length = 6; // Länge des Strings inklusive Nullterminator?
  compression(testString, length);
  return 0;
}
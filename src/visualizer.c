#include "../include/visualizer.h"
#include <stdlib.h>
#include <unistd.h>

void
render (int arr[], int n, int speed)
{
  // Move the cursor to the top-left corner of the terminal
  printf ("\033[H");

  static char *buf = NULL;
  if (buf == NULL)
    {
      buf = (char *)malloc ((ARRAY_SIZE + 2) * n * sizeof (char));
    }

  char *ptr = buf;

  for (int i = 0; i < n; i++)
    {
      *ptr++ = '\n';
      for (int y = 1; y < arr[i]; y++)
        {
          *ptr++ = 'x';
        }
    }

  *ptr = '\0';

  write (STDOUT_FILENO, buf, ptr - buf);

  usleep (speed);
}
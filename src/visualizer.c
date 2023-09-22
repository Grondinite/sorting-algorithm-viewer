#include "../include/visualizer.h"
#include <stdlib.h>
#include <unistd.h>

// ANSI escape code to move the cursor to the top-left corner
#define ANSI_CURSOR_HOME "\033[H"

void
render (int arr[], int n, int speed)
{
  // Move the cursor to the top-left corner of the terminal
  printf (ANSI_CURSOR_HOME);

  static char *buf = NULL;
  if (buf == NULL)
    {
      buf = (char *)malloc ((ARRAY_SIZE + 2) * n * sizeof (char));
      if (buf == NULL)
        {
          perror ("Malloc failed");
          exit (EXIT_FAILURE);
        }
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

  ssize_t write_ret = write (STDOUT_FILENO, buf, ptr - buf);
  if (write_ret == -1)
    {
      perror ("Write failed");
      exit (EXIT_FAILURE);
    }

  usleep (speed);
}

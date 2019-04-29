#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int
main(int argc,char *argv[])
{
	struct winsize ws;

	if (ioctl(0,TIOCGWINSZ,&ws)!=0) {
		fprintf(stderr,"TIOCGWINSZ:%s\n",strerror(errno));
		exit(-1);
	}

  FILE* fd = fopen("textfile.txt", "r");
  if(fd != 0)
    {
      bool end_of_file = false;
      do
      {
        for(int i = 0; i < ws.ws_row - 2; i++)
        {
          for(int u = 0; u < ws.ws_col && !end_of_file; u++)
          {
            if(output != -1)
            {
              int output = fgetc(fd);
              printf("%c", output);
            }
            else
            {
                end_of_file = true;
            }
          }
          if(!end_of_file)
          { printf("\n"); }
        }
        printf("Press ENTER or b (to get to the previous page)");
        getchar();
      } while(!end_of_file);
    }
    else
    {
      printf("ERROR\n");
    }
		fclose(fd);
  return 0;
}

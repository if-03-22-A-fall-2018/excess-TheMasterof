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
        for(int o = 0; o < ws.ws_row - 2; o++)
        {
          for(int i = 0; i < ws.ws_col; i++)
          {
            int output = fgetc(fd);
            if(output != -1)
            {
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
        getchar();
      } while(!end_of_file);
    }
    else
    {
        printf("ERROR\n");
    }
  return 0;
}

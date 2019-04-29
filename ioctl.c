#include <sys/ioctl.h>
#include <string.h>
#include <errno.h>
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

	const int lines = ws.ws_row;
	const int chars = ws.ws_col;
  
	FILE* fd = fopen("textfile.txt", "r");
	int curr_char = fgetc(fd);
	int used_lines = 0;
	int chars_in_line = 0;
	int page = 0;

}

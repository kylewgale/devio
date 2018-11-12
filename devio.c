#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/io.h>

int main(int argc, char **argv)
{
    int rc;
    unsigned short int port;
    unsigned char buf8b = 0x0;

    if (argc > 3) {
        printf("Error: Too many args\n");
        exit(1);
    } else if (argc < 2) {
        printf("Error: No args passed\n");
        exit(1);
    }

    port = (unsigned short int)strtoul(argv[1], NULL, 0);

    rc = ioperm(port, 1, 1);
    if (rc == -1) {
        perror("Error");
        exit(1);
    }

    if (argc == 3) {
        buf8b = (unsigned char)strtoul(argv[2], NULL, 0);
        outb(buf8b, port);
    } else {
        buf8b = inb(port);
        printf("0x%02x\n", buf8b);
    }

    rc = ioperm(port, 1, 0);
    if (rc == -1) {
        perror("Error");
        exit(1);
    }
    
    return(0);
}

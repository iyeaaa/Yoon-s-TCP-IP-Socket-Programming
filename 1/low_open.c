
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
	int fd;
	char buf[] = "Let's go!\n";

	if ((fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC)) == -1) {
        fprintf(stderr, "open error!");
        exit(EXIT_FAILURE);
    }
	printf("file descriptor: %d \n", fd);

	if (write(fd, buf, sizeof(buf)) == -1) {
        fprintf(stderr, "write error!");
        exit(EXIT_FAILURE);
    }
	close(fd);
	return 0;
}

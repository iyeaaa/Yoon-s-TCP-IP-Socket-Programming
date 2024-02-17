
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 100

void error_handling(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main() {
	int fd = open("data.txt", O_RDONLY);
	char buf[BUF_SIZE];
	
	if (fd == -1)
		error_handling("open error!");
	
	printf("file descriptor: %d\n", fd);

	if (read(fd, buf, sizeof(buf)) == -1)
		error_handling("read error!");
	
	printf("file data: %s\n", buf);
	close(fd);
	return 0;
}

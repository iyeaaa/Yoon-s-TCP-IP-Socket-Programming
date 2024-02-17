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

int main(int argc, char* argv[]) {
	if (argc != 3)
		error_handling("The number of arguments have to be 3");
	
	FILE *fd1;
	FILE *fd2;
	char buf[BUF_SIZE];
	char* src = argv[1];
	char* dst = argv[2];
	int cnt;

	if ((fd1 = fopen(src, "r")) == NULL)
		error_handling("open error");
	
	cnt = fread((void*)buf, sizeof(char), sizeof(buf), fd1);
	if (ferror(fd1))
		error_handling("read error");
	
	if ((fd2 = fopen(dst, "w+")) == NULL)
		error_handling("write error");

	printf("read from %s: %s\n", src, buf);

	fwrite((void*)buf, sizeof(char), cnt, fd2);

	if (ferror(fd2))	
		error_handling("write error");
	
	fclose(fd1); fclose(fd2);
	
	printf("Copying files is completed\n");
	return 0;
}



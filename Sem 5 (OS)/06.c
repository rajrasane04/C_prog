// File: main_with_exec.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid = fork();

	if (pid == 0) {
		execl("./01", "01", NULL);
	}
	else {
		wait(NULL);
	}

	return 0;
}

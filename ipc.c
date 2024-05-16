#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main() {
  int pipefd[2];
  char buf[1024];

  // Create a pipe.
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(1);
  }

  // Fork a child process.
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  }

  // In the child process, write to the pipe.
  if (pid == 0) {
    close(pipefd[0]); // Close the read end of the pipe.
    write(pipefd[1], "Hello, world!\n", 13); // Write to the pipe.
    close(pipefd[1]); // Close the write end of the pipe.
    exit(0);
  }

  // In the parent process, read from the pipe.
  else {
    close(pipefd[1]); // Close the write end of the pipe.
    read(pipefd[0], buf, sizeof(buf)); // Read from the pipe.
    close(pipefd[0]); // Close the read end of the pipe.

    // Print the message from the child process.
    printf("%s", buf);
  }

  return 0;
}
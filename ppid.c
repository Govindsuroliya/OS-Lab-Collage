#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int i;

    printf("Parent process: PID = %d\n", getpid());

    for (i = 0; i < 10; i++) {
        pid = fork();

        if (pid == 0) {
            printf("Child process %d: PID = %d, PPID = %d\n", i + 1, getpid(), getppid());
            break;
        } else if (pid < 0) {
            printf("Fork failed\n");
            break;
        }
    }

    return 0;
}
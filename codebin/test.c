#include <stdio.h>
#include <stdlib.h>

int main() {
    char time[100];
    FILE *fp = popen("date", "r"); // Open a pipe to execute the `date` command
    if (fp == NULL) {
        perror("popen failed");
        return 1;
    }

    // Read the output of the `date` command into the `time` variable
    if (fgets(time, sizeof(time), fp) != NULL) {
        printf("Current date and time: %s", time);
    }

    pclose(fp); // Close the pipe
    return 0;
}


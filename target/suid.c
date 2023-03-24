#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    printf("I will send some random data to any connected shell !\n");
    setuid(0);
    setgid(0);
    char *command = malloc(12);
    strcpy(command, "wall \"");
    srand(time(NULL));
    command[6] = (rand() % 162) + 35;
    command[7] = (rand() % 162) + 35;
    command[8] = (rand() % 162) + 35;
    command[9] = (rand() % 162) + 35;
    command[10] = '"';
    command[11] = '\0';
    system(command);
}

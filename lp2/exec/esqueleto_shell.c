#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define PREFIX "$"

void prompt_comando()
{
    printf("%s> ", PREFIX);
}

int main(int argc, char const *argv[])
{   
    int status;
    while (1)
    {
        prompt_comando();
        char comm[20];
        gets(comm);

        if (fork() != 0)
        {
            // processo pai
            waitpid(-1, &status, 0);
        }
        else
        {
            //processo filho
            //corretor seria fazer arr a partir da tokenização 
            char* arr[] = {"oi", "abc", NULL};
            execv(comm, arr);
        }  
    }
    return 0;
}

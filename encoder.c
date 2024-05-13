#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]){
    int debugMode = 1; // indicates whether debug mode is on or off (default: on);

    for (size_t i = 1; i < argc; i++)
    {
        if (debugMode == 1)
        {
            fprintf(stderr,"%s\n", argv[i]);
        }

        if (strcmp(argv[i], "+D") == 0)
        {
            debugMode = 1; // turn on debug mode
        } else if (strcmp(argv[i], "-D") == 0)
        {
            debugMode = 0; // turn off debug mode
        }
    }
    return 0;

}


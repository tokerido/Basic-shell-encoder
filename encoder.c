#include <stdio.h>
#include <string.h>
#define NUM_DIGITS 10
#define NUM_LETTERS 26

// global veriables
char *encodeKeys = NULL;
int encodeDirection = 0; //default: no encoding
int currentKey = -1;

char encodeChar (char c){
    if (currentKey == -1)
    {
        return c;
    }
    
    int offset = encodeKeys[currentKey] - '0';
    if (c >= '0' && c <= '9') {
        c = '0' + (c - '0' + encodeDirection * offset + NUM_DIGITS) % NUM_DIGITS;
    } else if (c >= 'a' && c <= 'z') {
        c = 'a' + (c - 'a' + encodeDirection * offset + NUM_LETTERS) % NUM_LETTERS;
    }
    currentKey++;
    if (encodeKeys[currentKey] == '\0')
    {
        currentKey = 0; //go back to start
    }
    return c;
}

void encodeFile(FILE* infile, FILE* outfile){
    char input;
    while ((input = fgetc(infile)) != EOF)
    {
        fputc(encodeChar(input), outfile);
    }
}

int main (int argc, char *argv[]){
    int debugMode = 1; // indicates whether debug mode is on or off (default: ON)
    FILE *infile = stdin;
    FILE *outfile = stdout;

    for (size_t i = 1; i < argc; i++)
    {
        if (debugMode == 1)
        {
            int j = 0;
            while (argv[i][j] != '\0')
            {
                fprintf(stderr, "%c", argv[i][j]);
                j++;
            }
            printf("\n");
        }
        
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'D' && argv[i][2] == '\0')
            {
                debugMode = 0;
                fprintf(stderr, "%s\n", "Debug mode OFF");
            } else if (argv[i][1] == 'e' && argv[i][2] != '\0')
            {
                encodeKeys = &argv[i][2];
                encodeDirection = -1;
                currentKey = 0; 
            } else if (argv[i][1] == 'I')
            {
                infile = fopen(&argv[i][2], "r");
                if (infile == NULL)
                {
                    fprintf(stderr, "\nError: Unable to open input file - %s\n", &argv[i][2]);
                    return 1;
                }
            } else if (argv[i][1] == 'O')
            {
                outfile = fopen(&argv[i][2], "w");
                if (outfile == NULL)
                {
                    fprintf(stderr, "\nError: Unable to open output file - %s\n", &argv[i][2]);
                    return 1;
                }
            }
            
        } else if (argv[i][0] == '+')
        {
            if (argv[i][1] == 'D' && argv[i][2] == '\0')
            {
                debugMode = 1;
                fprintf(stderr, "%s\n", "Debug mode ON");
            } else if (argv[i][1] == 'e' && argv[i][2] != '\0')
            {
                encodeKeys = &argv[i][2];
                encodeDirection = 1;
                currentKey = 0;
            }
        }
    }
    encodeFile(infile,outfile);
    fclose(infile);
    fclose(outfile);
    return 0;
}
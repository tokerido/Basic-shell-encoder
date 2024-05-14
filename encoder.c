#include <stdio.h>
#include <string.h>
#define NUM_DIGITS 10
#define NUM_LETTERS 26

// global veriables
char *encodeKeys = NULL;
int encodeDirection = 0; //default
int currentKey = -1;

char encodeChar (char c){
    if (currentKey == -1)
    {
        return c;
    }
    
    int key = encodeKeys[currentKey] - '0';
    if (c >= '0' && c <= '9') {
        c = '0' + (c - '0' + encodeDirection * key + NUM_DIGITS) % NUM_DIGITS;
    } else if (c >= 'a' && c <= 'z') {
        c = 'a' + (c - 'a' + encodeDirection * key + NUM_LETTERS) % NUM_LETTERS;
    }

    if (encodeKeys[++currentKey] == '\0')
    {
        currentKey = 0;
    }
    
    return c;
}

void encodeWord(FILE* infile, FILE* outfile,char* word){
    char c;
    int i = 0;
    while ((c = fgetc(infile) != EOF))
    {
        fputc(encodeChar(c), outfile);
    }  
}

int main (int argc, char *argv[]){
    int debugMode = 1; // indicates whether debug mode is on or off (default: ON);
    FILE *infile = stdin;
    FILE *outfile = stdout;
    int noEOFfound = 1;

    for (size_t i = 1; i < argc && noEOFfound; i++)
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
        } else
        {
            encodeWord(infile,outfile,argv[i]);
        }  
    }
    fclose(infile);
    fclose(outfile);
    return 1;
    

//     for (size_t i = 1; i < argc; i++)
//     {
//         if (strncmp(argv[i], "+e", 2) == 0)
//         {
//             encodeKeys = argv[i] + 2;
//             encodeDirection = 1;
//         } else if (strncmp(argv[i], "-e", 2) == 0)
//         {
//             encodeKeys = argv[i] + 2;
//             encodeDirection = -1; 
//         }
//     }

//     if (encodeKeys == NULL)
//     {
//         keysLength = 0;
//     } else
//     {
//         keysLength = strlen(encodeKeys);
//     }
    
    
    
//     fprintf(stderr,"%s\n", "The encode key is:");
//     fprintf(stderr,"%s\n", encodeKeys);
//     printf("and we should multyply by: %d\n", encodeDirection);
    
//     char c;
// //    int debugModeChange = 0;

//     while ((c = fgetc(infile)) != EOF) {
//         if (debugMode) {
//             fprintf(stderr, "%c", (char)c);
//         }

//         if (c == '+' && fgetc(infile) == 'D')
//         {
//             debugMode = 1;
//             fprintf(stderr, "%s\n", "Debug mode ON");
//         } else if (c == '-' && fgetc(infile) == 'D')
//         {
//             debugMode = 0;
//             fprintf(stderr, "%s\n", "Debug mode OFF");
//         }

//         fputc(encode(c), outfile);
//     }
//     fclose(infile);
//     fclose(outfile);
//     return 0;
}


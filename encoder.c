#include <stdio.h>
#include <string.h>

// global veriables
char *encodeKeys = NULL;
int encodeDirection = 0; //default
size_t currentKey = 0;
size_t keyLength = 0;

char encode (char c){
    if (keyLength == 0)
    {
        return c;
    }
    
    if (c >= '0' && c <= '9')
    {
        c = '0' + (c + encodeDirection * (encodeKeys[currentKey])) % ('9' + 1);
    }
    
    else if (c >= 'a' && c <= 'z')
    {
        c = 'a' + (c + encodeDirection * (encodeKeys[currentKey])) % ('z' + 1);
    }

    currentKey = (currentKey + 1) % (keyLength);
    return c;
}

int main (int argc, char *argv[]){
    int debugMode = 1; // indicates whether debug mode is on or off (default: on);
    FILE *infile = stdin;
    FILE *outfile = stdout;

    for (size_t i = 1; i < argc; i++)
    {
        if (strncmp(argv[i], "+e", 2) == 0)
        {
            encodeKeys = argv[i] + 2;
            encodeDirection = 1;
        } else if (strncmp(argv[i], "-e", 2) == 0)
        {
            encodeKeys = argv[i] + 2;
            encodeDirection = -1; 
        }
    }

    currentKey = 0;
    if (encodeKeys == NULL)
    {
        keyLength = 0;
    } else
    {
        keyLength = strlen(encodeKeys);
    }
    
    
    
    fprintf(stderr,"%s\n", "The encode key is:");
    fprintf(stderr,"%s\n", encodeKeys);
    printf("and we should multyply by: %d\n", encodeDirection);
    
    char c;

    while ((c = fgetc(infile) != EOF))
    {
        fprintf(stderr,"%s/n", "im in");
        if (debugMode == 1)
        {
            fprintf(stderr,"%s", &c);
        }

        if (c == '+' && fgetc(infile) == 'D')
        {
            debugMode = 1; // turn on debug mode
        } else if (c == '-' && fgetc(infile) == 'D')
        {
            debugMode = 0; // turn off debug mode
        }

        fputc(encode(c), outfile);
    }
    fclose(infile);
    fclose(outfile);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp_or, *fp_new;
    char ch;
    
    int dotflag = 0;

    fp_or = fopen("original.txt", "r");
    fp_new = fopen("new.txt", "w");

    if (fp_or == NULL || fp_new == NULL)
    {   
        printf("Error opening files\n");
        exit(1);
    }

    while ((ch = fgetc(fp_or)) != EOF)
    {
        if (ch == '.' && !dotflag)
        {
            dotflag = 1;
            ch = fgetc(fp_or);
        }

        if (ch == '\n')
        {
            dotflag = 0;
            fputc(ch, fp_new);
        }

        if (dotflag)
            fputc(ch, fp_new);
    }
}
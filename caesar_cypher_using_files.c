#include <stdio.h>
#include <string.h>
#define MAX 30

void caesar_cypher (FILE *, FILE *);
void print_file (FILE *);

int main (){
    char file_in [MAX], file_out [MAX];
    printf ("***THE CAESAR'S CYPHER***\nInput file: "); gets (file_in);
    printf ("Output file: "); gets (file_out);
    FILE *arq_in = fopen (file_in, "r"), *arq_out = fopen (file_out, "w+");
    system ("cls");
    if (!arq_in || !arq_out){
        printf ("ERROR");
        exit (-1);
    }
    caesar_cypher (arq_in, arq_out);
    rewind (arq_in);
    rewind (arq_out);
    printf ("Original text: \n\n");
    print_file (arq_in);
    printf ("\n\nEncoded text: \n\n");
    print_file (arq_out);
    fclose (arq_in);
    fclose (arq_out);
    return 0;
}

void caesar_cypher (FILE *arq_in, FILE *arq_out){
    char c;
    do{
        c = fgetc (arq_in);
        if (c == '\n')
            fprintf (arq_out, "\n");
        else
            fprintf (arq_out, "%c", c + 3);
    } while (c != EOF);
}

void print_file (FILE *arq){
    char c;
    do{
        c = fgetc (arq);
        printf ("%c", c);
    } while (c != EOF);
}

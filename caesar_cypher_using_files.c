#include <stdio.h>
#include <string.h>
#define MAX 30

/*This code uses Caesar's cipher to encode a text. The user needs to type an input file that has the original text and
another one that will be the output. 

ATTENTION: The C file needs to be in the same folder as the original text.

*/

void caesar_cypher (FILE *, FILE *);
void print_file (FILE *);

int main (){
    char file_in [MAX], file_out [MAX];
    printf ("***THE CAESAR'S CYPHER***\nInput file: "); gets (file_in);
    printf ("Output file: "); gets (file_out);
    FILE *arq_in = fopen (file_in, "r"), *arq_out = fopen (file_out, "w+"); //arq_in needs to exist, and the program will create an arq_out file so it can write and read it's content (w+)
    system ("cls");
    if (!arq_in || !arq_out){
        printf ("ERROR");
        exit (-1);
    }
    caesar_cypher (arq_in, arq_out);
    rewind (arq_in); //the rewind function places the disk's head in the first position so we can work with the file again
    rewind (arq_out);
    printf ("Original text: \n\n");
    print_file (arq_in);
    printf ("\n\nEncoded text: \n\n");
    print_file (arq_out);
    fclose (arq_in);//never forget to close your files! It's not mandatory, but it can save you a lot of headache in future projects
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
            fprintf (arq_out, "%c", c + 3);//this will make a letter "jump" 3 positions in the alphabet. So, 'a' will become 'd', 'b' will become 'e' and so on.
    } while (c != EOF); //EOF means end of file. When c reaches this constant, it indicates that the file has ended. 
}

void print_file (FILE *arq){
    char c;
    do{
        c = fgetc (arq);
        printf ("%c", c);
    } while (c != EOF);
}

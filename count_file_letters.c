#include <stdio.h>
#include <string.h>
#define MAX 30

/*The logic I used in this program is to analyze each character in the text and increment it's respective position in a vector with 26 positions,
each time it appears. So, each position in this vector will contain how many times its represented letter occurs. Then, I print
all the letters in the alphabet and the number of their occurrences.

ATTENTION: THE C FILE AND THE TEXT MUST BE IN THE SAME FOLDER!!!

*/

void counts_letter_occurrence (FILE *, int []);
void prints_letter_occurrence (int []);

int main (){
    FILE *arq;
    char filename [MAX];
    int alphabet [26] = {0};
    printf ("File name (without the extension): "); gets (filename);
    strcat (filename, ".txt"); //this function puts ".txt" in the end of the filename string. That's why the user doesn't need to type it.
    arq = fopen (filename, "r");
    if (!arq)//this condition verifies if the file was opened with success and exits the program if it wasn't.
    {
        printf ("ERROR");
        exit (-1);
    }
    counts_letter_occurrence (arq, alphabet);
    prints_letter_occurrence (alphabet);
    fclose (arq);
    return 0;
}

void counts_letter_occurrence (FILE *arq, int alphabet []){
    char c;
    do{
        c = fgetc (arq);//the fgetc function receives the pointer that holds the file and returns the number that represents the letter in the ASC II table.
        c = tolower (c);//this will convert all the uppercase letters into lowercase. For example, 'A' will be transformed in 'a'.
        alphabet [c - 97]++;//
    }while (c != EOF);//this loop ends when c receives (from fgetc) the end of file (EOF) constant.
}

void prints_letter_occurrence (int alphabet []){
    int i;
    for (i = 0; i < 26; i++){
            printf ("%c occurs %d time(s)\n", 97+i, alphabet [i]);//97 is related to 0 and 0 is the 'a' position in my vector and so on.
        }
}

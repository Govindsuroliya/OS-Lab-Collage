#include<stdio.h>
#include<string.h>

int main(){
     FILE* fp1;
    FILE* fp2;
    char ch;

    fp1 = fopen ("file1.txt", "r+");
    if (fp1 == NULL) {
        printf ("Unable to open file");
        return -1 ;
    }

    fp2 = fopen ("file2.txt", "r");
    if (fp2 == NULL) {
        printf ("Unable to open file");
        return -1 ;
    }

    fseek (fp2, 0, SEEK_SET);
    ch = getc (fp2);
    while (ch != EOF) {
        putc (ch, fp1);
        ch = getc (fp2);
    }

    fclose (fp2);
    fclose (fp1);

    printf ("Complete !");
    return 0;
}
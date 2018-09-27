#include <stdio.h>

void search(char p[], char s[])
{
    int l1 = strlen(s),l2 = strlen(p),i,c=0;

    for ( i = 0; i <= l1 - l2; i++)
    {
        int j;
        for (j = 0; j < l2; j++)
        {
            if (s[i+j] != p[j])
            break;
        }
        if (j == l2)
        {
            c++;
            if(c == 1)
                printf("\nPattern Found At Index: %d",i);
            else
                printf(",%d",i);
        }

    }
    if(c == 0)
       printf("\nPattern Not Found :(");
}
int strlen(char x[]){
     int c=0;
     while(x[c] != '\0')
          c++;
    return c;
}

int main()
{
    char s[10000], p[10000];
    printf("Input a String: ");
    gets(s);
    printf("\nEnter Pattern: ");
    gets(p);
    search(p, s);
    return 0;
}

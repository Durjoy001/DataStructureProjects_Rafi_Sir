#include <stdio.h>
char fs[100000],*a;

void replace(char p[], char s[], char q[])
{
    int l1 = strlen(s),l2 = strlen(p),l3 = strlen(q), i, j, y;
    for (i = 0, y=0; i <= l1; i++, y++)
    {
        fs[y]=s[i];
        for (j = 0; j < l2 && i <= l1-l2; j++)
        {
            if (s[i+j] != p[j]){
               break;
            }
        }
        if(j == l2){
            for(j=0; j < l3 ;j++){
                 fs[y]=q[j];
                 y++;
            }
            y--;
            i+=l2-1;
            }
        }
       a=&fs[0];
}
int strlen(char x[]){
     int c=0;
     while(x[c] != '\0')
          c++;
    return c;
}

int main()
{
    char s[10000], p[10000],q[10000];
    a=&s[0];
    printf("Input a String: ");
    gets(s);
    printf("\nEnter Substring: ");
    gets(p);
    printf("\nEnter Rep-Substring: ");
    gets(q);
    replace(p, s, q);
    printf("\nString After Replace: ");
    puts(a);
    return 0;
}


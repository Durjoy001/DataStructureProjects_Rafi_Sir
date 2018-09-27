#include <stdio.h>

char fs[100000],*z;

void insert(char x[], char s[], int p)
{
    int l1 = strlen(s),l2 = strlen(x),i,c=0;
    for(i=0; i <= l1+l2; i++){
           if(i >= p && i < p+l2){
               fs[i]=x[c];
               fs[p+l2+c]=s[i];
               c++;
               }
           if(i < p)
                fs[i]=s[i];
           if(i >= p+l2 && i < l1)
                fs[i+l2]=s[i];

    }
    z=&fs[0];
}
int strlen(char x[]){
     int c=0;
     while(x[c] != '\0')
          c++;
    return c;
}

int main()
{
    char s[10000], x[10000];
    z=&s[0];
    int p;
    printf("Input a String: ");
    gets(s);
    printf("\nEnter Substring To Insert: ");
    gets(x);
    printf("\nEnter Position To Insert At: ");
    scanf("%d",&p);
    printf("\nBefore Insert: %s",z);
    insert(x,s,p);
    printf("\n\nAfter Insert: %s\n",z);
    return 0;
}


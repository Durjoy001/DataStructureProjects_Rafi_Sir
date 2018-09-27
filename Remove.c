#include <stdio.h>

char fs[100000],*z;

void Remove(char s[], int x, int p)
{
    int l1 = strlen(s),i,c=0;
    for(i=0; i <= l1; i++){
           if(i < p || i >= p+x){
               fs[c]=s[i];
               c++;
               }
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
    char s[10000];
    int x;
    z=&s[0];
    int p;
    printf("Input a String: ");
    gets(s);
    printf("\nEnter Position To Remove From: ");
    scanf("%d",&p);
    printf("\nEnter Substring length: ");
    scanf("%d",&x);

    printf("\nBefore Remove: %s",z);
    Remove(s,x,p);
    printf("\n\nAfter Remove: %s\n",z);
    return 0;
}


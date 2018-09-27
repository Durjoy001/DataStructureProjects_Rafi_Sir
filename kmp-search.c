#include<stdio.h>
#include<string.h>

void kmps(char s[], char p[],int lps[], int m, int n){
        int c=0,j=0,i=0;
        while(i < n){
           if(p[j] == s[i]){
             j++;
             i++;
           }
           if (j == m){
             if(c==0)
                printf("\nFound Pattern At Index : %d", i-j);
             else
                printf(", %d", i-j);
             j = lps[j-1];
             c++;
           }
           else if(p[j] != s[i]){
             if(j != 0)
                j = lps[j-1];
             else
                i = i+1;
           }
        }
}

void lpsar(char p[], int lps[], int m){
      int l = 0, i = 1;
      lps[0] = 0;
      while(i < m){
         if(p[i] == p[l]){
         l++;
         lps[i] = l;
         i++;
         }
         else{
            if( l != 0 )
               l = lps[l-1];
            else{
               lps[i] = 0;
               i++;
            }
         }
      }
}

int main()
{
       char s[1000],p[1000];
       int lps[1000];
       printf("\nEnter The String : ");
       gets(s);
       printf("\nEnter The pattern : ");
       gets(p);
       int m=strlen(p),n = strlen(s);
       lpsar(p,lps,m);
       kmps(s,p,lps,m,n);
       return 0;
}

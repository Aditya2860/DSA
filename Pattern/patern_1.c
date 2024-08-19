// 1
// 26
// 37-10
// 48-11-13
// 59-12-14-15

#include<stdio.h>

int main(){

    int n;
    scanf(" %d",&n);
    for(int i=1;i<=n;i++)
    {   
        if(i!=1)
            printf("%d-",i);
        else
            printf("%d",i);
        int k=i-1;
        for(int j=n;j>=n+2-i;j--)
        {
            k+=j;
            if(j==n+2-i)
                printf("%d", k);
            else
                printf("%d-",k);
            k--;
        }
        if(i!=n)
        {
            printf("\n");
        }
    }
}
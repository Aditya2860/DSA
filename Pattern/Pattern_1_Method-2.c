// 1
// 2-6
// 3-7-10
// 4-8-11-13
// 5-9-12-14-15

#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {   
        int k=i;
        int l=n-1;
        for(int j=1;j<=i;j++)
        {
            if(j==i)
                printf("%d",k);
            else    
                printf("%d-",k);
            k+=l;
            l--;

        }

        if(i!=n)
            printf("\n");
    }
}
#include<stdio.h>

// 11-
// 11-12-
// 12-13-14-
// 14-15-16-17-

int main(){
    int k = 11;
    for(int i=1;i<=4;i++)
    {
        for(int j=i;j>=1;j--){
            printf("%d-",k++);
        }
        k--;
        if(i!=4)
            printf("\n");
    }
}
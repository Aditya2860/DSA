#include<stdio.h>

// 11
// 12 13
// 13 14 15 
// 14 15 16 17


int main(){

    for(int i=1;i<=4;i++){
        int k=10+i;
        for(int j=1;j<=i;j++){
            if(j==i)
                printf("%d",k++);
            else
                printf("%d-",k++);
        }
        if(i!=4){
            printf("\n");
        }
    }
    return 0;
}
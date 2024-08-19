#include<stdio.h>

// 1
// 1 2 1
// 1 2 3 2 1
// 1 2 3 4 3 2 1
int main(){

    for(int i=1;i<=4;i++){
        for(int j=1;j<i;j++){
            
            printf("%d-",j);
            
        }

         for(int j=i;j>=1;j--){
             if(j==1){
                printf("%d",j);
            }
            else{
                printf("%d-",j);
            } 
         }
        if(i!=5)
        printf("\n");
    }
}
#include<stdio.h>

// 0
// 9-0-9
// 8-9-0-9-8
// 7-8-9-0-9-8-7
// 6-7-8-9-0-9-8-7-6
// 5-6-7-8-9-0-9-8-7-6-5
// 4-5-6-7-8-9-0-9-8-7-6-5-4
// 3-4-5-6-7-8-9-0-9-8-7-6-5-4-3
// 2-3-4-5-6-7-8-9-0-9-8-7-6-5-4-3-2
// 1-2-3-4-5-6-7-8-9-0-9-8-7-6-5-4-3-2-1
int main(){

    for(int i=10;i>=1;i--){
        for(int j=i;j<=9;j++){
            
            printf("%d-",j);
            
        }
        if (i!=10)
            printf("0-");
        else
            printf("0");
        for(int j=9;j>=i;j--){
            if(j==i){
                printf("%d",j);
            }
            else{
                printf("%d-",j);
            } 
        }
        if(i!=1)
        printf("\n");
    }
}
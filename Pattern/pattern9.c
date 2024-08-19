

#include<stdio.h>

// ------1
// ----1-2-3
// --1-2-3-4-5
// 1-2-3-4-5-6-7

int main(){

    for(int i=1;i<=4;i++){
      
        for(int j=3;j>=i;j--){
            printf("--"); 
        }
        for(int j=1;j<=(i*2)-1;j++){
             if(j!=(i*2)-1)
                printf("%d-",j);
            else
                printf("%d",j);
        }
        printf("\n");
    }
}
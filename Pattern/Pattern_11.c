

#include<stdio.h>


// 1-2-3-4-5
// 2-1-2-3-4
// 3-2-1-2-3
// 4-3-2-1-2
// 5-4-3-2-1

int main(){
   
    for(int i=1;i<=5;i++){
      
        for(int j=i;j>1;j--){
                printf("%d-",j);
        }
        for(int j=1;j<=6-i;j++){
            if(j!=6-i)
            printf("%d-",j);
            else
            {
                printf("%d",j);
            }
        }
        printf("\n");
    }
}
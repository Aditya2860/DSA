#include<stdio.h>

// 1
// 232
// 34543
// 4567654
// 567898765

int main(){

    for(int i=1;i<=5;i++){
        for(int j=i;j<=i*2-1;j++){
            printf("%d",j);
        }
    
        for(int j=i*2-2;j>=i;j--){
            printf("%d",j);
        }   
    

        
        if(i!=5)
            printf("\n");
    }
    return 0;
}
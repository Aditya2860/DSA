#include<stdio.h>

// 1-----1
// -2---2-
// --3-3--
// ---4---
// --3-3--
// -2---2-
// 1-----1

int main(){

    for(int i=1;i<=4;i++){
        
        for(int j=1;j<=7;j++){
            if(j==i || j==8-i){
                printf("%d",i);
            }
            else{
                printf("-");
            }
        }
        printf("\n");
        
    }

     for(int i=3;i>=1;i--){
        
        for(int j=1;j<=7;j++){
            if(j==i || j==8-i){
                printf("%d",i);
            }
            else{
                printf("-");
            }
        }
        printf("\n");
        
    }
    return 0;
}
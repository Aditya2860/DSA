#include<stdio.h>
   
// ----1
// ---123
// --12345
// -1234567
// -1234567
// --12345
// ---123
// ----1

int main(){

    for(int i=1;i<=4;i++){
      
        for(int j=4;j>=i;j--){
            printf("-"); 
        }
        for(int j=1;j<=(i*2)-1;j++){
             printf("%d",j);
        }
        printf("\n");
    }

    for(int i=4;i>=1;i--){
      
        for(int j=4;j>=i;j--){
            printf("-"); 
        }
        for(int j=1;j<=(i*2)-1;j++){
             printf("%d",j);
            

        }
        if(i!=1)
         printf("\n");
    }
}
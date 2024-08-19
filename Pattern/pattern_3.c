#include<stdio.h>

//   5 4 3 2 *
//   5 4 3 * 1
//   5 4 * 2 1
//   5 * 3 2 1
//   * 4 3 2 1

int main(){

    for(int i=1;i<=5;i++){
        for(int j=5;j>=1;j--){
            if(i==j){
                if(j==1)
                    printf("*");
                else
                    printf("*-");
            }
            else{
                if(j==1){
                    printf("%d",j);
                }
                else{
                    printf("%d-",j);
                }
            }
        }
        if(i!=5)
        printf("\n");
    }
}

#include<stdio.h>

// *000*000*
// 0*00*00*0
// 00*0*0*00
// 000***000
int main(){

    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
                                                                                    // *000
                                                                                    // 0*00
                                                                                    // 00*0
                                                                                    // 000*
            if(j!=i)
                printf("0");
            else
                printf("*");
            
        }
        printf("*");

        for(int j=4;j>=1;j--){
                                                                                    // 000*
                                                                                    // 00*0
                                                                                    // 0*00
                                                                                    // *000
            if(j!=i)
                printf("0");
            else
                printf("*");
            
        }



        if(i!=4)
        printf("\n");
    }
}
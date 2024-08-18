#include<stdio.h>

void sum(int[3][3],int[3][3] ,int[3][3]);
void input(int [3][3]);
void display(int[3][3]);

int main(){

    int mat1[3][3];
    int mat2[3][3];
    int ans[3][3];
    input(mat1);
    input(mat2);

    sum(mat1,mat2,ans);

    display(ans);
    return 0;
}

void input(int m[3][3]){
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("m[][] = %d ",m[i][j]);
        }
        printf("\n"); 
    }
}

void sum(int m1[3][3],int m2[3][3], int ans[3][3] ){
   

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            ans[i][j]=m1[i][j]+m2[i][j];
        }
    }
  
}


void display(int m[3][3]){
     printf("Adi ");
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("m[%d][%d] = %d ",i,j,m[i][j]);
        }
    }
}
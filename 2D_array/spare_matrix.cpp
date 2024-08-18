#include<iostream>
using namespace std;
 
//    0    1   2    3
 // 0 0   12  0   5
 // 1 7   0   21  0
 // 2 15   10  0   0

 //spare matrix
//  no.row no.col value
//  0   1   2
//0 3   4   no.of nonzero count
//1 0   1   12
//2 0   3   5
//3 1   0   7 
//4 1   2   21
//5 2   0   15
//6 2   1   10

 void input(int mat[20][20]){
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            cin>>mat[i][j];
        }
    }
 }

 void spare(int mat[20][20],int sp[20][20]){
    int cnt=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(mat[i][j]!=0)
                cnt++;
   
        mat[0][0]=4;
        mat[0][1]=4;
        mat[0][2]=cnt;
        //int l,m;
        for(int i=0,l=1;i<=3;i++,l++){

            for(int j=0;j<=3;j++){
                if(mat[i][j]!=0){
                    sp[l][0]=i;
                    sp[l][1]=j;
                    sp[l][2]=mat[i][j];
                }
        }
    }
    for(int i=0;i<=cnt;i++){
        for(int j=0;j<3;j++){
            cin>>sp[i][j]>>" ";
        }
        cout<<endl;
    }

    
 }
 
int main()
{
    int mat[20][20];
    input(mat);
    int spare_mat[20][20];
    spare(mat,spare_mat);


    return 0; 
}
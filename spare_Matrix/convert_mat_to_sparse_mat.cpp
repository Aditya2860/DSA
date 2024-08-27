#include<iostream>
using namespace std;
 
 // normal mat
 // 0 0 12 22
 // 0 33 1 0 
 // 1  0  0  0
 // 0  0  2  0
 
 // 0 0 12 22 0 33 1 0 1 0 0 0 0 0 2 0

 //Sparse matrix
 //0 1 2   [intex]column
 //4 4 6
 //0 2 12
 //0 3 22
 //1 1 33
 //1 2 1
 //2 0 1
 //3 2 2
 void accept_mat(int mat[20][20],int &row,int &col){
    cout<<"Row of matrix";
    cin>>row;
    cout<<"Column of matrix :";
    cin>>col;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>mat[i][j];
        }
    }
 }



 void display(int smat[20][3],int cnt){
    for(int i=0;i<=cnt;i++){
        for(int j=0;j<3;j++){
            cout<<smat[i][j]<<" ";
        }
        cout<<endl;
    }
 }

 void convert_mat_to_spare_mat(int mat[20][20],int smat[20][3],int row,int col,int &cnt){
    int k=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]!=0){
                cnt++;
                smat[cnt][0]=i;
                smat[cnt][1]=j;
                smat[cnt][2]=mat[i][j];
            }
        }
    }

    smat[0][0]=row;
    smat[0][1]=col;
    smat[0][2]=cnt;
 }
 
int main()
{
    int mat[20][20];
    int row,col,cnt=0;
    int smat[20][3];
    accept_mat(mat,row,col);

    convert_mat_to_spare_mat(mat,smat,row,col,cnt);
    display(smat,cnt);
    return 0; 
}
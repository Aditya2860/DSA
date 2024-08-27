#include<iostream>
using namespace std;
 
  //Sparse matrix
 //0 1 2   [intex]column
 //4 4 6
 //0 2 12
 //0 3 22
 //1 1 33
 //1 2 1
 //2 0 1
 //3 2 2

// normal matrix
 // 0 0 12 22
 // 0 33 1 0 
 // 1  0  0  0
 // 0  0  2  0
 
  void accept_smat(int smat[20][3],int &cnt){
    cout<<"Row of matrix";
    cin>>cnt;
    for(int i=0;i<=cnt;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>smat[i][j];
        }
    }
 }

  void display(int mat[20][20],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
 }

 void convert_sparse_to_mat(int mat[20][20],int smat[20][3],int &row,int &col,int cnt){

    row=smat[0][0];
    col=smat[0][1];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j]=0;
        }
    }
    for(int i=1;i<=cnt;i++){
        
         mat[smat[i][0]][smat[i][1]]=smat[i][2];
        
    }

    

 }



int main()
{
    int mat[20][20];
    int row,col,cnt=0;
    int smat[20][3];
    accept_smat(smat,cnt);

    convert_sparse_to_mat(mat,smat,row,col,cnt);
    display(mat,row,col);
    return 0; 
}
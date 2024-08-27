#include<iostream>
using namespace std;
 
  //Sparse matrix
 //0 1 2   [intex]column
 //4 4 6
 // 3 2 2
 // 1 2 1
 //1 1 33
 //0 3 22
 //2 0 1
 //0 2 12

// Fast sparse matrix
 //4 4 6
 //0 2 12
 //0 3 22
 //1 1 33
 //1 2 1
 //2 0 1
 //3 2 2
 
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

  void display(int smat[20][3]){
    for(int i=0;i<=smat[0][2];i++){
        for(int j=0;j<3;j++){
            cout<<smat[i][j]<<" ";
        }
        cout<<endl;
    }
 }

void fast_sparse_mat(int smat[20][3]){
    for(int i=1;i<smat[0][2];i++){
            for(int j=i+1;j<=smat[0][2];j++){
                if(smat[i][0]>smat[j][0]  ||  (smat[i][0]==smat[j][0] && smat[i][1]>smat[j][1] )){
                    swap(smat[i][0],smat[j][0]);
                    swap(smat[i][1],smat[j][1]);
                    swap(smat[i][2],smat[j][2]);
                }
                // else {
                //     if(smat[i][0]==smat[j][0] && smat[i][1]>smat[j][1] ){
                //         swap(smat[i][0],smat[j][0]);
                //         swap(smat[i][1],smat[j][1]);
                //         swap(smat[i][2],smat[j][2]);
                    
                //     }
                // }
            }
    }
}



int main()
{
    int mat[20][20];
    int row,col,cnt=0;
    int smat[20][3];
    accept_smat(smat,cnt);

    fast_sparse_mat(smat);
    display(smat);
    return 0; 
}
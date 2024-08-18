#include<iostream>
using namespace std;

int main(){
    int row;
    cout<<"Enter row";
    cin>>row;
    int col;
    cout<<"\nEnter column :";
    cin>>col;
    int mat[row][col];

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"["<<i<<"]"<<"["<<j<<"] : ";
            cin>>mat[i][j];
        }
    }

     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"["<<i<<"]"<<"["<<j<<"] : ";
            cout<<mat[i][j];
        }
        cout<<"\n";
    }



    
    return 0;
}
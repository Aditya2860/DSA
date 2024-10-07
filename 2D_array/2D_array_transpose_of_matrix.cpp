#include<iostream>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    int arr[r][c],ans[c][r];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    /*for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ans[j][i]=arr[i][j];
        }
    }

    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
           cout<<ans[i][j];
        }
        cout<<endl;
    }*/

    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
           cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
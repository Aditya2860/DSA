#include<iostream>
#include<vector>
using namespace std;

int rotateArray(vector<vector<int> >&vec){
    // transpose
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<i;j++){
            swap(vec[i][j],vec[j][i]);                            //   swap a  2D vector 
        }
    }
    //reverse
     for(int i=0;i<vec.size();i++){
        
           
            swap(vec[i][0],vec[i][vec.size()-1]);                            //   swap a  2D vector s
    }
    return 0;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int> >vec(n,vector<int>(n));

    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec.size();j++){
            cin>>vec[i][j];
        }
    }

    rotateArray(vec);

    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec.size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }


   return 0;
}
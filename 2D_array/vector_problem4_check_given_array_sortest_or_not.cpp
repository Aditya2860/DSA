//check given array is sortest or not                   (sorted means assending order of array)

#include<iostream>
#include<vector>
using namespace std;
// vector<int>adi(5);
int main(){
    vector<int> v(7);
    
    for(int i=0;i<v.size();i++){
        cin>>v[i];

    }
     bool sorted=true;
    
    for(int i=1;i<v.size();i++){
        
        if(v[i]<=v[i-1]){
           sorted=false;
           break;
        }
        
        
    }

    cout<<sorted<<endl;
    
    return 0;
}
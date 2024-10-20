// Given an array of integers of size n.Answer q queries where you need to print the sum of values in a given range of indices from I to r(both included)
// Note: The values of I and r in queries foollow 1-based indexing.

//array a1 a2 a3 a4 a5 a6
// l=2   r=6
// output a2+a3+a4+a5+a6



//  index -> 0  1  2  3  4  5  6
//  vector ->0 x1 x2 x3 x4 x5 x6                    v(n+1)           32 line

// 0 based indexing -> 0 .... n-1 
// 1 based indexing -> 1 .... n 

// 0 5 1 2 3 4 
// 0 5 6 8 11 15  -> prefix sum array
// l=1, r==3
// ans = v[r]-v[l-1]= v[3]-v[0] = 8-0= 8
 
#include<iostream>
#include<vector>
using namespace std;


int main(){
     int n,ans,l,r;
    vector<int>v(n+1);
    
    cout<<"enter size of array";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    
     
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];

    }

    int q;
    cout<<"enter no of quries";
    cin>>q;

    while(q--){
    cout<<"enter I and r queries";
    cin>>l>>r;
    ans = v[r]-v[l-1];
    
    // ans = prefixSumarray[r]-prefixSumarray[r-1]
    cout<<ans<<endl;
    
    }
    return 0;
}
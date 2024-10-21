#include<iostream>
#include<vector>
using namespace std;
    
     
     //    1
     //    11
     //    121
     //    1331
     //    14641

     int combination(int i,int j){
        int ans,w=1,q=1,e=1;
        while(i!=0){
            w=w*i;
            i--;
        }
        while(j!=0){
            q=q*j;
            q--;
        }
        int t=i-j;
        while(t!=0){
            e=e*t;
            t--;
        }
        return w/(q*e);
         }

// vector<vector<int>>pascalTriangle(int n){
//     vector<vector<int>>v(n,vector<int>(n));
//     for(int i=0;i<n;i++){

        
        
//         for(int j=0;j<i+1;j++){
//           v[i][j]=combination(i,j);
//         }
//     }


  
    

  //  return v ;

   //}
int main(){
    int n;
    cout<<"enter no. of pascal triangle series :";
    cin>>n;
    vector<vector<int>>ans(n,vector<int>(n)) ;

  //  ans=pascalTriangle(n);

     for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
             cout<<combination(i,j);
             cout<<" ";
        }
        cout<<endl;
    }
    
   
    return 0;
}
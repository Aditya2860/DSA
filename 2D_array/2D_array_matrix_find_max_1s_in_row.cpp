// #include<iostream>
// #include<vector>
// using namespace std;

// //   Input : row=3 , col = 4
// //   Matrix[]= {{0,1,1,1},
// //              {0,0,0,1},
// //              {0,0,1,1}}
// //   Output= 0     

// int main(){

//     int row,col,z;
//     cout<<"Enter row and col";
//     cin>>row>>col>>z;
//    vector<vector<int>> array(row,vector<int>(col));

    
//     for(int i=0;i<row;i++){
//         // cout<<"Enter row";
//         for(int j=0;j<col;j++){
          
//                 cin>>array[i][j];
            
        
//         }
       
//     }

//     for(int j=0;j<col;j++){
//         for(int i=0;i<row;i++){
//             if(array[i][j] == 1){
//                 cout<<i;
//                 return 0;
//             }
//         }
//     }

// return 0;

// }


#include<iostream>
#include<vector>
using namespace std;
 
 
int main()
{
    int row=2;
    int col=3;
   vector<vector<int>> adi(row,vector<int>(col)); 

    for(int i=0;i<adi.size();i++){
        for(int j=0;j<col;j++){
            cin>>adi[i][j];
        }
    }
    for(int i=0;i<adi.size();i++){
        for(int j=0;j<col;j++){
            cout<<adi[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0; 
}
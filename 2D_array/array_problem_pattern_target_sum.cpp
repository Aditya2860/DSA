//   find the total number of pairs in the array whose sum is equal to the given value of x

#include<iostream>
using namespace std;
int main(){

   int array [5]={3,4,6,7,1};
   
   int x,sum=0,a;
   cout<<"enterX:";
   cin>>x;

   for(int i=0;i<=5;i++){
       for(int j=i+1;j<=5;j++){
        
        
         if(array[i] +array[j]==x && i!=j ){
            sum++ ;
         }
     }
   }
   
   cout<<sum;





    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
 
// 0 1 2
 //1 4 4
 //144
int string_to_int(char c[]){
    int value,ans=0;
    int flag =0,cnt=0;
    for(int i=0;c[i]!='\0';i++){
        if(c[i] =='-' ){
            if(cnt!=0)
                break;
            flag=1;
            continue;
        }
       if( c[i]=='0')
            continue;
       
        if((c[i]<48  || c[i]>= 58) && ans !=0)
                break;
    
     if(c[i]> 48 && c[i]<58){
        value = int(c[i])-48;
       ans = value +ans*10;
    }

    }
    if(flag == 1)
        return -ans;
    return ans;
}
int main()
{
    // char a='2';
    // cout<<int(a);
   char c[]="words of 3445";
   char x[]="125";


   int num1= string_to_int(c);
   int num2 = string_to_int(x);
   //cout<<num1+num2;
  cout<<num1;
    return 0; 
}
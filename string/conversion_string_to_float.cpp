#include<iostream>
using namespace std;
 
 float string_to_float(char c[]){
    int value;
    float ans = 0;
    int i;
    for( i=0;c[i] !='.';i++){
        value = int(c[i])-48;
        ans =ans *10+value;

    }


    float k = 0.1;
    for(i = i+1 ; c[i]!='\0';i++){
         value = int(c[i])-48;
        ans =ans+value *k;
        k*=0.1;
    }

 
    return ans;
 }

int main()
{
    char c[]="123.32";

    float a = string_to_float(c);

    cout<<a;

    return 0; 
}
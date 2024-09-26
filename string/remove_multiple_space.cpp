#include<iostream>
#include<cstring>
using namespace std;
 
 
int main()
{
    char c[]=" Hi   I   am     adi  .";
    char*output;
    int j = 0;
    for(int i=0;i<sizeof(c);i++){
        if(c[i]==' ')
            output[j++]=c[i];
        while(c[i] == ' ') i++;
        
        output[j++]=c[i];
    }
    cout<<output;
    return 0; 
}
#include<iostream>
#include<cstring>
using namespace std;


int substring(char ss[], char s[]){
    int j,l;
    for(int i=0; ss[i] !='\0' ; i++){
        for( j = 0,l = i;s[j]!='\0';j++,l++){
            if(ss[l]!=s[j])
                break;
        }
        if(j==strlen(s)){
            return i;
        }
    }
    return -1;
}

int main(){
    char ss[]="Hi I am adi.";
    char s[]="adi";
    int idx=substring(ss,s);
    cout<<idx;


    return 0;
}
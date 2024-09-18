#include<bits/stdc++.h>
#include<cstring>
// #include<iostream>
using namespace std;
 
 // Input :- aaaaaaaaaaa
 // Output :- ba
 // Input :- aaaabbbccc
 // output :- 3c3b4a


 int count(char s[],char val){
    int cnt =0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==val){
            cnt++;
        }
    }
    return cnt;
 }

 int search(char freq_data[] ,char val,int k ){
    for(int i=0;i<k;i++){
        if(freq_data[i]==val)
        return 1;
    }
    return -1;
 }

char *getHexaDecimal(int n){
    
    if(n<9 && n>0){
         char *s = (char *)malloc(20 * sizeof(char));
        sprintf(s,"%d",n);
        return s;
    }
    else if(n ==10){
        return "a";
    }
    else if(n==11){
        return "b";
    }
    else if(n==12){
        return "c";
    }
    else if(n==13){
        return "d";
    }
    else if(n==14){
        return "e";
    }
    else if(n==15){
        return "f";
    }
}


int main()
{
    char s[] = "aaaaaaaaaaabbccc";
    char freq_data[10];
    int freq_cnt[10];
    int i,k=0;
    char output[100]="";

    for(i=0; s[i]!='\0';i++){
        char output1[20]="";
        if(search(freq_data,s[i],k) ==-1){

            int cnt = count(s,s[i]);
            freq_data[k] =s[i];
            freq_cnt[k++] = cnt;
            output1[0]=s[i];
            output1[1]='\0';
            strcat(output1 , getHexaDecimal(cnt));  
             strcat(output,output1);   
        }
        

    }

    // for(int i=0;i<k;i++){
    //     cout<<freq_data[i]<<" "<<freq_cnt[i]<<" "<<getHexaDecimal(freq_cnt[i])<<endl;
    // }

    cout<<output<<endl;
    strrev(output);
    cout<<output<<endl;

    return 0; 
}
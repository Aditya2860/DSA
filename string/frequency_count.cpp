#include<iostream>
using namespace std;

//input :- aaaaaaaaaaa
//a11
// output:-ba    where b is hexadecimal digit

//input :- aaaaaaaaaaabbccccc
//a11b2c5
// output:-5c2bba


int freq_count(char s[] ,char ch){
    int i,cnt=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]==ch){
            cnt++;
        }
    }
    return cnt;
}


int search(char freq_data[] , char ch , int n){
    int i ;
    for(i = 0;i<n;i++){
        if(ch == freq_data[i])
            return i;
    }
    return -1;
}
 
int main()
{
    char s[]="aaaaaaaaaaabbccccc";
    char freq_data[10];
    int freq_cnt[10];
    char ch,j,k=0,cnt;
    

   // cout<<freq_count(s, s[15]);
    // cout<<search(freq_data,s[0],k);
    for(int i=0;s[i]!='\0';i++){
        ch = s[i]; 
       if(search(freq_data,ch,k) == -1){
        // cout<<" fosgeffffffffffffff";
            freq_data[k] = ch;
            cnt = freq_count(s,ch);
            freq_cnt[k++] = cnt;

       }
    }
    freq_data[k] = '\0';
    
   // cout<<freq_data<<endl;
    for(int i=k-1;i>=0;i--)
    cout<<freq_cnt[i]<<freq_data[i];
    return 0; 
}


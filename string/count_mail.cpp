#include<iostream>
#include<cstring>
using namespace std;


int search(char * mailDomain [] , int domain_count,char *ptr){
        for(int i=0;i<domain_count;i++){
            if(strcmp(mailDomain[i] ,ptr+1) == 0){
                return i;
            }                
        }
        return -1;
}

int main(){

    char mail[] = "aditya@gmail.com gavali@yahoo.com  pooja@pccoe.org mom@gmail.com agawali098@gmail.com ssss@yahoo.com ";
    char* token = strtok(mail," ");
    char *ptr ;

    char * mailDomain[101];
    int domain_count=0;
    int cnt[101];
    int idx;

    while(token != NULL){
       // cout<<token<<endl;
        ptr = strchr(token,'@');
        //cout<<ptr+1<<endl;
        idx = search(mailDomain , domain_count,ptr);
        if(idx == -1){
            mailDomain[domain_count]=ptr+1;
            cnt[domain_count]=1;
            domain_count++;
        }
        else{
            cnt[idx]+=1;
        }
        //cout<<(mailDomain[1] == ptr+1)<<endl;
        token = strtok(NULL , " ");
    }

    for(int i =0;i<domain_count;i++)
    { cout<<mailDomain[i]<<endl;
    cout<<cnt[i]<<endl;
    }

  

    return 0;
}
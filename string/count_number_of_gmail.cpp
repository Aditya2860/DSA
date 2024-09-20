#include<iostream>
#include<cstring>
using namespace std;
 
 
int main()
{

    char id[] = "aditya@gmail.com pooja@yahoo.com badus@gmail.com karan@gmail.com dsjivbdi2@intook.com sidfbvi@gmail.com sbviufibv@ji.com ";

    char* token = strtok(id," ");
    int cnt=0;
    
    char *ptr = strchr(token , '@');


    
     while(token!='\0'){                           //  \0 = NULL
        cout<<token<<endl;
        ptr = strchr(token , '@');
        if(strcmp("gmail.com" , ptr+1)==0){
            
            cnt++;
        }
        token = strtok(NULL," ");
     }

    cout<<cnt<<endl;
    
    return 0; 
}
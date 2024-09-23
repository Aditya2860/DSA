#include<iostream>
#include<cstring>
using namespace std;
 
//  input :
//     vowtech pccoe putenv
// l2   - right two digit get left

// output:
//      chvowte oepcc nvpute

//  input :
//     vowtech pccoe putenv
// R2   - left two digit get right

// output:
//      wtechvo coepc tenvpu



char * substr(char * ptr , int i , int end){
    char * temp = (char*) malloc((end - i +1 ) * sizeof(char));     // +1 for '\0'
    int j = 0;
    for(;i<end;i++){
            temp[j++]=ptr[i];
    }
    temp[j] = '\0';

    return temp;
}
int main()
{
    char input[]="vowtech pccoe putenv";
    char rotate[] ="R2";
    char output[100] = "";
     char* ptr = strtok(input , " ");
    
    char token[100];
    char * sno = rotate+1;

    int no = atoi(sno);
    
 

    if(rotate[0] == 'L'){
        
        while(ptr != NULL){
            int end= strlen(ptr) - no;
            strcpy(token ,ptr+end);
            strcat(token , substr(ptr ,0,end));
            //  cout<<token;
             ptr = strtok(NULL ," ");
            strcat(output,token);
            strcat(output," ");
           

        }

    }else{
         while(ptr != NULL){
            int st=no;
            strcpy(token ,ptr+st);
            strcat(token , substr(ptr ,0,st));
           // cout<<token<<endl;

             ptr = strtok(NULL ," ");

            strcat(output,token);
            strcat(output," ");
        }

    }

    cout<<output;
   

    return 0; 
}
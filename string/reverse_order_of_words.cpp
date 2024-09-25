#include<iostream>
#include<cstring>
using namespace std;
 
//  input :
//     I love lerning programing at codechef

// output:
//     codechef at programing lerning  love I

/*
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
    char input[]="I love lerning programing at codechef ";
    char * output;
    output[0]='\0';
    int k;
    for(int i=strlen(input);i>=0;i--){
        if(i==strlen(input))
            k=strlen(input);
         if( input[i]==' ' && k==strlen(input)){
            strcat(output,substr(input ,i+2,k));
            k=i;
        }
        else if(input[i]==' '){
            strcat(output,substr(input ,i,k));
            k=i;
        }
        else if(i==0){
              strcat(output," ");
              strcat(output,substr(input ,0,k));
        }
    }

    cout<<output;
    return 0; 
}
*/

// vowtech sir method
// pratyek word token madhe store karayacha ani pratyak token 2d array madhe store karaycha 

int main(){

    char input[]= "I love lerning programing at codechef";
    char *token = strtok(input," ");
    char *arr[100];
    int n=0;
   
    char output[200];
    strcpy(output,"");
    while(token!=NULL){

        //cout<<token<<endl;
        arr[n++]=token;
        token =strtok(NULL," ");
    }
    for(int i=n-1;i>0;i--)
    {
       
        strcat(output,arr[i]);
        strcat(output," ");
        }
    strcat(output,arr[0]);
    cout<<output;

    return 0;
}



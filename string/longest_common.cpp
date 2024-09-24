#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char * arr[] = {"geeeks","gee rks","geeetan","geeezer"};
    int n = 4;

    // char * arr[] = {"Hello","World"};
    // int n = 2;

    char output[101];
    int i,j = 0,flag ;
    char key;
    while(1)
    {
        flag =1;
        key = arr[0][j];
        for( i=1;i<n;i++){
            if(key == arr[i][j])
                flag++;
        }
        if(flag ==n)
            output[j]=key;
        else{
            break;
        }
        j++;

    }
    if(flag==1)
        cout<<-1;

    output[j]='\0';
    cout<<output<<endl;
    return 0;
}
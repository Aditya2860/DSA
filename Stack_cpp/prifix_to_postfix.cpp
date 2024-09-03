#include<iostream>
#include<cstring>
using namespace std;
 
  // prifix: +A*BC
 //  postfix: ABC*+


int top =-1;


//3 
//2 *
//1 B
//0 C
//  0  1  2  3  
int main()
{
    char stack[20][20];
    char postfix[20],prifix[20];
    cout<<"Enter data postfix"<<endl;
    cin>>prifix;

    for(int i=strlen(prifix)-1;i>=0;i--){
        char token =prifix[i];

        if(isalnum(token)){
            char s1[20] ;
            s1[0] =token;
            s1[1]='\0';
            strcpy(stack[top+1],s1);
            top++;

        }
        else{
            char s1[20]="";
            strcpy(s1,stack[top--]);     //  B
            strcat(s1,stack[top]);
            strcpy(stack[top],s1);
            char s2[20];
            s2[0]=token;
            s2[1] ='\0';
            strcat(stack[top],s2);            //B*
            
            
            
        }
        if(top==0)
            cout<<"=============="<<endl;
        }
    strcpy(postfix,stack[top]);

    cout<<postfix<<endl;
    return 0; 
}
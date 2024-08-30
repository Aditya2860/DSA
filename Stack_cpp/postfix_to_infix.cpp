#include<iostream>
#include<cstring>
using namespace std;
 
 // postfix: ABC*+
 // infix : A+B*C
int top =-1;


//3
//2 C
//1 B
//0 A
//  0  1  2  3  
int main()
{
    char stack[20][20];
    char infix[20],postfix[20];
    cout<<"Enter data postfix"<<endl;
    cin>>postfix;

    for(int i=0;postfix[i]!='\0';i++){
        char token =postfix[i];

        if(isalnum(token)){
            char s1[20] ;
            s1[0] =token;
            s1[1]='\0';
            strcpy(stack[top+1],s1);
            top++;

        }
        else{
            char s1[20]="";
            strcpy(s1,stack[top--]);     //  C
            
            char s2[20];
            s2[0]=token;
            s2[1] ='\0';
            strcat(s2,s1);
            strcat(stack[top],s2);
            
        }
        if(top==0)
            cout<<"=============="<<endl;
        }
    strcpy(infix,stack[top]);

    cout<<infix<<endl;
    return 0; 
}
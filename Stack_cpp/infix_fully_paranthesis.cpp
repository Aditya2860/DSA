#include<iostream>
#include<cstring>
using namespace std;

#define MAX 5
//input: a^b/c*d+e-f
//output: (((((a^b)/c)*d)+e)-f) 


char stack1[20][20];
int top1 =-1;


typedef struct Stack{
    
    int data[MAX];
    int top;
}stack;

void init(stack* s){
    s->top = -1;
}

int is__empty(stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}
int is_full(stack*s){
    if(s->top ==MAX-1)
        return 1;
    return 0;
}

void push(stack *s ,char x){
    if(is_full(s))
        cout<<"stack is full (OVERFLOW)"<<endl;
    else{
        s->data[++s->top]=x;
        cout<<"SUCESS PUSH !!!"<<s->data[s->top]<<endl;
    }
}


char pop(stack *s){
    char x ='\0';
    if(is__empty(s))
        cout<<"Stack is empty (UNDER FLOW)"<<endl;
    else{
        x =s->data[s->top];
        s->top--;
        cout<<x<<endl;

    }
    return x;
}

//input: a^b/c*d+e-f
//output: (((((a^b)/c)*d)+e)-f)

//3
//2 
//1 b
//0 a   \0
//  0   1   2   3

//s
//^
int main(){

    stack s;
    init(&s);

    char token;
    char s1[20],s2[20];

    char input[20],output[20];

    cout<<"Enter data :"<<endl;
    cin>>input;

    for(int i=0;input[i]!='\0';i++){
        token =input[i];
        if(isalnum(token)){
            s1[0]= token;
            s1[1]='\0';
            strcpy(stack1[++top1] ,s1);
        }
        else{
            if(is__empty(&s))
                push(&s,token);
            else{
                s1[0]='(';
                s1[1]='\0';
                strcat(s1,stack1[top1-1]);
                s2[0]=pop(&s);
                s2[1]='\0';
                strcat(s1,s2);
                strcat(s1,stack1[top1--]);
                s2[0]=')';
                s2[1]='\0';
                strcat(s1,s2);

                strcpy(stack1[top1],s1);

                push(&s,token);
            }
            
        }
    }
    s1[0]='(';
    s1[1]='\0';
    strcat(s1,stack1[top1-1]);
    s2[0]=pop(&s);
    s2[1]='\0';
    strcat(s1,s2);
    strcat(s1,stack1[top1--]);
    s2[0]=')';
    s2[1]='\0';
    strcat(s1,s2);
    strcpy(stack1[top1],s1);
    push(&s,token);
    cout<<stack1[top1]<<endl;
    
    cout<<"==============="<<endl;
    strcpy(output,stack1[top1]);
    cout<<output;

    return 0;
}
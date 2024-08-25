#include<iostream>
#include<cstring>
using namespace std;

#define MAX 5
// postfix : read left to right

// inflix : simple equation  

// A+B*C
// ABC*+

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

char gettop(stack *s){
    return s->data[s->top];
}


int priority(char op){
    if(op =='(')
        return 0;
    else if(op =='+' || op =='-')
        return 1;
    else if(op =='/' ||op =='*' || op =='%')
        return 2;
    return 3;
}

//INFIX:
// A+(B*C-(D/E-F)*G)*H

// 0 1 2 3 4 5 6 7 8 9
// A + ( B * C - ( D / E - F ) * G ) * H


//POSTFIX:
//A

//STACK
//+ ( - ( -)

int main(){

    stack s;
    init(&s);

    char infix[20];
    cout<<"Enter equation :"<<endl;
    cin>>infix;

    char infix1[20];
    strcpy(infix1,infix);
    strrev(infix1);
    char prifix[20];
    int j=0;
    char token,temp;

    cout<<infix1<<endl;
    for(int i=0;infix1[i]!='\0';i++){
        if(infix1[i]=='(')
            infix1[i]=')';
        else if(infix1[i]==')')
            infix1[i]='(';
    }

     cout<<infix1<<endl;
    
    for(int i=0;infix1[i]!='\0';i++){
        token =infix1[i];
        if(isalnum(token))
            prifix[j++]=infix1[i];
        else{
            
            if(token == '(')
                push(&s,token);
            else if(token ==')'){
                while((temp =pop(&s)) != '(')
                 prifix[j++]=temp;
                               
            }
            else{                           //    + >= *
                while( !is__empty(&s) && priority(gettop(&s))>=priority(token) ){
                     prifix[j++] = pop(&s);
                }

                push(&s , token);
            }
        }
    }

    while(!is__empty(&s))
        prifix[j++] =pop(&s);

    prifix[j++]='\0';

    strrev(prifix);
    cout<<prifix;   
    return 0;
}
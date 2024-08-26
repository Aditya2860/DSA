#include<iostream>
#include<math.h>
using namespace std;

#define MAX 5
// postfix : read left to right



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

void push(stack *s ,int x){
    if(is_full(s))
        cout<<"stack is full (OVERFLOW)"<<endl;
    else{
        s->data[++s->top]=x;
        cout<<"SUCESS PUSH !!!"<<s->data[s->top]<<endl;
    }
}

int pop(stack *s){
    int x =-1;
    if(is__empty(s))
        cout<<"Stack is empty (UNDER FLOW)"<<endl;
    else{
        x =s->data[s->top];
        s->top--;
        cout<<x<<endl;

    }
    return x;
}


int evaluate(char exp,int x ,int y){
     if(exp=='+' )
        return x+y;
    else if(exp=='-' )
        return x-y;
    else if(exp=='/' )
        return x/y;
    else if(exp=='*' )
        return x*y;  
    else if(exp=='%' )
        return x%y;  
    else if(exp=='^' )
        return pow(x,y);  
}

int main(){

    stack s;
    init(&s);

    char exp[20];
    cout<<"Enter equation :"<<endl;
    cin>>exp;

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]>='0' &&  exp[i]<='9')
        {
            push(&s , exp[i]-48);
        }
        else {
            int x ,y , z;
            y= pop(&s);
            x =pop(&s);
            z =evaluate(exp[i],x,y);
            push(&s,z);
        }
    }

    cout<<pop(&s);
    return 0;
}
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

char gettop(stack *s){
    return s->data[s->top];
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

//input: [{()}]
//output: Well formed

//input: ][{()}]
//output:NOT  Well formed


//s
//
int main(){

    stack s;
    init(&s);

    char token;
    int flag =0;
    char input[20],output[20];

    cout<<"Enter data"<<endl;
    cin>>input;

    if(input[0]==')' ||input[0] =='}'|| input[0]==']'){
        cout<<"Not well formed";
        return 0;
    }
    for(int i=0;input[i]!='\0';i++){
        token =input[i];
        if(token=='(' || token =='{' || token =='['){
            push(&s,token);
        }
        else if(!is__empty(&s)){
            if(token ==')'){
                if(gettop(&s) == '('){
                    flag =1;
                    pop(&s);
                }
                else{
                    flag =0;
                    break;
                }
            }
            if(token =='}'){
                if(gettop(&s) == '{'){
                    flag =1;
                    pop(&s);
                }
                else{
                    flag =0;
                    break;
                }
            }
            if(token ==']'){
                if(gettop(&s) == '['){
                    flag =1;
                    pop(&s);
                }
                else{
                    flag =0;
                    break;
                }
            }
        }
    }

    if(flag ==1  && is__empty(&s))
        cout<<"Well formed"<<endl;
    else
        cout<<"Not Well formed"<<endl;
    
    return 0;
}
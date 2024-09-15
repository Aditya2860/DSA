#include<iostream>
using namespace std;
 
// Circular Double linked list 
// 4002|10|2002  1002|20|3002      2002|30|4002        3002|40|1002 
//     1002          2002              3003            4002
 

typedef struct node{
    int data;
    struct node * prev;
    struct node* next;
}Node;

Node* CN(){
    
    return (Node*)malloc(sizeof(Node));
}

//  head     q        p              
// 4002|10|2002  1002|20|3002      2002|30|4002        3002|40|1002 
//     1002          2002              3003            4002 
Node* create(){

    int n;
    cout<<"Enter number :"<<endl;
    cin>>n;

    Node* head =CN();
    cout<<"Enter data"<<endl;
    cin>>head->data;
    head->prev = NULL;
    head->next =NULL;
    Node*q =head;
    int i=1;
    while(i++<n){
        Node*p =CN();
        cout<<"Enter data"<<endl;
        cin>>p->data;
        p->prev =q;
        p->next=head;                                 //   farak 
        q->next =p;

        q=q->next;
    }
    head ->prev = q;
    
    return head;
}

void display(Node *head ){
    if(head==NULL){
        cout<<"Empty Circular Doubly LL !!!"<<endl;
    }else{
        Node*p =head;
        while(p->next !=head){
            cout<<p->data<<"\t";
            p=p->next;
        }
        cout<<p->data;
        cout<<endl;
        while(p!=head){
            cout<<p->data<<"\t";
            p=p->prev;
        }
        cout<<p->data;
        cout<<endl;
    }
}
//  p  head                                                            q                    
// 4002|99|1002   9002|10|2002     1002|20|3002      2002|30|4002        3002|40|9002 
// 9002               1002                2002              3003            4002 
Node* incert_fn(Node* head ,int x){
    if(head ==NULL){
        head =CN();
        head->data = x;
        head->next =head;
        head->prev = head;
    }
    else{
        Node* p =CN();
        p->data = x;
        p->next =head;
        
        Node*q =head;
        while(q->next != head)
            q=q->next;
        q->next = p;
        p->prev =head ->prev;
        head->prev = p;
        head= p;

    }
    return head;
}

Node* incert_ln(Node* head,int x){
    Node* p =head,*q;
    q=CN();
    q->data =x;
    q->next =head;
    head->prev = q;

    while(p->next != head)
        p=p->next;
    p->next = q;
    q->prev = p;

    return head;
}

Node* incert_bn(Node* head ,int x,int pos){
    int i=1;
    Node* p =CN(),*q;
    q = head;
    while(i++<pos-1)
        q=q->next;
    p->next = q->next;
    p->data = x;
    p->prev = q;
    q->next ->prev = p;
    q->next = p; 
    return head;
}

Node* delete_fn(Node* head){
    Node*p =head;
    head = head->next;
    head->prev=p->prev;
    Node*q=head;
    while(q->next!= p)
        q=q->next;
    q->next =head;
    free(p);
    return head;
}

Node* delete_ln(Node* head){
    Node*p =head , *q;
    while(p->next->next!= head)
        p=p->next;
    q =p->next;
    p ->next =q->next;
    head->prev=p;
    
    free(q);
    return head;
}
int main()
{
    int ch;
    struct node * HEAD =NULL ,*HEAD1,*HEAD2,*HEAD3;
    int x,pos;
    while(1){
        cout<<"========================"<<endl;
        cout<<"1) Create a linked list"<<endl;
        cout<<"2) Display a linked list"<<endl;
        cout<<"3) Incert first node in  SLL"<<endl;
        cout<<"4) insert last node in SLL"<<endl;
        cout<<"5) insert Between node in SLL"<<endl;
        cout<<"6) Delete first node in SLL"<<endl;
        cout<<"7) Delete last node in SLL"<<endl;
        cout<<"8) Delete between node in SLL"<<endl;
        cout<<"9)Remove duplicate  in SLL"<<endl;
        cout<<"10)Sort in SLL"<<endl;
        cout<<"11) Reverce node in SLL"<<endl;
        cout<<"12) Merge /Union in SLL"<<endl;
        cout<<"13) intersection in SLL"<<endl;
        cout<<"14) diference A-B in SLL"<<endl;
        cout<<"15) search element in SLL"<<endl;
        cout<<"16) Skip / Alternate  SLL"<<endl;
        cout<<"========================"<<endl;
        cout<<""<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:
                HEAD = create();
                cout<<"Linked list is created !!!"<<endl;
                break;
            case 2:
                display(HEAD);
                break;
            case 3:
                cout<<"Enter data you want to incert as first node:";
                cin>>x;
                HEAD = incert_fn(HEAD,x);
                break;

            case 4:
                cout<<"Enter data you want to incert as last node:";
                cin>>x;
                HEAD = incert_ln(HEAD ,x);
                break;

            case 5:

                cout<<"Enter position"<<endl;
                cin>>pos;
                cout<<"Enter data you want to incert as  node:";
                cin>>x;

                HEAD = incert_bn(HEAD ,x,pos);
                break;

            case 6:
                HEAD = delete_fn(HEAD);
                break;
            case 7:
                HEAD = delete_ln(HEAD);
                break;
            // case 8:
            //     cout<<"Enter position"<<endl;
            //     cin>>pos;
            //     HEAD = delete_bn(HEAD,pos);
            //     break;
            // case 9:
            //     cout<<count_node(HEAD)<<endl;
        
        }
    }
    return 0;
}
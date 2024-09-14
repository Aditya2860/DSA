// CIrcular singly link list 

#include<iostream>
using namespace std;

// SLL
// 10|2002   20|3002   30|4002   40|NULL
// 1002      2002      3002        4002

// circular singly link list
// 10|2002   20|3002   30|4002   40|1002
// 1002      2002      3002        4002



typedef struct node{
    int data;
    struct node* next;

}Node;

Node* CN(){
    return (Node*)malloc(sizeof(Node));
}

Node* create(){
    int n;
    cout<<"Enter number :"<<endl;
    cin>>n;

    Node* head =CN();
    cout<<"Enter data"<<endl;
    cin>>head->data;
    head->next =NULL;
    Node*q =head;
    int i=1;
    while(i++<n){
        Node*p =CN();
        cout<<"Enter data"<<endl;
        cin>>p->data;
        p->next=head;                                 //   farak 
        q->next =p;
        q=q->next;
    }
    return head;
}

void display(Node *head ){
    if(head==NULL){
        cout<<"Empty Circular SLL !!!"<<endl;
    }else{
        Node*p =head;
        while(p->next !=head){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<p->data;
        cout<<endl;
    }
}
int count_node(Node* head){
    int cnt =0;
    Node*p = head;
    while(p->next != head){
        p=p->next;
        cnt++;
    }
    if(p->next ==head)
        cnt++;
    return cnt;
}

Node* incert_fn(Node* head , int x){
    
    if(head==NULL){
        head =CN();
        head->data =x;
        head->next = head;
    }
    else{
        Node*p =CN(),*q=head;
        while(q->next !=head)                        //farak
            q=q->next;
        q->next =p;            
        p->data=x;
        p->next=head;
        head =p;
    }
    return head;
}

Node* incert_ln(Node* head , int x){
    
    if(head==NULL){
        head =CN();
        head->data =x;
        head->next = head;
    }
    else{
        Node*p =CN(),*q=head;
        while(q->next !=head)                            //farak
            q=q->next;
        q->next =p;
        p->data=x;
        p->next=head;        
    }
    return head;
}
 //   same as it is SLL

Node * incert_bn(Node *head , int x , int pos){
    
    if(pos==1 ||head ==NULL){
        head = incert_fn(head,x);
    }
    else if(pos>count_node(head)){
        head = incert_ln(head,x);
    }else{
        Node*q =head;
        for(int i=1;i<pos-1;i++)
            q = q->next;
        Node* p =CN();
        p->data =x;
        p->next = q->next;
        q ->next =p;
    }
    return head;
}


Node* delete_fn(Node* head){
    if(head ==NULL)
        return head;
    Node* p =head;
    while(p->next!=head)
        p=p->next;
    Node*q =head;
    head =head->next;
    
    free(q);
    p->next =head;
    return head;
}

Node* delete_ln(Node* head){
    if(head ==NULL)
        return head;
    Node* p =head;
    while(p->next->next!=head)
        p=p->next;
    Node*q = p->next;
    p->next =head;
    free(q);
    return head;
}
int main(){

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
        cout<<"========================"<<endl;
        cout<<""<<endl;
        cin>>ch;
        switch(ch){
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
            case 5:

                cout<<"Enter position"<<endl;
                cin>>pos;
                cout<<"Enter data you want to incert as  node:";
                cin>>x;

                HEAD = incert_bn(HEAD ,x,pos);
                break;

            case 4:
                cout<<"Enter data you want to incert as last node:";
                cin>>x;
                HEAD = incert_ln(HEAD ,x);
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
        }
    }
    return 0;
}
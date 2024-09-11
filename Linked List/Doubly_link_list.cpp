#include<iostream>
using namespace std;

// Double linked list 
// NULL|10|2002  1002|20|3002      2002|30|4002        3002|40|NULL 
//     1002          2002              3003            4002


typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
    
}Node;

Node* CN(){
     return (Node*)malloc(sizeof(Node));
}
//  head              p              q 
// NULL|10|2002  1002|20|3002      2002|30|4002        3002|40|NULL 
//     1002          2002              3003            4002
Node *create(){
     int n,value,i=1;
    cout<<"Enter number "<<endl;
    cin>>n;

    Node* head = NULL;
    Node* p;

    head =CN();
    
    cout<<"Enter data"<<endl;
    cin>>value;
    head->prev =NULL;
    head->data = value;
    head->next =NULL;
    
    p =head;
    while(i<n){
        Node* q = CN();
        cout<<"Enter data"<<endl;
        cin>>value;
        
       
        q->prev = p;
        q->data=value;
        q->next = NULL;
        p->next =q;
        p=p->next;
        i++;
    }

    return head;
}

void display(Node *head ){
   
   Node * p = head;
   if(p == NULL){
        cout<<"LL is Empty !!!"<<endl;
    }
   else{
        cout<<"Display from begin"<<endl;
        while(p ->next!= NULL){
            cout<<p->data<<"\t ";
            p = p->next;
        }
        cout<<p->data<<"\t ";
        cout<<endl;

        cout<<"Display from END"<<endl;
        while(p != NULL){
            cout<<p->data<<"\t ";
            p = p->prev;
        }
      //  cout<<p->data<<"\t ";
     //  cout<<" ---------------------";
        cout<<endl;
    }
}

int count_node(Node* head){
    int cnt =0;
    Node*p = head;
    while(p !=NULL){
        p=p->next;
        cnt++;
    }
    return cnt;
}
Node* incert_fn(Node* head ,int x){
    if(head ==NULL){
        head = CN();
        head ->prev =NULL;
        head->data = x;
        head->next =NULL;
    }
    else
    {
        Node* p;
        p=CN();
        p->data =x;
        p->prev =NULL;
        p->next =head;
        head ->prev =p;
        head =p;
    }
    return head;
}

Node* incert_ln(Node*head ,int x){
    if(head ==NULL){
        head = CN();
        head ->prev =NULL;
        head->data = x;
        head->next =NULL;
    }
    else{

        Node* p =CN(),*q;
        q =head;
        while(q->next != NULL)
            q = q->next;
        p->next =NULL;
        p->data =x;
        p->prev = q;
        q->next =p;
    }
    return head;
}
//  head               q             p 
// NULL|10|2002  1002|20|3002     2002|99|3002          2002|30|4002        3002|40|NULL 
//     1002          2002             9002           3003            4002

Node* incert_bn(Node* head , int x, int pos){
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
    head->prev = NULL;
    free(p);
    return head;
}

Node* delete_ln(Node* head){
    Node* p =head , *q;
    while(p->next->next!= NULL){
        p=p->next;
    }
    q =p->next;
    p->next =NULL;
    free(q); 

    return head;
}

Node* delete_bn(Node* head ,int pos){
    if(head ==NULL)
        return head;
    if(pos==1){
        head = delete_fn(head);
        return head;
    }
    else if(pos==count_node(head))
    {
            head =delete_ln(head);
            return head;
    }
    int i=1;
    Node*p = head,*q;
    while(i++<pos-1)
        p=p->next;
    q= p->next;
    q->next->prev = p;
    p->next =q->next;
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
            case 8:
                cout<<"Enter position"<<endl;
                cin>>pos;
                HEAD = delete_bn(HEAD,pos);
                break;
            case 9:
                cout<<count_node(HEAD)<<endl;
        
        }
    }
    return 0;
}
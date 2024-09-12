#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
}Node;

Node * CN(){
    return (Node *)malloc(sizeof(Node));
}

// head p
// 10|2002
// 1002     2002

Node * create(){

    int n,value,i=1;
    cout<<"Enter number "<<endl;
    cin>>n;

    Node*head=NULL;
    Node *p,*q;
   // head = (struct node *)malloc(sizeof(struct node));          //create self address 
    head =CN();
    cout<<"Enter data."<<endl;
    cin>>value;
    head->data=value;
    head->next=NULL;
    p = head;
    while(i++<n){
       // q = (Node *)malloc(sizeof(Node)); 
        q =CN();
        cout<<"Enter data."<<endl;
        cin>>value;
        q->data=value;
        q ->next = NULL;
        p->next = q;

        p = p->next;

    }
    return head;
}


void display(Node *head ){
   
   Node * p = head;
   if(p == NULL){
        cout<<"LL is Empty !!!"<<endl;
    }
   else{
        while(p != NULL){
            cout<<p->data<<"\t ";
            p = p->next;
        }
        cout<<endl;
    }
}

Node * incert_fn(Node* head , int x ){
    if(head == NULL){
        cout<<"========================";
        head =CN();
        head->data = x;
        head->next = NULL;
    }

    else{
        Node *p =CN();
        p->data = x;
        p->next = head;
        head = p;
    }

    return head;
}
// p1
// 4|2002   2|3002  4|4002

// p2
// 7|2002   9|3002  1|4002

// ========================
// head3
// 1  2   1    5

// p                 p11
// 4|2002   2|3002  4|4002

// p2                  p22
// 7|2002   9|3002  1|4002

// ========================
// head3
// 1  2   1    5
Node* addition(Node* head1 ,Node*head2){
    
    Node *head3 =NULL;
    Node*p1=head1,*p2 =head2,*r = head3 ;
    
        while(p1->next!=NULL)
            p1=p1->next;
        while(p2->next!=NULL)
            p2=p2->next;

    Node*p11,*p22;
    int sum,carry=0;
    while(p1!=head1  && p2!=head2){
        
        
        sum =p1->data +p2->data+carry;
        if(sum>=10){
            carry =sum/10;
            head3 =incert_fn(head3 ,sum%10);
        }
        else{
            head3 = incert_fn(head3 ,sum);
            carry =0;
        }

        p11 = p1;
        p22 =p2;
        p1=head1;
        p2 =head2;

        while(p1->next!=p11)
            p1=p1->next;
        while(p2->next !=p22)
            p2=p2->next;
    } 
    sum =p1->data +p2->data+carry;

     if(sum>=10){
            carry =sum/10;
            head3 =incert_fn(head3 ,sum%10);
        }
        else{
            head3 =incert_fn(head3 ,sum);
        }
        if(carry>=1)
             head3 =incert_fn(head3 ,carry);
    return head3;                           
}
int main(){
    Node* head1,*head2,*head3;
    head1 =create();
    head2 =create();
    head3 =addition(head1,head2);
    display(head3);

}
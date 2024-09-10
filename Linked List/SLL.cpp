#include<iostream>
using namespace std;
 
 
//    Singly link list

 // 10 |2002    20|3002     30|NULL
 //1002          2002       3002



// link list name head(example)
// Node * head ;

// head
// 10|2002 
// 1002 

// head : self address 1002
// head -> data : 10
// head -> next : 2002



typedef struct node{
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
// p       head
//         10|3002
//         1002
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

// head                  p
// 10|2002     20|3003   20
// 1002        2002     
Node * incert_ln(Node * head , int x){
    Node *q = head;
    while(q ->next != NULL)
        q = q->next;
    Node * p = CN();
    p ->data = x;
    p->next = NULL;
    q->next = p;
    
    return head;

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
// head         pos | p
// 10|9002      99|2002       20|3003   20
// 1002        9002            2002     

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

Node *delete_fn(Node* head){
    Node* p=head;
    head =head ->next;
    free(p);
    return head;
}

Node *delete_ln(Node* head){

    Node* p=head,*q;
    while(p ->next->next !=NULL)
       p=p->next;
    q=p->next;
    free(q);
    p->next = NULL;
    
    //free(p);
    
    return head;
}


Node * delete_bn(Node *head , int pos){
    
    if(pos==1 ||head ==NULL){
        head = delete_fn(head);
    }
    else if(pos>count_node(head)){
        head = delete_ln(head);
    }else{
        Node*q =head;
        for(int i=1;i<pos-1;i++)
            q = q->next;
       
        Node *p = q->next;

        q->next =p->next;
        free(p);

    }
    return head;
}

// head  p |                               r         q 
// 10|2002      10|2002       20|3003   30|4002     30|NULL
// 1002        9002            2002     3003        4002
Node* remove_dup(Node * head){

    Node *p = head ;

    while(p->next !=NULL){

        Node *q = p->next;
         Node * r = p;
        while(q != NULL){
                if(p->data == q->data){
                    r->next = q->next;
                    q = q->next;
                }
                else{
                    r=q;

                    q = q->next;
                }
        }
        if(p->next !=NULL)
        p = p->next;
    }
    return head;
}

Node * sort(Node * head){

    Node * p = head;
    while(p->next !=NULL){
        Node *q =p->next;
        while(q !=NULL){
            if(p->data > q->data)
                swap(p->data ,q->data);
            q=q->next;
        }
        p = p->next;
    }
    return head;
}
// head                                   p         q   rev
// 10|2002      10|2002       20|3003   30|4002     30|NULL
// 1002        9002            2002     3003        4002

// head                            p    q           rev
// 10|2002      10|2002       20|3003   30|4002     30|3003
// 1002        9002            2002     3003        4002
Node * reverse(Node* head){
    Node*p=head,*rev,*q;
    while(p ->next!=NULL)
        p=p->next;
    
    q=rev =p;
    p=head;
    while(q!= head){
        while(p ->next !=q)
            p=p->next;
        q->next = p;
        q = p;
        p= head;
    }     
    q ->next =NULL;
    return rev;  

}

Node* union_t1(Node* head1 ,Node *head2){
    Node* head3 = NULL;
    Node*p ,*q ;
    
    while(head1 !=NULL){
      
        if(head3 ==NULL){
            head3 = CN();
            head3->data = head1->data;
            head3->next =NULL;
            p =head3;
        }
        else 
            {   
                q = CN();
                q->data = head1->data;
                q->next =NULL;
                p->next = q;
                p = p->next;
               
            } 
    head1=head1->next;
    }

    while(head2!=NULL){
      
        if(head3 ==NULL){
            head3 = CN();
            head3->data = head2->data;
            head3->next =NULL;
            p =head3;
        }
        else 
            {   
                q = CN();
                q->data = head2->data;
                q->next =NULL;
                p->next = q;
                p = p->next;
                
            }
    head2=head2->next;
    }       
    return head3;
}

Node* intersection(Node* head1 , Node* head2 ){
    Node* head3 =NULL;
    Node*p;
    Node*q = head2;
    while(head1!=NULL){
        head2 = q;
        while(head2 !=NULL){
            
            if(head1->data==head2->data){
                if(head3==NULL){
                    head3 =CN();
                    head3->data = head1->data;
                    head3->next =NULL;
                    p =head3;
                }
                else{
                    Node*r =CN();
                    r->data = head1->data;
                    p->next =r;
                    p =p->next;
                    p->next =NULL;
                
                }
                break;
            }
             head2 =head2->next;
        }
        head1 = head1->next;
    }

    return head3;
}

Node* diff(Node*head1 ,Node* head2){
    Node* head3 =NULL;
    Node*q ,*r=head2;
    while(head1 !=NULL){

        int flag =0;
        head2 = r;
        while(head2 != NULL){
            
            if(head1 ->data == head2->data){
                flag =1;
                break;
            }
            head2 = head2 ->next;
        }

        if(flag ==0){

            if(head3 == NULL){
                head3 =CN();
                head3->data =head1->data;
                head3->next = NULL;
                q=head3;
            }
            else
            {
                Node *p = CN();
                p->data = head1 ->data;
                q->next  = p;  
                q =q->next;
                q->next =NULL;
            }
        }
        head1 = head1->next;
    }

    return head3;
}

int search(Node* head ,int val){
    int pos=0;
    while(head!=NULL){
        pos++;
        if(val ==head->data)
            return pos;
        head =head->next;
    }
    return 0;
}

// head                       pos 
// 10|2002      10|2002       20|3003   30|4002     30|NULL
// 1002        9002            2002     3003        4002

Node* skip(struct node * head ){
    
    if(head ==NULL || head->next ==NULL)
        return head;
    else if(head->next->next ==NULL){
        delete_ln(head);
        return head;
        }
    Node*p =head , *q;
    while(p->next!=NULL){
        q =p->next;
        p->next =q->next;
        free(q);
        p = p->next;
        if(p==NULL)
            break;
    }
    

    return head;
}
int main()
{
    int ch;
    struct node * HEAD ,*HEAD1,*HEAD2,*HEAD3;
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
            case 9:
                HEAD = remove_dup(HEAD);
                break;
            case 10:
                HEAD =sort(HEAD);
                break;
            case 11:
                HEAD = reverse(HEAD);
                break;
            case 12:
                HEAD1 = create();
                cout<<"Linked list 1 is created !!!"<<endl;

                 HEAD2 = create();
                cout<<"Linked list 2 is created !!!"<<endl;

                HEAD3 = union_t1(HEAD1 ,HEAD2);
                cout<<" Union is done !!!"<<endl;

                cout<<"Display a linked list 1 "<<endl;
                display(HEAD1);
                
                cout<<"Display a linked list 2 "<<endl;
                display(HEAD2);

                cout<<"Display a linked list 3 "<<endl;
                display(HEAD3);
        
                break;
            
            case 13:
                HEAD1 = create();
                cout<<"Linked list 1 is created !!!"<<endl;

                HEAD2 = create();
                cout<<"Linked list 2 is created !!!"<<endl;

                HEAD3 = intersection(HEAD1 ,HEAD2);
                cout<<" intersection is done !!!"<<endl;

                cout<<"Display a linked list 1 "<<endl;
                display(HEAD1);
                
                cout<<"Display a linked list 2 "<<endl;
                display(HEAD2);

                cout<<"Display a linked list 3 "<<endl;
                display(HEAD3);
        
                break;

            case 14:
                HEAD1 = create();
                cout<<"Linked list 1 is created !!!"<<endl;

                HEAD2 = create();
                cout<<"Linked list 2 is created !!!"<<endl;

                HEAD3 = diff(HEAD1 ,HEAD2);
                cout<<" intersection is done !!!"<<endl;

                cout<<"Display a linked list 1 "<<endl;
                display(HEAD1);
                
                cout<<"Display a linked list 2 "<<endl;
                display(HEAD2);

                cout<<"Display a linked list 3 "<<endl;
                display(HEAD3);
        
                break;
        
            case 15:
                cout<<"Enter element :"<<endl;
                int val;
                cin>>val;
                if(search(HEAD,val) !=0){
                    cout<<"element is present"<<endl;
                }else{
                    cout<<"element is NOT present"<<endl;
                }
                break;

            case 16:
                
                HEAD =skip(HEAD);
                break;
        }

    
    }
    return 0; 
}
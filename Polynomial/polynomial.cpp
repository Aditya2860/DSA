#include<iostream>
using namespace std;

//  General form of polynomial    ax2 + bx + c = 0      //It is 2 degree polynomial

//  how yo store polynomial in array

//  ax3 +bx2 + cx + d = 0                      // a = coeficient  and 3 = power

// 0                1     2          3      4         5     6   
// number of terms  power coeficient power coeficient power coeficient

//example
// 0 1 2 3 4 5 6 7 8
// 4 3 a 2 b 1 c 0 d




void display_poly(int arr[]){
        if(arr[0]==0)
            cout<<"Polynomial is empty .";
        int i;
        for(i=2;i<arr[0]*2;i+=2){
            cout<<arr[i]<<"X^"<<arr[i-1]<<" + ";
        }
        cout<<arr[i]<<"X^"<<arr[i-1]<<" ."<<endl;
}

void accept_poly(int arr[]){
    int power ,coeficient;
    cout<<"Enter no of terms :";

    cin>>arr[0];

     for(int i=1;i<=2*arr[0];){
        cout<<"Enter power and coeficient :";
        cin>>power>>coeficient;
        arr[i++]=power;
        arr[i++]=coeficient;

    }
}

int evaluate(int arr[],int x){
    int ans=0;
    int i;
    for(i=2;i<=arr[0]*2;i+=2){
        int pow=1;
        for(int j=1;j<=arr[i-1];j++){
            pow *= x;
        }
        ans += arr[i] *pow; 
    }

    return ans;

}


//  poly1 
//                 i
// 0 1 2  3 4  5 6
// 3 3 10 2 20 1 30

//  poly2
//                      j
// 0 1 2  3 4  5 6  7 8
// 4 4 15 3 25 1 35 0 40

//  poly3 
//                         k
// 0 1 2  3 4  5 6 7  8  9 10
//   4 15 3 35 2 20 1 65 0 40 
void sum_poly(int poly1[],int poly2[],int poly3[]){

    int k=1,i,j;
    for(i=1,j=1;i<=poly1[0]*2 && j<=poly2[0]*2 ;){
        if(poly1[i]>poly2[j]){
            poly3[k++]=poly1[i++];
            poly3[k++]=poly1[i++];
        }
        else if(poly1[i]< poly2[j]){
            poly3[k++]=poly2[j++];
            poly3[k++]=poly2[j++];
        }
        else{       //   poly[i] ==poly[j]
            poly3[k++]=poly1[i++];
            j++;
            poly3[k++]=poly1[i++]+poly2[j++];
        }  
    }


    // remaining 
    while(i<=poly1[0]*2){
         poly3[k++]=poly1[i++];
         poly3[k++]=poly1[i++];
    }
    while(j<=poly2[0]*2){
        poly3[k++]=poly2[j++];
        poly3[k++]=poly2[j++];   
    }


    poly3[0]=k/2;
}

//  poly1 
//   i
// 0 1 2  3 4  5 6
// 3 3 10 2 20 1 30

//  poly2
//   j
// 0 1 2  3 4  5 6  7 8
// 4 4 15 3 25 1 35 0 40

//  poly4
//                        k
// 0 1 2   3 4   5 6   7  8     9 10
//   7 150 6 300 4 450 6  250   5 500 3 750 4 350 3 700    2 1050 3 400 2 800 1 1200


//poly3
//  
// poly 5
//  

void multi_poly(int poly1[],int poly2[],int poly3[]){
    int k ;
    int poly4[101],poly5[101];
    poly5[0]=0;
    int l;
    for(int i=1;i<=poly1[0]*2;i+=2){
        k = 1;
       
        for(int j = 1;j<=poly2[0]*2;){
            poly4[k++]=poly1[i]+poly2[j++];
            poly4[k++]= poly1[i+1]*poly2[j++];

        }
        poly4[0]=k/2;
        sum_poly(poly4,poly5,poly3);
        
        for(l=0;l<=poly3[0]*2;l++){
            poly5[l]=poly3[l];
        }
    }
}

int main(){

    int arr[100];
    arr[0]=0;
    int ch,x,ans;

    int poly1[101],poly2[101],poly3[101],poly4[101];

    
    while(1){
        cout<<"========================="<<endl;
        cout<<"Enter case no : "<<endl;
        cin>>ch;
        cout<<"========================="<<endl;
        switch(ch){
            case 1:
                 accept_poly(arr);
                 break;
            case 2:
                display_poly(arr);
                break;

            case 3:
                cout<<"Enter value of X :";
                cin>>x;
                ans = evaluate(arr,x);
                cout<<ans<<endl;
            case 4:
                cout<<"Sum of 2 polynomial : "<<endl;
                cout<<"Enter 1st polynomial"<<endl;
                accept_poly(poly1);
                 cout<<"Enter 2nd polynomial"<<endl;
                accept_poly(poly2);

                sum_poly(poly1,poly2,poly3);
                
                display_poly(poly3);

            case 5:
                cout<<"Multiplication of 2 polynomial : "<<endl;
                 cout<<"Enter 1st polynomial"<<endl;
                accept_poly(poly1);
                cout<<endl;
                 cout<<"Enter 2nd polynomial"<<endl;
                accept_poly(poly2);
                cout<<endl;

                multi_poly(poly1,poly2,poly4);

                display_poly(poly4);

            default:
                return 0;
        }
    }

    return 0;
}
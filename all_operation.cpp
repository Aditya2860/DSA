#include<iostream>

using namespace std;

void incert_array(int arr[],int &n){
    cout<<"Enter number of elements :";
    cin>>n;
    cout<<"Enter values :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

}


void display_array(int arr[],int &n){
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

}

bool delete_element(int arr[],int &n,int x){
    bool flag=false;
    for(int i=0;i<n;i++){
        if(arr[i] ==x){
            for(int j=i;j<n-1;j++){
                arr[j]=arr[j+1];
            }
            n = n-1;
            i--;
            flag = true;
        }
    }

    return flag;
}

void delete_position(int arr[],int &n,int x){
    for(int i=x-1;i<n-1;i++){
        arr[i]=arr[i+1];
        
    }
    n=n-1;

    cout<<"Delete position sucessfully."<<endl;
}

void insert_Element(int arr[],int &n,int x,int idx){
    for(int i=n+1;i>idx-1;i--){
        arr[i]=arr[i-1];
    }
    arr[idx-1]=x;
    n+=1;
}

int linear_search(int arr[],int n,int x){
    // for(int i=0;i<n;i++){
    //     if(arr[i]==x)
    //         return i;
    // }

    // return -1;
    int i;
    for( i=0;i<n && arr[i]!=x ;i++);
    
    if(i<n && arr[i]==x)
        return i;
        
    return -1;

}

int binary_search(int arr[],int n,int x){
    int first=0;
    int last = n-1;
    int mid;

    while(first<=last){
        mid = (first +last)/2;

        if(arr[mid] ==x){
            cout<<"Index position is :"<<mid<<"\n";
            return mid;
        }
        else if(arr[mid] > x){
            last= mid -1;

        }
        else{
            first = mid+1;
        }
    }

    return -1;

    

}

int binary_search_rec(int arr[],int first , int last ,int x){
    int mid;
    mid = (last+first)/2;

    if(first <=last){
        if(arr[mid]==x){
          cout<<"Index position is :"<<mid<<"\n";
            return mid;
        }
        else if(arr[mid] > x ){
            binary_search_rec(arr,first,mid-1,x);
        }

        else{
            binary_search_rec(arr,mid+1,last,x);
        }
    }
    return -1;


}

void bubble_sort(int arr[],int n){
    // 50 40 30 20 10 

    int max = arr[0];
    for(int j=n;j>0;j--){
        for(int i=1;i<j;i++){
            if(arr[i-1] > arr[i]){
                    swap(arr[i-1],arr[i]);
            }
        }
    }
}

void selection_sort(int arr[],int n){
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
        
    }
}

int  main(){
    int n;
    int arr[100];
    int num;
    int x;
    int idx;
    while(1){
        cout<<"-----------------------"<<endl;
        cin>>num;
        cout<<"-----------------------"<<endl;
        switch (num)
        {
        case 1:
            incert_array(arr,n);
            break;
        case 2:
            display_array(arr,n);
            break;
        case 3:
            cout<<"Enter element you want to delete."<<endl;
            cin>>x;
            if(delete_element(arr,n,x))
                cout<<"Delete sucessfilly . "<<endl;
            else
                cout<<"Failed"<<endl;
            break;
        case 4:
            cout<<"Enter POSITION of element you want to delete."<<endl;
            cin>>x;
            delete_position(arr,n,x);
        case  5:
            cout<<"Enter Element.";
            cin>>x;
            cout<<"Enter position you want to insert . "<<endl;
            cin>>idx;

            insert_Element(arr,n,x,idx);

        case 6:
            cout<<"linear search.";
            cout<<"Enter element.";
            cin>>x;
            if(linear_search(arr,n,x))
                cout<<"Element is present ."<<endl;
            else
                cout<<"element is not present."<<endl;

        case 7:
            cout<<"Binary Search."<<endl;
            cout<<"Enter element you want to SEARCH."<<endl;
            cin>>x;

            if(binary_search(arr,n,x))
                cout<<"Element is present .\n";
            else
                cout<<"Element is not present\n";
            
        
         case 8:
            cout<<"Binary Search recursion."<<endl;
            cout<<"Enter element you want to SEARCH."<<endl;
            cin>>x;

            if(binary_search_rec(arr,0,n-1,x))
                cout<<"Element is present .\n";
            else
                cout<<"Element is not present\n";
            
        
        case 9:
            cout<<"Bubble sort .";
            bubble_sort(arr,n);

        case 10:
            cout<<"Selection sort."<<endl;
            selection_sort(arr,n);
        default:
            break;
        }
    }
    return 0;
}
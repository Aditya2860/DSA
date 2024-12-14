#include<iostream>
#include<vector>
using namespace std;

void printF(int index , vector<int>&temp , int arr[] , int n ){
    if(n <= index)
    {
        for(auto it : temp){
            cout<<it<<" ";
        }
        if(temp.size() == 0)
            cout<<"{}";
        cout<<endl;
        return;
    }

    // take the value at index
    temp.push_back(arr[index]);
    printF(index+1 , temp , arr , n);

    // not- take the value at index

    temp.pop_back();
    printF(index+1 , temp , arr ,n);
}

int main(){
    int arr[] = {3,1,2};
    vector<int>temp;
    int n= 3;
    printF(0 , temp , arr , n);
    return 0;
}
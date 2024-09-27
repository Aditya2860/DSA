#include<iostream>
#include<cstring>

using namespace std;
 
 
int main()
{
    // char c[] = "Aditya Gavali";
    // cout<<c<<endl;      //  c as base address    output = "Aditya Gavali"
    // cout<<c+7<<endl;          //                 output = "Gavali"
   

    char token []= "adigavali@gmail.com";
    char *ptr;
    char ch = '@';

    ptr = strchr(token , ch );                            //  strchr( string , character) = after value of character

    cout<< "The first occurance of "<<ch<<" in "<<token<<" is "<<ptr<<endl;
    
    cout<<ptr+1<<endl;       

    cout<<strcmp("gmail.com",ptr+1)<<endl;                      //  if string1 =string2  then strcmp(string1 , string2) =0
    if(strcmp("gmail.com",ptr+1)==0)                           //  if string1 !=string2  then strcmp(string1 , string2) =1   
        cout<<"gmail is found !!!";
    else
        cout<<"Gmail is not found ";

    
    
     return 0; 


}


#include<stdio.h>


// 1
// 1-2
// 3-5-8
// 13-21-34-55

int main(){
    int n1=1,n2=0,ans;
    for(int i=1;i<=5;i++){
      
        for(int j=i;j>=1;j--){
            ans=n1+n2;
            if(j!=1)
            printf("%d-",ans);
            else
            {
                printf("%d",ans);
            }
            n1=n2;
            n2=ans;
            
        }
        printf("\n");
    }
}

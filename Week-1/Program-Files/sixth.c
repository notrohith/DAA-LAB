//CH.SC.U4CSE24140 - Rohith S
#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int a=0;
    int b=1;
    int c;
    int count=0;
    while(count<n){
        if(count==0){
            printf("%d ",a);
        }
        else if(count==1){
            printf("%d ",b);
        }
        else{
            c=a+b;
            printf("%d ",c);
            a=b;
            b=c;
        }
        count++;
    }
    return 0;
}

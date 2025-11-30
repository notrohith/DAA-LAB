//CH.SC.U4CSE24140
#include<stdio.h>
int sumofn(int n){
    int i;
    int sum=0;
    for(i=0;i<=n;i++){
        sum+=i*i;
    }
    return sum;
}
int main(){
    int n,result;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("The sum of square of the %d natural numbers is: ",n);
    result=sumofn(n);
    printf("%d\n",result);
    return 0;
}
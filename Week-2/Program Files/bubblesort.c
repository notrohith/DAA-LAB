//CH.SC.U4CSE24140 - Rohith S
#include<stdio.h>
int main(){
    int i,j,size,temp;
    printf("Enter the size of your array: ");
    scanf("%d",&size);
    printf("Enter the elements of your array: ");
    int arr[size];
    printf("\n");
    for(i=0;i<size;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size-1;i++){
        for(j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted array\n");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0; 
}

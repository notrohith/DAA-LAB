#include<stdio.h>
int main(){
    int i,j,size,key;
     printf("Enter the size of your array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of your array:\n");
    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for(i=1;i<size;i++){
        key=arr[i];
        j=i-1;

        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
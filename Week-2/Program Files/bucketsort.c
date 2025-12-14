//CH.SC.U4CSE24140 - Rohith S
#include <stdio.h>
int main() {
    int i, j, size;
    printf("Enter the size of your array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of your array:\n");
    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
     }
    int bucket[10][size];
    int count[10];
    for (i = 0; i < 10; i++) {
        count[i] = 0;
    }
    for (i = 0; i < size; i++) {
        int index = arr[i] / 10;
        bucket[index][count[index]++] = arr[i];
    }
    for (i = 0; i < 10; i++) {
        for (j = 1; j < count[i]; j++) {
            int key = bucket[i][j];
            int k = j - 1;
            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = key;
        }
    }
    int index = 0;
    for (i = 0; i < 10; i++){
        for (j=0;j<count[i];j++) {
            arr[index++]=bucket[i][j];
        }
    }
    printf("Sorted array:\n");
    for (i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    return 0;
}

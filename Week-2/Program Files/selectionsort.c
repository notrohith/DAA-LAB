//CH.SC.U4CSE24140 - Rohith S
#include <stdio.h>
int main() {
    int i, j, size, min, temp;
    printf("Enter the size of your array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of your array:\n");
    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

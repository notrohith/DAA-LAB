//CH.SC.U4CSE24140 - Rohith S
#include <stdio.h>
int main() {
    int i, j, size, temp;
    printf("Enter the size of your array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of your array:\n");
    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = size / 2 - 1; i >= 0; i--) {
        int parent = i;
        while (1) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int largest = parent;
            if (left < size && arr[left] > arr[largest])
                largest = left;
            if (right < size && arr[right] > arr[largest])
                largest = right;
            if (largest != parent) {
                temp = arr[parent];
                arr[parent] = arr[largest];
                arr[largest] = temp;
                parent = largest;
            } else {
                break;
            }
        }
    }
    for (i = size - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        int parent = 0;
        while (1) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int largest = parent;
            if (left < i && arr[left] > arr[largest])
                largest = left;
            if (right < i && arr[right] > arr[largest])
                largest = right;
            if (largest != parent) {
                temp = arr[parent];
                arr[parent] = arr[largest];
                arr[largest] = temp;
                parent = largest;
            } else {
                break;
            }
        }
    }
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

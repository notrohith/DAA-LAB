#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 14

struct Node
{
    char data;
    int freq;
    struct Node *left, *right;
};

struct Node *createNode(char data, int freq)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void findTwoMin(struct Node *arr[], int size, int *min1, int *min2)
{
    *min1 = -1;
    *min2 = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == NULL)
            continue;

        if (*min1 == -1 || arr[i]->freq < arr[*min1]->freq)
        {
            *min2 = *min1;
            *min1 = i;
        }
        else if (*min2 == -1 || arr[i]->freq < arr[*min2]->freq)
        {
            *min2 = i;
        }
    }
}

void printCodes(struct Node *root, int code[], int top)
{
    if (root->left)
    {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right)
    {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (root->left == NULL && root->right == NULL)
    {
        printf("%c : ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

int main()
{

    char letters[N] = {'d', 'a', 't', 'n', 'l', 'y', 'i', 'c', 's', 'e', 'g', 'b', 'o', 'r'};
    int freq[N] = {2, 7, 4, 4, 4, 2, 3, 2, 1, 3, 1, 1, 2, 2};

    struct Node *arr[2 * N];

    for (int i = 0; i < N; i++)
        arr[i] = createNode(letters[i], freq[i]);

    int size = N;

    while (size > 1)
    {
        int min1, min2;
        findTwoMin(arr, size, &min1, &min2);

        struct Node *left = arr[min1];
        struct Node *right = arr[min2];

        struct Node *newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        arr[min1] = newNode;
        arr[min2] = NULL;

        size--;
    }

    struct Node *root = NULL;
    for (int i = 0; i < 2 * N; i++)
    {
        if (arr[i] != NULL)
        {
            root = arr[i];
            break;
        }
    }

    int code[100];
    printf("Huffman Codes \n");
    printCodes(root, code, 0);

    return 0;
}
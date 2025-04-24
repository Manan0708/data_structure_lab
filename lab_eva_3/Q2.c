#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void storeInorder(Node* root, int* arr, int* index) {
    if (root == NULL) return;
    storeInorder(root->left, arr, index);
    arr[(*index)++] = root->data;
    storeInorder(root->right, arr, index);
}

void findSum(Node* root, int target) {
    int arr[MAX];
    int n = 0;

    storeInorder(root, arr, &n); 
    int i = 0, j = n - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == target) {
            printf("Pair found: %d + %d = %d\n", arr[i], arr[j], target);
            return;
        }
        if (sum < target)
            i++;
        else
            j--;
    }
    printf("No pair found with sum %d\n", target);
}
 
int main() {
    Node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);

    int target = 27;

    findSum(root, target);

    return 0;
}
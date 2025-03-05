#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;          
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; 
        return;
    }
    struct Node* temp = *head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; 
}

struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2; 
    }

    struct Node* temp = list1;
  
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = list2;

    return list1; 
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    insertAtEnd(&list1, 10);
    insertAtEnd(&list1, 20);
    insertAtEnd(&list1, 30);

    insertAtEnd(&list2, 40);
    insertAtEnd(&list2, 50);
    insertAtEnd(&list2, 60);

    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    struct Node* concatenatedList = concatenateLists(list1, list2);

    printf("Concatenated List: ");
    displayList(concatenatedList);

    // Free allocated memory
    freeList(concatenatedList);

    return 0;
}

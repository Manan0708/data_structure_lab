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

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head; 
    *head = newNode;       
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


void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next; 
    free(temp);            
}


void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next = NULL;
}


void deleteAtIndex(struct Node** head, int index) {
    if (*head == NULL || index < 0) {
        printf("Invalid index or list is empty.\n");
        return;
    }

    struct Node* temp = *head;

    
    if (index == 0) {
        *head = temp->next; 
        free(temp);
        return;
    }

    
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    
    if (temp == NULL || temp->next == NULL) {
        printf("Index out of bounds.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next; 
    free(nodeToDelete);            
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

int main() {
    struct Node* head = NULL;

    
    insertAtBeginning(&head, 10);  
    insertAtEnd(&head, 20);        
    insertAtEnd(&head, 30);        
    insertAtEnd(&head, 40);        
    insertAtEnd(&head, 50);        

    printf("Linked List before deletion: ");
    displayList(head);

    
    deleteAtBeginning(&head);
    printf("Linked List after deleting at beginning: ");
    displayList(head);

   
    deleteAtEnd(&head);
    printf("Linked List after deleting at end: ");
    displayList(head);

   
    deleteAtIndex(&head, 1);
    printf("Linked List after deleting at index 1: ");
    displayList(head);

 
    deleteAtIndex(&head, 10);
    return 0;
}

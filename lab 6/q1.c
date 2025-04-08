#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = value;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

Node* createList(int n) {
    Node *head = NULL, *temp = NULL, *new = NULL;
    int value, i;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        new = createNode(value);

        if (head == NULL) {
            head = new;
            temp = new;
        } else {
            temp->next = new;
            new->prev = temp;
            temp = new;
        }
    }

    return head;
}

void TF(Node* head) {
    Node* temp = head;
    printf("\nList in forward direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void TB(Node* head) {
    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nList in backward direction: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main() {
    Node* head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    TF(head);
    TB(head);

    return 0;
}
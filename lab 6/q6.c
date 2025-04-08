#include <stdio.h>
#include <stdlib.h>

struct node {
    int a;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new = (struct node*)malloc(sizeof(struct node)); 
    new->a = data;
    new->next = NULL;
    return new;
}

void display(struct node* head) {
    struct node* ptr = head;
    if (head == NULL) return;  
    do {
        printf("%d ", ptr->a);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

struct node* input(int data, struct node* head) {
    struct node* new = create_node(data);
    if (head == NULL) {
        head = new;
        new->next = head;  
        return head;
    }

    struct node* temp = head;
    while (temp->next != head) { 
        temp = temp->next;
    }
    temp->next = new;
    new->next = head; 
    return head;
}

int main() {
    int n, i, data;
    struct node* head = NULL;  
    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        head = input(data, head); 
    }

    display(head); 

    return 0;
}

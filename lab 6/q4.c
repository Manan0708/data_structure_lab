#include<stdio.h>
#include<stdlib.h>

struct node{
    int a;
    struct node*next;
    struct node*prev;
};

struct node*create_node(int data){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->a=data;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

void display(struct node*head){
    while(head!=NULL){
        printf("%d\n",head->a);
        head=head->next;
    }
}

struct node*input(int data,struct node*head){
    struct node*new=create_node(data);
    if(head==NULL){
        head=new;
        return head;
    }
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
    return head;
}

struct node*insertion(int m,int n,int data1, struct node*head){
    struct node*new=create_node(data1);
    struct node*temp=head;
    if(m==1){
        head=new;
        new->next=temp;
        temp->prev=new;
    }
    else if(m>1 && m<n){
        for(int i=1;i<m-1;i++){
            temp=temp->next;
        }
        struct node*temp1=temp->next;
        temp->next=new;
        new->prev=temp;
        new->next=temp1;
        if(temp1=NULL){
        temp1->prev=new;
        }
        }
        else if(m==n){
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new;
            new->prev=temp;
        }
    return head;
}

int main(){
    int n;
    struct node*new,*head;
    head=NULL;
    int data;
    printf("Enter the number of elements you want to enter");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        head=input(data,head);
    }
    int m, data1;
    printf("Enter the position at which you want to enter element:");
    scanf("%d",&m);
    printf("Enter the element");
    scanf("%d",&data1);

    head=insertion(m,n,data1,head);
    display(head);


}
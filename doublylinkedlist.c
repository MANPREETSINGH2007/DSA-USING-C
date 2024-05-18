#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head=NULL;
struct Node* createNode(){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d",&node->data);
    node->next=NULL;
    node->prev=NULL;
    return node;
}
void createList(){
    int n,i;
    printf("Enter number of node: ");
    scanf("%d",&n);
    struct Node *temp=head;
    for(i=0;i<n;i++){
        struct Node *newNode=createNode();
        if(head==NULL){
            head=newNode;
        }
        else{
            temp->next=newNode;
            newNode->prev=temp;
        }
        temp=newNode;
    }
}
void displayList(){
     if(head==NULL){
        printf("List is empty!!!");
    }
    else{
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
       }
    }
}
void insertNodeinBeg(){
    struct Node *newNode=createNode();
    newNode->next=head;
    head=newNode;
}
void insertNodeinEnd(){
    struct Node *newNode=createNode();
    if(head==NULL){
        head=newNode;
    }
    else{
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->prev=temp;
    temp->next=newNode;
    }
}
void insertNodeAtPosition(){
    if(head==NULL){
        printf("List is empty!!!");
    }
    else{
        int pos,cnt=0;
        printf("Enter the position: ");
        scanf("%d",&pos);
        if(pos==1){
            struct Node *newNode=createNode();
            newNode->next=head;
        }
        else{
            struct Node *temp=head;
        while(temp->next!=NULL){
            if(cnt==pos-1){
            break;
            }
            cnt++;
            temp=temp->next;
        }
        if(temp->next==NULL){
            printf("Invalid position!!!");
        }
        else{
            struct Node *newNode=createNode();
            newNode->next=temp->next;
            newNode->prev=temp;
            temp->next=newNode;
        }
        }
    }
}
void deleteNodeAtPosition(){
    if(head==NULL){
        printf("List is empty!!!");
    }
    else{
        int pos,cnt=1;
        printf("Enter Position: ");
        scanf("%d",&pos);
        if(pos==1){
            head=head->next;
            head->prev=0;
        }
        else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            if(cnt==pos){
                break;
            }
            cnt++;
            temp=temp->next;        
        }
        if(temp->next==NULL){
            printf("Invalid Position!!!");
        }
        else{
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
    }
}
}
int main()
{
    system("cls");
    createList();
    while(1){
    printf("\n");
    printf("\n1. Insert Node In Begining\n");
    printf("\n2. Insert Node In End\n");
    printf("\n3. Insert Node At Any Position\n");
    printf("\n4. Delete Node From Given Position\n");
    printf("\n5. Search Node In List\n");
    printf("\n6. Display List\n");
    printf("\n7. Exit\n");
    int choice;
    printf("\nEnter your choice : \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insertNodeinBeg();
        break;
        case 2:
        insertNodeinEnd();
        break;
        case 3:
        insertNodeAtPosition();
        break;
        case 4:
        deleteNodeAtPosition();
        break;
        // case 5:
        // searchNode();
        // int val;
        // printf("Enter the value : ");
        // scanf("%d",&val);
        // if(searchNode(val)) printf("\nFOUNDED\n");
        // else printf("\nNOT FOUNDED\n");
        // break;
        case 6:
        displayList();
        break;
        case 7:
        exit(0);
        break;
    }
   }
   printf("\n");
   return 0;
}
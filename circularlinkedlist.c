#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL, *tail=NULL;
struct Node* createNode(){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data:");
    scanf("%d",&node->data);
    node->next=NULL;
    return node;
}
void createList(){
    int n,i;
    printf("Enter total number of nodes:");
    scanf("%d",&n);
    struct Node *temp=NULL;
    for(i=0;i<n;i++){
        struct Node *newNode=createNode();
        if(tail==NULL){
        tail=newNode;
        tail->next=newNode;
    }
        else{
            newNode->next=tail->next;
            tail->next=newNode;
        }
        tail=newNode;
    }
}
void displayList(){
    if(tail==NULL){
        printf("List is empty!!!");
    }
    else{
        struct Node *temp=tail->next;
        while(temp->next!=tail->next){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
void insertNodeinBeg(){
    struct Node *newNode=createNode();
    if(tail==0){
        tail=newNode;
        tail->next=newNode;
    }
    else{
    newNode->next=tail->next;
    tail->next=newNode;
    }
}
void insertNodeinEnd(){
    struct Node *newNode=createNode();
    if(tail==NULL){
        tail=newNode;
        tail->next=newNode;
    }
    else{
        newNode->next=tail->next;
        tail->next=newNode;
        tail=newNode;
    }
}
void insertNodeAtPosition() {
    if(tail==NULL)
    {
        printf("Invalid Postion !!!!\n");
    }
    else
    {
        int pos,cnt=1;
        printf("Enter Postion : ");
        scanf("%d",&pos);
        if(pos==1)
        {
            insertNodeinBeg();
        }
        else{
            struct Node *temp = tail->next;
            while(temp->next!=tail->next)
            {
                if(cnt==pos-1){
                    break;
                }
                cnt++;
                temp = temp->next;
            }
        if(temp->next==tail->next)
        {
            printf("Invalid Postion !!!!\n");
        }
        else{
            struct Node *newnode = createNode();
            newnode->next = temp->next;
            temp->next = newnode;
        }
        }
    }
}
void deleteNodeAtPosition() {
    if (tail == NULL)
    {
        printf("\nInvalid Postion\n");
        return;
    }
    else
    {
        int pos,cnt=1;
        printf("Enter Postion : ");
        scanf("%d",&pos);
        if(pos==1)
        {
            tail = tail->next->next;
        }
        else{
            struct Node *temp = head;
            while(temp->next!=NULL)
            {
                if(cnt==pos-1){
                    break;
                }
                cnt++;
                temp = temp->next;
            }
        
        if(temp->next==NULL)
        {
            printf("\nInvalid Postion !!!!\n");
        }
        else{
            temp->next = temp->next->next;
        }
        }
    }
}
int searchNode(int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
int main()
{
    system("clear");
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
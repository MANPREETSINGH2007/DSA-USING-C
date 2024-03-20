#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 1000
struct movie{
    int movieId;
    char movieName[50];
    char release[20];
    float rating;
};
struct movie mlist[maxsize];
int count=0;
void addMovie(){
    int i;
    for(i=count;i<maxsize && i==count;i++){
        printf("\nEnter Movie name: ");
        scanf(" %[^\n]s",mlist[i].movieName);
        printf("Enter movie ID: ");
        scanf("%d",&mlist[i].movieId);
        printf("Enter movie release date: ");
        scanf(" %[^\n]s",mlist[i].release);
        printf("Enter movie rating: ");
        scanf("%f",&mlist[i].rating);
    }
    count++;
}    
void displayMovie(){
    if(count==0){
        printf("No Record Found!!");
    }
    else{
    for(int i=0;i<count;i++){
        printf("\n\nMovie Name: %s",mlist[i].movieName);
        printf("\nMovie ID: %d",mlist[i].movieId);
        printf("\nMovie release date: %s",mlist[i].release);
        printf("\nMovie rating: %.2f",mlist[i].rating);
    }
    }
}
void editMovie(){
    if(count==0){
        printf("No Record Found!!");
    }
    else{
    int pos;
    printf("\n\nEnter the serial no. of the movie you want to edit: ");
    scanf("%d",&pos);
    for(int i=pos-1;i<pos;i++){
        char choice;
        printf("Do You Want To Edit Movie Name (Y or N): ");
        scanf(" %c",&choice);
        if(choice=='Y'||choice=='y'){
            printf("Enter New Movie Name: ");
            scanf(" %[^\n]s",mlist[i].movieName);
        }
        printf("Do You Want To Edit Movie ID (Y or N): ");
        scanf(" %c",&choice);
        if(choice=='Y'||choice=='y'){
            printf("Enter New Movie ID: ");
            scanf("%d",&mlist[i].movieId);
        }
        printf("Do You Want To Edit release date (Y or N): ");
        scanf(" %c",&choice);
        if(choice=='Y'||choice=='y'){
            printf("Enter New release date: ");
            scanf(" %[^\n]s",mlist[i].release);
        }
        printf("Do You Want To Edit Movie rating (Y or N): ");
        scanf(" %c",&choice);
        if(choice=='Y'||choice=='y'){
            printf("Enter New Movie rating: ");
            scanf("%f",&mlist[i].rating);
        }
    }
    printf("Editing Succesfull!!");
    }
}    
void deleteMovie(){
    if(count==0){
        printf("No Record Found!!");
    }
    else{
        int del;
        printf("\nEnter the serial no. of the movie you want to delete: ");
        scanf("%d",&del);
        for(int i=del-1;i<count;i++){
            mlist[i]=mlist[i+1];
        }
        count--;
        printf("Deletion Succesfull!!");
        }
}
void searchMovie(){
    if(count==0){
        printf("No Record Found!!");
    }
    else{
        int search;
        char srch[50];
        char relse[20];
        int flag=0;
        printf("Do you want to search by movie name or release date\n1 For Name\n2 For Release Date\n");
        scanf("%d",&search);
        if(search==1){
            printf("Enter Movie Name: ");
            scanf(" %[^\n]s",srch);
            for(int i=0; i<count ; i++){
                if(strcmp(srch, mlist[i].movieName) == 0){
                    printf("Movie Found at serial no. %d!!\n",i+1);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                printf("Movie Not Found!!\n");
        }
        else if(search==2){
            printf("Enter Release Date: ");
            scanf(" %[^\n]s",relse);
            for(int i=0; i<count ; i++){
                if(strcmp(relse, mlist[i].release) == 0){
                    printf("Movie Found at serial no. %d!!\n",i+1);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                printf("Movie Not Found!!\n");
        }
    }
}
int main(){
    while(1){
        printf("1. Add a new Movie Record");
        printf("\n2. Display all Movie Records");
        printf("\n3. Edit Movie Record by movie ID");
        printf("\n4. Delete Movie from list");
        printf("\n5. Search Movie by Name or Realese Date");
        printf("\n6. Exit");
        int choice;
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addMovie();
                break;
            case 2:
                displayMovie();
                break;
            case 3:
                editMovie();
                break;
            case 4:
                deleteMovie();
                break;
            case 5:
                searchMovie();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Choice!");
        }
        printf("\n");
        system("pause");
        system("cls");
    }
}
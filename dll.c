#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    struct node *llink;
    int ssn;
    char name[20];
    float sal;
    struct node *rlink;
};
typedef struct node *NODE;
NODE first=NULL;
int count=0;
NODE createnode();
void createdll();
void insertfront();
void insertend();
void deletefront();
void deleteend();
void display();
int main(){
    int ch;
    while(1){
        printf("1.CreateDLL\n2.DisplayDLL\n3.Insert front\n4.Insert End\n5.Delete Front\n6.Delete End\n7.Exit\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                createdll();
                break;
            case 2:
                display();
                break;
            case 3:
                insertfront();
                break;
            case 4:
                insertend();
                break;
            case 5:
                deletefront();
                break;
            case 6:
                deleteend();
                break;
            case 7:
                exit(0);
        }
    }
    return 0;
}
NODE createnode(){
    NODE temp=malloc(sizeof(struct node));
    printf("Enter ssn,name,salary: ");
    scanf("%d %s %f", &temp->ssn,temp->name,&temp->sal);
    temp->llink=NULL;
    temp->rlink=NULL;
    count++;
    return temp;
}
void createdll(){
    int n,i;
    NODE temp,cur;
    printf("Enter the number of employees you want to enter: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter details of employee %d:",i+1);
        temp=createnode();
        if(first==NULL){
            first=temp;
        }else{
            cur=first;
            while(cur->rlink!=NULL){
                cur=cur->rlink;
            }
            temp->llink=cur;
            cur->rlink=temp;
        }
    }
}
void display(){
    NODE temp=first;
    if(first==NULL){
        printf("DLL is Empty\n");
    }else{
        printf("Employee Details:\nSSN\tNAME\tSALARY\n");
        while(temp!=NULL){
            printf("%d\t%s\t%.2f\n",temp->ssn,temp->name,temp->sal);
            temp=temp->rlink;
        }
        printf("Total no of employees are %d\n",count);
    }
}
void insertfront(){
    NODE temp=createnode();
    if(first==NULL){
        first=temp;
    }else{
        temp->rlink=first;
        first=temp;
    }
}
void insertend(){
    NODE cur=first,temp=createnode();
    if(first==NULL){
        first=temp;
    }else{
        while(cur->rlink!=NULL){
            cur=cur->rlink;
        }
        temp->llink=cur;
        cur->rlink=temp;
    }
    display();
}
void deletefront(){
    if(first==NULL){
        printf("DLL is Empty\n");
    }else{
        first=first->rlink;
        first->llink=NULL;
        count--;
    }
}
void deleteend(){
    NODE cur=first;
    if(first==NULL){
        printf("DLL is Empty\n");
    }else if(first->rlink==NULL){
        first=NULL;
        count--;
    }else{
        while(cur->rlink->rlink!=NULL){
            cur=cur->rlink;
        }
        cur->rlink=NULL;
        count--;
    }
}
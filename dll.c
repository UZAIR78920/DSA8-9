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
/*
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    struct node *llink;
    int eid;
    char ename[20];
    float salary;
    struct node *rlink;
};
typedef struct node *NODE;
NODE first=NULL;
int c=0;
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
        printf("Menu\n1.CreateDLL\n2.InsertFront\n3.InsertEnd\n4.DeleteFront\n5.DeleteEnd\n6.Display\n7.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                createdll();
                break;
            case 2:
                insertfront();
                break;
            case 3:
                insertend();
                break;
            case 4:
                deletefront();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
        }
    }
    return 0;
}
NODE createnode(){
    NODE temp=malloc(sizeof(struct node));
    temp->rlink=NULL;
    temp->llink=NULL;
    c++;
    printf("Enter eid,name,salary: ");
    scanf("%d %s %f",&temp->eid,temp->ename,&temp->salary);
    return temp;
}
void createdll(){
    int n,i;
    NODE temp,cur;
    printf("Enter no of emp details: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        cur=first;
        printf("Enter details of emp %d:",i+1);
        temp=createnode();
        if(first==NULL){
            first=temp;
        }else{
            while(cur->rlink!=NULL){
                cur=cur->rlink;
            }
            temp->llink=cur;
            cur->rlink=temp;
        }
    }
    display();
}
void insertfront(){
    NODE temp=createnode();
    if(first==NULL){
        first=temp;
    }else{
        first->llink=temp;
        temp->rlink=first;
        first=temp;
    }
    display();
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
        first->rlink->llink=NULL;
        first=first->rlink;
        c--;
    }
    display();
}
void deleteend(){
    NODE cur=first;
    if(first==NULL){
        printf("DLL is Empty\n");
    }else if(first->rlink==NULL){
        first=NULL;
        c--;
    }else{
        while(cur->rlink->rlink!=NULL){
            cur=cur->rlink;
        }
        cur->rlink=NULL;
        c--;
    }
    display();
}
void display(){
    NODE temp=first;
    if(first==NULL){
        printf("DLL is Empty\n");
    }else{
        printf("Employee Details:\nEID\tNAME\tSalary\n");
        while(temp!=NULL){
            printf("%d\t%s\t%.2f\n",temp->eid,temp->ename,temp->salary);
            temp=temp->rlink;
        }
        printf("Total no of employees are %d\n",c);
    }
}
*/
int output(){return 0;}
/*
Menu
1.CreateDLL
2.InsertFront
3.InsertEnd
4.DeleteFront
5.DeleteEnd
6.Display
7.Exit
Enter your choice: 1
Enter no of emp details: 2
Enter details of emp 1:Enter eid,name,salary: 101 asdf 10000
Enter details of emp 2:Enter eid,name,salary: 102 qwerty 20000
Employee Details:
EID     NAME    Salary
101     asdf    10000.00
102     qwerty  20000.00
Total no of employees are 2
Menu
1.CreateDLL
2.InsertFront
3.InsertEnd
4.DeleteFront
5.DeleteEnd
6.Display
7.Exit
Enter your choice: 2
Enter eid,name,salary: 100 zxcvb 5000
Employee Details:
EID     NAME    Salary
100     zxcvb   5000.00
101     asdf    10000.00
102     qwerty  20000.00
Total no of employees are 3
Menu
1.CreateDLL
2.InsertFront
3.InsertEnd
4.DeleteFront
5.DeleteEnd
6.Display
7.Exit
Enter your choice: 3
Enter eid,name,salary: 103 jkl 6000
Employee Details:
EID     NAME    Salary
100     zxcvb   5000.00
101     asdf    10000.00
102     qwerty  20000.00
103     jkl     6000.00
Total no of employees are 4
Menu
1.CreateDLL
2.InsertFront
3.InsertEnd
4.DeleteFront
5.DeleteEnd
6.Display
7.Exit
Enter your choice: 4
Employee Details:
EID     NAME    Salary
101     asdf    10000.00
102     qwerty  20000.00
103     jkl     6000.00
Total no of employees are 3
Menu
1.CreateDLL
2.InsertFront
3.InsertEnd
4.DeleteFront
5.DeleteEnd
6.Display
7.Exit
Enter your choice: 5
Employee Details:
EID     NAME    Salary
101     asdf    10000.00
102     qwerty  20000.00
Total no of employees are 2
Menu
1.CreateDLL
2.InsertFront
3.InsertEnd
4.DeleteFront
5.DeleteEnd
6.Display
7.Exit
Enter your choice: 6
Employee Details:
EID     NAME    Salary
101     asdf    10000.00
102     qwerty  20000.00
Total no of employees are 2
Menu
1.CreateDLL
2.InsertFront
3.InsertEnd
4.DeleteFront
5.DeleteEnd
6.Display
7.Exit
Enter your choice: 7
*/

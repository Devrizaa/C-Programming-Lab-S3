#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*newnode,*START,*p,*prev;

void menu();
void submenuin();
void submenudel();
void in();
void inFirst();
void inLast();
void inPos();
void del();
void delFirst();
void delLast();
void delItem();
void display();

int main()
{
    START=NULL;
    int ch;
    do{
        
        menu();
        printf("Enter The Operation Number : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 :in();
                    break;
                    break;
            case 2 :del();
                    break;
            case 3 :display();
                    break;
            case 4 :return 0;
            default:printf("Enter Valid Operation Number!");
        }
        
    }while(1);
}
void menu()
{
    printf("\n-------------------------------------------\n");
    printf("OPERATIONS MENU\n");
    printf("\t1.Insertion\n");
    printf("\t2.Deletion\n");
    printf("\t3.Display\n");
    printf("\t4.Exit\n");
}
void submenuin()
{
    printf("\t\t1.At First Position\n");
    printf("\t\t2.At Last Position\n");
    printf("\t\t3.At Particular Position\n");
}
void submenudel()
{
    printf("\t\t1.From First Position\n");
    printf("\t\t2.From Last Position\n");
    printf("\t\t3.A Particular Element\n");
}
void in()
{
    int ch;
    submenuin();
    printf("Your Choice : ");
    scanf("%d",&ch);
    switch(ch){
        case 1 :inFirst();
                break;
        case 2 :inLast();
                break;
        case 3 :inPos();
                break;
        default:printf("Enter Valid Operation Number!");
    }
}
void inFirst()
{
    if(START==NULL){
        printf("......LIST IS EMPTY !!......ENTERING AS FIRST ELEMENT.....\n");
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Element : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        START=newnode;
    }
    else{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Element : ");
        scanf("%d",&newnode->data);
        newnode->next=START;
        START=newnode;
    }
    
}
void inLast()
{
    if(START==NULL){
        printf("......LIST IS EMPTY !!......ENTERING AS FIRST ELEMENT.....\n");
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Element : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        START=newnode;
    }
    else{
        newnode=(struct node*)malloc(sizeof(struct node));
        p=START;
        while(p->next!=NULL){
            p=p->next;
        }
        printf("Enter Element : ");
        scanf("%d",&newnode->data);
        p->next=newnode;
        newnode->next=NULL;
    }
}
void inPos()
{
    int item;
    printf("Enter the key Element next to Which the Element is to be Entered :");
    scanf("%d",&item);
    p=START;
    while(p!=NULL){
        if(p->data==item){
            break;
        }
        prev=p;
        p=p->next;
    }
    if(p==NULL){
        printf("!!---------------INSERTION FAILED---------------!!");
        printf("\n.........\' %d \' NOT FOUND IN THE LIST.........\n",item);
    }
    else if(p->next==NULL && p->data==item){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Element : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        p->next=newnode;
    }
    else{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Element : ");
        scanf("%d",&newnode->data);
        newnode->next=p->next;
        p->next=newnode;
    }
}
void del()
{
    int ch;
    submenudel();
    printf("Your Choice : ");
    scanf("%d",&ch);
    switch(ch){
        case 1 :delFirst();
                break;
        case 2 :delLast();
                break;

case 3 :delItem();
                break;
        default:printf("Enter Valid Operation Number!");
    }
}
void delFirst()
{
    p=START;
    printf("\n.........DELETING \' %d \' FROM LIST.........\n",p->data);
    START=START->next;
    free(p);
}
void delLast()
{
    p=START;
    while(p->next!=NULL){
        prev=p;
        p=p->next;
    }
    printf("\n.........DELETING \' %d \' FROM LIST.........\n",p->data);
    prev->next=NULL;
    free(p);
}
void delItem()
{
    int item;
    printf("Enter the Element to be Deleted From LIST :");
    scanf("%d",&item);
    p=START;
    while(p->data!=item && p->next!=NULL){
        prev=p;
        p=p->next;
    }
    
    if(p==START){
        printf("\n.........DELETING \' %d \' FROM LIST.........\n",item);
        START=START->next;
        free(p);
    }
    else if(p->data==item){
        printf("\n.........DELETING \' %d \' FROM LIST.........\n",item);
        prev->next=p->next;
        free(p);
    }
    else if(p->next==NULL){
        printf("\n.........DELETING \' %d \' FROM LIST.........\n",item);
        prev->next=NULL;
        free(p);
    }
    else{
        printf("!!---------------DELETION FAILED---------------!!");
        printf("\n.........\' %d \' NOT FOUND IN THE LIST.........\n",item);
    }
}
void display()
{
    if(START==NULL){
        printf("LIST is EMPTY !!");
    }
    else{
        printf("Entered LIST :");
        p=START;
        while(p!=NULL){
            printf(" %d ",p->data);
            p=p->next;
        }
    }
}



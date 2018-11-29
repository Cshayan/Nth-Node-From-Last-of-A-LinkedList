//Programme to display the nth node from the last
#include <stdio.h>
#include <stdlib.h>
//structure declaration
struct node
{
    int data;
    struct node *next;
};
//create function to add link list nodes
void create(struct node **start,int num)
{
    struct node *temp,*curr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if((*start)==NULL)
    {
        (*start)=temp;
    }
    else
    {
        curr=(*start);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=temp;
    }
}
// function to display the list
void display(struct node *start)
{
    struct node *curr=start;
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr=curr->next;
    }
    printf("\n\n");
}
// function displays the nth node from last
void displayNth(int tot,int n,struct node *start)
{
    int temp=(tot-n);
    struct node *curr=start;
    while(temp>0)
    {
        curr=curr->next;
        temp--;
    }
    printf("\n%dth node from last is %d\n\n\n\n",n,curr->data);
}
int main()
{
    struct node *start=NULL;
    int n,num,tot;
    printf("Enter the no of nodes to be created:- ");
    scanf("%d",&tot);
    printf("\nEnter the value of n:- ");
    scanf("%d",&n);
    int i;
    printf("\nEnter the elements:- ");
    for(i=0;i<tot;i++)
    {
        scanf("%d",&num);
        create(&start,num);
    }
    printf("The given list is:-\n");
    display(start);
    displayNth(tot,n,start);
 return 0;
}

/*
Utilities, which are used for xcast, but not belongs to xcast function should be implemented here.
Function like set Union, set difference (subtraction) and intersection should be move here.
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX_RECEIVER 32
class Utility{
public:

// Functions for linked list implementation.
  Utility();
  void append(int* data);
  void add(int* data);
  void addafter(int* data, int loc);
  int count();
  void insert(int* data);
  int deleteNode(int* data);
  void display(struct node* r);

//function for set (difference, intersection, union)


};
// node of a linked list
struct node
{
    int* data;//data is normally an array of int.
    struct node *next;
}*head;

Utility::Utility(){

}

void Utility::append(int* data )
{
    struct node *temp,*right;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->data=data;
    right=(struct node *)head;
    while(right->next != NULL)
      right=right->next;
  
    right->next =temp;
    right=temp;
    right->next=NULL;
}



void Utility::add( int* data )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    if (head== NULL)
    {
      head=temp;
      head->next=NULL;
    }
    else
    {
      temp->next=head;
      head=temp;
    }
}
void Utility::addafter(int* data, int loc)
{
    int i;
    struct node *temp,*left,*right;
    right=head;
    for(i=1;i<loc;i++)
    {
      left=right;
      right=right->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    left->next=temp;
    left=temp;
    left->next=right;
    return;
}

int Utility::count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
      n=n->next;
      c++;
    }
    return c;
} 


void Utility::insert(int* data)
{
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
      add(data);
    }
    else
    {
      while(temp!=NULL)
      {
        if(temp->data[0]<data[0])
          c++;
        temp=temp->next;
      }
    if(c==0)
        add(data);
    else if(c<count())
        addafter(data,++c);
    else
        append(data);
    }
}



int Utility::deleteNode(int* data)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
      if(temp->data[0]==data[0])
      {
        if(temp==head)
        {
          head=temp->next;
          free(temp);
          return 1;
        }
        else
        {
          prev->next=temp->next;
          free(temp);
          return 1;
        }
      }
      else
      {
        prev=temp;
        temp= temp->next;
      }
    }
    return 0;
}


void Utility::display(struct node *r)
{
    r=head;
    if(r==NULL)
    {
      return;
    }
    while(r!=NULL)
    {
      int i = 0;
      while(r->data[i] != -1)
        printf("%d ",r->data[i++]);
      printf("\n");
      r=r->next;
    }
    printf("\n");
}


int  main()
{
    int i,num;
    struct node *n;
    head=NULL;
//    while(1)
//    {
      printf("\nList Operations\n");
      printf("===============\n");
      printf("1.Insert\n");
      printf("2.Display\n");
      printf("3.Size\n");
      printf("4.Delete\n");
      printf("5.Exit\n");
      printf("Enter your choice : ");

      int a[] = {1,2,3,4,5,-1};//array must be ended by -1 (for display function to work)
      int b[] = {11,12,13,14,15,-1};
      int c[] = {111,112,113,114,115,-1};

			      
      Utility* obj = new Utility();
      obj->insert(a);
      obj->insert(b);
      obj->insert(c);
      obj->insert(a);
      obj->display(n);
      obj->deleteNode(b);
      obj->display(n);
/*
      if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
      } else {
        switch(i)
        {
        case 1:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert(num);
                 break;
        case 2: if(head==NULL)
                {
                printf("List is Empty\n");
                }
                else
                {
                printf("Element(s) in the list are : ");
                }
                display(n);
                break;
        case 3: printf("Size of the list is %d\n",count());
                break;
        case 4: if(head==NULL)
                printf("List is Empty\n");
                else{
                printf("Enter the number to delete : ");
                scanf("%d",&num);
                if(deleteNode(num))
                    printf("%d deleted successfully\n",num);
                else
                    printf("%d not found in the list\n",num);
                }
                break;
        case 5: return 0;
        default:printf("Invalid option\n");
        }
      }
*/

//    }
    return 0;
}


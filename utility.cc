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
  void append(int MR, int hopcount, int* data);
  void add(int MR, int hopcount, int* data);
  void addafter(int MR, int hopcount, int* data, int loc);
  int count();
  void insert(int MR, int hopcount, int* data);
  int deleteNode(int MR);
  void display(struct node* r);

//function for set (difference, intersection, union)


};
// node of a linked list
struct node
{
    int MR;//multicast router
    int hopcount;
    int* data;//data is destination list, which is an array of int.
    struct node *next;
}*head;

Utility::Utility(){

}

void Utility::append(int MR, int hopcount, int* data)
{
    struct node *temp,*right;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->MR = MR;
    temp->hopcount = hopcount;
    temp->data = data;
    right=(struct node *)head;
    while(right->next != NULL)
      right=right->next;
  
    right->next =temp;
    right=temp;
    right->next=NULL;
}



void Utility::add(int MR, int hopcount, int* data )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->MR = MR;
    temp->hopcount = hopcount;
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
void Utility::addafter(int MR, int hopcount, int* data, int loc)
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
    temp->MR = MR;
    temp->hopcount = hopcount;
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


void Utility::insert(int MR, int hopcount, int* data) //insert new node based on hopcount, node with larger hopcount has higher priority.
{
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
      add(MR, hopcount, data);
    }
    else
    {
      while(temp!=NULL)
      {
        if(temp->hopcount > hopcount)
          c++;
        temp=temp->next;
      }
    if(c==0)
        add(MR, hopcount, data);
    else if(c<count())
        addafter(MR, hopcount, data, ++c);
    else
        append(MR, hopcount, data);
    }
}



int Utility::deleteNode(int MR) //delete node based on MR (Multicast Router), because MR is the unique value (the key) for each Node in the linked list
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
      if(temp->MR==MR)
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
      printf("MR: %d, hopcount: %d, dest list:", r->MR, r->hopcount);
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
/*      printf("\nList Operations\n");
      printf("===============\n");
      printf("1.Insert\n");
      printf("2.Display\n");
      printf("3.Size\n");
      printf("4.Delete\n");
      printf("5.Exit\n");
      printf("Enter your choice : ");
*/
      int MR1 = 3;
      int hopcount1 = 3;
      int a[] = {1,2,3,4,5,-1};//array must be ended by -1.

      int MR2 = 4;
      int hopcount2 = 2;
      int b[] = {11,12,13,14,15,-1};

      int MR3 = 6;
      int hopcount3 = 4;
      int c[] = {111,112,113,114,115,-1};
			      
      Utility* obj = new Utility();
      obj->insert(MR1, hopcount1, a);
      obj->insert(MR2, hopcount2, b);
      obj->insert(MR3, hopcount3, c);
      obj->insert(MR1, hopcount1, a);
      obj->display(n);
      obj->deleteNode(4);
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


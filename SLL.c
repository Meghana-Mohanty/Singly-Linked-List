
/*Following is the code for singly linked list. The code:
1. creates nodes
2. Displays their content
3. searches for nodes
4. Inserts nodes
5. Deletes nodes
6. Deletes the list
7. Displays its data in reverse
8. Reverses the linked list
9. prints middle element if list*/

#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

//function declarations
void PostpendNode(struct node **fhead,struct node **flast, int d);
void PrependNode(struct node **fhead,struct node **flast,int d);
void Display(struct node **fhead);
int Search(struct node **fhead, int num);
void Delete(struct node **fhead,struct node **flast, int d);
void InsertNode(struct node **fhead,struct node **flast,int d, int num);
void PrintReverse(struct node **fhead);
void ReverseSLL(struct node **fhead, struct node **flast);
void DeleteList(struct node **fhead);
int Middle(struct node **fhead, struct node **flast);

int main(void)
{
    int choice = 0;
    int num = 0;
    int choice2 = 0;
    int current = 0;
    int pos = 0;
    int mid = 0;
    struct node *head = NULL;
    struct node *last = NULL;
    
    printf("\n\t-----------Singly Linked List----------");
    
    do
    {
        printf("\n\tEnter 1 to display all node data");
        printf("\n\tEnter 2 to add a node to the list");
        printf("\n\tEnter 3 to delete a node");
        printf("\n\tEnter 4 to search a node(returns position of node)");
        printf("\n\tEnter 5 to delete the whole list");
        printf("\n\tEnter 6 to print list in reverse");
        printf("\n\tEnter 7 to reverse the list");
	printf("\n\tEnter 8 to printf middle element of the list");
        printf("\n\tEnter 0 to Exit");
        printf("\n\tEnter your choice : ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 0:
            DeleteList(&head);
            //exit case
            break;
            
            case 1:
            Display(&head);//displaying data
            break;
            
            case 2:
            printf("\nEnter data to be added: ");
            scanf("%d", &num);//node data accepted
            //asking where node is to be inserted
            printf("\n\tEnter 1 if you want to add node at end");
            printf("\n\tEnter 2 if you want to add node in between");
            printf("\n\tEnter 3 if you want to add node at beginning");
            printf("\n\tEnter your choice : ");
            scanf("%d", &choice2);
            switch(choice2)
            {
                case 1:
                PostpendNode(&head,&last, num);
                break;
                
                case 2:
                printf("\nEnter number after which data to be added: ");
                scanf("%d", &current);//accepting where node is to be inserted
                pos = Search(&head, current);//checking if node exists
                if(pos == -1)
                {
                    //node doesnt exist
                    printf("\n\tData does not exist.");
                }
                else
                {
                    //node exists
                    InsertNode(&head, &last,num, current );
                }
                break;
                
                case 3:
                PrependNode(&head,&last, num);
                break;
                
                default:
                printf("\nInvalid choice.");
                break;
            }
            break;
            
            case 3:
            printf("\nEnter data to be deleted: ");
            scanf("%d", &num);
            pos = Search(&head, num);//checking if node exists
            if(pos == -1)
            {
                printf("\n\tData does not exist.");
            }
            else
            {
                Delete(&head, &last, num);
            }
            break;
            
            case 4:
            printf("\nEnter data to be searched: ");
            scanf("%d", &num);
            pos = Search(&head, num);//checking if node exists
            if(pos == -1)
            {
                printf("\n\tData does not exist.\n");
            }
            else
            {
                printf("\n\tData is at position %d", pos);
            }
            break;
            
            case 5:
            DeleteList(&head);//deletes entire list
            break;
            
            case 6:
            if(head == NULL)
            {
                printf("\n\tList does not exist.");
            }
            else
            {
                printf("\n\tList data in reverse is: ");
                PrintReverse(&head);
            }
            break;
            
            case 7:
            if(head == NULL)
            {
                printf("\n\tList does not exist.");
            }
            else
            {
                //head = ReverseSLL(head);
                ReverseSLL(&head, &last);
                Display(&head);
                printf("\n\tList reversed.\n");
            }
            break;
            
            case 8:
            mid = Middle(&head, &last);
            printf("\n\tMiddle element is: %d", mid);
            break;
            
            default:
            printf("\n\n!!!WRONG CHOICE!!!");
            break;
            
        }
    }while(choice != 0);
    return 0;
}

void Display(struct node **fhead)
{
    struct node *head = NULL;
    struct node *temp = NULL;
    
    head = *fhead;
    if(head == NULL)
    {
        printf("\n\tList is empty. Add data first.\n");
    }
    else
    {
        //printing node data
        printf("\n---Node Data---");
        temp = head;
        while(temp != NULL)
        {
            printf("\n\t%d", temp->data);
            temp = temp->next;
        }
    }
    
}

void PostpendNode(struct node **fhead,struct node **flast, int d)
{
    struct node *head = NULL;
    struct node *last = NULL;
    struct node *temp = NULL;
    struct node *newnode = NULL;
    newnode = ( struct node*)calloc(1,sizeof(struct node));
    
    head = *fhead;
    last = *flast;
    if(newnode == NULL)
    {
        printf("\n\tSorry could not allocate memory.\n");
    }
    else
    {
        newnode->data = d;
        if(head == NULL)
        {
            //list is empty, so node becomes head and last
            head = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;//append newnode to end of list
            last = newnode;
        }
        printf("\n\tNode added.\n");
    }
    
    *fhead = head;
    *flast = last;
}

void PrependNode(struct node **fhead,struct node **flast,int d)
{
    struct node *head = NULL;
    struct node *last = NULL;
    struct node *temp = NULL;
    struct node *newnode = NULL;
    
    newnode = ( struct node*)calloc(1,sizeof(struct node));
    head = *fhead;
    last = *flast;
    
    if(newnode == NULL)
    {
        printf("\n\tSorry could not allocate memory.\n");
    }
    else
    {
        newnode->data = d;
        if(head == NULL)
        {
            //list is empty, so node becomes head and last
            head = newnode;
            last = newnode;
        }
        else
        {
            //prepend node to before head, and make it the head
            newnode->next = head;
            head = newnode;
        }
        printf("\n\tNode added.\n");
        
    }
    
    *fhead = head;
    *flast = last;
}

void InsertNode(struct node **fhead,struct node **flast,int d, int num)
{
    int pos = 0;
    struct node *head = NULL;
    struct node *last = NULL;
    struct node *temp = NULL;
    struct node *newnode = NULL;
    
    newnode = ( struct node*)calloc(1,sizeof(struct node));
    head = *fhead;
    last = *flast;
    
    if(newnode == NULL)
    {
        printf("\n\tSorry could not allocate memory.\n");
    }
    else
    {
        newnode->data = d;
        if(head == NULL)
        {
            printf("\n\tList is empty. Node becomes firstnode.\n");
            head = newnode;
            last = newnode;
        }
        else
        {
            temp = head;
            while(temp != NULL)
            {
                if(temp->data == num)//checking for position where newnode is to be added
                {
                    newnode->next = temp->next;
                    temp->next = newnode;
                    printf("\nNode added.\n");
                    temp = NULL;
                }
                else
                {
                    //goto next node
                    temp = temp->next;
                }
                    
            }
            
        }
        
        
    }
    
    *fhead = head;
    *flast = last;
}

int Search(struct node **fhead, int num)
{
    int succ = -1;
    struct node *head = NULL;
    struct node *temp = NULL;
    head = *fhead;
    
    if(head == NULL)
    {
        printf("\n\tList is empty. Add data first.\n");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            if(temp->data == num)
            {
                //data found. succ +=2 because we start at -1.adding 2 will give 
                //us right position of node, counting from 1
                succ += 2;
                temp = NULL;
            }
            else
            {
                //goto next node
                temp = temp->next;
                succ ++;
            }
            
        }
        
    }
    
    *fhead = head;
    return succ;
}

void Delete(struct node **fhead,struct node **flast, int d)
{
    int pos = -1;
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *dnode = NULL;
    head = *fhead;
    if(head == NULL)
    {
        printf("\n\tList is empty. Add data first.\n");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            //from search function, return pointer to node before the 
            //node to be deleted. if 1->4->7->10, and 7 is to be deelted,
            //return pointer to 4 . reduces time complexity.
            if(temp->next->data == d)
            {
                //if next node to be deleted, then link present node 
                //to next to next node.
                temp->next = temp->next->next;
                dnode = temp->next;
                free(dnode);
                dnode = NULL;
                temp = NULL;
            }
            else
            {
                //goto next node
                temp = temp->next;
            }
        }    
        
        
    }
    *fhead = head;
}

void PrintReverse(struct node **fhead)
{
    struct node *head = NULL;
    head = *fhead;
    if(head == NULL)
    {
        printf("\n");
    }
	else
	{
	    //recursive call
		PrintReverse(&head->next);
        printf("\n\t%d", head->data);
    }
    
}

void DeleteList(struct node **fhead)
{
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *dnode = NULL;
    head = *fhead;
    
    if(head == NULL)
    {
        printf("\n\tList is empty.\n");
    }
    else
    {
        temp = head;
        while(temp !=  NULL)
        {
            //taking each node, freeing it
            dnode = temp;
            free(dnode);
            dnode = NULL;
        }
        printf("\n\tList deleted.\n");
    }
}



void ReverseSLL(struct node **fhead, struct node **flast)
{
    struct node *dnode = NULL;
    struct node *head = NULL;
    struct node *last = NULL;
    struct node *head2 = NULL;
    struct node *last2 = NULL;
    
    head = *fhead;
    last = *flast;
    while(head != NULL)
    {
        dnode = head;
        head = head->next;
        dnode->next = NULL;
        if(head2 == NULL)
        {
            head2 = dnode;
            last2 = dnode;
        }
        else
        {
            dnode->next = head2;
            head2 = dnode;
        }
    }
    head = head2;
    last = last2;
    
    *fhead = head;
    *flast = last;

    
}

int Middle(struct node **fhead, struct node **flast)
{
    int mid = 0;
    struct node *head = NULL;
    struct node *last = NULL;
    struct node *temp1 = NULL;//fast pointer(moves up 2 nodes at 1 time)
    struct node *temp2 = NULL;//slow pointer
    head = *fhead;
    last = *flast;
    
    temp1 = temp2 = head;
    while(temp1 != NULL && temp1->next != NULL)
    {
        temp1 = temp1->next->next;
        temp2 = temp2->next;
    }
    
    mid = temp2->data;
    *flast = last;
    *fhead = head;
    return mid;
}
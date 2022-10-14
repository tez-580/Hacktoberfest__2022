#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void addnew(struct node **head, int val)
{   
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;  
    if(*head == NULL)
        *head = newNode;    
    else
    {
        struct node *lastNode = *head;        
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }        
        lastNode->next = newNode;
    }
}

void printlinkedlist(struct node *head)
{
    struct node *temp = head;   
    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    int n;
    scanf("%d", &n);
    for(int i=1; i<n+1; i++)
    {
        int x;
        scanf("%d", &x);
        addnew(&head, x);
    }

    struct node *ptr;  
    int element,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Empty list\n");  
    }  
    else  
    {   
        printf("\nEnter an element which you want to search?\n");   
        scanf("%d", &element);  
        while(ptr!=NULL)  
        {  
            if(ptr->data == element)  
            {  
                printf("Element %d is found at index %d \n ",element,i);  
                flag=0;  
                break;
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("-1\n");  //returns -1 if the element is not present in the list
        }  
    }  
    
    //printlinkedlist(head);

    return 0;
}

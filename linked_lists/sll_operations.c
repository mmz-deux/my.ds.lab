#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

// insert at the beginning position
void insert_begin()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("enter the value for a new node\n");
    scanf("%d",&newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        return;
    }

    else
    {
        newnode->next = head;
        head = newnode;
    }
}

// insert at the ending position
void insert_end()
{
    struct node *newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("enter the value for a new node\n");
    scanf("%d",&newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        return;
    }

    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = NULL;
        temp = temp->next;
    }
}

// length of the list
int length ()
{
    int count = 0;
    
    if(head == NULL)
    {
        return 0;
    }

    else
    {
        struct node *temp;
        temp = head;

        while(temp!=NULL)
        {
            count ++;
            temp = temp->next;
        }

        return count;
    }
}

// insert at a specific position
void insert_specific()
{
    int count = length ();
    int pos,i=1;

   printf("enter the position where the node is to be inserted\n");
   scanf("%d",&pos);

   if(pos > count + 1|| pos < 1)
   {
    printf("invalid position\n");
    return;
   }

   if(pos == 1)
   {
    insert_begin();
    return;
   }

   else
   {
     struct node *newnode,*temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("enter the value for a new node\n");
    scanf("%d",&newnode->data);

    temp = head;
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    temp = temp->next;
   }
}

// delete at the beginning
void delete_begin()
{
    if(head == NULL)
    {
        printf("deletion is not possible\n");
        return;
    }

    else
    {
        struct node *temp;
        temp = head;
        head = temp->next;
        printf("the deleted node is %d\n",temp->data);
        free(temp);
    }
}

// delete at the ending
void delete_end()
{
    if(head == NULL)
    {
        printf("deletion is not possible\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("the deleted node is %d\n",head->data);
        free (head);
        head = NULL;
    }

    else
    {
        struct node *temp, *xyz;
        temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        xyz = temp->next;
        temp->next = NULL;
        printf("the deleted node is %d\n",xyz->data);
        free(xyz);
    }
}

// delete at a certain location
void delete_specific()
{
    int count = length();
    int pos,i=1;

   printf("enter the position where the node is to be deleted\n");
   scanf("%d",&pos);

   if(pos > count || pos < 1)
   {
    printf("invalid position\n");
    return;
   }

   if(pos == 1)
   {
    delete_begin();
    return;
   }

   else
   {
    struct node *xyz, *temp;
    temp = head;
    while (i < pos -1)
    {
        temp = temp->next;
        i++;
    }

    xyz = temp->next;
    temp->next = xyz->next;
    printf("the deleted node is %d\n",xyz->data);
    free(xyz);
   }
}

// searching a particular node
void search ()
{
    int key, flag = 0, pos = 1;
    printf("enter the key element to be searched\n");
    scanf("%d",&key);

    struct node *temp;
    temp = head;

    while(temp!=NULL)
    {
        if(key == temp->data)
        {
            flag ++;
            break;
        }

        temp = temp->next;
        pos ++;
    }

    if(flag == 1)
     {
        printf("the search element %d has been found at location %d",key,pos);
        return;
     }

    if(flag == 0)
    {
        printf("the key node has not been found\n");
        return;
    }
}

//displaying the list
void display()
{
    if(head == NULL)
    {
        printf("the list is empty\n");
        return;
    }

    else
    {
        struct node *temp;
        temp = head;
        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
    }
}

// reversing the list
void reverse ()
{
    struct node *pre,*curr,*succ;
    pre = NULL;
    curr = succ = head;

    while(succ!=NULL)
    {
        succ = succ->next;
        curr->next = pre;
        pre = curr;
        curr = succ;
    }

    head = pre;
    printf("the reversed list is\n");
    display();
}

int main()
{
    int choice;
    do
    {
        printf("\n");
        printf("\n--- SINGLE LINKED LIST MENU---\n");
        printf("1.Insert at the beginning\n");
        printf("2.Insert at the end position\n");
        printf("3.Length of the list\n");
        printf("4.Insert a particular position\n");
        printf("5.Delete at the beginning\n");
        printf("6.Delete at the ending \n");
        printf("7.Delete a specific a position\n");
        printf("8.Searching a node\n");
        printf("9.Display the list\n");
        printf("10.Reversing the list\n");
        printf("11.exiting the program\n");
        printf("\n");

        printf("enter choice:  \n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insert_begin();
            break;

            case 2: insert_end();
            break;

            case 3: printf("the length of the list %d\n",length());
            break;

            case 4: insert_specific();
            break;

            case 5: delete_begin();
            break;

            case 6: delete_end();
            break;

            case 7: delete_specific();
            break;

            case 8: search();
            break;

            case 9: display();
            break;

            case 10: reverse();
            break;

            case 11: exit(0);
            break;
        }

    } while (choice !=11);

}

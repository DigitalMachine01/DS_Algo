#include<stdio.h>
#include<stdlib.h>

/* pointers: mughe access kaunsa variable karna hai? uss variable ko mai uske address se access karunga. Node access karna hai toh node ka address, node ke pointer par 
operate karna hai toh uska adress. Just a little twist here is uss address ko mai hawa mai nahi rakh sakta. use kahin store karna hoga. To store that address we create 
address storing variables called as pointers. Now adress toh sab 4byte ke hi hote hain, but pointers can point to different data types. So we declare the type of the data
type to which the pointer points to. This tells the compiler to access those many bytes. Remember that a pointer is a adress of some location / variable*/

typedef struct node_t
{
    char name;
    struct node_t* next;
}node;

void add_nodes(node**);

void print(node*);

void reverse(node**);

int main()
{
    node* head_ptr = 0;
    printf("Welcome to the linked list\n\nPlease add nodes..\n");
    add_nodes(&head_ptr);
    printf("\nYour linked List is:\t");
    print(head_ptr); //print the linked list
    printf("\n");
    reverse(&head_ptr);
    printf("\nReverse linked List is:\t");
    print(head_ptr); //print the linked list
    printf("\n");
}

void add_nodes(node** headPointer_ptr)
{
    node* temp;
    node* previous_temp;

    char response = 'y';

    do 
    {
        temp = malloc(sizeof(node));

        printf("Node Name: ");
        scanf(" %c",&temp->name); //leading space with %c to skip the white spaces

        // /* logic to put the node at the begninning of the linked list */
        // temp->next = *headPointer_ptr; 
        // *headPointer_ptr = temp;

        /*  logic to put the node at the end */

        if(*headPointer_ptr == 0)
        {
            temp->next = 0; 
            *headPointer_ptr = temp;
        }
        else
        {
            previous_temp->next = temp;
            temp->next = 0;
        }

        previous_temp = temp;

        printf("Want to add node? (y/n)");
        scanf(" %c",&response); //skip the white space left in bufffer with a leading space with %c
    }while(response == 'y' || response == 'Y');
}

void print(node* h_ptr)
{
    while(h_ptr)
    {
        printf("%c\t",h_ptr->name);
        h_ptr = h_ptr->next;
    }
}

void reverse(node** headPointer_ptr)
{
    node *nextNode, *previousNode, *currentNode; //When declaring multiple pointers, put the astrik with the variable. otherwise put it with the type.

    //Initial Case

    previousNode = *headPointer_ptr;
    nextNode = (*headPointer_ptr)->next;
    (*headPointer_ptr)->next = 0;
    *headPointer_ptr = nextNode;

    //The repetitive Case

    while((*headPointer_ptr)->next != 0)
    {
        currentNode = nextNode;
        nextNode = (*headPointer_ptr)->next;
        (*headPointer_ptr)->next = previousNode;
        *headPointer_ptr = nextNode;
        previousNode = currentNode;
    }

    //Last Case

    (*headPointer_ptr)->next = previousNode;
}
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

int main()
{
    node* head_ptr = 0;
    printf("Welcome to the linked list\n\nPlease add nodes..\n");
    add_nodes(&head_ptr);
    print(head_ptr); //print the linked list
}

void add_begin(node** headPointer_ptr)
{
    node* temp;

    char response = 'y';

    do 
    {
        temp = malloc(sizeof(node));

        printf("Node Name: ");
        scanf("%s",temp->name);

        /* logic to put the node at the begninning of the linked list */
        temp->next = *headPointer_ptr; 
        *headPointer_ptr = temp;

        printf("Want to add node? (y/n)");
        scanf("%c",&response);
    }while(response == 'y' || response == 'Y');
}

void print(node* h_ptr)
{
    while(h_ptr)
    {
        printf("%s\t",h_ptr->name);
        h_ptr = h_ptr->next;
    }
}
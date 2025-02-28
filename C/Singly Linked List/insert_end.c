#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert_end(struct node *head, int data)
{
    // New node will store address of the new node
    struct node* new_node=new_node(data);
    
    // Set the next pointer of the new node to the current head
    new_node->next=head;

    // Move the head to point to the new node
    head=new_node;

    return head; // returning head as it cn later be used
}
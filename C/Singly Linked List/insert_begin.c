// Program to insert a new node at the beginning
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *new_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    (*temp).next = NULL; // Both the statements mean the same thing

    return temp;
}

struct node *insert_begin(struct node *head, int data)
{
    // New node will store address of the new node
    struct node* new_node=new_node(data);
    
    // Set the next pointer of the new node to the current head
    new_node->next=head;

    // Move the head to point to the new node
    head=new_node;

    return head; // returning head as it cn later be used
}
// Program to create a new node in a singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *new_node(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    (*temp).next=NULL;  // Both the statements mean the same thing
}
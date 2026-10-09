#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *newnode, *temp;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf

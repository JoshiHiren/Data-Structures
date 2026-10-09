#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
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
    scanf("%d", &value);

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted successfully.\n");
}

void delete()
{
    struct node *temp;
    int value;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    if (temp->prev == NULL)
        head = temp->next;
    else
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node deleted successfully.\n");
}

void modify()
{
    struct node *temp;
    int oldvalue, newvalue;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter value to modify: ");
    scanf("%d", &oldvalue);

    temp = head;

    while (temp != NULL && temp->data != oldvalue)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &newvalue);

    temp->data = newvalue;

    printf("Node modified successfully.\n");
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List (Forward): ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                modify();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

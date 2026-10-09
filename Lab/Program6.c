#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue Overflow!\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &value);

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    queue[rear] = value;

    printf("Element inserted successfully.\n");
}

void delete()
{
    if (front == -1)
    {
        printf("Circular Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void modify()
{
    int position, value, index;
    int count;

    if (front == -1)
    {
        printf("Circular Queue is empty!\n");
        return;
    }

    count = (rear - front + MAX) % MAX + 1;

    printf("Enter position from front (1 to %d): ", count);
    scanf("%d", &position);

    if (position < 1 || position > count)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    index = (front + position - 1) % MAX;
    queue[index] = value;

    printf("Element modified successfully.\n");
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is empty!\n");
        return;
    }

    printf("Circular Queue elements: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Circular Queue Operations ---\n");
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

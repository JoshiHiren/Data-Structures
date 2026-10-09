#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insert()
{
    int value, choice;

    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque Overflow!\n");
        return;
    }

    printf("1. Insert at Front\n");
    printf("2. Insert at Rear\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (choice == 1)
    {
        front = (front - 1 + MAX) % MAX;
    }
    else if (choice == 2)
    {
        rear = (rear + 1) % MAX;
    }
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    deque[(choice == 1) ? front : rear] = value;

    printf("Element inserted successfully.\n");
}

void delete()
{
    int choice;

    if (front == -1)
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("1. Delete from Front\n");
    printf("2. Delete from Rear\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2)
    {
        printf("Invalid choice!\n");
        return;
    }

    if (choice == 1)
    {
        printf("Deleted element: %d\n", deque[front]);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
    else
    {
        printf("Deleted element: %d\n", deque[rear]);

        if (front == rear)
            front = rear = -1;
        else
            rear = (rear - 1 + MAX) % MAX;
    }
}

void modify()
{
    int position, value, index, count;

    if (front == -1)
    {
        printf("Deque is empty!\n");
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
    deque[index] = value;

    printf("Element modified successfully.\n");
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements (Front to Rear):\n");

    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

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
        printf("\n--- Double Queue Operations ---\n");
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


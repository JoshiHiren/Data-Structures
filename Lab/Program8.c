#include <stdio.h>
#define MAX 5

int queue[MAX];
int priority[MAX];
int size = 0;

void insert()
{
    int value, p, i;

    if (size == MAX)
    {
        printf("Priority Queue Overflow!\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    printf("Enter priority (1 = highest): ");
    scanf("%d", &p);

    i = size - 1;

    while (i >= 0 && priority[i] > p)
    {
        queue[i + 1] = queue[i];
        priority[i + 1] = priority[i];
        i--;
    }

    queue[i + 1] = value;
    priority[i + 1] = p;
    size++;

    printf("Element inserted successfully.\n");
}

void delete()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[0]);
    printf("Priority: %d\n", priority[0]);

    for (i = 0; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}

void modify()
{
    int position, value, p, i;

    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Enter position to modify: ");
    scanf("%d", &position);

    if (position < 1 || position > size)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter new element: ");
    scanf("%d", &value);

    printf("Enter new priority: ");
    scanf("%d", &p);

    position--;

    for (i = position; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;

    i = size - 1;

    while (i >= 0 && priority[i] > p)
    {
        queue[i + 1] = queue[i];
        priority[i + 1] = priority[i];
        i--;
    }

    queue[i + 1] = value;
    priority[i + 1] = p;
    size++;

    printf("Element modified successfully.\n");
}

void display()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("\nElement\tPriority\n");

    for (i = 0; i < size; i++)
    {
        printf("%d\t%d\n", queue[i], priority[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Priority Queue Operations ---\n");
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
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int process;

    if (rear == MAX - 1)
    {
        printf("Process Queue is Full!\n");
    }
    else
    {
        printf("Enter Process ID: ");
        scanf("%d", &process);

        if (front == -1)
            front = 0;

        queue[++rear] = process;

        printf("Process inserted successfully.\n");
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Process Queue is Empty!\n");
    }
    else
    {
        printf("Executing Process ID: %d\n",
               queue[front]);

        front++;

        if (front > rear)
            front = rear = -1;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Process Queue is Empty!\n");
    }
    else
    {
        printf("Processes waiting for execution:\n");

        for (i = front; i <= rear; i++)
            printf("P%d\n", queue[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Process Queue ---\n");
        printf("1. Insert Process\n");
        printf("2. Execute Process\n");
        printf("3. Display Processes\n");
        printf("4. Exit\n");
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
                display();
                break;

            case 4:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}

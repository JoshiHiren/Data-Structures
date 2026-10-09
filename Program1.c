#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Element pushed successfully.\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void peep()
{
    int position;

    printf("Enter position from top: ");
    scanf("%d", &position);

    if (position < 1 || position > top + 1)
    {
        printf("Invalid position!\n");
    }
    else
    {
        printf("Element at position %d: %d\n",
               position, stack[top - position + 1]);
    }
}

void modify()
{
    int position, value;

    printf("Enter position from top to modify: ");
    scanf("%d", &position);

    if (position < 1 || position > top + 1)
    {
        printf("Invalid position!\n");
    }
    else
    {
        printf("Enter new value: ");
        scanf("%d", &value);
        stack[top - position + 1] = value;
        printf("Element modified successfully.\n");
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements (Top to Bottom):\n");

        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Modify\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peep();
                break;

            case 4:
                modify();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

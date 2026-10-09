#include <stdio.h>
#define MAX 10

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push()
{
    int choice, value;

    if (top1 + 1 == top2)
    {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Push into which stack? (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        stack[++top1] = value;
        printf("Element pushed into Stack 1.\n");
    }
    else if (choice == 2)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        stack[--top2] = value;
        printf("Element pushed into Stack 2.\n");
    }
    else
    {
        printf("Invalid stack choice!\n");
    }
}

void pop()
{
    int choice;

    printf("Pop from which stack? (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        if (top1 == -1)
            printf("Stack 1 Underflow!\n");
        else
            printf("Popped element: %d\n", stack[top1--]);
    }
    else if (choice == 2)
    {
        if (top2 == MAX)
            printf("Stack 2 Underflow!\n");
        else
            printf("Popped element: %d\n", stack[top2++]);
    }
    else
    {
        printf("Invalid stack choice!\n");
    }
}

void peep()
{
    int choice, position;

    printf("Select stack (1 or 2): ");
    scanf("%d", &choice);
    printf("Enter position from top: ");
    scanf("%d", &position);

    if (choice == 1)
    {
        if (position < 1 || position > top1 + 1)
            printf("Invalid position!\n");
        else
            printf("Element: %d\n",
                   stack[top1 - position + 1]);
    }
    else if (choice == 2)
    {
        if (position < 1 || position > MAX - top2)
            printf("Invalid position!\n");
        else
            printf("Element: %d\n",
                   stack[top2 + position - 1]);
    }
    else
    {
        printf("Invalid stack choice!\n");
    }
}

void modify()
{
    int choice, position, value;

    printf("Select stack (1 or 2): ");
    scanf("%d", &choice);
    printf("Enter position from top: ");
    scanf("%d", &position);

    if (choice == 1)
    {
        if (position < 1 || position > top1 + 1)
        {
            printf("Invalid position!\n");
            return;
        }

        printf("Enter new value: ");
        scanf("%d", &value);
        stack[top1 - position + 1] = value;
    }
    else if (choice == 2)
    {
        if (position < 1 || position > MAX - top2)
        {
            printf("Invalid position!\n");
            return;
        }

        printf("Enter new value: ");
        scanf("%d", &value);
        stack[top2 + position - 1] = value;
    }
    else
    {
        printf("Invalid stack choice!\n");
        return;
    }

    printf("Element modified successfully.\n");
}

void display()
{
    int i;

    printf("Stack 1 (Top to Bottom):\n");
    if (top1 == -1)
        printf("Stack 1 is empty.\n");
    else
        for (i = top1; i >= 0; i--)
            printf("%d\n", stack[i]);

    printf("Stack 2 (Top to Bottom):\n");
    if (top2 == MAX)
        printf("Stack 2 is empty.\n");
    else
        for (i = top2; i < MAX; i++)
            printf("%d\n", stack[i]);
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Double Stack Operations ---\n");
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
            case 1: push();   break;
            case 2: pop();    break;
            case 3: peep();   break;
            case 4: modify(); break;
            case 5: display(); break;
            case 6: printf("Program terminated.\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}

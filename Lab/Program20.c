
#include <stdio.h>
#include <stdlib.h>

struct node {
    int row, col, data;
    struct node *right, *down;
};

struct node *head = NULL;

void create() {
    struct node *p, *temp;
    int m, n, i, j, x;

    printf("Enter rows and columns: ");
    scanf("%d%d", &m, &n);

    head = NULL;
    temp = NULL;

    printf("Enter matrix elements:\n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &x);

            if (x != 0) {
                p = (struct node *)malloc(sizeof(struct node));

                p->row = i;
                p->col = j;
                p->data = x;
                p->right = NULL;
                p->down = NULL;

                if (head == NULL)
                    head = p;
                else
                    temp->right = p;

                temp = p;
            }
        }
    }
    printf("Matrix created successfully!\n");
}

void display() {
    struct node *p = head;

    if (head == NULL) {
        printf("Matrix is empty!\n");
        return;
    }

    printf("Row  Column  Value\n");

    while (p != NULL) {
        printf("%d      %d       %d\n",
               p->row, p->col, p->data);
        p = p->right;
    }
}

int main() {
    int ch;

    do {
        printf("\n1. Create\n2. Display\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 3);

    return 0;
}

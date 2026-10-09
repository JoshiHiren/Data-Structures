```c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *root, int value)
{
    struct node *newnode, *parent, *current;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL)
        return newnode;

    parent = NULL;
    current = root;

    while (current != NULL)
    {
        parent = current;

        if (value < current->data)
            current = current->left;
        else if (value > current->data)
            current = current->right;
        else
        {
            printf("Duplicate value not allowed.\n");
            free(newnode);
            return root;
        }
    }

    if (value < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    return root;
}

void display(struct node *root)
{
    struct node *stack[100];
    int top = -1;
    struct node *current = root;

    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    printf("Inorder Display: ");

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }

    printf("\n");
}

struct node* deleteNode(struct node *root, int key)
{
    struct node *parent = NULL;
    struct node *current = root;
    struct node *child;
    struct node *successor;
    struct node *successorParent;
    struct node *temp;

    /* Find the node to delete */
    while (current != NULL && current->data != key)
    {
        parent = current;

        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL)
    {
        printf("Node not found.\n");
        return root;
    }

    /* If node has two children */
    if (current->left != NULL && current->right != NULL)
    {
        successorParent = current;
        successor = current->right;

        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }

        current->data = successor->data;
        parent = successorParent;
        current = successor;
    }

    /* Node has zero or one child */
    if (current->left != NULL)
        child = current->left;
    else
        child = current->right;

    if (parent == NULL)
        root = child;
    else if (parent->left == current)
        parent->left = child;
    else
        parent->right = child;

    free(current);

    printf("Node deleted successfully.\n");
    return root;
}

int main()
{
    struct node *root = NULL;
    int choice, value;

    do
    {
        printf("\n--- Binary Search Tree Menu ---");
        printf("\n1. Iterative Insert");
        printf("\n2. Iterative Display");
        printf("\n3. Delete Node");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                display(root);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

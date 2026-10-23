
#include <stdio.h>

int main() {
    int block[20], process[20], alloc[20];
    int nb, np, i, j, best, ch;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");
    for (i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    for (i = 0; i < nb; i++)
        alloc[i] = -1;

    do {
        printf("\n1. Allocation");
        printf("\n2. Deallocate");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter number of processes: ");
            scanf("%d", &np);

            printf("Enter process sizes:\n");
            for (i = 0; i < np; i++) {
                scanf("%d", &process[i]);
                best = -1;

                for (j = 0; j < nb; j++) {
                    if (block[j] >= process[i] &&
                        (best == -1 || block[j] < block[best]))
                        best = j;
                }

                if (best != -1) {
                    alloc[best] = process[i];
                    printf("Process %d allocated to block %d\n",
                           i + 1, best + 1);
                    block[best] = -1;
                } else {
                    printf("Process %d not allocated\n", i + 1);
                }
            }
            break;

        case 2:
            printf("Enter block number to deallocate: ");
            scanf("%d", &i);

            if (i >= 1 && i <= nb && alloc[i - 1] != -1) {
                block[i - 1] += alloc[i - 1];
                alloc[i - 1] = -1;
                printf("Block deallocated successfully\n");
            } else {
                printf("Block is not allocated or invalid\n");
            }
            break;

        case 3:
            printf("\nBlock\tRemaining Size\tStatus\n");
            for (i = 0; i < nb; i++) {
                printf("%d\t%d\t\t%s\n", i + 1,
                       block[i] == -1 ? 0 : block[i],
                       alloc[i] != -1 ? "Allocated" : "Free");
            }
            break;

        case 4:
            printf("Exit\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}

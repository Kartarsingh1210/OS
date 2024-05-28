#include <stdio.h>
#include <stdbool.h>

int main() {
    int np, nr;
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the number of resources: ");
    scanf("%d", &nr);

    int alloc[10][10], request[10][10], avail[10], r[10];
    bool executed[20] = {false};
    int executionOrder[20], executedCount = 0;

    for (int i = 0; i < nr; i++) {
        printf("Enter the total amount of Resource R%d: ", i + 1);
        scanf("%d", &r[i]);
    }

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < np; i++)
        for (int j = 0; j < nr; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the request matrix:\n");
    for (int i = 0; i < np; i++)
        for (int j = 0; j < nr; j++)
            scanf("%d", &request[i][j]);

    for (int j = 0; j < nr; j++) {
        avail[j] = r[j];
        for (int i = 0; i < np; i++) {
            avail[j] -= alloc[i][j];
        }
    }

    int w[10];
    for (int j = 0; j < nr; j++) {
        w[j] = avail[j];
    }

    bool deadlockDetected = false;

    while (executedCount < np) {
        bool progressMade = false;
        for (int i = 0; i < np; i++) {
            if (!executed[i]) {
                bool canBeProcessed = true;
                for (int j = 0; j < nr; j++) {
                    if (request[i][j] > w[j]) {
                        canBeProcessed = false;
                        break;
                    }
                }

                if (canBeProcessed) {
                    executed[i] = true;
                    executionOrder[executedCount++] = i;
                    progressMade = true;
                    for (int j = 0; j < nr; j++) {
                        w[j] += alloc[i][j];
                    }
                }
            }
        }

        if (!progressMade) {
            deadlockDetected = true;
            break;
        }
    }

    if (deadlockDetected) {
        printf("Deadlock detected among the following processes:\n");
        for (int i = 0; i < np; i++) {
            if (!executed[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("No deadlock detected\n");
        printf("Processes executed in the following order:\n");
        for (int i = 0; i < executedCount; i++) {
            printf("P%d ", executionOrder[i]);
        }
        printf("\n");
    }

    return 0;
}

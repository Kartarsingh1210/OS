#include <stdio.h>

void FIFO(int pages[], int n, int capacity) {
    int frame[capacity], pageFaults = 0, index = 0, pageMiss=0;
    for (int i = 0; i < capacity; i++) frame[i] = -1;

    printf("FIFO Page Replacement:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                pageMiss++;
                break;
            }
        }
        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % capacity;
            pageFaults++;
        }
        for (int j = 0; j < capacity; j++) {
            if (frame[j] != -1) printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
    printf("Total Page Miss: %d\n", pageMiss);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;

    FIFO(pages, n, capacity);

    return 0;
}

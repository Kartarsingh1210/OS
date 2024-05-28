#include <stdio.h>
#include <stdlib.h>

void CSCAN(int requests[], int n, int head,int direction, int diskSize) {
    int totalMovement = 0;
    int tempRequests[n + 2];
    int index = 0;

    for (int i = 0; i < n; i++) tempRequests[i] = requests[i];
    tempRequests[n] = 0; // add start
    tempRequests[n + 1] = diskSize - 1; // add end

    n += 2;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tempRequests[j] > tempRequests[j + 1]) {
                int temp = tempRequests[j];
                tempRequests[j] = tempRequests[j + 1];
                tempRequests[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (tempRequests[i] > head) {
            index = i;
            break;
        }
    }

    printf("C-SCAN Disk Scheduling:\n");
    printf("Order of servicing requests: ");
    if(direction==1){
    for (int i = index; i < n; i++) {
        printf("%d ", tempRequests[i]);
        totalMovement += abs(tempRequests[i] - head);
        head = tempRequests[i];
    }
    for (int i = 0; i < index; i++) {
        printf("%d ", tempRequests[i]);
        totalMovement += abs(tempRequests[i] - head);
        head = tempRequests[i];
    }
    }
    else{
        for (int i = index-1; i >=0; i--) {
        printf("%d ", tempRequests[i]);
        totalMovement += abs(tempRequests[i] - head);
        head = tempRequests[i];
    }
    for (int i = n-1; i >= index; i--) {
        printf("%d ", tempRequests[i]);
        totalMovement += abs(tempRequests[i] - head);
        head = tempRequests[i];
    }
    }
    

    printf("\nTotal head movement: %d\n", totalMovement);
}

int main() {
    int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 53;
    int diskSize = 200;
    int direction=0;

    CSCAN(requests, n, head,direction, diskSize);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

void SCAN(int request[],int n, int head, int direction,int diskSize){
    int total_seek_time=0;
    int index=0;
    int tempRequest[n+2];

    for(int i=0;i<n;i++) tempRequest[i]=request[i];

    tempRequest[n]=0;
    tempRequest[n+1]=diskSize-1;

    n+=2;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(tempRequest[j]>tempRequest[j+1]){
                int temp=tempRequest[j];
                tempRequest[j]=tempRequest[j+1];
                tempRequest[j+1]=temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(tempRequest[i]>head){
            index=i;
            break;
        }
    }

    printf("SCAN Algorithm");
    printf("Order of Servicing Requests: \n");

    if(direction==1){
        for(int i=index;i<n;i++){
            printf("%d ",tempRequest[i]);
            total_seek_time+=abs(tempRequest[i]-head);
            head=tempRequest[i];
        }
        for(int i=index-1;i>0;i--){
            printf("%d ",tempRequest[i]);
            total_seek_time+=abs(tempRequest[i]-head);
            head=tempRequest[i];
        }
    }
    else{
            for(int i=index-1;i>=0;i--){
            printf("%d ",tempRequest[i]);
            total_seek_time+=abs(tempRequest[i]-head);
            head=tempRequest[i];
        }
        for(int i=index;i<n-1;i++){
            printf("%d ",tempRequest[i]);
            total_seek_time+=abs(tempRequest[i]-head);
            head=tempRequest[i];
        }
    }
    printf("\n Total Seek Time : %d",total_seek_time);
}

int main(){
     int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 53;
    int direction = 1; // 1 for high, 0 for low
    int diskSize = 200;

    SCAN(requests, n, head, direction, diskSize);

    return 0;
}
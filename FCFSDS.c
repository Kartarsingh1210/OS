#include<stdio.h>

void FCFS(int request[],int n, int head){
    int total_seektime=0;
    int i;
    printf("FCFS Scheduling Algo\n");
    printf("Order of Executing\n");

    for(i=0;i<n;i++){
        printf("%d ", request[i]);
      
        total_seektime+= abs(request[i]-head);
        head=request[i];

    }
    printf("\n");
    printf("\nTotal Seek Time is: %d",total_seektime);
}

int main(){
    int request[]={98,183,37,122,14,124,65,67};
    int n=sizeof(request)/sizeof(request[0]);

    int head=53;

    FCFS(request,n,head);

    return 0;
}
#include <stdio.h>

void SSTF(int request[],int n,int head){
    int total_seektime=0, minDist,minIndex,completed=0,i;
    int visited[n];

    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    printf("SSTF Scheduling Algo\n");
    printf("Order of Executing: \n");

    while(completed<n){
        minDist=9999;

        for(i=0;i<n;i++){

        if(!visited[i] && abs(request[i]-head)< minDist){
           minDist=abs(request[i]-head);
           minIndex=i;
        }
    }
      visited[minIndex]=1;
      total_seektime+=minDist;
      head=request[minIndex];
      printf("%d ",head);
      completed++;

    }

    printf("\n Total Seek Time: %d\n",total_seektime);

}

int main(){
    int request[]={98,183,37,122,14,124,65,67};
    int n=sizeof(request)/sizeof(request[0]);

    int head=53;

   SSTF(request,n,head);

    return 0;
}
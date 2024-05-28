

#include<stdio.h>

int findLRU(int time[],int capacity){
    int min=time[0],i,pos=0;

    for(i=0;i<capacity;i++){
        if(time[i]<min){
            min=time[i];
            pos=i;
        }
    }
    return pos;
}

void LRU(int page[],int n,int capacity){
    int frame[capacity], time[capacity],counter=0,PageFault=0,PageMiss=0;

    for(int i=0;i<capacity;i++){
        frame[i]=-1;
        time[i]=0;
    }

    printf("LRU Page Replacement Algo:\n");

    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<capacity;j++){
            if(frame[j]==page[i]){
            found=1;
            PageMiss++;
            counter++;
            time[j]=counter;
            break;
        }
    }

    if(!found){
        int pos=findLRU(time,capacity);
        frame[pos]=page[i];
        counter++;
        time[pos]=counter;
        PageFault++;
    }

    for(int j=0;j<capacity;j++){
      if(frame[j]!=-1){
        printf("%d ",frame[j]);
      }
    }
    printf("\n");
    }
  printf("Total no. of PageFault: %d\n",PageFault);
   printf("Total no. of PageMiss: %d",PageMiss);
}

int main(){
    int page[]={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n=sizeof(page)/sizeof(page[0]);
    int capacity=4;
    LRU(page,n,capacity);
    return 0;
}


#include<stdio.h>

int findOptimal(int page[],int n,int frame[],int capacity,int index){
    int pos=-1,farthest=index;

    for(int i=0;i<capacity;i++){
        int j;
        for(j=index;j<n;j++){
          if(frame[j]==page[i]){
            if(j>farthest){
                farthest=j;
                pos=i;
            }
                break;
        }
    }
    if(j==n) return i;
}
    return (pos==-1) ? 0:pos;
          
        
}

void Optimal(int page[],int n,int capacity){
    int frame[capacity], PageFault=0,pagemiss=0,index=0,i,j;

    for(int i=0;i<capacity;i++) frame[i]=-1;

    printf("Optimal Page Replacement: \n");

    for(i=0;i<n;i++){
        int found=0;
        for(j=0;j<capacity;j++){
            if(frame[j]==page[i]){
                found=1;
                pagemiss++;
                break;
            }
        }
        if(!found){
            if(i<capacity){
                frame[i]=page[i];
            }else{
                int pos=findOptimal(page,n,frame,capacity,i+1);
                frame[pos]=page[i];
            }
            PageFault++;
        }
        for(j=0;j<capacity;j++){
            if(frame[j]!=-1){
                printf("%d ",frame[j]);
            }
           
        }
         printf("\n");
    }
    printf("Total no. of Page fault: %d\n",PageFault);
    printf("Total no. of Page Miss: %d\n",pagemiss);
}

int main(){
    int page[]={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(page) / sizeof(page[0]);
    int capacity = 4;

    Optimal(page, n, capacity);

    return 0;
}

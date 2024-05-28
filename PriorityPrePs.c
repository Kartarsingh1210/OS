#include<stdio.h>
#include<limits.h>
struct P{
    int pos,AT,WT,TAT,BT,FT,RT,priority;
};

int main(){
    int n,i,j;

    printf("Enter No. of processes : ");
    scanf("%d",&n);

    struct P p[n];
    printf("Enter Process Numbers: \n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].pos);
    }

     printf("Enter AT: \n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].AT);
    }

     printf("Enter BT: \n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].BT);
        p[i].RT=p[i].BT;
    }

     printf("Enter Priority (lower no. higher priority) \n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].priority);
    }

    float time=0;
    int tot_wt=0,tot_tat=0,completed=0;
   
   while(completed!=n){
    int index=-1;
    int min_priority=INT_MAX;

    for(i=0;i<n;i++){
        if(p[i].AT<=time && p[i].RT>0 &&p[i].priority<min_priority){
            min_priority=p[i].priority;
            index=i;
        }
    }

    if(index!=-1){
        p[index].RT-=1;
        time+=1;

    if(p[index].RT==0){
        completed++;
        p[index].FT=time;
        p[index].TAT=p[index].FT-p[index].AT;
        p[index].WT=p[index].TAT-p[index].BT;

        tot_tat+=p[index].TAT;  
        tot_wt+=p[index].WT;
     }
    }
    else{
        time++;
    }
  }
   printf("Process\tArrival\tBurst\tPriority\tFinish\tTurnaround\tWait\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t\t%d\n", p[i].pos, p[i].AT, p[i].BT, p[i].priority, p[i].FT, p[i].TAT, p[i].WT);
    }

    double avg_wt = tot_wt / (float)n;
    double avg_tat = tot_tat / (float)n;

    printf("The average wait time is: %lf\n", avg_wt);
    printf("The average turnaround time is: %lf\n", avg_tat);

    return 0;

}

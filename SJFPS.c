#include<stdio.h>

struct P{
    int pos,AT,BT,WT,TAT,FT,originalBT;
};

int main(){
    int i,j,n;

    printf("Enter no. of processes: ");
    scanf("%d",&n);
    struct P p[n];

    printf("Enter Process No. :");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].pos);
    }
    printf("Enter AT :");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].AT);
    }
    printf("Enter BT :");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].BT);
        p[i].originalBT=p[i].BT;
    }

    int tot_wt=0, tot_tat=0;

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].AT>p[j+1].AT){
                struct P temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    float time=0;

    for(i=0;i<n;i++){
        int min_bt=__INT_MAX__;
        int index=-1;
        for(j=0;j<n;j++){
            if(p[j].AT<=time && p[j].BT>0 && p[j].BT<min_bt){
                min_bt=p[j].BT;
                index=j;
            }
        }
        if(index==-1){
            time++;
            i--;
            continue;
        }
        time+=p[index].BT;
        p[index].FT=time;
        p[index].TAT=p[index].FT-p[index].AT;
        p[index].WT=p[index].TAT-p[index].originalBT;

        tot_tat+=p[index].TAT;
        tot_wt+=p[index].WT;
        p[index].BT=0;
    }
printf("Process\tArrival time\tBurst Time\tFinishTime\tTurn Around Time\tWaiting Time\n");
for(i=0;i<n;i++){
    printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",p[i].pos,p[i].AT,p[i].originalBT,p[i].FT,p[i].TAT,p[i].WT);
}
 double avg_wt=tot_wt/(float)n;
 double avg_tat=tot_tat/(float)n;
 printf("\n");
 printf("Avg Waiting time : %lf\n",avg_wt);
 printf("Avg TurnAround time  : %lf\n",avg_tat);
}
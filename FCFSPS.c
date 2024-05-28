#include<stdio.h>

struct P{
    int pos,AT,BT,FT,TAT,WT;
};

int main(){
    int i,j,n;
 printf("Enter no. of processes :");
 scanf("%d",&n);

 struct P p[n];
 printf("Enter the process no. :");
 for(i=0;i<n;i++)
 scanf("%d",&p[i].pos);

 printf("Enter the Arrival Time : \n");
 for(i=0;i<n;i++){
    scanf("%d",&p[i].AT);
 }

printf("Enter the Burst Time : \n");
 for(i=0;i<n;i++){
    scanf("%d",&p[i].BT);
 }

 int tot_wt=0; int tot_tat=0;
 float time=0;
 for(i=0;i<n;i++){
    if(time<p[i].AT)
    time=p[i].AT;

    time+=p[i].BT;

    p[i].FT=time;
    p[i].TAT=p[i].FT-p[i].AT;
    p[i].WT=p[i].TAT-p[i].BT;

    tot_tat+=p[i].TAT;
    tot_wt+=p[i].WT;

 }
 printf("Process\tArrival time\tBurst Time\tFinishTime\tTurn Around Time\tWaiting Time\n");
 for(i=0;i<n;i++){
    printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",p[i].pos,p[i].AT,p[i].BT,p[i].FT,p[i].TAT,p[i].WT);
 }
 double avg_wt=tot_wt/(float)n;
 double avg_tat=tot_tat/(float)n;
 printf("\n");
 printf("Avg Wating time : %lf\n",avg_wt);
 printf("Avg TurnAroundtime : %lf\n",avg_tat);
}
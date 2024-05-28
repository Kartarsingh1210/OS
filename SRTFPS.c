#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

struct P{
    int pos,AT,BT,Original_BT,FT,TAT,WT;
};

int main(){
 int n,i,j;
  printf("Enter no. of processes: ");
  scanf("%d",&n);
  struct P p[n];
  printf("Enter Process No. : ");
  for(i=0;i<n;i++){
    scanf("%d",&p[i].pos);
  }

   printf("Enter AT : ");
  for(i=0;i<n;i++){
    scanf("%d",&p[i].AT);
  }

   printf("Enter BT : ");
  for(i=0;i<n;i++){
    scanf("%d",&p[i].BT);
    p[i].Original_BT=p[i].BT;
  }

  int tot_wt=0,tot_tat=0;
  bool processed[n];
  int rem_processes=n;
  float time=0;

  for(i=0;i<n;i++){
    processed[i]=false;
  }

  while(rem_processes!=0){
    int index=-1;
    int min_bt=INT_MAX;

    for(i=0;i<n;i++){
        if(p[i].AT<=time && p[i].BT>0 && p[i].BT<min_bt){
            min_bt=p[i].BT;
            index=i;
            
        }
    }
    if(index==-1){
       time++;
       continue;
    }
    p[index].BT--;

    if(p[index].BT==0){
        
        rem_processes--;
        p[index].FT=time+1;
        p[index].TAT=p[index].FT-p[index].AT;
        p[index].WT=p[index].TAT-p[index].Original_BT;

        tot_tat+=p[index].TAT;
        tot_wt+=p[index].WT;

        processed[index]=true;
    }
    time++;
  }
printf("Process\tArrival time\tBurst Time\tFinishTime\tTurn Around Time\tWaiting Time\n");
for(i=0;i<n;i++){
    printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",p[i].pos,p[i].AT,p[i].Original_BT,p[i].FT,p[i].TAT,p[i].WT);
}
 double avg_wt=tot_wt/(float)n;
 double avg_tat=tot_tat/(float)n;
 printf("\n");
 printf("Avg Waiting time : %lf\n",avg_wt);
 printf("Avg TurnAround time  : %lf\n",avg_tat);
}


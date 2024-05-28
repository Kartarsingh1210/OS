#include<stdio.h>

struct P{
    int pos,AT,WT,TAT,BT,FT,priority;
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
    }

     printf("Enter Priority (lower no. higher priority) \n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].priority);
    }

    float time=0;
    int tot_wt=0,tot_tat=0;

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].AT>p[j+1].AT|| p[j].AT==p[j+1].AT && p[j].priority>p[j+1].priority){
                struct P temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            } 
        }
    }

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

    printf("Process\tpriority\tAT\tBT\tFT\tTAT\tWT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pos,p[i].priority,p[i].AT,p[i].BT,p[i].FT,p[i].TAT,p[i].WT);
    }

    double avg_wt= tot_wt/(float)n;
    double avg_tat=tot_tat/(float)n;

    printf("AVG WT : %lf\n",avg_wt);
    printf("AVG TAT : %lf\n",avg_tat);
    
    return 0;
}
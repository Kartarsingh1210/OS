#include<stdio.h>

int main(){
    int np,nr;
    printf("No.of process: ");
    scanf("%d",&np);
    printf("No. of resources: ");
    scanf("%d",&nr);

    int allocation[np][nr];
    printf("Enter Allocation Matrix: \n");
   for(int i=0;i<np;i++){
    for(int j=0;j<nr;j++){
        scanf("%d",&allocation[i][j]);
    }
   }

   int max[np][nr];
   printf("Enter Max Matrix: \n");
     for(int i=0;i<np;i++){
    for(int j=0;j<nr;j++){
        scanf("%d",&max[i][j]);
    }
   }

   int available[nr];
   printf("Enter Available Resources: \n");
   for(int i=0;i<nr;i++){
    scanf("%d",&available[i]);
   }

   int f[np];
   int ans[np];
   int index=0;

   for(int i=0;i<np;i++){
     f[i]=0;
   }

   int need[np][nr];

   for(int i=0;i<np;i++){
    for(int j=0;j<nr;j++){
        need[i][j]=max[i][j]-allocation[i][j];
    }
   }

   int y=0;
   for(int k=0;k<np;k++){
    for(int i=0;i<np;i++){
        if(f[i]==0){
            int flag=0;

            for(int j=0;j<nr;j++){
                if(need[i][j]>available[j]){
                    flag=1;
                    break;
                }
            }

            if(flag==0){
                ans[index++]=i;
                for(y=0;y<nr;y++){
                    available[y]+=allocation[i][y];
                   }
                    f[i]=1;
                }
            }
        }
    }
    int flag=1;

    for(int i=0;i<np;i++){
        if(f[i]==0){
            flag=0;
            printf("System not safe");
            break;
        }
    }
    if(flag==1){
        printf("Safe Sequence : \n");

    for(int i=0;i<np-1;i++){
        printf("P%d ->",ans[i]);
    }
    printf("P%d\n",ans[np-1]);
}
return 0;
}



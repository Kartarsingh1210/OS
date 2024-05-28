#include<stdio.h>

void firstfit(int bs[],int ps[],int m,int n){
 int allocate[n];
 int i,j;
 
 for(i=0;i<n;i++){
    allocate[i]=-1;
 }

 for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        if(bs[j]>=ps[i]){
            allocate[i]=j;
            bs[j]-=ps[i];
            break;
        }
    }
 }

 printf("\nProcess no.\t Process Size\tBlock no.\n");

 for(i=0;i<n;i++){
    printf("%i\t\t\t",i+1);
    printf("%i\t\t\t\t",ps[i]);
    if(allocate[i]!=-1){
        printf("%i",allocate[i]+1);
    }else{
        printf("Not allocated");
    }

        printf("\n");
 }
}


int main(){
    int bs[]={100,500,200,300,600};
    int ps[]={212,417,112,426};

    int m=sizeof(bs)/sizeof(bs[0]);
    int n=sizeof(ps)/sizeof(ps[0]);

    firstfit(bs,ps,m,n);
    return 0;
}
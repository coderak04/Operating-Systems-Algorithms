#include<stdio.h>
int main()
{
    int time,p[10],bt[10],at[10],sum_bt=0,smallest,n,i,sumt=0,sumw=0;
    printf("enter the no of processes: ");
    scanf("%d",&n);
    printf("enter %d processes: ",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&p[i]);  
    }
    printf("enter %d arrival times: ",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("enter %d burst times: ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        sum_bt+=bt[i];
    }
    bt[9]=9999;
    for(time=0;time<sum_bt;)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time && bt[i]>0 && bt[i]<bt[smallest])
            smallest=i;
        }
        printf("\nP %d\t WT:%d\t TAT:%d",smallest+1,time-at[smallest],time+bt[smallest]-at[smallest]);
        sumt+=time+bt[smallest]-at[smallest];
        sumw+=time-at[smallest];
        time+=bt[smallest];
        bt[smallest]=0;
    }
    printf("\n");
    printf("\nAVERAGE WAITING TIME= %.2f ms",sumw*1.0/n);
    printf("\nAVERAGE TURNAROUND TIME= %.2f ms\n",sumt*1.0/n);
    return 0;
}
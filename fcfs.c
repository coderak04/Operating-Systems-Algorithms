#include <stdio.h>
int main()
{
    int p[10],bt[10],at[10],wt[10],i,j,n,temp,ta[10],temp1=0;
    float sum=0,tat=0,avgwt,avgtat;
    printf("enter the number of processes:");
    scanf("%d",&n);
    printf("enter %d processes:",n);
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
    }
    for(i=1;i<n;i++)
    {
        temp=0;
        for(j=0;j<(n-i);j++)
        {
            if(at[j]>at[j+1])
            {
                temp=p[j+1];
                p[j+1]=p[j];
                p[j]=temp;
                temp=at[j+1];
                at[j+1]=at[j];
                at[j]=temp;
                temp=bt[j+1];
                bt[j+1]=bt[j];
                bt[j]=temp;
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        temp1=bt[i-1]+temp1;
        wt[i]=temp1-at[i];
    }
    for(i=0;i<n;i++)
    {
        sum=sum+wt[i];
    }
    for(i=0;i<n;i++)
    {
        ta[i]=wt[i]+bt[i];
        tat=tat+ta[i];
    }
    avgwt=sum/n;
    avgtat=tat/n;
    for(i=0;i<n;i++)
    {
        printf("\n P %d\t WT: %d\t TAT: %d\t",p[i],wt[i],ta[i]);
    }
    printf("\n");
    printf("AVERAGE WAITING TIME= %.2f ms",avgwt);
    printf("\nAVERAGE TURNAROUND TIME= %.2f ms\n",avgtat);
}
                                                                                                                                   
                                                                                                                                   

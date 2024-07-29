#include <stdio.h>
void FirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocate[processes];
    for(int i = 0; i < processes; i++)
    {
		allocate[i] = -1;
    }
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++) { 
            if (blockSize[j] >= processSize[i])
            {
                allocate[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n",allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void main()
{
    int blockSize[100],processSize[100],i,m,n;s
    printf("Enter no. of blocks: ");
    scanf("%d",&m);
    printf("Enter size of each block: ");
    for(i = 0; i < m; i++)
    scanf("%d", &blockSize[i]);
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    printf("Enter size of each process: ");
    for(i = 0; i < n; i++)
    scanf("%d", &processSize[i]);
    FirstFit(blockSize, m, processSize, n);
}
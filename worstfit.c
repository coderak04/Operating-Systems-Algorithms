#include <stdio.h>

void WorstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[processes];
    int occupied[blocks];
    for(int i = 0; i < processes; i++)
    {
        allocation[i] = -1;
    }
    for(int i = 0; i < blocks; i++)
    {
        occupied[i] = 0;
    }
    for (int i=0; i < processes; i++)
    {
	int indexPlaced = -1;
	for(int j = 0; j < blocks; j++)
	{
	    if(blockSize[j] >= processSize[i] && !occupied[j])
            {
                if (indexPlaced == -1)
                    indexPlaced = j;
                else if (blockSize[indexPlaced] < blockSize[j])
                    indexPlaced = j;
            }
        }
        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
            blockSize[indexPlaced] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
 
void main()
{
    int blockSize[100],processSize[100],i,m,n;
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
    WorstFit(blockSize,m,processSize,n);
}
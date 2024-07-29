//INSERTION SORT
#include<stdio.h>
int main()
{
    int i,j,temp,arr[20],n;
    printf("Number of elements in list: ");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++) 
    {  
        temp=arr[i];
        for(j=i-1;j>=0;j--)
        {  
            if(temp<arr[j])   
            {    
                arr[j+1]=arr[j];
                arr[j]=temp;   
            }    
        }
    }
    printf("Sorted List using INSERTION SORT is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }  
}

//SELECTION SORT
#include<stdio.h>
int main()
{
    int i,j,temp,arr[20],n,min;
    printf("Number of elements in the list: ");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++)     
    {  
        min=i;   
        for (j=i+1;j<n;j++)
        {  
            if (arr[j]<arr[min]) 
            { 
                min=j;
            }
        }  
        temp=arr[min];  
        arr[min]=arr[i];  
        arr[i]=temp;
    }
    printf("Sorted List using SELECTION SORT is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;        
}

//HEAP SORT
#include <stdio.h>

void heapify(int a[], int n, int i)
{
	int largest = i;
	int left = 2 *i + 1;
	int right = 2 *i + 2;

	if (left < n && a[left] > a[largest])
		largest = left;

	if (right < n && a[right] > a[largest])
		largest = right;

	if (largest != i)
	{
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, i, 0);
	}
}

int main()
{
	int arr[30], n, i;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	printf("Enter elements\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	heapSort(arr, n);
	printf("\nLIST AFTER HEAP SORT:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}
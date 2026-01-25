#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

int partitionFirst(int a[],int low,int high)
{
	int pivot=a[low];
	int i=low+1;
	int j=high;
	while(i<=j)
	{
		while(i<=high&&a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
			swap(&a[i],&a[j]);
	}
	swap(&a[low],&a[j]);
	return j;
}

void quickSortFirst(int a[],int low,int high)
{
	if(low<high)
	{
		int p=partitionFirst(a,low,high);
		quickSortFirst(a,low,p-1);
		quickSortFirst(a,p+1,high);
	}
}

int partitionLast(int a[],int low,int high)
{
	int pivot=a[high];
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
}

void quickSortLast(int a[],int low,int high)
{
	if(low<high)
	{
		int p=partitionLast(a,low,high);
		quickSortLast(a,low,p-1);
		quickSortLast(a,p+1,high);
	}
}

int partitionRandom(int a[],int low,int high)
{
	int r=low+rand()%(high-low+1);
	swap(&a[r],&a[high]);
	return partitionLast(a,low,high);
}

void quickSortRandom(int a[],int low,int high)
{
	if(low<high)
	{
		int p=partitionRandom(a,low,high);
		quickSortRandom(a,low,p-1);
		quickSortRandom(a,p+1,high);
	}
}

int main()
{
	int a[]={157,110,147,122,149,151,111,141,112,123,133,117};
	int n=sizeof(a)/sizeof(a[0]);
	srand(time(0));
	int a1[n],a2[n],a3[n];
	for(int i=0;i<n;i++)
	{
		a1[i]=a[i];
		a2[i]=a[i];
		a3[i]=a[i];
	}
	quickSortFirst(a1,0,n-1);
	quickSortLast(a2,0,n-1);
	quickSortRandom(a3,0,n-1);
	printArray(a1,n);
	printArray(a2,n);
	printArray(a3,n);
	return 0;
}

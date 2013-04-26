#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int *a,int size)
{
int value;
int j;
for(int i=0;i<size;i++)
{
	value = a[i];
	j=i-1;
	while(j>=0 && a[j]>value)
	{
		a[j+1]=a[j];
		j--;
	
	}
	a[j+1]=value;
}


}

void merge(int *a,int l, int m,int u)
{
	int b[u-l+1];
	int i1=l;
	int i2=m+1;
	int j=0;
	while(i1<=m && i2 <=u)
	{
		if(a[i1]<a[i2])
		{
			b[j++]=a[i1++];
		}
		else
		{
			b[j++]=a[i2++];
		}
	
	}
	if(i1<=m)
	{
		while(i1<=m)
		b[j++]=a[i1++];
	}
	if(i2<=u)
	{
		while(i2<=u)
		b[j++]=a[i2++];
	}
	
	j=0;
	while(j<u-l+1)
	{
		a[l+j] = b[j];
		j++;
	
	}
	
}



void mergeSort(int* a,int l,int u)
{
 if(l==u) return;
 if(l<u){
		int mid = (l+u)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,u);
		merge(a,l,mid,u);
  }
}

void print(int a[],int size)
{
 
for(int i=0;i<size;i++) cout<<a[i]<<" ";
cout<<endl;

}

void swap(int *a,int x,int y)
{
int temp =a[x];
a[x]=a[y];
a[y]=temp;
}


int partition(int *a,int l,int r, int p)
{

int pivotvalue = a[p];
int startIndex = l;

swap(a,p,r);

for(int i=l;i<=r-1;i++)
{
	if(a[i]<=pivotvalue)
	{
		swap(a,i,startIndex);
		startIndex++;	
	}

}

swap(a,r,startIndex);
return startIndex;
}

void quickSort(int *a,int l,int r)
{
	int pivotIndex = (l+r)/2;
	int pivotNewIndex = 0;
	if(l<r)
	{
		pivotNewIndex=partition(a,l,r,pivotIndex);
		print(a,10);
		quickSort(a,l,pivotNewIndex-1);
		quickSort(a,pivotNewIndex+1,r);
	}

}

int main()
{
	int a[]={90,67,45,100,35,178,34,90,12,50};
	//insertionSort(a,10);
	int size=10;
	//int a[]={3,1};
	print(a,size);
	cout<<endl;
	//mergeSort(a,0,size-1);
	quickSort(a,0,size-1);
	print(a,size);
return 0;
}
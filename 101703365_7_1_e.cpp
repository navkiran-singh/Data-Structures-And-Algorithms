#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int array[],int start,int end){
	int partitionIndex=start;
	int pivot=array[end];
	for(int i=start;i<end;++i){
		if(array[i]<=pivot){
			swap(&array[i],&array[partitionIndex]);
			partitionIndex++;
		}	
	}
	swap(&array[partitionIndex],&array[end]);
	return partitionIndex;	
}
void display(int *array,int size){
	for(int i=0;i<size;++i){
		cout<<*(array+i)<<" ";
	}
}
void quicksort(int array[],int start,int end){
	if(start<end){
		int pi=partition(array,start,end);
		quicksort(array,start,pi-1);
		quicksort(array,pi+1,end);
	}
}



int main()
{
	int *array,size;
	cout<<"Enter array size and then enter values after pressing enter: \n";cin>>size;
	array=new int[size];
	for(int k=0;k<size;++k) cin>>array[k];
	quicksort(array,0,size-1);
	cout<<"Sorted Array by QuickSort: ";display(array,size);
	return 0;
}

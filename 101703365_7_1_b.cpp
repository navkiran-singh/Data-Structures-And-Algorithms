#include<iostream>
using namespace std;
void insertionsort(int array[],int size)
{
	
	int i,j,key;
	for(i=1;i<size;++i)
	{
		key=array[i];
		
		j=i-1; 
		
		while(j>=0&&array[j]>key)
		{
			array[j+1]=array[j]; 
			j=j-1; 
		}
	
		array[j+1]=key; 
	}
}
void display(int *array,int size){
	for(int i=0;i<size;++i){
		cout<<*(array+i)<<" ";
	}
}

int main()
{
	int *array,size;
	cout<<"Enter array size and then enter values after pressing enter: \n";cin>>size;
	array=new int[size];
	for(int k=0;k<size;++k) cin>>array[k];
	insertionsort(array,size);
	cout<<"Sorted Array (in O(n^2) via Insertion sort): ";display(array,size);
	return 0;
}

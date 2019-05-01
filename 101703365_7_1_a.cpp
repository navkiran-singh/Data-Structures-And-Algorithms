#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void selectionsort(int array[],int size)
{
	for(int i=0;i<size;++i)
	{
		int min_index=i;
		for(int j=i+1;j<size;++j){
			if(array[j]<array[min_index]) min_index=j;
		}
		if(min_index!=i)
		swap(&array[i],&array[min_index]);
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
	selectionsort(array,size);
	cout<<"Sorted Array (in O(n^2) via selection sort): ";display(array,size);
	return 0;
}

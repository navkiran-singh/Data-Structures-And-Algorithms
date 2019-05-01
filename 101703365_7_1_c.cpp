#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void display(int *array,int size){
	for(int i=0;i<size;++i){
		cout<<*(array+i)<<" ";
	}
}
void bubblesort(int array[],int size){
	for(int i=0;i<size-1;++i){
		
		for(int j=0;j<size-1-i;++j)
		{
			if(array[j]>array[j+1]) {
			swap(&array[j],&array[1+j]);
			
			}
		}
		
	}
}



int main()
{
	int *array,size;
	cout<<"Enter array size and then enter values after pressing enter: \n";cin>>size;
	array=new int[size];
	for(int k=0;k<size;++k) cin>>array[k];
	bubblesort(array,size);
	cout<<"Sorted Array (in O(n^2) via Bubble sort): ";display(array,size);
	return 0;
}

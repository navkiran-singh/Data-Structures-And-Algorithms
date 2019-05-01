#include<iostream>
using namespace std;
void display(int *array,int size){
	for(int i=0;i<size;++i){
		cout<<*(array+i)<<" ";
	}
}
int max(int array[],int size){
	int maximum=array[0];
	for(int i=0;i<size;++i){
		if(array[i]>maximum) maximum=array[i];
	}
	return maximum;
}
void countingsort(int array[],int size){
	
	int k=max(array,size);
	int *aux=new int[k];
	for(int i=0;i<=k;++i) aux[i]=0;
	
	for(int i=0;i<size;++i)
	{
		aux[array[i]]++;
	}
	cout<<"Auxillary array: ";display(aux,k+1);int j=0;
	for(int i=0;i<size;++i)
	{
		
		int temp=aux[i];
		while(temp--){
			array[j]=i;
			j++;
		}
		
	}
}
int main()
{
	int *array,size;
	cout<<"Enter array size and then enter values after pressing enter: \n";cin>>size;
	array=new int[size];
	for(int k=0;k<size;++k) cin>>array[k];
	countingsort(array,size);
	cout<<"\nSorted Array: ";display(array,size);
	return 0;
}

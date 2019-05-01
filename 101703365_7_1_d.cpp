#include<iostream>
using namespace std;

void merge(int array[],int left, int mid,int right){
	int lsub[mid-left+1],rsub[right-mid]; //Create two temporary sub-arrays
	int i=0; int j=0;
	int len1=mid-left+1; int len2=right-mid;
	for(i=0;i<len1;++i){
		lsub[i]=array[left+i]; //Left sub-array begins from left + i and covers upto mid
	}
	for(j=0;j<len2;++j){
		rsub[j]=array[mid+1+j]; //Right sub-array begins from mid+1 and covers till end
	}
	i=j=0;
	int k=left;
	
	//Merging process
	while(i<len1&&j<len2) //If one of the sub arrays goes empty, break
	{
		if(lsub[i]<=rsub[j]) {
			array[k]=lsub[i]; ++i; ++k;
		}
		else
		{
			array[k]=rsub[j]; ++j; ++k;
		}
	}
	
	while(i<len1) array[k++]=lsub[i++];
	while(j<len2) array[k++]=rsub[j++];
	
}

void mergesort(int array[],int left,int right){
	if(right-left+1==1) return; //base case - sub-array of length 1 is sorted
	
		int mid=(left+right)/2;
		mergesort(array,left,mid); //Pass left sub-array
		mergesort(array,mid+1,right); //Pass right sub-array
		merge(array,left,mid,right); //Merge two sub arrays
	
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
	mergesort(array,0,size-1);
	cout<<"Sorted Array (in O(nlogn) via mergesort): ";display(array,size);
	return 0;
}

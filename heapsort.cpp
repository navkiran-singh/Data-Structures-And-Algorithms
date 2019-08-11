#include<iostream>
using namespace std;
void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

void heapify(int array[],int size,int i)
{
int largest=i;
int left=2*i+1;
int right=2*i+2;

if(left<size&&array[left]>array[largest])
{
  largest=left;
}
if(right<size&&array[right]>array[largest])
{
  largest=right;
}
//base case is when the chosen root/passed largest index is actually the
//largest by the end
if(largest!=i){
  swap(&array[i],&array[largest]);
  heapify(array,size,largest);//Check for affected sub trees(down the tree)
}
}
void build_heap(int array[],int size){
for(int i=(size/2)-1;i>=0;--i){
  heapify(array,size,i); //max-heapify for all non leaf nodes since leaf nodes are already heaps
}
}

void heapsort(int array[],int size){
build_heap(array,size);
for(int i=size-1;i>=0;--i){
  swap(array[0],array[i]);
  heapify(array,i,0);
}
}
void disp_arr(int *arr,int size){
  for(int i=0;i<size;++i) cout<<arr[i]<<" ";
  cout<<"\n";
}
int main()
{
  int size;cin>>size;
  int *array=new int[size];
  for(int i=0;i<size;++i){
    cin>>array[i];
  }
  heapsort(array,size);
  disp_arr(array,size);
}

#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void heapify(int array[],int size,int i)
{
int smallest=i;
int l=2*i+1; int r=2*i+2;
if(l<size&&array[l]<array[smallest]) smallest=l;
if(r<size&&array[r]<array[smallest]) smallest=r;
if(smallest!=i)
{
swap(&array[i],&array[smallest]);
heapify(array,size,smallest);
}
}
void buildheap(int array[],int size){
for(int i=size/2-1;i>=0;--i)
{
heapify(array,size,i);
}
}
void heapsort(int array[],int size)
{buildheap(array,size);
for(int i=size-1;i>=0;--i)
{
swap(&array[0],&array[i]);
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

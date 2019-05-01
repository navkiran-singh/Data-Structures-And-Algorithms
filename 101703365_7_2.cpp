#include<iostream>
#define SIZE 10
using namespace std;
class stack{
private:
int top;
int array[SIZE];
public:
stack(){ top=-1;
}
bool empty(){ return top==-1;
}
bool full(){ return (top==SIZE-1);
}
void push(int value){
array[++top]=value;	
}	
int pop(){
	return array[top--];
}
int istop(){
	return array[top];
}
};
void display(stack s){
	while(!s.empty()){
		cout<<s.pop()<<" ";
	}
}
stack sorter(stack &input, stack &tmp)
{
while(!input.empty()) {
	int tempvar=input.pop();
	if(tempvar>tmp.istop()||tmp.empty()) tmp.push(tempvar);
	else
	{
		while(!tmp.empty()&&tempvar<tmp.istop()){
			input.push(tmp.pop());
		}
		tmp.push(tempvar);
	}
}
return tmp;
}

int main(){
	stack s1,temp;
	int size,value;
	cout<<"Enter size(max 10) followed by values:\n";
	cin>>size;
	for(int i=0;i<size;++i)
	{
		cin>>value;
		s1.push(value);
	}
	temp=sorter(s1,temp);
    cout<<"\nDisplaying Descending Order: ";display(temp);
	
}

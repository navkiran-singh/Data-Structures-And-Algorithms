#include<iostream>
#include<string>
#define size 20
using namespace std;
class stack_class{
  private:
  char stack[size];
  public:
  int top=-1;
  void push(char value){
    if(top!=size-1) stack[++top]=value; 
    else cout<<"Stack Overflow\n";
    }
  char pop(){if(top!=-1) return stack[top--];else {cout<<"Stack Underflow\n";return 0;}}
  char istop(){return stack[top];}
  void display(){while(top!=-1) cout<<"Index:"<<top+1<<" holds "<<pop()<<endl;}
  bool empty(){if(top==-1) return true; else return false;}
};
bool balanced(stack_class &s, string expr)
{
	char x; 

	// Traversing the Expression 
	for (int i=0; i<expr.length(); i++) 
	{ 
		if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
		{ 
			// Push the element in the stack 
			s.push(expr[i]); 
			continue; 
		} 

		// IF current current character is not opening 
		// bracket, then it must be closing. So stack 
		// cannot be empty at this point. 
		if (s.empty()) 
		return false; 
        x=s.pop();
		switch (expr[i]) 
		{ 
		case ')': 
			if (x=='{' || x=='[') 
				return false; 
			break; 

		case '}': 
			if (x=='(' || x=='[') 
				return false; 
			break; 

		case ']': 
			if (x =='(' || x == '{') 
				return false; 
			break; 
		} 
	} 

	// Check Empty Stack 
	return (s.empty()); }
int main()
{stack_class stk;
  string input; cin>>input; 
  cout<<balanced(stk,input);
  
}


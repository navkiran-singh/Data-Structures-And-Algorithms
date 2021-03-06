#include<iostream>
#define size 20
using namespace std;
class stack_class{
  private:
  int stack[size];
  public:
  int top=-1;
  void push(char value){
    if(top!=size-1) stack[++top]=value; 
    else cout<<"Stack Overflow\n";
    }
  int pop(){if(top!=-1) return stack[top--];else {cout<<"Stack Underflow\n";return 0;}}
  int istop(){return stack[top];}
  void display(){while(top!=-1) cout<<"Index:"<<top+1<<" holds "<<pop()<<endl;}
  bool isempty(){if(top==-1) return true; else return false;}
};
void getMinimum(stack_class &stk){
    int minimum=stk.istop();
    while(!stk.isempty()){int current=stk.pop();
        if(minimum>current) minimum=current;
    }
    cout<<minimum<<endl;
}

int main()
{stack_class stk,minstk;
 int input;
 for(int i=0;i<5;++i)
 {  cin>>input;
     stk.push(input);
     if(i!=0)
     if(input<minstk.istop()) minstk.push(input); else minstk.push(minstk.istop());
     else minstk.push(input);
 }
 getMinimum(stk); // in O(n) time complexity
 cout<<"Minimum via auxillary stack:"<<minstk.istop();
}

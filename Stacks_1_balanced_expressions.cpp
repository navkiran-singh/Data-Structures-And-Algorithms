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
  void display(){while(top!=-1) cout<<"Index:"<<top+1<<" holds "<<pop()<<endl;}
};
void push_string_to_stk(stack_class stk, string input){
    int i=0;
  while(input[i]!='\0'){
    stk.push(input[i]);
    ++i;
  }
  stk.display();
}
bool balanced(stack_class &stk, string input)
{
 int i=0; char element;
 while(input[i]='\0')
 {
     //if character is an opening type, push it onto stack
     if(input[i]=='('||input[i]=='{'||input[i]=='[') stk.push(input[i]);
     
    
         //if character of closing type is encountered, pop(from top). If opening-closing pair
         //is valid, then proceed forward otherwise return false.
        else {
            switch(input[i])
        { 
            case ')':
                element=stk.pop();
                if(element=='{'||element=='[') //not a pair
                return false;
                break;
            
            case '}':
                element=stk.pop();
                if(element=='('||element=='[') return false;
                break;
            
            case ']':
                element=stk.pop();
                if(element=='{'||element=='[') return false;
                break;
                
            default:
                continue;
        }
     }
 }
 if(stk.top==-1) return true; else return false;

}
int main()
{stack_class stk;
  string input; cin>>input; 
  push_string_to_stk(stk,input);
  cout<<balanced(stk,input);
  
}

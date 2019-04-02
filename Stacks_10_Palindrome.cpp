#include<string>
#include<iostream>
#include<stack>
using namespace std;

bool palin(string expr){
    int s=0;
    int e=expr.length()-1;
    
    while(s!=e){
        if(expr[s]!=expr[e]) break;
        s++;
        e--;
    }
    if(s<e) return false; else return true;
    
}

bool palin_stk(string input){
    stack<char> stk; int i=0;
    if(input.length()==0||input.length()==1) return true;
    if(input.length()==2){
        return (input[0]==input[1]);
    }
    while(i!=(input.length()-1)/2)
    {
        stk.push(input[i]);
        i++;
    }
    i++;
    while(1){
        char x = stk.top();
        stk.pop();
        if(x=!input[i]) return false;
        i++;
        if(stk.empty()&&input[i]!='\0') return true;
        else if(stk.empty())
        {
            return false;
        }
        
        
    }
}
int main()
{
    string input;
    cin>>input;
    cout<<palin(input);
    cout<<palin_stk(input);
}

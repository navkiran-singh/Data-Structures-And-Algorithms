#include<iostream>
#include<stack>
using namespace std;
struct Queue{
  stack<int> s1;
  stack<int> s2;
};

void enqueue(Queue *Q,int data){
    Q->s1.push(data);
}
int dequeue(Queue *Q){ 
    int res;
    if(!Q->s2.empty()) //if stack 2 is not empty just pop
   { res=Q->s2.top();
    Q->s2.pop();
    return res;}
    else
    {
        while(!Q->s1.empty())
        {
            Q->s2.push(Q->s1.top());
            Q->s1.pop();
        }
        res=Q->s2.top();
        Q->s2.pop();
          return res;
    }
  
}
int main()
{
    Queue *Q=new Queue;
    int size,input;
    cin>>size;
    for(int i=0;i<size;++i){cin>>input;
    enqueue(Q,input);}
    for(int i=0;i<size;++i)
    cout<<dequeue(Q)<<" ";
    
}

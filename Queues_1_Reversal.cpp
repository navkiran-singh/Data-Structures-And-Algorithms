#include<iostream>
#include<stack>
using namespace std;

//create a user-defined datatype ArrayQueue
struct ArrayQueue{
  int front,rear,capacity,*array;
};

//function to create a queue (data type ArrayQueue) of a given size
struct ArrayQueue *Queue(int size){
struct ArrayQueue *Q=new ArrayQueue;
if(!Q) return NULL;
//By now we have allocated memory for our "ArrayQueue" 3*4+8(for pointer on 64-bit)

Q->capacity=size;
Q->front=Q->rear=-1;

//Now we allocate space to the array our Queue will use and return the pointer of first index to the pointer of our struct
Q->array=new int[Q->capacity];
if(!Q->array) return NULL;

return Q;
}

/*Operations*/
bool isFull(struct ArrayQueue *Q){
    //To insert, we move rear by 1 and enqueue. Here we move rear by 1 and check if it overlaps with front
    if((Q->rear+1)%Q->capacity==Q->front) return true; else return false;
}

bool isEmpty(struct ArrayQueue *Q){ return(Q->front==-1);/*returns 1 if front=-1 is true*/}

void enqueue(struct ArrayQueue *Q,int data){
//enqueue happens at rear
if(isFull(Q)) printf("Full\n");
else
{   Q->rear=(Q->rear+1)%Q->capacity;
    Q->array[Q->rear]=data;
    if(Q->front==-1) Q->front=Q->rear;
}
}

int dequeue(struct ArrayQueue *Q)
{int data;
    if(isEmpty(Q)) printf("Empty\n");
    else
    {
        data=Q->array[Q->front];
        if(Q->front==Q->rear) Q->front=Q->rear=-1; //If only one element is there
        else
        Q->front=(Q->front+1)%Q->capacity;
    }
    return data;
}

int RemainingCapacity(struct ArrayQueue *Q){
    return ((Q->capacity-(Q->rear-Q->front +1))+Q->capacity)%Q->capacity;
}

int QueueSize(struct ArrayQueue *Q){
    return (Q->capacity-RemainingCapacity(Q));
}

void display(struct ArrayQueue *Q){int current=Q->front;
    while(1){
        printf("%d ",Q->array[current]);
        current=(current+1)%Q->capacity;
        if(current==Q->front)
        break;
    }
    cout<<endl;
}
struct ArrayQueue *reverse(struct ArrayQueue *Q){
    stack<int> stk;
    while(!isEmpty(Q)){
    stk.push(dequeue(Q));
    }
    while(!stk.empty())
    {
        enqueue(Q,stk.top());
        stk.pop();
    }
    return Q;
    }
int main()
{   int size,input;
    scanf("%d",&size);
    struct ArrayQueue *Q=Queue(size);
    for(int i=0;i<size;++i){
        scanf("%d",&input);
        enqueue(Q,input);
    }
    display(Q);
    Q=reverse(Q);
    display(Q);
}

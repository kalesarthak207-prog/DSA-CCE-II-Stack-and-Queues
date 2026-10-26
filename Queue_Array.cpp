#include<iostream>
using namespace std;

const int MAX=5;

class Queue
{
    private:
    int a[MAX];
    int front;
    int rear;
   
    public:

    Queue()
    {
      front=-1;
      rear=-1;
      
    }

    int empty()
    {
        if(front==-1 && rear==-1)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int full()
    {
        if(rear==MAX-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }


    void enqueue(int x)
    {

     if(full())
     {
        cout<<"queue is full";
     }    
    else if(empty())
    {
        front++;
        rear++;
        a[front]=x;
        a[rear]=x;
    }
    else
    {
        rear++;
        a[rear]=x;
    }

    }

    void dequeue()
    {
        int x=a[front];
        front++;
    }

    void dispaly()
    {
        for(int i=front;i<=MAX-1;i++)
        {
            cout<<"\t"<<a[i];
        }
    }

    int peak()
    {
        return a[front];
    }
};

int main()
{
    Queue q;

   q.enqueue(10);
   q.enqueue(20);
   q.enqueue(30);
   q.enqueue(40);
   q.enqueue(50);

    cout<<"\nQueue elements is :"<<endl;
    q.dispaly();

    int x=q.peak();
    cout<<"\nfirst element in queue is :"<<x<< endl;
     
   q.dequeue();
   cout<<"\nafter dequeue operation elements are:"<< endl;
   q.dispaly();

   return 0;
}

/*PS D:\sarthak kale> 
> cd "d:\sarthak kale\" ; if ($?) { g++ queue_array.cpp -o queue_array } ; if ($?) { .\queue_array }

Queue elements is :
        10      20      30      40      50
first element in queue is :10

after dequeue operation elements are:
        20      30      40      50
PS D:\sarthak kale> */
                                                                                                                                                                                                                                            
#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int x)
    {
        data=x;
        next=NULL;
    }
};

class queue
{
    private:
     node *front;
     node *rear;

    public:

    queue()
    {
        front=NULL;
        rear=NULL;
    }

    void enqueue(int x)
    {
      node *p=new node(x);

      if(front==NULL )
      {
        front=p;
        rear=p;
      }
      else
      {
        rear->next=p;
        rear=p;

      }

    }
    void dequeue()
    {
        node *p;
        p=front;
        front=front->next;
        delete p;
    }

    void display()
    {
        node * q;
        q=front;
        while(q!=NULL)
        {
            cout<<endl<<q->data<<endl;
            q=q->next;
        }
    }

    int peak()
    {
        return front->data;
    }

};

int main()
{
    queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout<<"\nQueue elements are :"<<endl;
    q.display();

    int x=q.peak();
    cout<<"\nfirst element in the queue is :"<<x<<endl;

    cout<<"\nacoutfter dequeue operation :"<<endl;
    q.dequeue();
    q.display();

    cout<<"\nacoutfter dequeue operation :"<<endl;
    q.dequeue();
    q.display();

    cout<<"\nacoutfter dequeue operation :"<<endl;
    q.dequeue();
    q.display();


    return 0;
}

/*PS D:\sarthak kale> cd "d:\sarthak kale\" ; if ($?) { g++ smaple.cpp -o smaple } ; if ($?) { .\smaple }

Queue elements are :

10

20

30

40

50

first element in the queue is :10

acoutfter dequeue operation :

20

30

40

50

acoutfter dequeue operation :

30

40

50

acoutfter dequeue operation :

40

50
PS D:\sarthak kale> */
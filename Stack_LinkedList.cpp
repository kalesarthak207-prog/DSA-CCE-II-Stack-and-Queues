//stack usingh linked list//
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

class stack
{
  private:
  node *top;

public:

  stack()
  {
    top=NULL;
  }

  
  int empty()
  {
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
  }

  void push(int x)
  {
    node *p=new node(x);
    p->next=top;
    top=p;
    cout<<"stack is implemnted";
  }

  void pop()
  {
    node *p;
    p=top;
    top=top->next;
    delete p;

  }

 void display()
  {
    node *q;
    q=top;

  
    while(q!=NULL)
    {
        cout<<q->data<<endl;
        q=q->next;
    }
  }

  int peak()
  {
    return top->data;
  }
};

int main()
{
    stack s;

    s.push(100);
    s.push(200);
    s.push(300);
      cout<<"\n STACK ELEMENTS ARE :\n";
    s.display();
    
    cout<<"\nafter pop stack elements are:"<<endl;
    s.pop();
    s.display();

    int x=s.peak();
    cout<<"\ntop element of stack is :"<<x<<endl;
}
/*PS D:\sarthak kale> 
 > cd "d:\sarthak kale\" ; if ($?) { g++ stack.cpp -o stack } ; if ($?) { .\stack }
stack is implemntedstack is implemntedstack is implemnted
 STACK ELEMENTS ARE :
300
200
100

after pop stack elements are:
200
100

top element of stack is :200
PS D:\sarthak kale> */
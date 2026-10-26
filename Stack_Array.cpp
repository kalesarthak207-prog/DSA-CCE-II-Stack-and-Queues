//stack using array//
#include <iostream>
using namespace std;

const int MAX=5;

class Stack
{
    private:
    int a[MAX];
    int top;

    public:

    Stack()
    {
        top=-1;
    }

    void push(int x)
    {
        top++;
        a[top]=x;
    }
    int pop()
    {
        int x=a[top];
        top--;
        return x;
    }

    int peak()
    {
        return a[top];
    }

    int full()
    {
        if(top==MAX-1)
        {
            return 1;
        }
        else{
            return 0;
        }
    }

    int empty()
    {
        if(top==-1)
        {
            return 1;
        }
        else{
            return 0;
        }
    }

    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<"\t"<<a[i];
        }
    }

    
    
};

int main()
{
    Stack s;
    int x;

    if(!s.full())s.push(10);
     if(!s.full())s.push(20);
      if(!s.full())s.push(30);
       if(!s.full())s.push(40);
        if(!s.full())s.push(50);
    cout<<"\nstack elemnets are:\n"<<endl;
    s.display();

    x=s.pop();
    cout<<"\ntop element of stack is :\n"<<x;
    cout<<"\nafter pop elements are:\n"<<endl;
    s.display();

    int y=s.peak();
    cout<<"\ntop of stack is :"<<y<<endl;
}

/*PS D:\sarthak kale> 
 > cd "d:\sarthak kale\" ; if ($?) { g++ stack2.cpp -o stack2 } ; if ($?) { .\stack2 }

stack elemnets are:

        50      40      30      20      10
top element of stack is :
50
after pop elements are:

        40      30      20      10

top of stack is :40
PS D:\sarthak kale> */


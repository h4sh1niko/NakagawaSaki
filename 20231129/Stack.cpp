#include<iostream>
#include<vector>

using namespace std;
const int Max = 5;

string st[Max];
int top;

void init()
{
    top = 0;
}

bool isEmpty()
{
    return(top == 0);
}

bool isFull()
{
    return(top == Max);
}

void Push(string v)
{
    if(isFull())
    {
        cout << "error : stack is full" << endl;
        return;
    }
    st[top++] = v;cout << "Push: " << v << " | Stack: ";
    for (int i = 0; i < top; ++i) {
        cout << st[i] << " ";
    }
    cout << endl;
}

string Pop()
{
    if(isEmpty())
    {
        cout << "error : stack is empty" << endl;
        return NULL;
    }
    cout << "Pop: " << st[top - 1] << " | Stack: ";
    for (int i = 0; i < top - 1; ++i) {
        cout << st[i] << " ";
    }
    cout << endl;

    return st[--top];
}

int main()
{
    init();

    Push("A");
    Push("B");
    Push("C");
    cout << Pop() << endl;
    cout << Pop() << endl;
    Push("D");
    cout << Pop() << endl;
}
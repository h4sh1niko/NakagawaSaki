#include <iostream>
#include <vector>

using namespace std;
const int Max = 5;

string qu[Max];
int tail = 0, head = 0;

void init() 
{
    head = tail = 0;
}

bool isEmpty()
{
    return (head == tail);
}

bool isFull() 
{
    return (head == (tail + 1) % Max) || (head == 0 && tail == Max - 1);
}

void enqueue(string v) 
{
    if (isFull()) 
    {
        cout << "error: queue is full." << endl;
        return;
    }
    qu[tail++] = v;
    if (tail == Max) tail = 0;
    cout << "Enqueue: " << v << " | Queue: ";
    for (int i = head; i != tail; i = (i + 1) % Max) {
        cout << qu[i] << " ";
    }
    cout << endl;
}

string dequeue() 
{
    if (isEmpty()) 
    {
        cout << "error: queue is empty." << endl;
        return "";
    }
    string res = qu[head];
    ++head;
    if (head == Max) head = 0;
    cout << "Dequeue: " << res << " | Queue: ";
    for (int i = head; i != tail; i = (i + 1) % Max) {
        cout << qu[i] << " ";
    }
    cout << endl;
    return res;
}

int main() 
{
    init(); 

    enqueue("A"); 
    enqueue("B"); 
    enqueue("C");

    dequeue(); 
    dequeue(); 

    enqueue("D"); 
    enqueue("E"); 

    dequeue();
    dequeue();
    dequeue();
    
    return 0;
}

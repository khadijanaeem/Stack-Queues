#include <iostream>
using namespace std;
int n = 6;
class CircularQueue
{
    int *arr;
    int front;
    int back;
    int size;

public:
    CircularQueue()
    {
        arr = new int[n];
        front = back = -1;
        size = 0;
    }
    bool IsFull()
    {
        if (front == 0 && back == n - 1)
        {
            return true;
        }
        if (back == front - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int num)
    {
        if (IsFull())
        {
            cout << "The queue is full" << endl;
            return;
        }
        else
        {
            if (back != n - 1 && back != front - 1)
            {
                back++;
                arr[back] = num;
                size++;
            }
            if (back == n - 1 && front != 0)
            {
                back = 0;
                arr[back] = num;
                size++;
            }
            if (front == -1)
            {
                front++;
            }
            cout << "Element inserted" << endl;
            return;
        }
        cout << "Is full" << endl;
    }
    int sizeofQueue()
    {
        return size;
    }
    void pop()
    {
        if (IsEmpty())
        {
            cout << "Queue Empty" << endl;
            return;
        }
        arr[front] = 0;
        front++;
    }
    int peek()
    {
        if (front != -1)
        {
            return arr[front];
        }
        else
        {
            return -1;
        }
    }
    bool IsEmpty()
    {
        if (front == -1 || back == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print()
    {
        if (front < back)
        {
            for (int i = front; i <= back; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else if (front == back + 1 || front > back)
        {
            for (int i = 0; i < back; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = back; i < n; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};
int main()
{
    CircularQueue a;
    a.push(3);
    a.push(2);
    a.push(5);
    a.push(8);
    a.push(1);
    a.push(29);
    a.print();
    cout << endl;
    cout << "Size is " << a.sizeofQueue() << endl;
    cout << "After poping the first element " << endl;
    a.pop();

    a.print();
    cout << endl;
    a.push(80);
    // a.push(5);  it will not insert this as the queue is Full
    a.print();
    cout << endl;
    int top = a.peek();
    cout << "Top element is " << top << " " << endl;
    bool x = a.IsEmpty();
    if (x)
    {
        cout << "The Queue is Empty" << endl;
    }
    else
    {
        cout << "The Queue is not Empty" << endl;
    }
}
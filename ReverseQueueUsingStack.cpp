#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverseStackUsingQueue(queue<int> &q)
{
    stack<int> s;

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        s.push(n);
    }

    while (!s.empty())
    {
        int n = s.top();
        s.pop();
        q.push(n);
    }
}
int main()
{
    queue<int> q;
    for (int i = 0; i < 5; i++)
        q.push(i);
    reverseStackUsingQueue(q);
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
}
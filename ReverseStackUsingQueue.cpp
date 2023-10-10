#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverseStackUsingQueue(stack<int> &s)
{
    queue<int> q;

    while (!s.empty())
    {
        int n = s.top();
        s.pop();
        q.push(n);
    }

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        s.push(n);
    }
}
int main()
{
    stack<int> s;
    for (int i = 0; i < 5; i++)
        s.push(i);

    reverseStackUsingQueue(s);

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}
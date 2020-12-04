#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000

const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

// Design a simple stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

struct Stack
{
    stack<int> s;
    int minElement;

    void getMin()
    {
        if (s.empty())
        {
            cout << "Stack is Empty\n";
        }
        else
            cout << "Minimum Element is : " << minElement << "\n";
    }

    void top()
    {
        if (s.empty())
        {
            cout << "Empty Stack\n";
            return;
        }

        int t = s.top();

        cout << "Top Most Element is: ";

        (t < minElement) ? cout << minElement : cout << t;

        cout << "\n";
    }

    void pop()
    {
        if (s.empty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top Element Removed: ";

        int t = s.top();
        s.pop();

        if (t < minElement)
        {
            cout << minElement << "\n";
            minElement = 2 * minElement - t;
        }
        else
        {
            cout << t << "\n";
        }
    }

    void push(int x)
    {
        if (s.empty())
        {
            minElement = x;
            s.push(x);
            cout << "Number Inserted :" << x << "\n";
            return;
        }

        if (x < minElement)
        {
            s.push(2 * x - minElement);
            minElement = x;
        }
        else
        {
            s.push(x);
        }

        cout << "Number Inserted :" << x << "\n";
    }
};

int main()
{
    Stack s;
    s.push(3);
    s.push(5);
    s.getMin();
    return 0;
}
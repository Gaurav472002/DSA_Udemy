#include <iostream>
using namespace std;

// recursive approach  Time complexity O(2^n)

int recur_fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return recur_fibonacci(n - 1) + recur_fibonacci(n - 2);
    }
}
// iterative method  Time Complexity O(n)

int iter_fibo(int n)
{
    int t1 = 0, t2 = 1, s;
    if (n <= 1)
    {
        return n;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            s = t1 + t2;
            t1 = t2;
            t2 = s;
        }
        return s;
    }
}

// Better recursive approach  known as Memoization
int memoarr[10];

int memo_fibonacci(int n)
{
   
    if (n <= 1)
    {

        memoarr[n] = n;
        return n;
    }
    else
    {

        if (memoarr[n - 2] == -1)
        {
            memoarr[n - 2] = memo_fibonacci(n - 2);
        }

        if (memoarr[n - 1] == -1)
        {
            memoarr[n - 1] = memo_fibonacci(n - 1);
        }

       memoarr[n]= memoarr[n - 1] + memoarr[n - 2];
        return memoarr[n - 1] + memoarr[n - 2];
    }
}

int main()
{
    cout << recur_fibonacci(5) << endl;
    cout << iter_fibo(5) << endl;

    for (int i = 0; i < 10; i++)
    {
        memoarr[i]=-1;
    }
    
    cout << memo_fibonacci(5) << endl;

    return 0;
}
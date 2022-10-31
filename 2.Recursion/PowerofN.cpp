// Function to calculate n to the power of m

#include <iostream>
using namespace std;

int power(int m, int n)
{

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return power(m, n - 1) * m;
    }
}

// to reduce the number of multiplications of the above function
// We can write a modified function which will perform less number of multiplications to get the result

int more_power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        return more_power(m * m, n / 2); // reducing the power to its half if its even 2^8 = 2^2^4  =(2x2)^4
    }
    else
    {
        return m *more_power(m * m, (n - 1) / 2);  // reducing the power to half and multiplying with m as it is odd 2^9 = 2x(2x2)^4
    }
}


int main()
{

    // cout<<power(2,6);
    cout << more_power(2, 6);

    return 0;
}
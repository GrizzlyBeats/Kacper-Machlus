#include <iostream>

auto amax(int a[], int n) -> int
{
    int max = a[0];
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
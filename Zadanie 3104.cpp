#include <iostream>

auto amin(int a[], int n) -> int
{
    int min = a[0];
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}
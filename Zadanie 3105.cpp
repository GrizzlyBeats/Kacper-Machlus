#include <iostream>

auto search(int a[], int n, int needle) -> int
{
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == needle)
        {
            result = i;
        }
    }
    return result;
}
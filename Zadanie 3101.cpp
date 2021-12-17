#include <iostream>

auto iota(int a[], int n, int start) -> void
{
    for (int i = 0; i < n; i++)
    {
        a[i] = start + i;
    }
}
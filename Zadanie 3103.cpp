#include <iostream>

auto asum(int a[], int n) -> int
{
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += a[i];
    }
    return suma;
}
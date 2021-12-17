#include <iostream>

auto sort_desc(int a[], int n) -> void
{
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n - i; j++)
            if (a[j - 1] < a[j])
            {
                int tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
}
 
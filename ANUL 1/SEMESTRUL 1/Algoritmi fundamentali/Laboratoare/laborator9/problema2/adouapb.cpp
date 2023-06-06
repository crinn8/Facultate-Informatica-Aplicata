#include <iostream>
#include <algorithm>
#include <fstream>

void CitireVector(int array[], int &dim)
{
    std::ifstream f("date.in");
    f >> dim;
    for (int i = 0; i < dim; i++)
    {
        f >> array[i];
    }
}

int main()
{
    int array[100], dim;
    CitireVector(array, dim);
    std::sort(array, array + dim);
    for (int i = 0; i < dim / 2; i++)
    {
            std::cout << array[i] << " " << array[dim - i - 1] << " ";
    }
    if (dim % 2 == 1)
    {
        std::cout << array[dim / 2];
    }
    return 0;
}


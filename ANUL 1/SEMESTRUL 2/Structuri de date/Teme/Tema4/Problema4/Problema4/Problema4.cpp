#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

void Median()
{
    double median = 0,element;
    std::ifstream f("numere.in");
    int n;
    f >> n;
    std::priority_queue<double> max_heap;
    std::priority_queue<double, std::vector<double>, std::greater<double> > min_heap;
    f >> element;
    std::cout << element << " ";
    median = element;
    max_heap.push(element);

    for (int i = 1; i < n; i++)
    {
        f >> element;
        if (max_heap.size() > min_heap.size())
        {
            if (element < median)
            {
                double val = max_heap.top();
                max_heap.pop();
                min_heap.push(val);
                max_heap.push(element);
            }
            else
            {
                min_heap.push(element);
            }
            median = (max_heap.top() + min_heap.top()) / 2;
        }
        else 
            if (max_heap.size() < min_heap.size())
            {
                if (element > median)
                {
                    double val = min_heap.top();
                    min_heap.pop();
                    max_heap.push(val);
                    min_heap.push(element);
                }
                else
                {
                    max_heap.push(element);
                }
                median = (max_heap.top() + min_heap.top()) / 2;
            }
            else
            {
                if (element < median)
                {
                    max_heap.push(element);
                    median = max_heap.top();
                }
                else
                {
                    min_heap.push(element);
                    median = min_heap.top();
                }
            }
        std::cout << median << " ";
    }
}

int main()
{
    Median();
    return 0;
}

//Complexitate O(n)

#include <iostream>

struct COADA {
    int* DATA;
    int  size_max = 5;
    int begin = 0;
    int end = 0;
    bool FULL()
    {
        if ((end + 1 == begin && begin != 0) || (end == size_max - 1 && begin == 0))
            return true;
        return false;
    }
    void PUSH(int element)
    {
        if (FULL() == false)
        {
            DATA[end] = element;
            if (end < size_max - 1)
            {
                end++;
            }
            else
            {
                end = 0;
            }
        }
    }

    void POP()
    {
        if (begin < size_max - 1)
        {
            begin++;
        }
        else begin = 0;
    }

    bool EMPTY()
    {
        if (begin == end)
            return true;
        return false;
    }

    int FRONT()
    {
        if (EMPTY() == false)
        {
            return DATA[begin];
        }
    }

    void CLEAR()
    {
        while (EMPTY() == false)
        {
            POP();
        }
    }
};

int main()
{
    COADA C;
    int n;
    std::cin >> n;
    while (n >= C.size_max)
    {
        std::cout << "Introduceti alta valoare pt n." << std::endl;
        std::cin >> n;
    }
    C.DATA = new int[n]();
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        C.PUSH(x);
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << C.FRONT() << " ";
        C.POP();
    }
    return 0;
}


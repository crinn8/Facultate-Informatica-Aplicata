//Complexitate O(n) - n=nr paranteze

#include <iostream>
#include <stack>
#include <fstream>

int Prioritate(char c)
{
    int ok = 3;
    if (c == '(' || c == ')')
        ok = 1;
    else if (c == '[' || c == ']')
        ok = 2;
    return ok;
}

bool Pereche(char p1, char p2)
{
    if (p1 == '(' && p2 == ')')
        return true;
    if (p1 == '[' && p2 == ']')
        return true;
    if (p1 == '{' && p2 == '}')
        return true;
    return false;
}

bool VerificareParantezare(std::stack <char> stiva)
{
    std::ifstream f("paranteze.in");
    char c;
    int aux = 0;
    while (f >> c)
    {
        if (stiva.empty() == true)
        {
            if (c == ')' || c == ']' || c == '}')
                return false;
            else
            {
                stiva.push(c);
                aux = 0;
            }
        }
        else
            if (c == '(' || c == '[' || c == '{')
            {
                if (Prioritate(c) >= Prioritate(stiva.top()))
                    return false;
                stiva.push(c);
            }
            else
            {
                int p = Prioritate(c);
                char element = stiva.top();
                stiva.pop();
                if (Pereche(element, c) == false)
                    return false;
                if (c == ']' && aux != 1)
                    return false;
                if (c == '}' && aux != 2)
                    return false;
                if (p > aux)
                {
                    aux = p;
                }
            }
    }
    if (stiva.empty() == false)
        return false;
    return true;
}

int main()
{
    std::stack <char> stiva;
    if (VerificareParantezare(stiva) == true)
    {
        std::cout << "Sirul este corect.";
    }
    else
    {
        std::cout << "Sirul este gresit.";
    }
}


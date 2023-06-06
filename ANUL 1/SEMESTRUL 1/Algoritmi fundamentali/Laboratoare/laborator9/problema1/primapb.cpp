#include <iostream>
#include <algorithm>

void citireVectori(int &dim, int array[])
{
    std::cout << "Dimensiune array: ";
    std::cin >> dim;
    std::cout << "Elemente: ";
    for (int index = 0; index < dim; index++)
    {
        std::cin >> array[index];
    }
}

int main()
{
    int skii[100], copii[100], dim,suma_diferente=0;
    citireVectori(dim, skii);
    citireVectori(dim, copii);
    std::sort(skii, skii + dim);
    std::sort(copii, copii + dim);
    for (int i = 0; i < dim; i++)
    {
        suma_diferente += abs(skii[i] - copii[i]);
        std::cout << "Skii-urile de lunfime " << skii[i] << " sunt repartizate copilului de inaltime " << copii[i] << std::endl;
    }
    std::cout << "Suma diferentelor este: " << suma_diferente;
    return 0;
}

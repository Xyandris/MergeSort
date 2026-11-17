#include <iostream>
#include "MergeSort.h"

int main()
{
    // Tablica int.
    int tablica[] = {5, 2, 8, 1, 3};

    // Algorytm dla tablicy int.
    MergeSort<int> sortowanie;
    sortowanie.sortuj(tablica, 5);
    for (int i = 0; i < 5; i++)
    {
        std::cout << tablica[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

#include <iostream>
#include "MergeSort.h"

int main()
{
    // Tablica i odpowiedni typ sortowania.
    int liczbyInt[] = {8, -3, 5, 1, 5, 0};
    double liczbyDouble[] = {3.5, -1.25, 0.0, 2.75, -1.25};
    int rozmiarInt = sizeof(liczbyInt) / sizeof(liczbyInt[0]);
    int rozmiarDouble = sizeof(liczbyDouble) / sizeof(liczbyDouble[0]);

    MergeSort<int> sortowanieInt;
    MergeSort<double> sortowanieDouble;

    std::cout << "int przed: ";
    for (int i = 0; i < rozmiarInt; i++)
    {
        std::cout << liczbyInt[i] << " ";
    }
    std::cout << "\n";

    // Sortowanie zmienia kolejnosc elementow w przekazanej tablicy.
    sortowanieInt.sortuj(liczbyInt, rozmiarInt);

    std::cout << "int po: ";
    for (int i = 0; i < rozmiarInt; i++)
    {
        std::cout << liczbyInt[i] << " ";
    }
    std::cout << "\n";

    std::cout << "double przed: ";
    for (int i = 0; i < rozmiarDouble; i++)
    {
        std::cout << liczbyDouble[i] << " ";
    }
    std::cout << "\n";

    // Działa też dla zmiennoprzecinkowych.
    sortowanieDouble.sortuj(liczbyDouble, rozmiarDouble);

    std::cout << "double po: ";
    for (int i = 0; i < rozmiarDouble; i++)
    {
        std::cout << liczbyDouble[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

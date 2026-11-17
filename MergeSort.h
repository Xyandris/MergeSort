#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

// Typ elementow sortowanej tablicy.
template <typename T>
class MergeSort
{
public:
    // Wyowałanie metody z main albo z testu.
    void sortuj(T tablica[], int rozmiar)
    {
        // Pusta tablica i pojedynczy element sa juz posortowane.
        if (rozmiar < 2)
        {
            return;
        }

        sortujZakres(tablica, 0, rozmiar - 1);
    }

private:
    // Dzielenie zakresu do pozostania 1 elementu.
    void sortujZakres(T tablica[], int lewy, int prawy)
    {
        if (lewy < prawy)
        {
            int srodek = lewy + (prawy - lewy) / 2;
            sortujZakres(tablica, lewy, srodek);
            sortujZakres(tablica, srodek + 1, prawy);
            scal(tablica, lewy, srodek, prawy);
        }
    }

    // Łączenie posortowanych częśći.
    void scal(T tablica[], int lewy, int srodek, int prawy)
    {
        int rozmiarLewej = srodek - lewy + 1;
        int rozmiarPrawej = prawy - srodek;

        // Vectory jak tablice pomocnicze
        std::vector<T> lewa(rozmiarLewej);
        std::vector<T> prawa(rozmiarPrawej);

        for (int i = 0; i < rozmiarLewej; i++)
        {
            lewa[i] = tablica[lewy + i];
        }
        for (int j = 0; j < rozmiarPrawej; j++)
        {
            prawa[j] = tablica[srodek + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = lewy;

        // Z dwoch pierwszych dostepnych liczb wybieramy mniejsza.
        while (i < rozmiarLewej && j < rozmiarPrawej)
        {
            if (lewa[i] <= prawa[j])
            {
                tablica[k] = lewa[i];
                i++;
            }
            else
            {
                tablica[k] = prawa[j];
                j++;
            }
            k++;
        }

        // Przepisanie elementów z pozostałej lewej części
        while (i < rozmiarLewej)
        {
            tablica[k] = lewa[i];
            i++;
            k++;
        }

        // Przepisanie elementów z pozostałej prawej części
        while (j < rozmiarPrawej)
        {
            tablica[k] = prawa[j];
            j++;
            k++;
        }
    }
};

#endif

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

// Oznaczenie typu elementow sortowanej tablicy.
template <typename T>
class MergeSort
{
public:
    //  Metoda wywolywana z main albo z testu.
    void sortuj(T tablica[], int rozmiar)
    {

        sortujZakres(tablica, 0, rozmiar - 1);
    }

private:
    // Dzielenie zakresu do pojedynczych elementów
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

    // Łązczenie posortowanych czesci tablicy.
    void scal(T tablica[], int lewy, int srodek, int prawy)
    {
        int rozmiarLewej = srodek - lewy + 1;
        int rozmiarPrawej = prawy - srodek;

        // Vectory jako tablice pomocnicze.
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

        // Wybieranie mniejszej liczby
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

        // Przespisanie elementów z lewej części
        while (i < rozmiarLewej)
        {
            tablica[k] = lewa[i];
            i++;
            k++;
        }

        // Przepisanie elementów z prawej części
        while (j < rozmiarPrawej)
        {
            tablica[k] = prawa[j];
            j++;
            k++;
        }
    }
};

#endif

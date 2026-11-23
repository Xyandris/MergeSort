#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

// T oznacza typ elementow sortowanej tablicy.
template <typename T>
class MergeSort
{
public:
    // To jest metoda wywolywana z main albo z testu.
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
    // Dzielimy zakres tak dlugo, az zostanie w nim jeden element.
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

    // Laczymy dwie juz posortowane czesci tablicy.
    void scal(T tablica[], int lewy, int srodek, int prawy)
    {
        int rozmiarLewej = srodek - lewy + 1;
        int rozmiarPrawej = prawy - srodek;

        // Vectory sa tu zwyklymi tablicami pomocniczymi.
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

        // Przepisujemy elementy, ktore zostaly w lewej czesci.
        while (i < rozmiarLewej)
        {
            tablica[k] = lewa[i];
            i++;
            k++;
        }

        // To samo robimy z reszta prawej czesci.
        while (j < rozmiarPrawej)
        {
            tablica[k] = prawa[j];
            j++;
            k++;
        }
    }
};

#endif

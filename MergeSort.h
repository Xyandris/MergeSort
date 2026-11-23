/**
 * @file MergeSort.h
 * @brief Szablon klasy sortujacej tablice przez scalanie.
 */
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>

/**
 * @brief Sortuje tablice rosnaco algorytmem MergeSort.
 * @tparam T Typ elementow, np. int, double, float lub long int.
 *
 * Typ musi obslugiwac kopiowanie, domyslne tworzenie oraz operator <=.
 * Dla liczb zmiennoprzecinkowych zakladamy wartosci bez NaN.
 */
template <typename T>
class MergeSort
{
public:
    /**
     * @brief Sortuje elementy w przekazanej tablicy.
     * @param tablica Tablica zmieniana w miejscu; dla rozmiaru 0 moze byc nullptr.
     * @param rozmiar Liczba elementow tablicy.
     * @pre Rozmiar jest nieujemny. Dla rozmiaru dodatniego tablica wskazuje
     *      na co najmniej rozmiar poprawnych elementow typu T.
     * @note Dla pustej tablicy i jednego elementu funkcja od razu konczy prace.
     * @note Czas O(n log n), dodatkowa pamiec O(n).
     */
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
    /**
     * @brief Rekurencyjnie dzieli zakres i scala jego posortowane czesci.
     * @param tablica Tablica z sortowanymi danymi.
     * @param lewy Indeks pierwszego elementu zakresu.
     * @param prawy Indeks ostatniego elementu zakresu, wlacznie.
     */
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

    /**
     * @brief Scala dwie sasiednie, rosnaco posortowane czesci.
     * @param tablica Tablica, do ktorej wpisywany jest wynik.
     * @param lewy Poczatek lewej czesci.
     * @param srodek Koniec lewej czesci; prawa zaczyna sie o jeden dalej.
     * @param prawy Koniec prawej czesci, wlacznie.
     * @note Przy rownych wartosciach jako pierwszy wybierany jest element z lewej.
     */
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

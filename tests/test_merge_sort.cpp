#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include <vector>
#include "MergeSort.h"

// Rosnaco ulozona tablica ma pozostac taka sama.
TEST(MergeSortInt, JuzRosnaco)
{
    int tablica[] = {-2, 0, 3, 7, 9};
    int oczekiwane[] = {-2, 0, 3, 7, 9};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<int> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// Odwracamy kolejnosc tablicy malejacej.
TEST(MergeSortInt, Malejaco)
{
    int tablica[] = {9, 7, 3, 0, -2};
    int oczekiwane[] = {-2, 0, 3, 7, 9};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<int> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// Sprawdzamy tablice z samymi liczbami ujemnymi.
TEST(MergeSortInt, TylkoUjemne)
{
    int tablica[] = {-4, -12, -1, -7};
    int oczekiwane[] = {-12, -7, -4, -1};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<int> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// Zero oraz liczby obu znakow musza trafic na dobre miejsca.
TEST(MergeSortInt, UjemneIDodatnie)
{
    int tablica[] = {4, -2, 7, -8, 0};
    int oczekiwane[] = {-8, -2, 0, 4, 7};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<int> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// Stale ziarno pozwala odtworzyc ten sam test przy kolejnym uruchomieniu.
TEST(MergeSortInt, LosowaTablica)
{
    const int rozmiar = 50;
    int tablica[rozmiar];
    std::mt19937 generator(12345);
    std::uniform_int_distribution<int> losuj(-100, 100);

    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = losuj(generator);
    }
    std::vector<int> oczekiwane(tablica, tablica + rozmiar);
    // std::sort jest wzorcem tylko w testach, a nie implementacja MergeSort.
    std::sort(oczekiwane.begin(), oczekiwane.end());

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// Sprawdzamy niezmieniona kolejnosc liczb double.
TEST(MergeSortDouble, JuzRosnaco)
{
    double tablica[] = {-2.5, 0.0, 3.25, 7.5, 9.75};
    double oczekiwane[] = {-2.5, 0.0, 3.25, 7.5, 9.75};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<double> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}

// Dla double tez sprawdzamy odwrotna kolejnosc.
TEST(MergeSortDouble, Malejaco)
{
    double tablica[] = {9.75, 7.5, 3.25, 0.0, -2.5};
    double oczekiwane[] = {-2.5, 0.0, 3.25, 7.5, 9.75};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<double> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}

// Ujemne ulamki sortujemy wedlug ich wartosci.
TEST(MergeSortDouble, TylkoUjemne)
{
    double tablica[] = {-4.5, -12.25, -1.5, -7.75};
    double oczekiwane[] = {-12.25, -7.75, -4.5, -1.5};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<double> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}

// Sprawdzamy double o roznych znakach.
TEST(MergeSortDouble, UjemneIDodatnie)
{
    double tablica[] = {4.5, -2.25, 7.75, -8.5, 0.0};
    double oczekiwane[] = {-8.5, -2.25, 0.0, 4.5, 7.75};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<double> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}

// Stale ziarno pozwala odtworzyc ten sam test przy kolejnym uruchomieniu.
TEST(MergeSortDouble, LosowaTablica)
{
    const int rozmiar = 50;
    double tablica[rozmiar];
    std::mt19937 generator(12345);
    std::uniform_real_distribution<double> losuj(-100.0, 100.0);

    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = losuj(generator);
    }
    std::vector<double> oczekiwane(tablica, tablica + rozmiar);
    // std::sort jest wzorcem tylko w testach, a nie implementacja MergeSort.
    std::sort(oczekiwane.begin(), oczekiwane.end());

    MergeSort<double> sortowanie;
    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}


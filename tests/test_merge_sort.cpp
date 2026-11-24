/**
 * @file test_merge_sort.cpp
 * @brief Testy jednostkowe MergeSort w Google Test.
 *
 * Wymagane przypadki sa sprawdzane osobno dla int i double.
 * Dwa dodatkowe testy sprawdzaja float oraz long int.
 */
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

// Pusty vector reprezentuje tablice o zerowej liczbie elementow.
TEST(MergeSortInt, PustaTablica)
{
    std::vector<int> tablica;
    MergeSort<int> sortowanie;

    EXPECT_NO_THROW(sortowanie.sortuj(tablica.data(), 0));
    EXPECT_TRUE(tablica.empty());
}

// Jeden element nie wymaga zadnego przestawiania.
TEST(MergeSortInt, JedenElement)
{
    int tablica[] = {7};
    int oczekiwane[] = {7};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<int> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// Powtarzajace sie wartosci nie moga zniknac.
TEST(MergeSortInt, Duplikaty)
{
    int tablica[] = {4, 2, 4, 1, 2, 4};
    int oczekiwane[] = {1, 2, 2, 4, 4, 4};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<int> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// Duplikaty wystepuja tez w tablicy ujemnej.
TEST(MergeSortInt, UjemneZDuplikatami)
{
    int tablica[] = {-3, -1, -3, -7, -1};
    int oczekiwane[] = {-7, -3, -3, -1, -1};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<int> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// Laczymy oba znaki, zero i duplikaty.
TEST(MergeSortInt, MieszaneZDuplikatami)
{
    int tablica[] = {3, -2, 0, 3, -2, 1};
    int oczekiwane[] = {-2, -2, 0, 1, 3, 3};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<int> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// Dwa elementy rosnaco maja pozostac na swoich miejscach.
TEST(MergeSortInt, DwaElementyRosnaco)
{
    int tablica[] = {2, 5};
    int oczekiwane[] = {2, 5};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<int> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// 150 elementow spelnia warunek tablicy wiekszej niz 100.
TEST(MergeSortInt, PonadStoElementow)
{
    const int rozmiar = 150;
    int tablica[rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = rozmiar - i;
    }

    MergeSort<int> sortowanie;
    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], i + 1);
    }
}

// W tej duzej tablicy sa liczby obu znakow, zera i duplikaty.
TEST(MergeSortInt, PonadStoMieszanychZDuplikatami)
{
    const int rozmiar = 150;
    int tablica[rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = (i * 17) % 41 - 20;
    }
    std::vector<int> oczekiwane(tablica, tablica + rozmiar);
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

// Pusty vector reprezentuje tablice o zerowej liczbie elementow.
TEST(MergeSortDouble, PustaTablica)
{
    std::vector<double> tablica;
    MergeSort<double> sortowanie;

    EXPECT_NO_THROW(sortowanie.sortuj(tablica.data(), 0));
    EXPECT_TRUE(tablica.empty());
}

// Pojedynczy double zachowuje swoja wartosc.
TEST(MergeSortDouble, JedenElement)
{
    double tablica[] = {7.25};
    double oczekiwane[] = {7.25};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<double> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}

// Sprawdzamy liczbe wystapien powtarzajacych sie ulamkow.
TEST(MergeSortDouble, Duplikaty)
{
    double tablica[] = {4.5, 2.25, 4.5, 1.0, 2.25};
    double oczekiwane[] = {1.0, 2.25, 2.25, 4.5, 4.5};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<double> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}

// Ujemne liczby double moga sie powtarzac.
TEST(MergeSortDouble, UjemneZDuplikatami)
{
    double tablica[] = {-3.5, -1.25, -3.5, -7.0, -1.25};
    double oczekiwane[] = {-7.0, -3.5, -3.5, -1.25, -1.25};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<double> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}

// Sprawdzamy oba znaki i duplikaty double.
TEST(MergeSortDouble, MieszaneZDuplikatami)
{
    double tablica[] = {3.5, -2.25, 0.0, 3.5, -2.25, 1.0};
    double oczekiwane[] = {-2.25, -2.25, 0.0, 1.0, 3.5, 3.5};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<double> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}

// Dwa rosnace ulamki zostaja bez zmian.
TEST(MergeSortDouble, DwaElementyRosnaco)
{
    double tablica[] = {2.25, 5.5};
    double oczekiwane[] = {2.25, 5.5};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<double> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}

// 150 elementow spelnia warunek tablicy wiekszej niz 100.
TEST(MergeSortDouble, PonadStoElementow)
{
    const int rozmiar = 150;
    double tablica[rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = (rozmiar - i) / 2.0;
    }

    MergeSort<double> sortowanie;
    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], (i + 1) / 2.0);
    }
}

// W tej duzej tablicy sa liczby obu znakow, zera i duplikaty.
TEST(MergeSortDouble, PonadStoMieszanychZDuplikatami)
{
    const int rozmiar = 150;
    double tablica[rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = ((i * 17) % 41 - 20) / 2.0;
    }
    std::vector<double> oczekiwane(tablica, tablica + rozmiar);
    std::sort(oczekiwane.begin(), oczekiwane.end());

    MergeSort<double> sortowanie;
    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_DOUBLE_EQ(tablica[i], oczekiwane[i]);
    }
}

// Dodatkowo sprawdzamy szablon z typem float.
TEST(MergeSortInneTypy, Float)
{
    float tablica[] = {2.5f, -1.0f, 0.5f, 2.5f};
    float oczekiwane[] = {-1.0f, 0.5f, 2.5f, 2.5f};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<float> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}

// Sprawdzamy takze liczby typu long int.
TEST(MergeSortInneTypy, LongInt)
{
    long int tablica[] = {1000000L, -1000000L, 0L, 1000000L};
    long int oczekiwane[] = {-1000000L, 0L, 1000000L, 1000000L};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    MergeSort<long int> sortowanie;

    sortowanie.sortuj(tablica, rozmiar);

    for (int i = 0; i < rozmiar; i++)
    {
        EXPECT_EQ(tablica[i], oczekiwane[i]);
    }
}


#include "Sort.hpp"

// Fungsi Swapping
void Swap(larikBuku &buku, int minIndex, int i)
{
    Buku temp = buku[minIndex];
    buku[minIndex] = buku[i];
    buku[i] = temp;
}

// Fungsi untuk melakukan sort(bubble sort)
void bubbleSort(larikBuku &buku)
{
    int size = GetDataSizeBuku(buku);
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            // Bandingkan dua nama buku dan tukar jika urutan salah
            if (buku[j].namaBuku > buku[j + 1].namaBuku)
            {
                Swap(buku, j, i + 1);
            }
        }
    }
}

void selectionSort(larikBuku &bukuSort)
{
    int size = GetDataSizeBuku(bukuSort);
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (bukuSort[j].namaBuku < bukuSort[minIndex].namaBuku)
            {
                minIndex = j;
            }
        }
        // Tukar elemen terkecil dengan elemen pada indeks i
        Swap(bukuSort, minIndex, i);
    }
}

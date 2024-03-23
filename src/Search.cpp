#include "Search.hpp"
// Fungsi mencari target(std::String)
std::string getTarget(int max)
{
    std::string target;
    std::cout << "Masukkan NAMA atau NOMOR buku yang ingin dicari[Max: " << max << "]: ";
    getline(std::cin, target);
    return target;
}

// Melakukan Binary search
int BinarySearch(larikBuku &larikbuku, std::string &namaTarget)
{
    int size = GetDataSizeBuku(larikbuku);
    int left = 0;
    int right = size;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Bandingkan string menggunakan fungsi compare
        // int comparison = larikbuku[mid].namaBuku.compare(namaTarget);

        // Jika elemen tengah adalah namaTarget, kembalikan indeksnya
        if (larikbuku[mid].namaBuku == namaTarget)
        {
            return mid;
        }
        // Jika namaTarget lebih kecil, cari di setengah kanan
        else if (larikbuku[mid].namaBuku < namaTarget)
        {
            left = mid + 1;
        }
        // Jika target lebih besar, cari di setengah kiri
        else
        {
            right = mid - 1;
        }
    }

    // Jika elemen tidak ditemukan, kembalikan -1
    return -1;
}

// fungsi mengambil ukuran data buku yang tersedia dalam larik buku
int GetDataSizeBuku(larikBuku &buku)
{
    int size;
    for (int i = 0; i <= MAX_SIZE; i++)
    {
        if (buku[i].kodeBuku == "")
        {
            size = i;
            break;
        }
    }
    return size;
}

// Fungsi Mencari posisi data (INTEGER)
bool StrSearching(int pos, int size)
{
    return pos >= 0 && pos < size;
}

// (SEARCH) Fungsi Mencari buku dengan keyword perkata
void CariBuku(larikBuku &larikbuku)
{
    if (isDataEmpty(larikbuku))
    {
        return;
    }

    std::string target;
    std::cout << "Masukkan nama buku yang ingin dicari : ";
    getline(std::cin, target);
    int pos = BinarySearch(larikbuku, target);
    if (pos != -1)
    {
        Buku readBuku = readDataBuku(larikbuku, pos);
        DisplayOnceBuku(readBuku);
    }
    else
    {
        std::cout << "nama buku \"" << target << "\" tidak ketemu" << std::endl;
    }
}

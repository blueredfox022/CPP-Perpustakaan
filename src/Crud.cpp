#include "Crud.hpp"
#include "Sort.hpp"

// Fungsi Menyimpan data baru ke data buku
void WritedataBuku(larikBuku &buku, int posisi, Buku &inputBuku)
{
    buku[posisi].kodeBuku = inputBuku.kodeBuku;
    buku[posisi].namaBuku = inputBuku.namaBuku;
    buku[posisi].namaPenulisBuku = inputBuku.namaPenulisBuku;
    buku[posisi].penerbit = inputBuku.penerbit;
    buku[posisi].tahunTerbit = inputBuku.tahunTerbit;
}

// Fungsi Membuat kode buku
std::string CreatKodeBuku(std::string &nama, std::string &penulis, std::string &penerbit, int tahun)
{

    return nama.substr(0, 2) + penulis.substr(0, 2) + penerbit.substr(0, 2) + std::to_string(tahun).substr(2, 2);
}

// (CREATE) Fungsi menambahkan Buku
void TambahBuku(larikBuku &buku)
{
    Buku inputBuku;
    int size = GetDataSizeBuku(buku);
    std::cout << "size : " << size << std::endl;

    std::cout << "Nama Buku : ";
    getline(std::cin, inputBuku.namaBuku);
    std::cout << "penulis Buku : ";
    getline(std::cin, inputBuku.namaPenulisBuku);
    std::cout << "Nama penerbit Buku : ";
    getline(std::cin, inputBuku.penerbit);

    inputBuku.tahunTerbit = KonvesiTahun();
    inputBuku.kodeBuku = CreatKodeBuku(inputBuku.namaBuku, inputBuku.namaPenulisBuku,
                                       inputBuku.penerbit, inputBuku.tahunTerbit);

    WritedataBuku(buku, size, inputBuku);
    std::cout << "Data baru telah disimpan!" << std::endl;
}

// Fungsi Mengambil data buku untuk dibaca
Buku readDataBuku(larikBuku &buku, int index)
{
    Buku readBuku;
    readBuku.kodeBuku = buku[index].kodeBuku;
    readBuku.namaBuku = buku[index].namaBuku;
    readBuku.namaPenulisBuku = buku[index].namaPenulisBuku;
    readBuku.penerbit = buku[index].penerbit;
    readBuku.tahunTerbit = buku[index].tahunTerbit;
    return readBuku;
}

bool isDataEmpty(larikBuku &bukuSize)
{
    return GetDataSizeBuku(bukuSize) <= 0;
}

// (READ)Fungsi Menampilkan semua data buku
void DisplayAllBuku(larikBuku &buku)
{
    selectionSort(buku);
    // bubbleSort(buku);
    int size = GetDataSizeBuku(buku);
    if (isDataEmpty(buku))
    {
        std::cout << "Belum ada data Buku" << std::endl;
        return;
    }
    std::cout << "|==================================================================" << std::endl;
    std::cout << "| NO | Kode buku | Nama Buku | Penulis | Penerbit | Tahun terbit | " << std::endl;
    std::cout << "|==================================================================" << std::endl;
    for (int i = 0; i < size; i++)
    {
        Buku readBuku = readDataBuku(buku, i);
        std::cout << "| " << i + 1;
        std::cout << " | " << readBuku.kodeBuku;
        std::cout << " | " << readBuku.namaBuku;
        std::cout << " | " << readBuku.namaPenulisBuku;
        std::cout << " | " << readBuku.penerbit;
        std::cout << " | " << readBuku.tahunTerbit;
        std::cout << " | " << std::endl;
    }
    std::cout << "==================================================================" << std::endl;
}

// Menampilkan satu data
void DisplayOnceBuku(Buku &buku)
{
    std::cout << "  Nama Buku:  " << buku.namaBuku << std::endl;
    std::cout << "  Kode Buku : " << buku.kodeBuku << std::endl;
    std::cout << "  Nama Penulis Buku : " << buku.namaPenulisBuku << std::endl;
    std::cout << "  Nama Penulis : " << buku.penerbit << std::endl;
    std::cout << "  Tahun Terbit : " << buku.tahunTerbit << std::endl;
}

int KonvesiTahun()
{

    std::string strTahun;
    int tahun;
inputUlang:
    std::cout << "tahun Terbit Buku |FORMAT=[XXXX]| : ";
    getline(std::cin, strTahun);
    try
    {

        tahun = stoi(strTahun);
        if (strTahun.length() != 4 || tahun > 2024)
        {
            std::cout << "Gagal Menginput tahun terbit,\nTahun terbit tidak boleh KURANG / LEBIH dari tahun sekarang[2024]" << std::endl;
            std::cout << "Masukan ulang tahun terbit" << std::endl;
            goto inputUlang;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Input tidak Valid" << std::endl;
        std::cout << "Masukan ulang tahun terbit" << std::endl;
        goto inputUlang;
    }
    return tahun;
}

// (UPDATE) Fungsi Mengedit data buku yang sudah ada
void EditBuku(larikBuku &buku)
{
    if (isDataEmpty(buku))
    {
        return;
    }

    int noTarget; // nomor target
    int pos;      // Posisi
    Buku editBuku;
    bool isvalid = false; // validasi data yang ditemukan

    // mengambil ukuran data dalam lari yang ada
    int size = GetDataSizeBuku(buku);

    // Input keyword / target yang dicari
    std::string strTarget = getTarget(size);

    // Mencari posisi target(std::String)
    pos = BinarySearch(buku, strTarget);
    if (pos != -1)
    {
        isvalid = true;
    }
    else
    {
        try
        {
            pos = stoi(strTarget) - 1; // konversi std::string ke integer
            // Mencari posisi target (Int)
            isvalid = StrSearching(pos, size);
        }
        catch (const std::exception &e)
        {
            isvalid = false;
        }
    }

    if (isvalid)
    {
        char validasiEditing;
        Buku readBuku = readDataBuku(buku, pos);
        std::string tahunStr;
        std::cout << "data buku lama" << std::endl;

        DisplayOnceBuku(readBuku);

        std::cout << "\nMengganti ke data baru lama \n"
                  << std::endl;

        std::cout << "Nama Buku  : ";
        getline(std::cin, editBuku.namaBuku);
        std::cout << "penulis Buku : ";
        getline(std::cin, editBuku.namaPenulisBuku);
        std::cout << "Nama penerbit Buku : ";
        getline(std::cin, editBuku.penerbit);

        editBuku.tahunTerbit = KonvesiTahun();
        editBuku.kodeBuku = CreatKodeBuku(editBuku.namaBuku, editBuku.namaPenulisBuku,
                                          editBuku.penerbit, editBuku.tahunTerbit);

        std::cout << "anda yang ingin mengganti(Y/N)?: ";
        std::cin >> validasiEditing;
        if (validasiEditing == 'y')
        {
            WritedataBuku(buku, pos, editBuku);
            std::cout << "Berhasil mengganti data buku!!!" << std::endl;
        }
        else
        {
            std::cout << "Gagal mengganti data buku" << std::endl;
        }
    }
    else
    {
        std::cout << "Nama atau Nomor buku \"" << strTarget << "\" tidak ada!!!" << std::endl;
    }
}

// Fungsi Preoses Menghapus data buku yang diinput
void DeletingData(larikBuku &buku, int pos)
{
    char validasiEditing;
    Buku tempBuku, blankBuku;
    larikBuku larikTemp;
    int size = GetDataSizeBuku(buku);
    // WritedataBuku(buku, pos, blankBuku);
    int tempIndex = 0;
    for (int i = pos; i < size; i++)
    {
        tempBuku = readDataBuku(buku, i + 1);

        WritedataBuku(buku, i, tempBuku);
        tempIndex++;
    }
}

// (DELETE) Fugsi Menghapus data buku yang ada
void HapusBuku(larikBuku &buku)
{
    if (isDataEmpty(buku))
    {
        return;
    }

    bool isKetemu;
    // Mengambil ukuran data
    int size = GetDataSizeBuku(buku);

    // Input keyword / target yang dicari
    std::string strTarget = getTarget(size);

    // Mencari posisi target(std::String)
    int pos = BinarySearch(buku, strTarget);
    if (pos != -1)
    {
        isKetemu = true;
    }
    else
    {
        try
        {
            pos = stoi(strTarget) - 1; // konversi std::string ke integer
            // Mencari posisi target (Int)
            isKetemu = StrSearching(pos, size);
        }
        catch (const std::exception &e)
        {
            isKetemu = false;
        }
    }

    if (isKetemu)
    {
        char validasiDeleting;
        Buku readBuku = readDataBuku(buku, pos);

        // menampilkan data yang akana dihapus
        std::cout << "data buku yang akan dihapus" << std::endl;
        DisplayOnceBuku(readBuku);

        // validasi penghapusan data
        std::cout << "anda yang ingin mengganti(Y/N)?: ";
        std::cin >> validasiDeleting;
        if (validasiDeleting == 'y')
        {
            DeletingData(buku, pos);

            std::cout << "Berhasil Menghapus data buku" << std::endl;
        }
        else
        {
            std::cout << "Gagal Menghapus data buku" << std::endl;
        }
    }
    else
    {
        std::cout << "Nama atau Nomor buku \"" << strTarget << "\" tidak ada!!!" << std::endl;
    }
}

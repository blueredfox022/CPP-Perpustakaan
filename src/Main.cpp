#include "Crud.hpp"
#include "Sort.hpp"
#include "Search.hpp"
#include "Transaksi.hpp"

using namespace std;

int Menu();

void DataAwal(larikBuku &bukuAwal)
{

    bukuAwal[0].namaBuku = "Lakar Pelangi";
    bukuAwal[0].namaPenulisBuku = "Andrea Hirata";
    bukuAwal[0].penerbit = "Bentang Pustaka";
    bukuAwal[0].tahunTerbit = 2005;
    bukuAwal[0].kodeBuku = "LaAnbe05";

    bukuAwal[1].namaBuku = "Negeri 5 Negara";
    bukuAwal[1].namaPenulisBuku = "Ahmad Fuadi";
    bukuAwal[1].penerbit = "Gramedia";
    bukuAwal[1].tahunTerbit = 2009;
    bukuAwal[1].kodeBuku = "NeAhGr09";

    bukuAwal[2].namaBuku = "Casino Royale";
    bukuAwal[2].namaPenulisBuku = "Lan Fleming";
    bukuAwal[2].penerbit = "Jonathan cape";
    bukuAwal[2].tahunTerbit = 1953;
    bukuAwal[2].kodeBuku = "CaLaJo53";
}
int main()
{

    larikBuku buku;
    DataAwal(buku);

    char kembali;
    int menu;

    // Enumerasi menu
    enum MENU
    {
        PINJAM = 1,
        READ,
        SEARCH,
        CREATE,
        UPATE,
        HAPUS
    };
    do
    {
        system("cls");
        menu = Menu();
        switch (menu)
        {
        case PINJAM:
            // cout << "Pinjam Buku" << endl;
            system("cls");
            Transaksi(buku);
            break;
        case READ:
            // cout << "Tampilkan Semua buku" << endl;
            system("cls");
            DisplayAllBuku(buku);
            break;
        case SEARCH:
            // cout << "Cari buku" << endl;
            system("cls");
            DisplayAllBuku(buku);
            CariBuku(buku);
            break;
        case CREATE:
            system("cls");
            cout << "Tambah buku baru" << endl;
            TambahBuku(buku);
            break;
        case UPATE:
            // cout << "Edit buku" << endl;
            system("cls");
            DisplayAllBuku(buku);
            EditBuku(buku);
            break;
        case HAPUS:
            cout << "Hapus buku" << endl;
            DisplayAllBuku(buku);
            HapusBuku(buku);
            break;

        default:
            break;
        }
        if (menu != 0)
        {

            cout << "ingin Kembali(Y/N)? : ";
            cin >> kembali;
        }
    } while (kembali == 'y' && menu != 0);
    return 0;
}

// Fungsi Menu
int Menu()
{
    string pilihan;
    int pil;

    cout << "|=======================================|" << endl;
    cout << "|--------* PERPUSTAKAAN BAROKAH* -------|" << endl;
    cout << "|=======================================|" << endl;
    cout << "| 1. Pinjam Buku" << endl;
    cout << "| 2. Tampilkan Semua Buku" << endl;
    cout << "| 3. Cari Buku" << endl;
    cout << "| 4. Tambah Buku" << endl;
    cout << "| 5. Edit Buku" << endl;
    cout << "| 6. hapus Buku" << endl;
    cout << "| 0. Keluar" << endl;
    cout << "|=======================================|" << endl;
Ulang:
    cout << "| Silahkan Pilih: ";
    cin >> pilihan;
    try
    {
        pil = stoi(pilihan);
        if (pil < 0 || pil > 7)
        {

            cerr << "Input tidak Boleh Lebih dari 6 !!" << endl;
            goto Ulang;
        }
    }
    catch (const std::exception &e)
    {
        cerr << "Input tidak valid!!" << endl;
        goto Ulang;
    }

    cin.ignore();

    return pil;
}

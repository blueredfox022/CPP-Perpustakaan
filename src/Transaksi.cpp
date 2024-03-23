#include "Transaksi.hpp"

// Fungsi mengambil nama hari
std::string getHari(int weekday)
{
    std::string days[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    return days[weekday];
}

// Fungsi Mengambil Waktu tertentu
Waktu Getwaktu(int i)
{
    Waktu readWaktu;

    auto time = std::chrono::system_clock::now() + std::chrono::hours(24 * (i));
    std::time_t t_time = std::chrono::system_clock::to_time_t(time);
    std::tm *local_time = std::localtime(&t_time);
    readWaktu.tanggal = local_time->tm_mday;
    readWaktu.bulan = local_time->tm_mon + 1;
    readWaktu.tahun = local_time->tm_year + 1900;
    int weekday = local_time->tm_wday; // Hari dalam seminggu dimulai dari 0 (Minggu)
    readWaktu.hari = getHari(weekday);

    return readWaktu;
}

// Fngusi Memilih batas Waktu peminjaman
int PilihTanggal()
{
    int Wpengembalian;
    std::cout << "-    BATAs WAKTU PEMINJAMAN " << std::endl;
    // Melakukan loop untuk 7 hari ke depan
    for (int i = 1; i <= 7; ++i)
    {
        Waktu waktuSekarang = Getwaktu(i);

        // Menampilkan informasi tanggal untuk setiap hari
        std::cout << i << ". " << waktuSekarang.hari << ", " << waktuSekarang.tanggal << "/" << waktuSekarang.bulan << "/" << waktuSekarang.tahun << std::endl;
    }

    std::cout << "Pilih waktu pengembalian Buku : ";
    std::cin >> Wpengembalian;

    return Wpengembalian;
}

// Fungsi input data Peminjam
void inputDataPeminjam(Peminjam &peminjam)
{
    std::cout << "========================================" << std::endl;
    std::cout << "      MEMASUKKAN DATA PEMINJAM          " << std::endl;
    std::cout << "Nama Peminjam : ";
    getline(std::cin, peminjam.namaPeminjam);

    std::cout << "Nomor HP : ";
    std::cin >> peminjam.nomorHP;
    std::cin.ignore();

    peminjam.WaktuPinjam = Getwaktu(0);
    int batasPinjam = PilihTanggal();
    peminjam.batasPinjam = Getwaktu(batasPinjam);
    std::cout << peminjam.batasPinjam.hari << ", "
              << peminjam.batasPinjam.tanggal << "/"
              << peminjam.batasPinjam.bulan << "/"
              << peminjam.batasPinjam.tahun << std::endl;
}

// (READ) Fungsi menampilkan data peminjaan buku
void DisplayPeminjaman(Peminjam &peminjam)
{
    system("cls");

    std::cout << "==================================================" << std::endl;
    std::cout << "===========* NOTA PEMINJAMAN BUKU *===============" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "  Nama Peminjam : " << peminjam.namaPeminjam << std::endl;
    std::cout << "  Nomor HP : " << peminjam.nomorHP << std::endl;
    std::cout << "  Tanggal Pinjam : "
              << peminjam.WaktuPinjam.hari << ", "
              << peminjam.WaktuPinjam.tanggal << "/"
              << peminjam.WaktuPinjam.bulan << "/"
              << peminjam.WaktuPinjam.tahun << std::endl;
    std::cout << "  Batas Pinjam : "
              << peminjam.batasPinjam.hari << ", "
              << peminjam.batasPinjam.tanggal << "/"
              << peminjam.batasPinjam.bulan << "/"
              << peminjam.batasPinjam.tahun << std::endl;

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "  Buku yang dipinjam : " << std::endl;
    Buku readBuku = peminjam.bukuPinjam;
    DisplayOnceBuku(readBuku);
    std::cout << "==================================================" << std::endl;
}

// (MINIGAME)Fungsi untuk menghasilkan bilangan bulat acak antara min dan max
int SoalanKuis(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// (MINIGAME) Jawaban Kuis
int jawabanKuis(int a, int b, char operasi)
{
    int hasil;
    if (operasi == '+')
    {
        hasil = a + b;
    }
    else if (operasi == '-')
    {
        hasil = a - b;
    }
    else if (operasi == '*')
    {
        hasil = a * b;
    }
    // Tambahkan jenis operasi matematika lain di sini sesuai kebutuhan
    return hasil;
}

// (MINIGAME) Fungsi Kuis minigame
bool Kuis()
{
    srand(time(0));

    // Menghasilkan dua bilangan bulat acak antara 1 dan 100
    int soalA = SoalanKuis(1, 100);
    int soalB = SoalanKuis(1, 100);
    char operasi = "+-*/"[rand() % 4]; // Memilih operasi secara acak
    int jawaban;

    std::cout << "Berapakah hasil dari " << soalA << " " << operasi << " " << soalB << "? : ";
    std::cin >> jawaban;

    // Memeriksa jawaban yang benar
    int hasil = jawabanKuis(soalA, soalB, operasi);

    if (jawaban == hasil)
    {
        std::cout << "Jawaban Anda benar!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Maaf, jawaban Anda salah, jawabannya= " << hasil << std::endl;
        return false;
    }
    return false;
}

// FUNGSI UTAMA PEMINJAMAN BUKU
void Transaksi(larikBuku &buku)
{
    Peminjam peminjam;
    std::cout << "==================================================" << std::endl;
    std::cout << "================* MEMINJAM BUKU *=================" << std::endl;
    std::cout << "==================================================" << std::endl;

    DisplayAllBuku(buku);
    bool isvalid;
    int size = GetDataSizeBuku(buku);
    std::string pilihBuku = getTarget(size);

    // Mencari posisi target(std::String)
    int pos = BinarySearch(buku, pilihBuku);
    if (pos != -1)
    {
        isvalid = true;
    }
    else
    {
        try
        {
            pos = stoi(pilihBuku) - 1; // konversi std::string ke integer
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
        char jadiPinjam;
        Buku readBuku = readDataBuku(buku, pos);
        peminjam.bukuPinjam = readBuku;
        std::cout << "\nBuku tersedia" << std::endl;
        DisplayOnceBuku(readBuku);
        inputDataPeminjam(peminjam);
        DisplayPeminjaman(peminjam);

        std::cout << "NOTA PEMINJAMAN AKAN SEGERAN DI PRINT!!\n"
                  << "Yakin ingin meminjam(Y/N) : ";
        std::cin >> jadiPinjam;
        if (jadiPinjam != 'y')
        {
            return;
        }
        system("cls");
        int poin = 0;
        std::cout << "ANDA HARUS MENJAWAB 3 SOAl KUIS BISA PINJAM BUKU!!" << std::endl;
        std::cout << "\nSILAHKAN JAWAB PERTANYAAN DIBAWAH!!" << std::endl;
        while (poin < 3)
        {
            if (Kuis())
            {
                poin++;
                std::cout << "poin = " << poin << std::endl;
            }

            std::cout << "Lanjut ke soal berikutnya" << std::endl;
        }
        std::cout << "ANDA BERHASIL MENJAWAB" << std::endl;
        std::cout << "TUNGGU SEBENTAR UNTUK MENDPATKAN PEMINJAMAN BUKU" << std::endl;
        std::cout << "\t\tLoading...." << std::endl;
        Sleep(2000);
        DeletingData(buku, pos);
        DisplayPeminjaman(peminjam);
        std::cout << "TERIMA KASIH TELAH MEMINJAM DI PERPUS BAROKAH!! :)" << std::endl;
    }
    else
    {
        std::cout << "Nama atau Nomor buku \"" << pilihBuku << "\" tidak ada!!!" << std::endl;
    }
}

#ifndef TRANSAKSI_HPP
#define TRANSAKSI_HPP
#include "Crud.hpp"
#include "Sort.hpp"
#include "Search.hpp"
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <windows.h>

typedef struct
{
    std::string hari;
    int tanggal;
    int bulan;
    int tahun;
} Waktu;

typedef struct
{
    std::string namaPeminjam;
    int nomorHP;
    Buku bukuPinjam;
    Waktu WaktuPinjam;
    Waktu batasPinjam;

} Peminjam;

// Mendapatkan nama hari
std::string getHari(int weekday);
Waktu Getwaktu(int i);
int PilihTanggal();
void inputDataPeminjam(Peminjam &peminjam);
void DisplayPeminjaman(Peminjam &peminjam);
int SoalanKuis(int min, int max);
int jawabanKuis(int a, int b, char operasi);
bool Kuis();
void Transaksi(larikBuku &buku);
#endif
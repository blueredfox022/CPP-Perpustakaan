#ifndef CRUD_HPP
#define CRUD_HPP
#include <iostream>
#include <string>
#include <algorithm>

typedef struct
{

    std::string kodeBuku; // pk
    std::string namaBuku;
    std::string namaPenulisBuku;
    std::string penerbit;
    int tahunTerbit;
} Buku;

const int MAX_SIZE = 10;
typedef Buku larikBuku[MAX_SIZE];

// CREATE
void WritedataBuku(larikBuku &buku, int posisi, Buku &inputBuku);
std::string CreatKodeBuku(std::string &nama, std::string &penulis, std::string &penerbit, int tahun);
void TambahBuku(larikBuku &buku);

// READ
Buku readDataBuku(larikBuku &buku, int index);
bool isDataEmpty(larikBuku &bukuSize);
void DisplayAllBuku(larikBuku &buku);
void DisplayOnceBuku(Buku &buku);

// UPDATE
int KonvesiTahun();
void EditBuku(larikBuku &buku);

// DELETE
void DeletingData(larikBuku &buku, int pos);
void HapusBuku(larikBuku &buku);

#endif
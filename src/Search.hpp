#ifndef SEARCH_HPP
#define SEARCH_HPP
#include "Crud.hpp"
// SEARCH
std::string getTarget(int max);
int BinarySearch(larikBuku &larikbuku, std::string &namaTarget); // Metode 2
int GetDataSizeBuku(larikBuku &buku);                            // Metode 1
bool StrSearching(int pos, int size);
void CariBuku(larikBuku &larikbuku);
#endif
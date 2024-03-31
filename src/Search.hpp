// Search.hpp
#ifndef SEARCH_HPP
#define SEARCH_HPP
#include "Crud.hpp"
// SEARCH
std::string getTarget(int max);
int BinarySearch(larikBuku &larikbuku, std::string &namaTarget); // Metode 1
int GetDataSizeBuku(larikBuku &buku);
bool StrSearching(int pos, int size); // Metode 2
void CariBuku(larikBuku &larikbuku);
#endif
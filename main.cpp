#include "Doublylist.h"
#include <iostream>

using namespace std;

bool cekNopol(List L, string nopol) {
  infotype x;
  x.nopol = nopol;

  return findElem(L, x) != nullptr;
}

bool hapusKendaraan(List &L, string nopol) {
  infotype x;
  address P;
  address Prec;

  x.nopol = nopol;

  P = findElem(L, x);

  if (P == nullptr) {
    return false;
  }

  if (P == L.First) {
    deleteFirst(L, P);
  } else if (P == L.Last) {
    deleteLast(L, P);
  } else {
    Prec = P->prev;
    deleteAfter(L, Prec, P);
  }

  dealokasi(P);

  return true;
}

int main() {
  List L;
  infotype kendaraan;
  address P;
  address hasil;

  string cari;
  string hapus;

  CreateList(L);

  for (int i = 1; i <= 4; i++) {
    cout << "masukkan nomor polisi: ";
    cin >> kendaraan.nopol;

    cout << "masukkan warna kendaraan: ";
    cin >> kendaraan.warna;

    cout << "masukkan tahun kendaraan: ";
    cin >> kendaraan.thnBuat;

    cout << endl;

    if (cekNopol(L, kendaraan.nopol)) {
      cout << "nomor polisi sudah terdaftar" << endl;
    } else {
      P = alokasi(kendaraan);
      insertLast(L, P);
    }

    cout << endl;
  }

  cout << "DATA LIST 1" << endl << endl;
  printInfo(L);

  cout << "\nMasukkan Nomor Polisi yang dicari : ";
  cin >> cari;

  kendaraan.nopol = cari;
  hasil = findElem(L, kendaraan);

  if (hasil != nullptr) {
    cout << "\nNomor Polisi : " << hasil->info.nopol << endl;
    cout << "Warna        : " << hasil->info.warna << endl;
    cout << "Tahun        : " << hasil->info.thnBuat << endl;
  } else {
    cout << "Data kendaraan tidak ditemukan" << endl;
  }

  cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
  cin >> hapus;

  if (hapusKendaraan(L, hapus)) {
    cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus."
         << endl;
  } else {
    cout << "Data kendaraan tidak ditemukan." << endl;
  }

  cout << "\nDATA LIST 1" << endl << endl;
  printInfo(L);

  return 0;
}

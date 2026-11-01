#include "Doublylist.h"

void CreateList(List &L) {
  L.First = nullptr;
  L.Last = nullptr;
}

address alokasi(infotype x) {
  address P = new ElmList;

  P->info = x;
  P->next = nullptr;
  P->prev = nullptr;

  return P;
}

void dealokasi(address &P) {
  delete P;
  P = nullptr;
}

void printInfo(List L) {
  address P = L.Last;

  while (P != nullptr) {
    cout << "no polisi : " << P->info.nopol << endl;
    cout << "warna     : " << P->info.warna << endl;
    cout << "tahun     : " << P->info.thnBuat << endl;

    P = P->prev;
  }
}

void insertLast(List &L, address P) {
  if (P == nullptr) {
    return;
  }

  P->next = nullptr;
  P->prev = nullptr;

  if (L.First == nullptr) {
    L.First = P;
    L.Last = P;
  } else {
    P->prev = L.Last;
    L.Last->next = P;
    L.Last = P;
  }
}

address findElem(List L, infotype x) {
  address P = L.First;

  while (P != nullptr) {
    if (P->info.nopol == x.nopol) {
      return P;
    }

    P = P->next;
  }

  return nullptr;
}

void deleteFirst(List &L, address &P) {
  if (L.First == nullptr) {
    P = nullptr;
    return;
  }

  P = L.First;

  if (L.First == L.Last) {
    L.First = nullptr;
    L.Last = nullptr;
  } else {
    L.First = L.First->next;
    L.First->prev = nullptr;
  }

  P->next = nullptr;
  P->prev = nullptr;
}

void deleteLast(List &L, address &P) {
  if (L.Last == nullptr) {
    P = nullptr;
    return;
  }

  P = L.Last;

  if (L.First == L.Last) {
    L.First = nullptr;
    L.Last = nullptr;
  } else {
    L.Last = L.Last->prev;
    L.Last->next = nullptr;
  }

  P->next = nullptr;
  P->prev = nullptr;
}

void deleteAfter(List &L, address Prec, address &P) {
  if (Prec == nullptr || Prec->next == nullptr) {
    P = nullptr;
    return;
  }

  P = Prec->next;
  Prec->next = P->next;

  if (P == L.Last) {
    L.Last = Prec;
  } else {
    P->next->prev = Prec;
  }

  P->next = nullptr;
  P->prev = nullptr;
}

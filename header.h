#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iomanip>
#include <string>

#include <iostream>
using namespace std;

#define infoP(P) (P)->infoP
#define infoC(P) (P)->infoC
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define last(L) ((L).last)
#define listC(P) ((P)->listC)


//REKAM MEDIS//
typedef struct elmRekamMedis *adrC;

struct rekam_medis{
    string IDRekamMedis;
    string jadwal_kunjungan;
    string poli;
    string diagnosa;
    string tindakan;
    string jadwal_control;
};

struct elmRekamMedis{
    rekam_medis infoC;
    adrC next;
    adrC prev;
};

struct listRekamMedis{
    adrC first;
    adrC last;
};
//Pasien//

typedef struct elmPasien *adrP;

struct pasien{
    string IDPasien;
    string namaPasien;
    string usia;
    string nomorHP;
    string alamat;
};

struct elmPasien{
    pasien infoP;
    adrP next;
    listRekamMedis listC;
};
struct listPasien{
    adrP first;
};



adrP createElmP(pasien x);
adrC createElmC(rekam_medis x);

void createListP(listPasien &LP);
void createListC(listRekamMedis &LC);

void insertFirstP(listPasien &LP, adrP P);
void insertLastP(listPasien &LP, adrP P);

void insertFirstC(listRekamMedis &LC, adrC C);
void insertLastC(listRekamMedis &LC, adrC C);
void insertAfterC(listRekamMedis &LC, adrC prec, adrC C);

void deleteFirstP(listPasien &LP, adrP P);
void deleteLastP(listPasien &LP, adrP P);
void deleteAfterP(listPasien &LP, adrP prec, adrP P);

void deleteFirstC(listRekamMedis &LC, adrC &C);
void deleteLastC(listRekamMedis &LC, adrC &C);
void deleteAfterC(listRekamMedis &LC, adrC prec, adrC &C);


void ShowAllPasien(listPasien LP);
void showAllParentsAndChildren(listPasien LP);

adrP findPasienByID(listPasien LP, string NoIDPasien);
adrC findRekamMedisByID(listRekamMedis LC, string NoIDRekamMedis);
void findPasienByPoli(listPasien LP, listRekamMedis LR, string poli);

void updateParentData(listPasien &LP, adrP P, string IDPasien,string namaPasien, string newUsia,string newnoHP, string newAlamat);
void updateChildData(listRekamMedis &LC, adrC C, string IDRekamMedis, string kunjung,string newPoli, string newDiagnosa, string newTindakan,string newJadwalControl);
int totalRekamMedis(listPasien LP, listRekamMedis LC);

void inputDataPasien(listPasien &LP, listRekamMedis &LC);
void header();
void inputDataRekamMedis(listPasien &LP, listRekamMedis &LC);

void menu();
void welcomeMessage();


#endif // HEADER_H_INCLUDED

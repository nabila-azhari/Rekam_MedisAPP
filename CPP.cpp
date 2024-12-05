#include "header.h"


adrP createElmP(pasien x) {
    adrP P = new elmPasien;
    infoP(P) = x;
    createListC(listC(P));
    next(P) = NULL;
    return P;
}


adrC createElmC(rekam_medis x) {
    adrC C = new elmRekamMedis;
    infoC(C) = x;
    next(C) = NULL;
    return C;
}

void createListP(listPasien &LP) {
    first(LP) = NULL;
}

void createListC(listRekamMedis &LC) {
    first(LC) = NULL;
    last(LC) = NULL;
}



void insertFirstP(listPasien &LP, adrP P){
    if (first(LP) == NULL){
        first(LP) = P;
    }else{
        next(P) = first(LP);
        first(LP) = P;
    }
}


void insertLastP(listPasien &LP, adrP P) {
    if (first(LP) == NULL) {
        first(LP) = P;

    } else {
        adrP Q = first(LP);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertFirstC(listRekamMedis &LC, adrC C) {
        if (first(LC) == NULL) {
            first(LC) = C;
            last(LC) = C;
        } else {
            next(C) = first(LC);
            prev(first(LC)) = C;
            first(LC) = C;
        }
}

void insertLastC(listRekamMedis &LC,adrC C){
    if (first(LC) == NULL){
        first(LC) = C;
        last(LC) = C;
    } else {
            prev(C) = last(LC);
            next(last(LC)) = C;
            last(LC) = C;
        }
}


void insertAfterC(listRekamMedis &LC, adrC prec, adrC C){
    listPasien LP;
    string parentID;
    adrP parent = findPasienByID(LP, parentID);
    if (parent == NULL) {
        cout << "Pasien dengan ID" << parentID << "tidak ditemukan"<<endl;
    } else {
        if (first(LC) == NULL){
            first(LC) = C;
        }else{
            if (next(prec) == NULL){
                next(prec) = C;
                prev(C) = prec;
                next(C) = NULL;
                last(LC) = C;
            }else if (next(prec) != NULL){
                next(C) = next(prec);
                prev(next(C)) = C;
                next(prec) = C;
                prev(C) = prec;

            }
        }
    }
}

void deleteFirstC(listRekamMedis &LC, adrC &C){
        if (first(LC) == NULL){
            cout << "LIST KOSONG" << endl;
        }else{
            C = first(LC);
            first(LC) = next(C);
            next(C) = NULL;
        }
}

void deleteLastC(listRekamMedis &LC, adrC &C){
        if (first(LC) == NULL){
            cout << "LIST KOSONG" << endl;
        }else{
            C = last(LC);
            last(LC) = prev(C);
            prev(C) = NULL;
            next(last(LC)) = NULL;

        }
}

void deleteAfterC(listRekamMedis &LC, adrC prec, adrC &C){
        if (first(LC) == NULL){
            cout << "LIST KOSONG" << endl;
        }else{
            if (next(prec) == NULL){
                cout << "Tidak ada data" <<endl;
            }else{
                C = next(prec);
                next(prec) = next(C);
                prev(next(C)) = prec;
                prev(C) = NULL;
                next(C) = NULL;
            }
        }
}




void deleteFirstP(listPasien &LP, adrP P){
    if (first(LP) == NULL) {
        cout << "List kosong" << endl;
    }else{
        P = first(LP);
        first(LP) = next(P);
        next(P) = NULL;
    }
}

void deleteLastP(listPasien &LP, adrP P){
    if (first(LP) == NULL) {
        cout << "List kosong" << endl;
    }else{
        adrP Q = first(LP);
        while (next(next(Q)) != NULL ){
            Q = next(Q);
        }
        next(Q) = NULL;
    }
}

void deleteAfterP(listPasien &LP, adrP prec, adrP P) {
    if (first(LP) == NULL) {
        cout << "List kosong" << endl;
    } else if (prec == NULL || next(prec) == NULL) {
        cout << "Tidak ada data yang dapat dihapus setelah elemen ini" << endl;
    } else {
        P = next(prec);
        next(prec) = next(P);
        next(P) = NULL;
        cout << "Elemen setelah ID Pasien " << infoP(prec).IDPasien << " berhasil dihapus." << endl;
    }
}


adrP findPasienByID(listPasien LP, string NoIDPasien){
    if (first(LP) == NULL){
        cout << "List Kosong";

    }else{
        adrP P = first(LP);
        while (P != NULL && infoP(P).IDPasien != NoIDPasien ){
                P = next(P);
        }
            return P;

    }
}

adrC findRekamMedisByID(listRekamMedis LC, string NoIDRekamMedis){
    if (first(LC) == NULL){
        cout << "List Kosong";

    }else{
        adrC C = first(LC);
        while (C != NULL && infoC(C).IDRekamMedis!= NoIDRekamMedis){
                C = next(C);
        }
            return C;

    }
}


void findPasienByPoli(listPasien LP, listRekamMedis LR, string poli) {
    if (first(LP) == NULL) {
        cout << "List Kosong" << endl;
        return;
    }

    bool pasienDitemukan = false;
    adrP P = first(LP);

    while (P != NULL) {
        adrC C = first(listC(P));
        while (C != NULL) {
            if (infoC(C).poli == poli) {
                if (!pasienDitemukan) {
                    cout << "Pasien yang memiliki rekam medis di poli " << poli << ":\n";
                    pasienDitemukan = true;
                }
                cout << "ID: " << infoP(P).IDPasien;
                cout << " Nama: " << infoP(P).namaPasien << endl;
            }
            C = next(C);
        }
        P = next(P);
    }
    if (!pasienDitemukan) {
        cout << "Tidak ada pasien yang ditemukan dengan rekam medis di poli " << poli << endl;
    }
}



void header(){
    cout << "=====================================\n";
    cout << "               DATA PASIEN           \n";
    cout << "=====================================\n";
}
void ShowAllPasien(listPasien LP) {
    if (first(LP) == NULL) {
        cout << "List Kosong" << endl;
    } else {
        adrP P = first(LP);
        cout << "==============================================================\n";
        cout << "| " << setw(10) << left << "ID Pasien"
             << "| " << setw(15) << left << "Nama Pasien"
             << "| " << setw(5) << left << "Usia"
             << "| " << setw(15) << left << "Nomor HP"
             << "| " << setw(15) << left << "Alamat" << "|\n";
        cout << "==============================================================\n";
        while (P != NULL) {
            cout << "| " << setw(10) << left << infoP(P).IDPasien
                 << "| " << setw(15) << left << infoP(P).namaPasien
                 << "| " << setw(5) << left << infoP(P).usia
                 << "| " << setw(15) << left << infoP(P).nomorHP
                 << "| " << setw(15) << left << infoP(P).alamat << "|\n";
            P = next(P);
        }
        cout << "==============================================================\n";
    }
}

void showAllParentsAndChildren(listPasien LP) {
    adrP P = first(LP);
    if (P == NULL) {
        cout << "List pasien kosong!" << endl;
        return;
    }
    while (P != NULL) {
        cout << left << setw(15) << "ID Pasien" << ": " << infoP(P).IDPasien << endl;
        cout << left << setw(15) << "Nama" << ": " << infoP(P).namaPasien << endl;
        cout << left << setw(15) << "Usia" << ": " << infoP(P).usia << endl;
        cout << left << setw(15) << "Nomor HP" << ": " << infoP(P).nomorHP << endl;
        cout << left << setw(15) << "Alamat" << ": " << infoP(P).alamat << endl;

        adrC C = first(listC(P));
        if (C == NULL) {
            cout << setw(15) << "" << "Tidak ada rekam medis untuk pasien ini." << endl;
            cout << string(50, '-') << endl;
        } else {
            cout << setw(15) << "" << "Rekam Medis:" << endl;

            while (C != NULL) {
                cout << setw(15) << "" << "------------------------------------------" << endl;
                cout << setw(15) << "" << "| " << left << setw(30) << "Rekam Medis" << " |" << endl;
                cout << setw(15) << "" << "|----------------------------------------|" << endl;
                cout << setw(15) << "" << "| ID Rekam Medis   : " << left << setw(18) << infoC(C).IDRekamMedis << " |" << endl;
                cout << setw(15) << "" << "| Poli             : " << left << setw(18) << infoC(C).poli << " |" << endl;
                cout << setw(15) << "" << "| Diagnosa         : " << left << setw(18) << infoC(C).diagnosa << " |" << endl;
                cout << setw(15) << "" << "| Tindakan         : " << left << setw(18) << infoC(C).tindakan << " |" << endl;
                cout << setw(15) << "" << "| Jadwal Kunjungan : " << left << setw(18) << infoC(C).jadwal_kunjungan << " |" << endl;
                cout << setw(15) << "" << "| Jadwal Kontrol   : " << left << setw(18) << (infoC(C).jadwal_control.empty() ? "-" : infoC(C).jadwal_control) << " |" << endl;
                cout << setw(15) << "" << "------------------------------------------" << endl;
                C = next(C);
            }
            cout << string(50, '-') << endl;
        }
        P = next(P);
        cout << endl;
    }
}


void updateParentData(listPasien &LP, adrP P, string IDPasien,string namaPasien, string newUsia,string newnoHP, string newAlamat) {
            infoP(P).IDPasien = IDPasien;
            infoP(P).namaPasien = namaPasien;
            infoP(P).usia = newUsia;
            infoP(P).nomorHP = newnoHP;
            infoP(P).alamat = newAlamat;
            cout << "Data pasien berhasil diubah!" << endl;
}

void updateChildData(listRekamMedis &LC, adrC C, string IDRekamMedis, string kunjung,string newPoli, string newDiagnosa, string newTindakan,string newJadwalControl) {
            infoC(C).IDRekamMedis = IDRekamMedis;
            infoC(C).jadwal_kunjungan = kunjung;
            infoC(C).poli = newPoli;
            infoC(C).diagnosa = newDiagnosa;
            infoC(C).tindakan = newTindakan;
            infoC(C).jadwal_control = newJadwalControl;
            cout << "Data pasien berhasil diubah!" << endl;
}
int totalRekamMedis(listPasien LP, listRekamMedis LC){
    int total = 0;
    adrP P = first(LP);
    while (P != NULL){
        adrC C = first(listC(P));
        while (C != NULL){
            total++;
            C = next(C);
        }
        P = next(P);
    }
    return total;
}


void inputDataPasien(listPasien &LP, listRekamMedis &LC) {
    adrP P;
    pasien input;
    input.IDPasien = "P001";
    input.namaPasien = "Nabila";
    input.usia = "35";
    input.nomorHP = "081234567890";
    input.alamat = "Blitar";
    P = createElmP(input);
    insertLastP(LP,P);

    input.IDPasien = "P002";
    input.namaPasien = "Jeany";
    input.usia = "60";
    input.nomorHP = "087880464";
    input.alamat = "Kalimantan Utara";
    P = createElmP(input);
    insertLastP(LP,P);

    input.IDPasien = "P003";
    input.namaPasien = "Putri";
    input.usia = "80";
    input.nomorHP = "0866903746";
    input.alamat = "Palembang";
    P = createElmP(input);
    insertLastP(LP,P);

    input.IDPasien = "P004";
    input.namaPasien = "Veli";
    input.usia = "19";
    input.nomorHP = "08489394";
    input.alamat = "Bandung";
    P = createElmP(input);
    insertLastP(LP,P);

    input.IDPasien = "P005";
    input.namaPasien = "Yola";
    input.usia = "10";
    input.nomorHP = "047830247";
    input.alamat = "Solo";
    P = createElmP(input);
    insertLastP(LP,P);

    input.IDPasien = "P006";
    input.namaPasien = "Awa";
    input.usia = "18";
    input.nomorHP = "08439024";
    input.alamat = "Bandung";
    P = createElmP(input);
    insertLastP(LP,P);

    input.IDPasien = "P007";
    input.namaPasien = "Aul";
    input.usia = "27";
    input.nomorHP = "08379204";
    input.alamat = "Bandung";
    P = createElmP(input);
    insertLastP(LP,P);

    input.IDPasien = "P008";
    input.namaPasien = "Dina";
    input.usia = "46";
    input.nomorHP = "08379202";
    input.alamat = "Makassar";
    P = createElmP(input);
    insertLastP(LP,P);
}

void inputDataRekamMedis(listPasien &LP, listRekamMedis &LC){
    adrC C;
    rekam_medis input;
    input.IDRekamMedis = "R001";
    input.jadwal_kunjungan = "2024-12-01";
    input.poli = "Gigi";
    input.diagnosa = "Flu";
    input.tindakan = "istirahat";
    input.jadwal_control = "2024-12-15";
    C = createElmC(input);
    adrP cari = findPasienByID(LP, "P001");
    insertLastC(listC(cari), C);

    input.IDRekamMedis = "R002";
    input.jadwal_kunjungan = "2024-11-20";
    input.poli = "Gigi";
    input.diagnosa = "Gigi Berlubang";
    input.tindakan = "Tambal Gigi";
    input.jadwal_control = "2024-11-27";
    C = createElmC(input);
    cari = findPasienByID(LP, "P002");
    insertLastC(listC(cari), C);

    input.IDRekamMedis = "R003";
    input.jadwal_kunjungan = "2024-12-20";
    input.poli = "Anak";
    input.diagnosa = "Demam Tinggi";
    input.tindakan = "Resep Obat";
    input.jadwal_control = "-";
    C = createElmC(input);
    cari = findPasienByID(LP, "P003");
    insertLastC(listC(cari), C);

    input.IDRekamMedis = "R004";
    input.jadwal_kunjungan = "2024-12-29";
    input.poli = "Mata";
    input.diagnosa = "Rabun Jauh";
    input.tindakan = "Kacamata";
    input.jadwal_control = "-";
    C = createElmC(input);
    cari = findPasienByID(LP, "P004");
    insertLastC(listC(cari), C);

    input.IDRekamMedis = "R005";
    input.jadwal_kunjungan = "2024-05-20";
    input.poli = "Gigi";
    input.diagnosa = "Impacted";
    input.tindakan = "Operasi";
    input.jadwal_control = "2024-06-20";
    C = createElmC(input);
    cari = findPasienByID(LP, "P005");
    insertLastC(listC(cari), C);

}
void menu() {
    cout << "=====================================\n";
    cout << "                 MENU                \n";
    cout << "=====================================\n";
    cout << "1. Tampilkan Semua Pasien\n";
    cout << "2. Tampilkan Semua Pasien dan Rekam Medis\n";
    cout << "3. Cari Pasien Berdasarkan ID\n";
    cout << "4. Cari Pasien di Poli tertentu\n";
    cout << "5. Menambahkan Data Pasien\n";
    cout << "6. Menambahkan Data Rekam Medis dengan ID Pasien Tertentu\n";
    cout << "7. Hapus Pasien\n";
    cout << "8. Hapus Rekam Medis tertentu\n";
    cout << "9. Hapus Semua Rekam Medis pada Pasien Tertentu\n";
    cout << "10. Update Data Pasien\n";
    cout << "11. Update Data Rekam Medis\n";
    cout << "12. Hitung Rekam Medis dalam DataBase\n";
    cout << "13. Keluar\n";
    cout << "=====================================\n";
    cout << endl;
    cout << "Pilih menu (1-10): ";
}


void welcomeMessage() {
    cout << "\033[1;34m********************************************\n";
    cout << "*                                          *\n";
    cout << "*        WELCOME TO THE HOSPITAL           *\n";
    cout << "*                                          *\n";
    cout << "*  \033[1;34mSelamat datang di aplikasi              *\n";
    cout << "*  \033[1;34mData Pasien & Rekam Medis               *\n";
    cout << "*  \033[1;34mManajemen data pasien, rekam medis,     *\n";
    cout << "*  \033[1;34mdan kontrol jadwal pasien dengan mudah! *" << endl;
    cout << "*                                          *\n";
    cout << "*                                          *\n";
    cout << "********************************************\n";
    cout << endl;
    cout << "\033[1;33mPilih menu untuk melanjutkan...        \n";
    cout << endl;
    cout << "\033[0m";  // Reset warna
}



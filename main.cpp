#include "header.h"

int main() {
    listPasien LP;
    listRekamMedis LC;

    createListP(LP);
    createListC(LC);

    inputDataPasien(LP, LC);
    inputDataRekamMedis(LP, LC);
    welcomeMessage();
    menu();

        int pilihan;
        cin >> pilihan;
        while (pilihan != 13){

            if (pilihan == 1) {
                header();
                ShowAllPasien(LP);


            }else if (pilihan == 2) {
                header();
                showAllParentsAndChildren(LP);


            }else if (pilihan == 3){
                header();
                string NoIDPasien;
                cout << "Masukkan ID Pasien yang ingin dicari: ";
                cin >> NoIDPasien;

                adrP pasienDitemukan = findPasienByID(LP, NoIDPasien);
                if (pasienDitemukan == NULL){
                    cout << "Pasien dengan ID " << NoIDPasien << " tidak ditemukan." << endl;}
                    if (pasienDitemukan != NULL) {
                        cout << "ID Pasien: " << infoP(pasienDitemukan).IDPasien << endl;
                        cout << "Nama Pasien: " << infoP(pasienDitemukan).namaPasien << endl;
                        cout << "Usia Pasien: " << infoP(pasienDitemukan).usia << endl;
                        cout << "Nomor HP: " << infoP(pasienDitemukan).nomorHP << endl;
                        cout << "Alamat: " << infoP(pasienDitemukan).alamat << endl;
                    }


            }else if (pilihan == 4) {
                header();
                string poli;
                cout << "Masukkan nama poli yang dicari: ";
                cin >> poli;
                findPasienByPoli(LP, LC, poli);


            }else if (pilihan ==5){
                header();
                adrP P;
                pasien input;
                cout << "ID:";
                cin >> input.IDPasien;

                cout << "Nama:";
                cin >> input.namaPasien;

                cout << "Usia:";
                cin >> input.usia;

                cout << "noHP:";
                cin >> input.nomorHP;

                cout << "alamat:";
                cin >> input.alamat;

                P = createElmP(input);
                  cout << "Anda ingin menambah di awal atau di akhir list? ";
                    string insert;
                    cin >> insert;
                    if (insert == ("awal" )||( insert == "Awal" )|| (insert == "AWAL")){
                        insertFirstP(LP, P);
                    }else if (insert == ("akhir" )||( insert == "Akhir" )|| (insert == "AKHIR")){
                        insertLastP(LP, P);
                    }
                ShowAllPasien(LP);


            }else if (pilihan == 6){
                header();
                string IDPasien;

                cout << "Masukkan ID Pasien untuk Menambahkan Rekam Medis: ";
                cin >> IDPasien;
                adrP P = findPasienByID(LP, IDPasien);

                if (P != NULL){
                    rekam_medis x;
                    cout << "ID Rekam Medis: ";
                    cin >> x.IDRekamMedis;

                    cout << "Tujuan Poli: ";
                    cin >> x.poli;

                    cout << "Diagnosa: ";
                    cin >> x.diagnosa;

                    cout << "Tindakan: ";
                    cin >> x.tindakan;

                    cout << "Tanggal Kunjungan: ";
                    cin >> x.jadwal_kunjungan;

                    cout << "Tanggal Kontrol: ";
                    cin >> x.jadwal_control;

                    adrC C = createElmC(x);
                    cout << "Anda ingin menambah di awal atau di akhir list? ";
                    string insert;
                    cin >> insert;
                    if (insert == ("awal" )||( insert == "Awal" )|| (insert == "AWAL")){
                        insertFirstC(listC(P), C);
                    }else if (insert == ("akhir" )||( insert == "Akhir" )|| (insert == "AKHIR")){
                        insertLastC(listC(P), C);
                    }
                    cout << endl;
                    cout << "====DATA BARU PASIEN DAN DATA REKAM MEDIS====\n";
                    showAllParentsAndChildren(LP);

                }else{
                    cout << "NO ID Tidak Ditemukan" << endl;
                }


            }else if (pilihan == 7){
                string IDPasien;
                cout << "Masukkan ID Pasien yang ingin dihapus: ";
                cin >> IDPasien;

                adrP P = findPasienByID(LP, IDPasien);
                if (P != NULL){
                    if (P == first(LP)){
                        deleteFirstP(LP, P);
                    }else if (next(P) == NULL){
                        deleteLastP(LP, P);
                    }else{
                        adrP prec = first(LP);
                        while (next(prec) != P && next(prec) != NULL) {
                            prec = next(prec);
                        }
                        if (next(prec) == P) {
                            deleteAfterP(LP, prec, P);
                        }
                    }
                }else{
                    cout << "Data Pasien Tidak ada" <<endl;
                }
                cout << "====DATA PASIEN BARU====\n";
                cout << endl;
                showAllParentsAndChildren(LP);


               }else if (pilihan == 8){
                        showAllParentsAndChildren(LP);
                        string IDPasien;
                        cout << "Masukkan ID Pasien yang Rekam Medisnya Ingin Dihapus: ";
                        cin >> IDPasien;

                        adrP P = findPasienByID(LP, IDPasien);

                        if (P == NULL) {
                            cout << "Data Pasien Tidak ditemukan" << endl;
                        } else {
                            if (first(listC(P)) == NULL) {
                                cout << "Pasien ini tidak memiliki rekam medis" << endl;
                            } else {
                                string IDRekamMedis;
                                cout << "Masukkan ID Rekam Medis yang Ingin Dihapus: ";
                                cin >> IDRekamMedis;

                                adrC C = findRekamMedisByID(listC(P), IDRekamMedis);

                                if (C != NULL) {
                                    if (C == first(listC(P))) {
                                        deleteFirstC(listC(P), C);
                                    } else if (C == last(listC(P))) {
                                        deleteLastC(listC(P), C);
                                    } else {
                                        adrC prec = first(listC(P));
                                        while (next(prec) != C && next(prec) != NULL) {
                                            prec = next(prec);
                                        }
                                        if (next(prec) == C) {
                                            deleteAfterC(listC(P), prec, C);
                                        }
                                    }
                                } else {
                                    cout << "Data Rekam Medis Tidak ditemukan" << endl;
                                }
                            }
                        }
                        showAllParentsAndChildren(LP);

            }else if (pilihan == 9){
                string IDPasien;
                listRekamMedis LC;
                cout << "====Data Sebelum Diubah====" << endl;
                cout << endl;
                ShowAllPasien(LP);

                cout << "Masukkan ID Pasien yang ingin dihapus Rekam Medisnya: ";
                cin >> IDPasien;

                adrP P = findPasienByID(LP, IDPasien);
                if (P != NULL){
                    first(listC(P)) = nullptr;
                }else{
                    cout << "Data Pasien Tidak ada\n";
                }
                cout << "====DATA PASIEN BARU====\n";
                cout << endl;
                showAllParentsAndChildren(LP);

            }else if (pilihan == 10){
                string IDPasien;
                cout << endl;
                cout << "====Data Sebelum Diubah====" << endl;
                cout << endl;
                ShowAllPasien(LP);
                cout << "Masukkan ID Pasien yang ingin diUpdate: ";
                cin >> IDPasien;

                adrP P = findPasienByID(LP, IDPasien);
                if (P != NULL){
                    string IDBaru;
                    string NamaBaru;
                    string UsiaBaru;
                    string noHPBaru;
                    string AlamatBaru;

                    cout << "Masukkan ID Pasien Baru: ";
                    cin >> IDBaru;

                    cout << "Masukkan Nama Baru: ";
                    cin >> NamaBaru;

                    cout << "Masukkan Usia Baru: ";
                    cin >> UsiaBaru;

                    cout << "Masukkan noHP Baru: ";
                    cin >> noHPBaru;

                    cout << "Masukkan Alamat Baru: ";
                    cin >> AlamatBaru;

                    updateParentData(LP, P, IDBaru, NamaBaru, UsiaBaru, noHPBaru, AlamatBaru);
                    cout << endl;

                    cout << "==LIST DATA PASIEN UP TO DATE==" << endl;
                    ShowAllPasien(LP);
                }else{
                    cout << "Data Tidak Ditemukan !" << endl;
                }


            }else if (pilihan == 11){
                string IDPasien;
                cout << endl;
                cout << "====Data Sebelum Diubah====" << endl;
                cout << endl;
                ShowAllPasien(LP);
                cout << "Masukkan ID Pasien yang ingin diUpdate: ";
                cin >> IDPasien;

                adrP P = findPasienByID(LP, IDPasien);
                if (P != NULL){
                    string IDRekam;
                    cout << endl;
                    cout << "====Data Sebelum Diubah====" << endl;
                    cout << endl;
                    showAllParentsAndChildren(LP);
                    cout << "Masukkan ID Rekam Medis diUpdate: ";
                    cin >> IDRekam;

                    adrC C = findRekamMedisByID(listC(P), IDRekam);
                    if (C!= NULL){
                        string IDRekamBaru;
                        string jadwal_kunjung;
                        string poli;
                        string diagnosa;
                        string tindakan;
                        string jadwal_kontrol;

                        cout << "Masukkan ID Rekam Medis Baru: ";
                        cin >> IDRekamBaru;

                        cout << "Masukkan Jadwal Kunjung Baru: ";
                        cin >> jadwal_kunjung;

                        cout << "Masukkan Poli Baru: ";
                        cin >> poli;

                        cout << "Masukkan Diagnosa Baru: ";
                        cin >> diagnosa;

                        cout << "Masukkan tindakan Baru: ";
                        cin >> tindakan;

                        cout << "Masukkan jadwal kontrol Baru: ";
                        cin >> jadwal_kontrol;
                    updateChildData(listC(P), C, IDRekamBaru, jadwal_kunjung, poli, diagnosa, tindakan, jadwal_kontrol);
                    cout << endl;
                    }else{
                        cout << "Tidak Ada ID Rekam Medis Tersebut\n";
                    }

                    cout << "==LIST DATA REKAM MEDIS UP TO DATE==" << endl;
                    showAllParentsAndChildren(LP);
                }else{
                    cout << "Data Tidak Ditemukan !" << endl;
                }
            }else if (pilihan == 12){
                cout << "Jumlah Rekam Medis dalam DataBase: ";
                int total = totalRekamMedis(LP, LC);
                cout << total << endl;
            }


                menu();
                cin>>pilihan;
        }
    return 0;
}

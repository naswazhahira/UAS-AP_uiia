#include <iostream>
using namespace std;

void CetakGaris(char karakter,int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << karakter;
    }
}

int CheckDataPetugas(string nama_petugas, long id_petugas) {
    if (nama_petugas == "Endriano Kitswanto" && id_petugas == 231401073) {
        return 1;
    }
    return 0;
}

void TampilanAwal() {
    CetakGaris('=', 80);
    cout<<endl;
    CetakGaris('-', 26);
    cout << " S E L A M A T  D A T A N G ";
    CetakGaris('-', 26);
    cout << endl;
    CetakGaris(' ', 26);
    cout << "DI PORTAL PARKIR KHUSUS MOBIL";
    CetakGaris(' ', 26);
    cout << endl;
    CetakGaris(' ', 34);
    cout<< "MALL PRIENAL";
    CetakGaris(' ', 34);
    cout << endl;
    CetakGaris('=', 80);
    cout << endl << endl;
    cout << "Kami senang Anda telah hadir."<<endl;
    cout << "Sebelum melanjutkan, silahkan masukkan infromasi Anda yang akan bertugas hari ini."<<endl<<endl;

}

char TampilanAwalOpsi(){
    char opsi;
    
    CetakGaris('=', 80);
    cout << endl <<endl;
    cout << "Silahkan input opsi berikut dalam bentuk angka."<<endl;
    cout << "1. Tambahkan Daftar Kendaraan"<<endl;
    cout << "2. Tampilkan Daftar Kendaraan"<<endl;
    cout << "3. Pembayaran"<<endl;
    cout << "4. Keluar"<<endl;
    cout << "Masukkan opsi: ";
    cin >> opsi;

    if (opsi < '1' || opsi > '4') {
        cout << "Opsi tidak valid. Silahkan coba lagi." << endl << endl;
        return TampilanAwalOpsi();
    }
    return opsi;
}

//lanjutin fungsinya

int main() {
    string nama;
    long id;
    
    TampilanAwal();
    cout << "Masukkan nama : ";
    getline(cin, nama);
    cout << "Masukkan ID   : ";
    cin >> id;
    cin.ignore();

    system("cls");
    if (CheckDataPetugas(nama, id) == 1) {
        cout << endl;
        CetakGaris('=', 80);
        cout << endl;
        cout << "Nama Petugas : "<<nama<<endl;
        cout << "ID Petugas   : "<<id<<endl;
        cout << endl;
        CetakGaris(' ', 24);
        cout << "TERIMA KASIH ATAS KERJASAMANYA !"<<endl;
        CetakGaris('-', 24);
        cout << " S E L A M A T  B E R T U G A S ";
        CetakGaris('-', 24);
        cout << endl;
        TampilanAwalOpsi();
    }
    else
    {
        cout << "Nama petugas atau ID salah!." << endl;
        return 0;
    }
    
    return 0;
}

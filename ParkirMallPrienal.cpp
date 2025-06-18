#include <iostream>
#include <vector>
using namespace std;

const int KAPASITAS_MAKSIMUM = 20;

struct Mobil {
    string plat;
    string merk;
    string warna;
    bool sudahbayar;
    int jam;
    int menit;
    int detik;
};

vector<Mobil> daftarMobil;

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
    cin.get(); 
    
    if (opsi < '1' || opsi > '4') {
        cout << "Opsi tidak valid. Silahkan coba lagi." << endl << endl;
        return TampilanAwalOpsi();
    }
    return opsi;
}

void UpdateWaktuParkir() {
    for (int i = 0; i < daftarMobil.size(); i++) {
        if (!daftarMobil[i].sudahbayar) {
            daftarMobil[i].detik += 15; 
            
            if (daftarMobil[i].detik >= 60) {
                daftarMobil[i].menit += daftarMobil[i].detik / 60;
                daftarMobil[i].detik = daftarMobil[i].detik % 60;
            }
            
            if (daftarMobil[i].menit >= 60) {
                daftarMobil[i].jam += daftarMobil[i].menit / 60;
                daftarMobil[i].menit = daftarMobil[i].menit % 60;
            }
        }
    }
}

void TambahkanKendaraan() {
    if (daftarMobil.size() >= KAPASITAS_MAKSIMUM) {
        cout << "\nParkir sudah penuh! Tidak dapat menambah kendaraan baru.\n";
        return;
    
    int jumlah;
    cout << "\nMasukkan jumlah mobil yang akan diparkirkan: ";
    cin >> jumlah;
    cin.get();

    if (daftarMobil.size() + jumlah > KAPASITAS_MAKSIMUM) {
        int sisa = KAPASITAS_MAKSIMUM - daftarMobil.size();
        cout << "\nHanya " << sisa << " slot parkir yang tersedia.\n";
        jumlah = sisa;

    for (int i = 0; i < jumlah; i++) {
        Mobil mobilBaru;
        
        cout << "\nMobil ke-" << daftarMobil.size() + 1 << endl;
        cout << "Masukkan plat mobil    : ";
        getline(cin, mobilBaru.plat);
        cout << "Masukkan merk mobil    : ";
        getline(cin, mobilBaru.merk);
        cout << "Masukkan warna mobil   : ";
        getline(cin, mobilBaru.warna);

        mobilBaru.jam = 0;
        mobilBaru.menit = 0;
        mobilBaru.detik = 0;
        mobilBaru.sudahbayar = false;
        
        daftarMobil.push_back(mobilBaru);
    }
    cout << "\n" << jumlah << " mobil berhasil ditambahkan ke daftar parkir!\n";
}
void TampilkanKendaraan() {
    UpdateWaktuParkir();
    int mobilbelumbayar = 0;
    for (int i = 0; i < daftarMobil.size(); i++) {
        if (!daftarMobil[i].sudahbayar) {
            mobilbelumbayar++;
        }
    }
     cout << "Sisa slot parkir: " << KAPASITAS_MAKSIMUM - daftarMobil.size() << endl;
    
    if (mobilbelumbayar == 0) {
        cout << "\nBelum ada kendaraan yang sedang parkir.\n\n";
    } else {
        cout << "\nDAFTAR MOBIL YANG SEDANG TERPARKIR :\n";
        CetakGaris('=', 70); cout << endl;
        
        int nomor = 1;
        for (int i = 0; i < daftarMobil.size(); i++) {
            if (!daftarMobil[i].sudahbayar) {
                cout << "Mobil ke-" << nomor << endl;
                cout << "Plat mobil    : " << daftarMobil[i].plat << endl;
                cout << "Merk mobil    : " << daftarMobil[i].merk << endl;
                cout << "Warna mobil   : " << daftarMobil[i].warna << endl;
                cout << "Waktu parkir  : " << daftarMobil[i].jam << " jam " 
                     << daftarMobil[i].menit << " menit " 
                     << daftarMobil[i].detik << " detik" << endl;
                CetakGaris('=', 70); cout << endl;
                nomor++;
            }
        }
    }
}

int HitungBiayaParkir(int jam, int menit, int detik) {
    int totalDetik = jam * 3600 + menit * 60 + detik;
    double tarifPerDetik = 7140.0 / 3600.0; 
    int biaya = totalDetik * tarifPerDetik;
    return biaya;
}

void Pembayaran() {
    UpdateWaktuParkir();
    string platInput;
    cout << "\nMasukkan plat mobil yang ingin dibayar: ";
    getline(cin, platInput);

    for (auto &mobil : daftarMobil) {
        string platTerdaftar = mobil.plat;

        if (platInput == platTerdaftar) {
            if (mobil.sudahbayar) {
                cout << "Mobil sudah membayar dan tidak sedang parkir.\n";
                return;
            }

            int biaya = HitungBiayaParkir(mobil.jam, mobil.menit, mobil.detik);
            cout << "Biaya parkir untuk mobil " << mobil.plat << " adalah: Rp " << biaya << endl;
            char konfirmasi;
            cout << "Apakah pembayaran dilakukan? (y/n): ";
            cin >> konfirmasi;
            cin.get();

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                mobil.sudahbayar = true;
                cout << "Pembayaran berhasil. Mobil boleh keluar.\n";
            } else {
                cout << "Pembayaran dibatalkan.\n";
            }
            return;
        }
    }

    cout << "PLAT TIDAK TERDAFTAR.\n";
}

int main() {
    string nama;
    long id;
    
    TampilanAwal();
    cout << "Masukkan nama : ";
    getline(cin, nama);
    cout << "Masukkan ID   : ";
    cin >> id;
    cin.get();

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
        
       char pilihan;
        do {
            pilihan = TampilanAwalOpsi();
            switch (pilihan) {
                case '1':
                    TambahkanKendaraan();
                    break;
                case '2':
                    TampilkanKendaraan();
                    break;
                case '3':
                    Pembayaran();
                    break;
                case '4':
                    cout << "\n...Lanjutkan...\n";
                    break;
            }
        } while (pilihan != '4');
    } else {
        cout << "Nama petugas atau ID salah!." << endl;
    }
    return 0;
}

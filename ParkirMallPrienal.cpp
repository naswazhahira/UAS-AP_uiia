#include <iostream>
#include <vector>
using namespace std;

const int KAPASITAS_MAKSIMUM = 20;

// Struktur data untuk menyimpan informasi mobil
struct Mobil {
    string plat;
    string merk;
    string warna;
    bool sudahbayar;
    int jam;
    int menit;
    int detik;
};

// Vector untuk menyimpan daftar mobil yang terparkir
vector<Mobil> daftarMobil;

// Fungsi untuk mencetak garis dengan karakter tertentu agar tampilan lebih rapi
void CetakGaris(char karakter,int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << karakter;
    }
}

// Fungsi untuk memeriksa data petugas
int CheckDataPetugas(string nama_petugas, long id_petugas) {
    if (nama_petugas == "Endriano Kitswanto" && id_petugas == 231401073) {
        return 1;
    }
    return 0;
}

// Fungsi untuk menghitung jumlah mobil yang sedang parkir (belum bayar)
int hitungmobilaktif() {
    int count = 0;
    for (int i = 0; i < daftarMobil.size(); i++) {
        if (!daftarMobil[i].sudahbayar) {
            count++;
        }
    }
    return count;
}

// Fungsi untuk menghapus mobil yang sudah bayar dari daftar
void bersihkanmobilsudahbayar() {
    for (int i = daftarMobil.size() - 1; i >= 0; i--) {
        if (daftarMobil[i].sudahbayar) {
            daftarMobil.erase(daftarMobil.begin() + i);
        }
    }
}
// Fungsi untuk menampilkan tampilan awal
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

// Fungsi untuk menampilkan opsi awal
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
        cout << "Opsi tidak valid. Silahkan coba lagi (Tekan enter).";
        getchar(); 
        system("cls");
        return TampilanAwalOpsi();
    }
    return opsi;
}

//Fungsi untuk menentukan waktu parkir mobil
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

// Fungsi menambahkan kendaraan baru ke dalam daftar
void TambahkanKendaraan() {
    int mobilAktif = hitungmobilaktif();
    if (mobilAktif >= KAPASITAS_MAKSIMUM) {
        cout << "\nParkir sudah penuh! Tidak dapat menambah kendaraan baru.\nParkiran hanya dapat memuat 20 mobil!\n";
        return;
    }

    int jumlah;
    cout << "Masukkan jumlah mobil yang akan diparkirkan: ";
    cin >> jumlah;
    cin.get();

    if (mobilAktif + jumlah > KAPASITAS_MAKSIMUM) {
        cout << "Maaf, parkiran hanya dapat memuat 20 mobil.\n";
        cout << "Slot tersedia saat ini: " << (KAPASITAS_MAKSIMUM - mobilAktif) << " mobil.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        Mobil mobilBaru;
            
        cout << "\nMobil ke-" << mobilAktif + i + 1 << endl;
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
    system("cls");
    cout << "\n" << jumlah << " mobil berhasil ditambahkan ke daftar parkir!\n";
}

// Fungsi menampilkan semua kendaraan ke dalam daftar
void TampilkanKendaraan() {
    system("cls");
    UpdateWaktuParkir();
    int mobilAktif = hitungmobilaktif();
    
    if (mobilAktif == 0) {
        cout << "\nBelum ada kendaraan yang sedang parkir.\n\n";
    } else {
        cout << "\nDAFTAR MOBIL YANG SEDANG TERPARKIR :\n";
        
        int nomor = 1;
        for (int i = 0; i < daftarMobil.size(); i++) {
            if (!daftarMobil[i].sudahbayar) {
                CetakGaris('=', 80); cout << endl;
                cout << "Mobil ke-" << nomor << endl;
                cout << "Plat mobil    : " << daftarMobil[i].plat << endl;
                cout << "Merk mobil    : " << daftarMobil[i].merk << endl;
                cout << "Warna mobil   : " << daftarMobil[i].warna << endl;
                cout << "Waktu parkir  : " << daftarMobil[i].jam << " jam " 
                     << daftarMobil[i].menit << " menit " 
                     << daftarMobil[i].detik << " detik" << endl;
                nomor++;
            }
        }
        CetakGaris('=', 80); cout << endl;
        cout << "Mobil yang sedang parkir: " << mobilAktif << "/" << KAPASITAS_MAKSIMUM << endl;
        cout << "Sisa slot parkir: " << KAPASITAS_MAKSIMUM - mobilAktif << endl;
    }
}

//fungsi menentukan harga parkir mobil 
int HitungBiayaParkir(int jam, int menit, int detik) {
    int totalDetik = jam * 3600 + menit * 60 + detik; //menjumlahkan durasi
    double tarifPerDetik = 7140.0 / 3600.0; //patokan per jam
    int biaya = totalDetik * tarifPerDetik;
    return biaya;
}

//Fungsi menampilkan harga parkir sekaligus pembayaran
void Pembayaran() {
    UpdateWaktuParkir();
    string platInput;
    TampilkanKendaraan();
    CetakGaris('=', 80); cout << endl;
    cout << "\nMasukkan plat mobil yang ingin dibayar: ";
    getline(cin, platInput);

    for (auto &mobil : daftarMobil) { //mencari mobil yang terdaftar
        string platTerdaftar = mobil.plat;

        if (platInput == platTerdaftar) {
            if (mobil.sudahbayar) {
                cout << "Mobil sudah membayar dan tidak sedang parkir.\n";
                return;
            }

            int biaya = HitungBiayaParkir(mobil.jam, mobil.menit, mobil.detik);
            cout << "B I A Y A  P A R K I R : Rp " << biaya << endl; //tampilan biaya parkir
            char konfirmasi;
            cout << "Apakah pembayaran dilakukan? (y/n): ";
            cin >> konfirmasi;
            cin.get();

            if (konfirmasi == 'y' || konfirmasi == 'Y') { //tampilan jika sudah bayar 
                mobil.sudahbayar = true;
                cout << "Pembayaran berhasil. Mobil dengan plat "<<mobil.plat<< "boleh keluar.\n";
                cout << "Slot parkir telah dikosongkan.\n\n";

                // Bersihkan mobil yang sudah bayar dari daftar
                bersihkanmobilsudahbayar();
                
                // Tampilkan status parkir terbaru
                int mobilAktif = hitungmobilaktif();
                cout << "Status parkir terbaru:\n";
                cout << "Mobil yang sedang parkir: " << mobilAktif << "/" << KAPASITAS_MAKSIMUM << endl;
                cout << "Sisa slot parkir: " << KAPASITAS_MAKSIMUM - mobilAktif << endl;
            } else {
                cout << "Pembayaran dibatalkan.\n\n";
            }
            return;
        }
    }

    cout << "PLAT TIDAK TERDAFTAR.\n\n";
}

// Fungsi untuk menampilkan pesan keluar
void TampilanKeluar() {
    system("cls");
    CetakGaris('=', 80); cout << endl;
    CetakGaris(' ', 19);
    cout << "TERIMA KASIH TELAH MENGGUNAKAN LAYANAN KAMI\n";
    CetakGaris(' ', 23);
    cout << "S A M P A I   J U M P A   L A G I !\n";
    CetakGaris('=', 80);
}

// Main Program
int main() {
    string nama;
    long id;
    
    // Memanggil tampilan awal
    TampilanAwal();
    // Meminta input nama dan ID petugas
    cout << "Masukkan nama : ";
    getline(cin, nama);
    cout << "Masukkan ID   : ";
    cin >> id;
    cin.get();

    system("cls");
    // Memeriksa data petugas, jika valid maka akan menampilkan data petugas dan melanjutkan ke opsi
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
        
        // Menampilkan opsi awal dan menunggu input dari petugas
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
                    TampilanKeluar();
                    break;
            }
        } while (pilihan != '4');
    } else {
        cout << "Nama petugas atau ID salah!." << endl;
    }
    return 0;
}

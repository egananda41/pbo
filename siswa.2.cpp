#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // Untuk manipulasi format output

using namespace std;

// Struktur Mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    string prodi;
    string asal;
    vector<float> nilaiAkhir;
    vector<string> nilaiAbjad;

    // Menambahkan nilai akhir
    void tambahNilai(float nilai) {
        nilaiAkhir.push_back(nilai);
    }

    // Mengonversi nilai akhir ke nilai abjad
    void konversiNilai() {
        for (int i = 0; i < nilaiAkhir.size(); ++i) {
            float nilai = nilaiAkhir[i];
            if (nilai > 80) {
                nilaiAbjad.push_back("A");
            } else if (nilai > 70) {
                nilaiAbjad.push_back("AB");
            } else if (nilai > 60) {
                nilaiAbjad.push_back("B");
            } else if (nilai > 50) {
                nilaiAbjad.push_back("C");
            } else if (nilai > 40) {
                nilaiAbjad.push_back("D");
            } else {
                nilaiAbjad.push_back("E");
            }
        }
    }

    // Menghitung IPK
    float hitungIPK() {
        float totalIPK = 0;
        for (int i = 0; i < nilaiAbjad.size(); ++i) {
            string nilai = nilaiAbjad[i];
            if (nilai == "A") totalIPK += 4;
            else if (nilai == "AB") totalIPK += 3.5;
            else if (nilai == "B") totalIPK += 3;
            else if (nilai == "C") totalIPK += 2;
            else if (nilai == "D") totalIPK += 1;
            else if (nilai == "E") totalIPK += 0;
        }
        return nilaiAbjad.size() > 0 ? totalIPK / nilaiAbjad.size() : 0;
    }

    // Menampilkan Kartu Hasil Studi
    void tampilkanKHS() {
        cout << "\nNama      : " << nama << endl;
        cout << "NIM       : " << nim << endl;
        cout << "Prodi     : " << prodi << endl;
        cout << "Asal      : " << asal << endl;
        cout << "Nilai Abjad: ";
        for (int i = 0; i < nilaiAbjad.size(); ++i) {
            cout << nilaiAbjad[i] << " ";
        }
        cout << endl;
        cout << "IPK       : " << fixed << setprecision(2) << hitungIPK() << endl;
    }
};

// Fungsi utama untuk menjalankan menu
int main() {
    vector<Mahasiswa> mahasiswaList;
    int pilihan;

    while (true) {
        // Menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Menambahkan data Mahasiswa\n";
        cout << "2. Menampilkan data Mahasiswa\n";
        cout << "3. Masukkan nilai akhir masing-masing mata kuliah\n";
        cout << "4. Konversi nilai akhir\n";
        cout << "5. Kartu Hasil Studi\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Menambahkan data Mahasiswa
            Mahasiswa mhs;
            cout << "Masukkan nama: ";
            cin.ignore();  // Membersihkan newline karakter dari input sebelumnya
            getline(cin, mhs.nama);
            cout << "Masukkan NIM: ";
            cin >> mhs.nim;
            cout << "Masukkan Program Studi: ";
            cin.ignore();
            getline(cin, mhs.prodi);
            cout << "Masukkan Asal: ";
            getline(cin, mhs.asal);

            mahasiswaList.push_back(mhs);

        } else if (pilihan == 2) {
            // Menampilkan data Mahasiswa
            if (mahasiswaList.empty()) {
                cout << "Data mahasiswa tidak tersedia.\n";
            } else {
                for (int i = 0; i < mahasiswaList.size(); ++i) {
                    cout << "\nNama: " << mahasiswaList[i].nama << ", NIM: " << mahasiswaList[i].nim 
                         << ", Prodi: " << mahasiswaList[i].prodi << ", Asal: " << mahasiswaList[i].asal << endl;
                }
            }

        } else if (pilihan == 3) {
            // Masukkan nilai akhir masing-masing mata kuliah
            if (mahasiswaList.empty()) {
                cout << "Data mahasiswa tidak tersedia.\n";
            } else {
                string nim;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                bool ditemukan = false;

                for (int i = 0; i < mahasiswaList.size(); ++i) {
                    if (mahasiswaList[i].nim == nim) {
                        ditemukan = true;
                        int jumlahMataKuliah;
                        cout << "Masukkan jumlah mata kuliah: ";
                        cin >> jumlahMataKuliah;

                        for (int j = 0; j < jumlahMataKuliah; ++j) {
                            float nilai;
                            cout << "Masukkan nilai akhir mata kuliah ke-" << (j + 1) << ": ";
                            cin >> nilai;
                            mahasiswaList[i].tambahNilai(nilai);
                        }
                        break;
                    }
                }

                if (!ditemukan) {
                    cout << "Mahasiswa dengan NIM tersebut tidak ditemukan.\n";
                }
            }

        } else if (pilihan == 4) {
            // Konversi nilai akhir
            if (mahasiswaList.empty()) {
                cout << "Data mahasiswa tidak tersedia.\n";
            } else {
                string nim;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                bool ditemukan = false;

                for (int i = 0; i < mahasiswaList.size(); ++i) {
                    if (mahasiswaList[i].nim == nim) {
                        ditemukan = true;
                        mahasiswaList[i].konversiNilai();
                        break;
                    }
                }

                if (!ditemukan) {
                    cout << "Mahasiswa dengan NIM tersebut tidak ditemukan.\n";
                }
            }

        } else if (pilihan == 5) {
            // Menampilkan Kartu Hasil Studi
            if (mahasiswaList.empty()) {
                cout << "Data mahasiswa tidak tersedia.\n";
            } else {
                string nim;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                bool ditemukan = false;

                for (int i = 0; i < mahasiswaList.size(); ++i) {
                    if (mahasiswaList[i].nim == nim) {
                        ditemukan = true;
                        mahasiswaList[i].tampilkanKHS();
                        break;
                    }
                }

                if (!ditemukan) {
                    cout << "Mahasiswa dengan NIM tersebut tidak ditemukan.\n";
                }
            }

        } else if (pilihan == 6) {
            // Keluar dari program
            cout << "Terima kasih! Program selesai.\n";
            break;

        } else {
            cout << "Pilihan tidak valid. Silakan pilih menu yang ada.\n";
        }
    }

    return 0;
}


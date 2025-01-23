#include <iostream>
#include <string>
using namespace std;

class Buku {
private:
    string judul;
    string pengarang;
    string penerbit;
    int tahunTerbit;

public:
    // Setter untuk judul
    void setJudul(const string& j) {
        judul = j;
    }

    // Getter untuk judul
    string getJudul() const {
        return judul;
    }

    // Setter untuk pengarang
    void setPengarang(const string& p) {
        pengarang = p;
    }

    // Getter untuk pengarang
    string getPengarang() const {
        return pengarang;
    }

    // Setter untuk penerbit
    void setPenerbit(const string& p) {
        penerbit = p;
    }

    // Getter untuk penerbit
    string getPenerbit() const {
        return penerbit;
    }

    // Setter untuk tahunTerbit dengan validasi
    void setTahunTerbit(int t) {
        if (t > 0) {
            tahunTerbit = t;
        } else {
            cerr << "Tahun terbit harus positif!" << endl;
        }
    }

    // Getter untuk tahunTerbit
    int getTahunTerbit() const {
        return tahunTerbit;
    }

    // Metode untuk menampilkan informasi buku
    void tampilkanInfoBuku() const {
        cout << "Judul: " << judul << endl;
        cout << "Pengarang: " << pengarang << endl;
        cout << "Penerbit: " << penerbit << endl;
        cout << "Tahun Terbit: " << tahunTerbit << endl;
    }
};

int main() {
    Buku buku1;
    buku1.setJudul("Belajar C++");
    buku1.setPengarang("John Doe");
    buku1.setPenerbit("Penerbit ABC");
    buku1.setTahunTerbit(2023); // Tahun terbit yang valid

    // Menampilkan informasi buku
    buku1.tampilkanInfoBuku();

    // Mencoba set tahun terbit yang tidak valid
    buku1.setTahunTerbit(-2020); // Ini akan menampilkan pesan error

    return 0;
}

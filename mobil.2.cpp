#include <iostream>
#include <string>
using namespace std;

class Mobil {
private:
    string merek;
    string model;
    int tahun;
    string warna;

public:
    // Setter untuk merek
    void setMerek(const string& m) {
        merek = m;
    }

    // Getter untuk merek
    string getMerek() const {
        return merek;
    }

    // Setter untuk model
    void setModel(const string& m) {
        model = m;
    }

    // Getter untuk model
    string getModel() const {
        return model;
    }

    // Setter untuk tahun
    void setTahun(int t) {
        if (t > 1885) { // Tahun mobil pertama kali diciptakan
            tahun = t;
        } else {
            cerr << "Tahun tidak valid! Tahun harus lebih besar dari 1885." << endl;
        }
    }

    // Getter untuk tahun
    int getTahun() const {
        return tahun;
    }

    // Setter untuk warna
    void setWarna(const string& w) {
        warna = w;
    }

    // Getter untuk warna
    string getWarna() const {
        return warna;
    }

    // Metode untuk menampilkan informasi mobil
    void tampilkanInfo() const {
        cout << "Merek: " << merek << endl;
        cout << "Model: " << model << endl;
        cout << "Tahun: " << tahun << endl;
        cout << "Warna: " << warna << endl;
    }
};

int main() {
    Mobil mobil1;
    mobil1.setMerek("Toyota");
    mobil1.setModel("Camry");
    mobil1.setTahun(2020); // Tahun yang valid
    mobil1.setWarna("Hitam");

    // Menampilkan informasi mobil
    mobil1.tampilkanInfo();

    // Mencoba set tahun yang tidak valid
    mobil1.setTahun(1800); // Ini akan menampilkan pesan error

    return 0;
}

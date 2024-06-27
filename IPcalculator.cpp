#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

//
// NOTE: BUAT CATATAN AKHIR IP ANDA SEBELUM INPUT NILAI SEMESTER BARU
//

using namespace std;

struct IPK {
    int total_sks;
    int nilai_matakuliah;
    int sum;
};

struct Matakuliah {
    vector<IPK> components;
    string nama_matakuliah;
    int semester;
};

vector<Matakuliah> node_nilai;
int component;

void sumIP(Matakuliah &mata_kuliah, int sks, float nilai) {
    IPK node;
    node.total_sks = sks;
    node.sum = node.nilai_matakuliah = nilai * sks;
    mata_kuliah.components.push_back(node);
}

void createList(const string &nama_matakuliah, int semester, int sks, float nilai, float indeksPrestasi) {
    Matakuliah mata_kuliah;
    mata_kuliah.nama_matakuliah = nama_matakuliah;
    mata_kuliah.semester = semester;
    sumIP(mata_kuliah, sks, nilai);
    node_nilai.push_back(mata_kuliah);
}

float peringkatHuruf(int sum) {
    if (sum >= 85) return 4.00; // A
    if (sum <= 84.99) return 3.70; // A-
    if (sum <= 79.99) return 3.50; // AB
    if (sum <= 74.99) return 3.30; // B+
    if (sum <= 69.99) return 3.00; // B
    if (sum <= 64.99) return 2.70; // B-
    if (sum <= 59.99) return 2.50; // BC
    if (sum <= 54.99) return 2.30; // C+
    if (sum <= 49.99) return 2.00; // C
    if (sum <= 44.99) return 1.70; // C-
    if (sum <= 39.99) return 1.00; // D
    if (sum <= 34.99) return 0; // E
    else return 0; // T
}

void summaryIPK() {
    float total_sum = 0;
    int total_sks = 0;
    
    for (const auto &matakuliah : node_nilai) {
        for (const auto &component : matakuliah.components) {
            total_sum += component.sum;
            total_sks += component.total_sks;
        }
    }

    cout << total_sum << endl;
    cout << total_sks << endl;
    float ipk = total_sum / total_sks;
    cout << "IPK: " << ipk << endl;
}

void printNode() {
    for (const auto &matakuliah : node_nilai) {
        cout << "Nama Matakuliah: " << matakuliah.nama_matakuliah << endl;
        cout << "Semester: " << matakuliah.semester << endl;
        for (const auto &component : matakuliah.components) {
            cout << "SKS: " << component.total_sks << endl;
            cout << "Nilai Matakuliah: " << component.nilai_matakuliah << endl;
            cout << "Sum: " << component.sum << endl;
        }
        cout << endl;
    }
}

int main() {
    Matakuliah node_nilai;
    int pilihan;
    float nilai, persentase, sum = 0, indeks_prestasi = 0;
    int semester, total_sks;
    char matakuliah[50];

    while (1) {
        system("cls");
        cout << "1. Buat Node nilai Semester\n2. Hasil\n3. Tampilkan Semua Node\n0. Exit\nMasukkan Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                system("cls");
                cout << "Masukkan Semester: ";
                cin >> semester;
                cin.ignore();  // membersihkan buffer input

                cout << "Masukkan Matakuliah (format: nama_matakuliah): ";
                cin.getline(matakuliah, 50);

                cout << "Masukkan SKS: ";
                cin >> total_sks;

                cout << "Masukkan Komponen nilai (format: banyak_komponen): ";
                cin >> component;

                for (int i = 0; i < component; i++) {
                    cout << "Component " << i + 1 << ": ";
                    cin >> persentase;
                    persentase = persentase / 100;
                    cout << "Masukkan Nilai: ";
                    cin >> nilai;

                    cout << persentase << endl;
                    sum += (nilai * persentase);
                }
                
                sum = peringkatHuruf(sum);
                createList(matakuliah, semester, total_sks, sum, indeks_prestasi);
                
                // else {
                //     cout << "IP Semester Genap/Ganjil (format: Indeks_prestasi): ";
                //     cin >> indeks_prestasi;

                //     sum = peringkatHuruf(sum);
                //     createList(matakuliah, semester, total_sks, sum, indeks_prestasi);
                // }
                break;
            case 2:
                summaryIPK();
                system("pause");
                break;
            case 4:
                system("cls");
                printNode();
                system("pause");
                break;
            case 0:
                cout << "Keluar dari program.\n";
                system("cls");
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    }
    
    return 0;
}
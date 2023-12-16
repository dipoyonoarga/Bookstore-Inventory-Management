#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Variabel untuk loop
string loop;

// Fungsi tampilkan semua buku
void tampilkanDatabase(const vector<string> &databaseBuku)
{
    do
    {
        system("cls");
        if (databaseBuku.empty())
        {
            cout << "Database buku kosong\n";
        }
        else
        {
            cout << "\nDatabase buku:\n"
                 << endl;
            for (const auto &buku : databaseBuku)
            {
                cout << buku << endl;
            }
        }
        cout << "\nKetik t untuk kembali ke menu utama : ";
        cin >> loop;
    } while (loop == "y");
}

// Fungsi tambah buku
void tambahBuku(vector<string> &databaseBuku)
{
    do
    {
        system("cls");
        cout << "Tambah buku:"
             << endl;
        string bukuBaru;
        string judul, penulis;

        // Input judul buku
        cout << "\nJudul buku: ";
        cin.ignore();
        getline(cin, judul);

        // Input penulis buku
        cout << "Penulis buku: ";
        getline(cin, penulis);

        // Menggabungkan judul dan penulis menjadi data buku baru
        bukuBaru = judul + " - " + penulis;
        databaseBuku.push_back(bukuBaru);

        // Tambah buku lagi
        cout << "\nBuku berhasil ditambahkan, tambah buku lagi? (y/t): ";
        cin >> loop;
    } while (loop == "y");
}

int main()
{
    // Simulasi database buku
    vector<string> databaseBuku;
    // Interface menu
    int menu;
    do
    {
        system("cls");
        cout << "\nProgram Manajemen Inventaris Toko Buku" << endl;
        cout << "\n1. Tambah buku\n2. Cari buku\n3. Ubah data buku\n4. Tampilkan database\n5. Keluar " << endl;
        cout << "\nPilihan : ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambahBuku(databaseBuku);
            break;
        case 2:
            cout << "Cari buku" << endl;
            break;
        case 3:
            cout << "Edit" << endl;
            break;
        case 4:
            tampilkanDatabase(databaseBuku);
            break;
        case 5:
            cout << "\nProgram telah selesai" << endl;
            break;
        default:
            cout << "\nPilihan invalid";
            break;
        }
    } while (menu != 5);
    return 0;
}

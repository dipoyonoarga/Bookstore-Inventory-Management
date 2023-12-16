#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Variabel untuk loop
string loop;

// Fungsi edit buku
void editBuku(vector<string> &databaseBuku)
{
    do
    {
        system("cls");
        cout << "Edit buku" << endl;

        // Menerima judul atau penulis buku yang akan diedit
        string pencarian;
        cout << "\nMasukkan judul atau penulis buku untuk dicari: ";
        cin.ignore();
        getline(cin, pencarian);

        // Pencarian buku dengan algoritma sequential search
        bool ditemukan = false;
        for (size_t i = 0; i < databaseBuku.size(); ++i)
        {
            if (databaseBuku[i].find(pencarian) != string::npos)
            {
                // Edit data buku
                string judulBaru, penulisBaru;

                // Menerima judul buku baru
                cout << "Masukkan judul buku baru: ";
                getline(cin, judulBaru);

                // Menerima penulis buku baru
                cout << "Masukkan penulis buku baru: ";
                getline(cin, penulisBaru);

                // Menerima data buku baru
                databaseBuku[i] = judulBaru + " - " + penulisBaru;
                cout << "Data buku baru telah berhasil disimpan\n";
                ditemukan = true;
                break;
            }
        }

        // Buku tidak ditemukan
        if (!ditemukan)
        {
            cout << "Buku tidak ditemukan\n";
        }

        // Edit buku lagi
        cout << "\nEdit buku lagi? (y/t): ";
        cin >> loop;
    } while (loop == "y");
}

// Fungsi cari buku
void cariBuku(const vector<string> &databaseBuku)
{
    do
    {
        system("cls");
        cout << "Cari buku" << endl;

        // Menerima judul atau penulis buku yang dicari
        string pencarian;
        cout << "\nMasukkan judul atau penulis buku untuk dicari: ";
        cin.ignore();
        getline(cin, pencarian);

        // Pencarian buku dengan algoritma sequential search
        bool ditemukan = false;
        for (size_t i = 0; i < databaseBuku.size(); ++i)
        {
            if (databaseBuku[i].find(pencarian) != string::npos)
            {
                // Menampilkan data buku yang telah ditemukan
                cout << "\nBuku ditemukan: " << databaseBuku[i] << endl;
                ditemukan = true;
            }
        }

        // Buku tidak ditemukan
        if (!ditemukan)
        {
            cout << "Buku tidak ditemukan\n";
        }

        // Cari buku lagi
        cout << "\nCari buku lagi? (y/t): ";
        cin >> loop;
    } while (loop == "y");
}

// Fungsi tampilkan semua buku
void tampilkanDatabase(const vector<string> &databaseBuku)
{
    do
    {
        system("cls");

        // Keadaan database kosong
        if (databaseBuku.empty())
        {
            cout << "Database buku kosong\n";
        }

        // Keadaan database berisi
        else
        {
            cout << "\nDatabase buku:\n"
                 << endl;
            for (const auto &buku : databaseBuku)
            {
                cout << buku << endl;
            }
        }

        // Kembali ke menu utama
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
            cariBuku(databaseBuku);
            break;
        case 3:
            editBuku(databaseBuku);
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

#include <iostream>
using namespace std;

int main()
{
    int menu;
    do
    {
        system("cls");
        cout << "\nProgram Manajemen Inventaris Toko Buku" << endl;
        cout << "\n1. Tambah buku\n2. Cari buku\n3. Ubah data buku\n4. Tampilkan semua buku\n5. Keluar " << endl;
        cout << "\nPilihan : ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Tambah" << endl;
            break;
        case 2:
            cout << "Cari buku" << endl;
            break;
        case 3:
            cout << "Edit" << endl;
            break;
        case 4:
            cout << "Tampilkan" << endl;
            break;
        case 5:
            cout << "" << endl;
            break;
        default:
            cout << "\nPilihan invalid";
            break;
        }
    } while (menu != 5);
    cout << "Program telah selesai";
}

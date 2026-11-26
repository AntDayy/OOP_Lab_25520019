#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main()
{
    SoPhuc A, B;

    cout << "Nhap so phuc A!\n";
    A.Nhap();

    cout << "Nhap so phuc B!\n";
    B.Nhap();

    cout << "\nSo phuc A ban da nhap: ";
    A.Xuat();
    cout << "\nSo phuc B ban da nhap: ";
    B.Xuat();
    cout << endl;

    // Tinh toan
    SoPhuc tong = A.TinhTong(B);
    SoPhuc hieu = A.TinhHieu(B);
    SoPhuc tich = A.TinhTich(B);

    cout << "\nTong: ";
    tong.Xuat();

    cout << "\nHieu: ";
    hieu.Xuat();

    cout << "\nTich: ";
    tich.Xuat();

    // Xuat trong ham
    cout << "\nThuong: ";
    A.TinhThuong(B);

    return 0;
}
#include <iostream>
#include "GioPhutGiay.h"

using namespace std;

int main()
{
    GioPhutGiay gpg;

    cout << "Nhap gio phut giay!\n";
    gpg.Nhap();

    cout << "\nGio phut giay ban vua nhap la: ";
    gpg.Xuat();

    // Tinh toan gio phut giay ke tiep
    GioPhutGiay next = gpg.TinhCongThemMotGiay();
    cout << "\nGio phut giay sau khi them mot giay la: ";
    next.Xuat();

    return 0;
}
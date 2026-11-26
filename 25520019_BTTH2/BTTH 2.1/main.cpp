#include <iostream>
#include "NgayThangNam.h"

using namespace std;

int main()
{
    NgayThangNam ntn;

    cout << "Nhap ngay thang nam! \n";
    ntn.Nhap();

    cout << "\nNgay thang nam ban vua nhap la: ";
    ntn.Xuat();

    // Tinh toan ngay ke tiep
    NgayThangNam keTiep = ntn.TimNgayThangNamTiepTheo();
    cout << "\nNgay thang nam tiep theo la: ";
    keTiep.Xuat();

    return 0;
}
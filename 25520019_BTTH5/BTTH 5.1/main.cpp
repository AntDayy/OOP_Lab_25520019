#include <iostream>
#include "CongTy.h"

using namespace std;

int main()
{
    CongTy ct;

    cout << "=== NHAP THONG TIN NHAN VIEN ===\n";
    ct.Nhap();

    ct.Xuat();

    cout << "\nTong luong phai tra: " << ct.tongLuong() << " VND\n";

    ct.timLuongThapNhat();
    ct.timTuoiCaoNhat();

    return 0;
}

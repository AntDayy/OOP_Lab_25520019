#include <iostream>
#include "CongTy.h"

using namespace std;

int main()
{
    CongTy VAKALAND;
    cout << "=== NHAP DANH SACH GIAO DICH CUA CONG TY ===\n";
    VAKALAND.Nhap();

    VAKALAND.tinhSoLuongTungLoai();

    VAKALAND.tinhTrungBinhThanhTienChungCu();

    VAKALAND.timGDNhaPhoThanhTienCaoNhat();

    VAKALAND.xuatDSGDThang12Nam2024();

    return 0;
}
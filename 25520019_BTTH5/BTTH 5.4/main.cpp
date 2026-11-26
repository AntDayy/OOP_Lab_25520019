#include <iostream>
#include "CongTy.h"

using namespace std;

int main()
{
    CongTy ds; // Tạo đối tượng công ty

    // Nhập danh sách nhân viên
    cout << "=== NHAP DANH SACH NHAN VIEN CUA CONG TY ===\n";
    ds.Nhap();

    // Xuất danh sách nhân viên
    cout << "\n=== DANH SACH NHAN VIEN CUA CONG TY ===\n";
    ds.Xuat();

    // Xuất nhân viên có lương dưới TB
    cout << "\n=== DANH SACH NHAN VIEN CO LUONG THAP HON LUONG TRUNG BINH ===\n";
    ds.xuatDSNVCoLuongTBThap();

    // Xuất nhân viên lương cao nhất
    cout << "\n=== NHAN VIEN CO LUONG CAO NHAT ===\n";
    ds.xuatNVLuongCaoNhat();

    // Xuất nhân viên lương thấp nhất
    cout << "\n=== NHAN VIEN CO LUONG THAP NHAT ===\n";
    ds.xuatNVLuongThapNhat();

    // Xuất lập trình viên lương cao nhất
    cout << "\n=== LAP TRINH VIEN CO LUONG CAO NHAT ===\n";
    ds.xuatLTVLuongCaoNhat();

    // Xuất kiểm chứng viên lương thấp nhất
    cout << "\n=== KIEM CHUNG VIEN CO LUONG THAP NHAT ===\n";
    ds.xuatKCVLuongThapNhat();

    return 0;
}
#include <iostream>
#include "UIT.h"

using namespace std;

int main()
{
    UIT ds; // Tạo đối tượng quản lý sinh viên UIT

    // Nhập danh sách sinh viên
    cout << "=== NHAP DANH SACH SINH VIEN UIT ===\n";
    ds.Nhap();
    ds.Xuat(); // Xuất danh sách

    // Xuất các danh sách thống kê
    ds.xuatDSSVDuDKTotNghiep();          // SV đủ điều kiện TN
    ds.xuatDSSVKhongDuDKTotNghiep();     // SV không đủ điều kiện TN
    ds.xuatSVDHCoDTBCaoNhat();           // SV Đại Học DTB cao nhất
    ds.xuatSVCDCoDTBCaoNhat();           // SV Cao Đẳng DTB cao nhất
    ds.demSVMoiLoaiKhongDuDKTotNghiep(); // Đếm SV mỗi loại không đủ điều kiện TN

    return 0;
}
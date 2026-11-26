#ifndef UIT_H
#define UIT_H
#include <vector>
#include "SinhVien.h"

using namespace std;

// Lớp quản lý sinh viên của trường UIT
class UIT
{
private:
    vector<SinhVien *> ds; // Danh sách sinh viên (con trỏ đa hình)

public:
    UIT();  // Constructor
    ~UIT(); // Destructor (giải phóng bộ nhớ)

    void Nhap();                           // Nhập danh sách sinh viên
    void Xuat();                           // Xuất danh sách sinh viên
    void xuatDSSVDuDKTotNghiep();          // Xuất sinh viên đủ điều kiện TN
    void xuatDSSVKhongDuDKTotNghiep();     // Xuất sinh viên không đủ điều kiện TN
    void xuatSVDHCoDTBCaoNhat();           // Xuất SV Đại Học DTB cao nhất
    void xuatSVCDCoDTBCaoNhat();           // Xuất SV Cao Đẳng DTB cao nhất
    void demSVMoiLoaiKhongDuDKTotNghiep(); // Đếm SV mỗi loại không đủ điều kiện TN
};

#endif
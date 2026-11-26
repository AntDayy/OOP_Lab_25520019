#ifndef CONGTY_H
#define CONGTY_H
#include <vector>
#include "NhanVien.h"

// Lớp quản lý công ty
class CongTy
{
private:
    vector<NhanVien *> ds; // Danh sách nhân viên (con trỏ đa hình)

public:
    CongTy();  // Constructor
    ~CongTy(); // Destructor (giải phóng bộ nhớ)

    void Nhap();                  // Nhập danh sách nhân viên
    void Xuat();                  // Xuất danh sách nhân viên
    void xuatDSNVCoLuongTBThap(); // Xuất nhân viên có lương dưới TB
    void xuatNVLuongCaoNhat();    // Xuất nhân viên có lương cao nhất
    void xuatNVLuongThapNhat();   // Xuất nhân viên có lương thấp nhất
    void xuatLTVLuongCaoNhat();   // Xuất lập trình viên lương cao nhất
    void xuatKCVLuongThapNhat();  // Xuất kiểm chứng viên lương thấp nhất
};

#endif
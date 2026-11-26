#ifndef CONGTY_H
#define CONGTY_H
#include <vector>
#include "NhanVienSX.h"
#include "NhanVienVP.h"

using namespace std;

class CongTy
{
private:
    vector<NhanVien *> ds; // Danh sách chứa các con trỏ quản lý nhân viên

public:
    CongTy();
    ~CongTy();

    void Nhap();             // Nhập danh sách nhân viên
    void Xuat();             // Xuất thông tin toàn bộ nhân viên
    long long tongLuong();   // Tính tổng lương của tất cả nhân viên trong công ty
    void timLuongThapNhat(); // Tìm và in ra nhân viên có mức lương thấp nhất
    void timTuoiCaoNhat();   // Tìm và in ra nhân viên có tuổi cao nhất (sinh sớm nhất)
};

#endif
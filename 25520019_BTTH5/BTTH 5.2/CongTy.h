#ifndef CONGTY_H
#define CONGTY_H
#include <vector>
#include "GiaoDich.h"

using namespace std;

// Lớp Quản lý danh sách các giao dịch của công ty bds
class CongTy
{
private:
    vector<GiaoDich *> ds; // Danh sách con trỏ lưu trữ đa hình các loại giao dịch

public:
    CongTy();
    ~CongTy(); // Hàm hủy để giải phóng bộ nhớ động của danh sách giao dịch

    void Nhap();                          // Nhập danh sách nhiều giao dịch
    void tinhSoLuongTungLoai();           // Thống kê số lượng từng loại bds
    void tinhTrungBinhThanhTienChungCu(); // Tính trung bình tiền của căn hộ chung cư
    void timGDNhaPhoThanhTienCaoNhat();   // Tìm giao dịch nhà phố đắt nhất
    void xuatDSGDThang12Nam2024();        // Lọc giao dịch trong tháng 12/2024
};

#endif
#ifndef LAPTRINHVIEN_H
#define LAPTRINHVIEN_H
#include "NhanVien.h"

// Lớp con: Lập trình viên
class LapTrinhVien : public NhanVien
{
private:
    double soGioLamThem; // Số giờ làm thêm

public:
    LapTrinhVien();         // Constructor mặc định
    LapTrinhVien(double s); // Constructor có tham số
    ~LapTrinhVien();        // Destructor

    void nhap() override;      // Nhập thông tin lập trình viên
    void xuat() override;      // Xuất thông tin lập trình viên
    void tinhLuong() override; // Tính lương (cơ bản + thêm giờ)
    int getLoai() override;    // Trả về loại nhân viên (1)
};

#endif
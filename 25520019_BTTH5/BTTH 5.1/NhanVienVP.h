#ifndef NHANVIENVP_H
#define NHANVIENVP_H
#include "NhanVien.h"

// Lớp Nhân viên Văn phòng, kế thừa từ lớp NhanVien
class NhanVienVP : public NhanVien
{
private:
    int soNgayLam; // Số ngày làm việc

public:
    NhanVienVP();
    ~NhanVienVP();

    void nhap() override;      // Ghi đè hàm nhập
    void xuat() override;      // Ghi đè hàm xuất
    void tinhLuong() override; // Ghi đè hàm tính lương
};

#endif
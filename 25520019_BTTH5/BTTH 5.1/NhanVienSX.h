#ifndef NHANVIENSX_H
#define NHANVIENSX_H
#include "NhanVien.h"

// Lớp Nhân viên Sản xuất, kế thừa từ lớp NhanVien
class NhanVienSX : public NhanVien
{
private:
    long long luongCanBan;
    int soSP; // Số sản phẩm làm được

public:
    NhanVienSX();
    ~NhanVienSX();

    void nhap() override;      // Ghi đè hàm nhập
    void xuat() override;      // Ghi đè hàm xuất
    void tinhLuong() override; // Ghi đè hàm tính lương
};

#endif
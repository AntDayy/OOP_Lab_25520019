#ifndef GDCANHOCHUNGCU_H
#define GDCANHOCHUNGCU_H
#include "GiaoDich.h"

// Lớp GDCanHoChungCu kế thừa từ lớp GiaoDich (Giao dịch Căn hộ chung cư)
class GDCanHoChungCu : public GiaoDich
{
private:
    int maCan; // Mã số căn hộ
    int tang;  // Tầng của căn hộ

public:
    GDCanHoChungCu();
    GDCanHoChungCu(int m, int t);
    ~GDCanHoChungCu();

    void nhap() override;          // Ghi đè hàm nhập
    void xuat() override;          // Ghi đè hàm xuất
    void tinhThanhTien() override; // Ghi đè hàm tính tiền chung cư
    int getLoai() override;        // Trả về mã loại chung cư (3)
};

#endif
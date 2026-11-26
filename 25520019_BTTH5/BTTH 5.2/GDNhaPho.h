#ifndef GDNHAPHO_H
#define GDNHAPHO_H
#include <iostream>
#include "GiaoDich.h"

using namespace std;

// Lớp GDNhaPho kế thừa từ lớp GiaoDich (Giao dịch Nhà Phố)
class GDNhaPho : public GiaoDich
{
private:
    string loaiNha; // Loại nhà: cao cấp hoặc thường
    string diaChi;  // Địa chỉ nhà phố

public:
    GDNhaPho();
    GDNhaPho(string nha, string diachi);
    ~GDNhaPho();

    void nhap() override;          // Ghi đè hàm nhập
    void xuat() override;          // Ghi đè hàm xuất
    void tinhThanhTien() override; // Ghi đè hàm tính tiền nhà phố
    int getLoai() override;        // Trả về mã loại nhà phố (2)
};

#endif
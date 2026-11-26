#ifndef GDDAT_H
#define GDDAT_H
#include <iostream>
#include "GiaoDich.h"

using namespace std;

// Lớp GDDat kế thừa từ lớp GiaoDich (Giao dịch Đất)
class GDDat : public GiaoDich
{
private:
    string loaiDat; // Loại đất: A, B, hoặc C

public:
    GDDat();
    GDDat(string ld);
    ~GDDat();

    void nhap() override;          // Ghi đè hàm nhập
    void xuat() override;          // Ghi đè hàm xuất
    void tinhThanhTien() override; // Ghi đè hàm tính tiền đất
    int getLoai() override;        // Trả về mã loại đất (1)
};

#endif
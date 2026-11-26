#ifndef CAODANG_H
#define CAODANG_H
#include "SinhVien.h"

// Lớp con: Sinh viên hệ Cao Đẳng
class CaoDang : public SinhVien
{
private:
    double diemTotNghiep; // Điểm thi tốt nghiệp

public:
    CaoDang();            // Constructor mặc định
    CaoDang(double diem); // Constructor có tham số
    ~CaoDang();           // Destructor

    void nhap() override;      // Nhập thông tin sinh viên Cao Đẳng
    void xuat() override;      // Xuất thông tin sinh viên Cao Đẳng
    int getHe() override;      // Trả về hệ sinh viên (1)
    bool totNghiep() override; // Kiểm tra điều kiện tốt nghiệp Cao Đẳng
};

#endif
#ifndef DAIHOC_H
#define DAIHOC_H
#include <iostream>
#include "SinhVien.h"

using namespace std;

// Lớp con: Sinh viên hệ Đại Học
class DaiHoc : public SinhVien
{
private:
    string tenLuanVan;  // Tên luận văn
    double diemLuanVan; // Điểm luận văn

public:
    DaiHoc();                        // Constructor mặc định
    DaiHoc(string ten, double diem); // Constructor có tham số
    ~DaiHoc();                       // Destructor

    void nhap() override;      // Nhập thông tin sinh viên Đại Học
    void xuat() override;      // Xuất thông tin sinh viên Đại Học
    int getHe() override;      // Trả về hệ sinh viên (2)
    bool totNghiep() override; // Kiểm tra điều kiện tốt nghiệp Đại Học
};

#endif
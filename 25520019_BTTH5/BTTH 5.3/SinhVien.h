#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>

using namespace std;

// Lớp cơ sở cho tất cả sinh viên
class SinhVien
{
protected:
    int mssv;      // Mã số sinh viên
    string hoTen;  // Họ tên
    string diaChi; // Địa chỉ
    int tinChi;    // Số tín chỉ
    double dtb;    // Điểm trung bình

public:
    SinhVien();                                              // Constructor mặc định
    SinhVien(int m, string h, string d, int t, double diem); // Constructor có tham số
    virtual ~SinhVien();                                     // Destructor ảo

    virtual void nhap();      // Nhập thông tin sinh viên
    virtual void xuat();      // Xuất thông tin sinh viên
    virtual int getHe();      // Lấy hệ sinh viên
    virtual bool totNghiep(); // Kiểm tra điều kiện tốt nghiệp

    int getTinChi(); // Lấy số tín chỉ
    double getDTB(); // Lấy điểm trung bình
};

#endif
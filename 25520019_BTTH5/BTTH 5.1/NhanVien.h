#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <iostream>

using namespace std;

// Lớp cha đại diện cho một Nhân viên chung
class NhanVien
{
protected:
    string hoTen;
    int ngay;
    int thang;
    int nam;
    long long luong; // Được tính toán ở các lớp con

public:
    NhanVien();
    NhanVien(string ten, int d, int m, int y, long long l);
    virtual ~NhanVien(); // Destructor ảo để gọi đúng destructor của lớp con

    virtual void nhap();      // Hàm ảo nhập thông tin
    virtual void xuat();      // Hàm ảo xuất thông tin
    virtual void tinhLuong(); // Hàm ảo tính lương

    // Các hàm getter lấy thông tin
    long long getLuong() { return luong; }
    int getNgay() { return ngay; }
    int getThang() { return thang; }
    int getNam() { return nam; }
};

#endif
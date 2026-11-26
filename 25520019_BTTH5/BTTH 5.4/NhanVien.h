#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <string>

using namespace std;

// Lớp cơ sở cho tất cả các loại nhân viên
class NhanVien
{
protected:
    string maNV;    // Mã nhân viên
    string hoTen;   // Họ tên
    int tuoi;       // Tuổi
    long long soDT; // Số điện thoại
    string email;   // Email
    double luongCB; // Lương cơ bản
    double luong;   // Lương cuối cùng

public:
    NhanVien();                                                                                  // Constructor mặc định
    NhanVien(string maNV, string hoTen, int tuoi, long long soDT, string email, double luongCB); // Constructor có tham số
    virtual ~NhanVien();                                                                         // Destructor ảo

    virtual void nhap();      // Nhập thông tin nhân viên
    virtual void xuat();      // Xuất thông tin nhân viên
    virtual void tinhLuong(); // Tính lương
    virtual int getLoai();    // Lấy loại nhân viên

    double getLuong(); // Lấy lương nhân viên
};

#endif
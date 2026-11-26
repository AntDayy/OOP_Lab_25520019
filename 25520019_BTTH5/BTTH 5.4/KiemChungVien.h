#ifndef KIEMCHUNGVIEN_H
#define KIEMCHUNGVIEN_H
#include "NhanVien.h"

// Lớp con: Kiểm chứng viên
class KiemChungVien : public NhanVien
{
private:
    int soLoi; // Số lỗi được phát hiện

public:
    KiemChungVien();      // Constructor mặc định
    KiemChungVien(int s); // Constructor có tham số
    ~KiemChungVien();     // Destructor

    void nhap() override;      // Nhập thông tin kiểm chứng viên
    void xuat() override;      // Xuất thông tin kiểm chứng viên
    void tinhLuong() override; // Tính lương (cơ bản + lỗi phát hiện)
    int getLoai() override;    // Trả về loại nhân viên (2)
};

#endif
#include <iostream>
#include "LapTrinhVien.h"
#include <limits>

using namespace std;

// Kiểm tra nhập số thực hợp lệ
double kiemTraNhapLTV(const string &prompt)
{
    double val;
    while (1)
    {
        cout << prompt;
        if (cin >> val) // Kiểm tra nhập thành công
        {
            if (cin.peek() == '\n') // Kiểm tra kết thúc bằng Enter
                break;
            else // Có ký tự phụ sau số
            {
                cout << "[!] Loi. Vui long nhap lai!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else // Nhập thất bại
        {
            cout << "[!] Loi. Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return val;
}

LapTrinhVien::LapTrinhVien()
{
    this->soGioLamThem = 0.0;
}

LapTrinhVien::LapTrinhVien(double s)
{
    this->soGioLamThem = s;
}

LapTrinhVien::~LapTrinhVien() {}

// Nhập thông tin lập trình viên (gọi nhập cơ sở + số giờ thêm)
void LapTrinhVien::nhap()
{
    NhanVien::nhap();                                              // Nhập thông tin nhân viên cơ sở
    this->soGioLamThem = kiemTraNhapLTV("Nhap so gio lam them: "); // Nhập giờ làm thêm
}

// Xuất thông tin lập trình viên (gọi xuất cơ sở + giờ thêm + lương)
void LapTrinhVien::xuat()
{
    NhanVien::xuat();                              // Xuất thông tin nhân viên cơ sở
    cout << soGioLamThem << '\t' << luong << endl; // Xuất giờ thêm và lương
}

// Tính lương lập trình viên: lương cơ bản + (giờ thêm × 200,000)
void LapTrinhVien::tinhLuong()
{
    this->luong = this->luongCB + (this->soGioLamThem * 200000);
}

int LapTrinhVien::getLoai()
{
    return 1;
}
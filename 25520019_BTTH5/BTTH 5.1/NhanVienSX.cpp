#include <iostream>
#include <limits>
#include "NhanVienSX.h"

// Hàm hỗ trợ kiểm tra nhập số an toàn cho file NhanVienSX
long long kiemTraNhapNVSX(const string &prompt)
{
    long long val;
    while (1)
    {
        cout << prompt;
        if (cin >> val)
        {
            if (cin.peek() == '\n')
                break;
            else
                cout << "[!] Loi. Vui long nhap lai!\n";
        }
        else
        {
            cout << "[!] Loi. Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return val;
}

// Constructor mặc định khởi tạo giá trị
NhanVienSX::NhanVienSX()
{
    this->luongCanBan = 0;
    this->soSP = 0;
}

// Destructor
NhanVienSX::~NhanVienSX() {}

// Tính lương: Lương Căn Bản + Số Sản Phẩm * 5.000
void NhanVienSX::tinhLuong()
{
    this->luong = luongCanBan + soSP * 5000;
}

// Hàm nhập cho NVSX
void NhanVienSX::nhap()
{
    NhanVien::nhap(); // Gọi hàm nhập của lớp cha để lấy Họ tên và Ngày sinh

    // Yêu cầu nhập lương cơ bản và số sản phẩm không âm
    while (1)
    {
        luongCanBan = kiemTraNhapNVSX("Nhap luong can ban: ");
        soSP = kiemTraNhapNVSX("Nhap so san pham: ");

        if (luongCanBan < 0 || soSP < 0)
            cout << "Vui long nhap so duong!\n";
        else
            break;
    }
    tinhLuong(); // Tính toán lương ngay sau khi nhập xong
}

// Hàm xuất cho NVSX
void NhanVienSX::xuat()
{
    NhanVien::xuat();              // Gọi hàm xuất của lớp cha (Họ tên, ngày sinh)
    cout << '\t' << luong << endl; // In thêm thông tin lương
}
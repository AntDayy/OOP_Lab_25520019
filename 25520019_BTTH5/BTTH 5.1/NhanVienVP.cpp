#include <iostream>
#include <limits>
#include "NhanVienVP.h"

using namespace std;

// Hàm hỗ trợ kiểm tra nhập số an toàn cho file NhanVienVP
int kiemTraNhapNVVP(const string &prompt)
{
    int val;
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
NhanVienVP::NhanVienVP()
{
    this->soNgayLam = 0;
}

// Destructor
NhanVienVP::~NhanVienVP() {}

// Tính lương: Số ngày làm * 100.000
void NhanVienVP::tinhLuong()
{
    this->luong = soNgayLam * 100000;
}

// Hàm nhập cho NVVP
void NhanVienVP::nhap()
{
    NhanVien::nhap(); // Gọi hàm nhập của lớp cha để lấy Họ tên và Ngày sinh

    // Yêu cầu nhập số ngày làm không âm
    while (1)
    {
        soNgayLam = kiemTraNhapNVVP("Nhap so ngay lam: ");

        if (soNgayLam < 0)
            cout << "Vui long nhap lai so ngay lam >= 0!\n";
        else
            break;
    }
    tinhLuong(); // Tính toán lương ngay sau khi nhập xong
}

// Hàm xuất cho NVVP
void NhanVienVP::xuat()
{
    NhanVien::xuat();              // Gọi hàm xuất của lớp cha (Họ tên, ngày sinh)
    cout << '\t' << luong << endl; // In thêm thông tin lương
}
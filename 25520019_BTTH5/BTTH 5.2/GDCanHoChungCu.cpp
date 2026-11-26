#include <iostream>
#include <limits>
#include "GDCanHoChungCu.h"

using namespace std;

// Hàm hỗ trợ kiểm tra và nhập số nguyên hợp lệ riêng cho lớp Chung Cư
int kiemTraNhapCHCC(const string &prompt)
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

// Hàm khởi tạo mặc định cho GDCanHoChungCu
GDCanHoChungCu::GDCanHoChungCu()
{
    this->maCan = 0;
    this->tang = 1;
}

// Hàm khởi tạo có tham số cho GDCanHoChungCu
GDCanHoChungCu::GDCanHoChungCu(int m, int t)
{
    this->maCan = m;
    this->tang = t;
}

// Hàm hủy GDCanHoChungCu
GDCanHoChungCu::~GDCanHoChungCu() {}

// Hàm nhập thông tin riêng cho Căn hộ chung cư
void GDCanHoChungCu::nhap()
{
    GiaoDich::nhap(); // Nhập thông tin chung của giao dịch từ lớp cha
    maCan = kiemTraNhapCHCC("Nhap ma can: ");

    // Ràng buộc số tầng của chung cư phải từ tầng 1 trở lên
    while (1)
    {
        tang = kiemTraNhapCHCC("Nhap tang: ");

        if (tang < 1)
            cout << "Vui long nhap tang >= 1!";
        else
            break;
    }
}

// Hàm xuất thông tin chi tiết của Căn hộ chung cư
void GDCanHoChungCu::xuat()
{
    GiaoDich::xuat(); // Xuất thông tin chung
    cout << '\t' << maCan << '\t' << tang << endl;
}

// Hàm tính thành tiền cho Căn hộ chung cư dựa vào số tầng
void GDCanHoChungCu::tinhThanhTien()
{
    // Căn hộ ở tầng 1: nhân hệ số giá 2.0
    if (tang == 1)
        this->tien = dienTich * gia * 2.0;
    // Căn hộ từ tầng 15 trở lên: nhân hệ số giá 1.2
    else if (tang >= 15)
        this->tien = dienTich * gia * 1.2;
    // Các tầng còn lại: tính giá bình thường
    else
        this->tien = dienTich * gia;
}

// Trả về số định danh loại giao dịch Chung cư là 3
int GDCanHoChungCu::getLoai()
{
    return 3;
}
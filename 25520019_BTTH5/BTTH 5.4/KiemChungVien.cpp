#include <iostream>
#include <limits>
#include "KiemChungVien.h"

using namespace std;

// Kiểm tra nhập số nguyên hợp lệ
int kiemTraNhapKCV(const string &prompt)
{
    int val;
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

KiemChungVien::KiemChungVien()
{
    this->soLoi = 0;
}

KiemChungVien::KiemChungVien(int s)
{
    this->soLoi = s;
}

KiemChungVien::~KiemChungVien() {}

// Nhập thông tin kiểm chứng viên (gọi nhập cơ sở + số lỗi)
void KiemChungVien::nhap()
{
    NhanVien::nhap();                              // Nhập thông tin nhân viên cơ sở
    this->soLoi = kiemTraNhapKCV("Nhap so loi: "); // Nhập số lỗi phát hiện
}

// Xuất thông tin kiểm chứng viên (gọi xuất cơ sở + số lỗi + lương)
void KiemChungVien::xuat()
{
    NhanVien::xuat();                       // Xuất thông tin nhân viên cơ sở
    cout << soLoi << '\t' << luong << endl; // Xuất số lỗi và lương
}

// Tính lương kiểm chứng viên: lương cơ bản + (lỗi phát hiện × 50,000)
void KiemChungVien::tinhLuong()
{
    this->luong = this->luongCB + this->soLoi * 50000;
}

int KiemChungVien::getLoai()
{
    return 2;
}
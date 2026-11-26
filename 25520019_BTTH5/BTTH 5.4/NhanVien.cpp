#include <iostream>
#include <limits>
#include "NhanVien.h"

using namespace std;

// Kiểm tra nhập số nguyên hợp lệ
long long kiemTraNhap(const string &prompt)
{
    long long val;
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

NhanVien::NhanVien()
{
    this->maNV = "";
    this->hoTen = "";
    this->tuoi = 0;
    this->soDT = 0;
    this->email = "";
    this->luongCB = 0.0;
}

NhanVien::NhanVien(string maNV, string hoTen, int tuoi, long long soDT, string email, double luongCB)
{
    this->maNV = maNV;
    this->hoTen = hoTen;
    this->tuoi = tuoi;
    this->soDT = soDT;
    this->email = email;
    this->luongCB = luongCB;
}

NhanVien::~NhanVien() {}

// Nhập thông tin nhân viên từ bàn phím
void NhanVien::nhap()
{
    cout << "Nhap ma nhan vien: ";
    cin.ignore();
    getline(cin, this->maNV);

    cout << "Nhap ho ten: ";
    getline(cin, this->hoTen);

    cout << "Nhap tuoi: ";
    cin >> this->tuoi;
    cin.ignore();

    this->soDT = kiemTraNhap("Nhap so dien thoai: "); // Kiểm tra hợp lệ

    cout << "Nhap email: ";
    cin.ignore();
    getline(cin, this->email);

    cout << "Nhap luong co ban: ";
    cin >> this->luongCB;
    cin.ignore();
}

// Xuất thông tin nhân viên (không có dòng mới để tiếp tục)
void NhanVien::xuat()
{
    cout << maNV << '\t' << hoTen << '\t' << tuoi << '\t' << soDT << '\t' << email << '\t' << luongCB << '\t';
}

// Tính lương (lớp cơ sở: lương = lương cơ bản)
void NhanVien::tinhLuong()
{
    this->luong = this->luongCB;
}

double NhanVien::getLuong()
{
    return this->luong;
}

int NhanVien::getLoai()
{
    return 0;
}
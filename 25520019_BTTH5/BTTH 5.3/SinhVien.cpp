#include <iostream>
#include "SinhVien.h"
#include <limits>

using namespace std;

// Kiểm tra nhập số thực hợp lệ
double kiemTraNhap(const string &prompt)
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
                cout << "[!] Loi. Vui long nhap lai!\n";
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

SinhVien::SinhVien()
{
    this->mssv = 0;
    this->hoTen = "";
    this->diaChi = "";
    this->tinChi = 0;
    this->dtb = 0.0;
}

SinhVien::SinhVien(int m, string h, string d, int t, double diem)
{
    this->mssv = m;
    this->hoTen = h;
    this->diaChi = d;
    this->tinChi = t;
    this->dtb = diem;
}

SinhVien::~SinhVien() {}

// Nhập thông tin sinh viên từ bàn phím
void SinhVien::nhap()
{
    // Nhập MSSV (phải > 0)
    while (1)
    {
        mssv = kiemTraNhap("Nhap ma so sinh vien: ");
        if (mssv < 0)
            cout << "Vui long nhap mssv la so nguyen duong!\n";
        else
            break;
    }

    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);

    // Nhập tín chỉ (phải > 0)
    while (1)
    {
        tinChi = kiemTraNhap("Nhap so tin chi: ");
        if (tinChi > 0)
            break;
        else
            cout << "Vui long nhap so tin chi lon hon 0!\n";
    }

    // Nhập DTB (0.0 - 10.0)
    while (1)
    {
        dtb = kiemTraNhap("Nhap diem trung binh: ");
        if (dtb >= 0.0 && dtb <= 10.0)
            break;
        else
            cout << "[!] Loi. Vui long nhap lai diem trung binh!\n";
    }
}

// Xuất thông tin sinh viên (không có dòng mới để tiếp tục)
void SinhVien::xuat()
{
    cout << mssv << '\t' << hoTen << '\t' << diaChi << '\t' << tinChi << '\t' << dtb << '\t';
}

int SinhVien::getHe()
{
    return 0;
}

bool SinhVien::totNghiep()
{
    return false;
}

int SinhVien::getTinChi()
{
    return this->tinChi;
}

double SinhVien::getDTB()
{
    return this->dtb;
}
#include <iostream>
#include "CaoDang.h"
#include <limits>

using namespace std;

// Kiểm tra nhập số thực hợp lệ cho Cao Đẳng
double kiemTraNhapCD(const string &prompt)
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

CaoDang::CaoDang()
{
    this->diemTotNghiep = 0.0;
}

CaoDang::CaoDang(double diem)
{
    this->diemTotNghiep = diem;
}

CaoDang::~CaoDang() {};

// Nhập thông tin sinh viên Cao Đẳng
void CaoDang::nhap()
{
    SinhVien::nhap(); // Gọi nhập thông tin sinh viên cơ sở

    // Nhập điểm thi tốt nghiệp (0.0 - 10.0)
    while (1)
    {
        diemTotNghiep = kiemTraNhapCD("Nhap diem thi tot nghiep: ");
        if (diemTotNghiep >= 0.0 && diemTotNghiep <= 10.0)
            break;
        else
            cout << "[!] Loi. Vui long nhap lai diem thi tot nghiep!\n";
    }
}

// Xuất thông tin sinh viên Cao Đẳng
void CaoDang::xuat()
{
    SinhVien::xuat();              // Xuất thông tin sinh viên cơ sở
    cout << diemTotNghiep << endl; // Xuất điểm thi tốt nghiệp
}

int CaoDang::getHe()
{
    return 1;
}

// Kiểm tra điều kiện tốt nghiệp Cao Đẳng: tín chỉ >= 120, DTB >= 5.0, điểm TN >= 5.0
bool CaoDang::totNghiep()
{
    return (this->tinChi >= 120 && this->dtb >= 5.0 && this->diemTotNghiep >= 5.0);
}
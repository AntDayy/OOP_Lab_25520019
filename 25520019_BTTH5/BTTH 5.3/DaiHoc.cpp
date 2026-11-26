#include <iostream>
#include <limits>
#include "DaiHoc.h"

using namespace std;

// Kiểm tra nhập số thực hợp lệ cho Đại Học
double kiemTraNhapDH(const string &prompt)
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

DaiHoc::DaiHoc()
{
    this->tenLuanVan = "";
    this->diemLuanVan = 0.0;
}

DaiHoc::DaiHoc(string ten, double diem)
{
    this->tenLuanVan = ten;
    this->diemLuanVan = diem;
}

DaiHoc::~DaiHoc() {}

// Nhập thông tin sinh viên Đại Học
void DaiHoc::nhap()
{
    SinhVien::nhap(); // Gọi nhập thông tin sinh viên cơ sở

    cout << "Nhap ten luan van: ";
    cin.ignore();
    getline(cin, tenLuanVan);

    // Nhập điểm luận văn (0.0 - 10.0)
    while (1)
    {
        diemLuanVan = kiemTraNhapDH("Nhap diem luan van: ");
        if (diemLuanVan >= 0.0 && diemLuanVan <= 10.0)
            break;
        else
            cout << "[!] Loi. Vui long nhap lai diem luan van!\n";
    }
}

// Xuất thông tin sinh viên Đại Học
void DaiHoc::xuat()
{
    SinhVien::xuat();                                  // Xuất thông tin sinh viên cơ sở
    cout << tenLuanVan << '\t' << diemLuanVan << endl; // Xuất tên luận văn và điểm
}

int DaiHoc::getHe()
{
    return 2;
}

// Kiểm tra điều kiện tốt nghiệp Đại Học: tín chỉ >= 170, DTB >= 5.0, điểm LV >= 5.0
bool DaiHoc::totNghiep()
{
    return (this->tinChi >= 170 && this->dtb >= 5.0 && this->diemLuanVan >= 5.0);
}
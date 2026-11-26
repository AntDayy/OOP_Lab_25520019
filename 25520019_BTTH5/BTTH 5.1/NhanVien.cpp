#include <iostream>
#include <limits>
#include "NhanVien.h"

using namespace std;

// Hàm hỗ trợ kiểm tra nhập số nguyên an toàn cho kiểu long long
long long kiemTraNhap(const string &prompt)
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

// Hàm kiểm tra năm nhuận
bool isNamNhuan(int nam)
{
    return (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0));
}

// Hàm trả về số ngày tối đa trong một tháng cụ thể của một năm cụ thể
int traVeSoNgay(int thang, int nam)
{
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isNamNhuan(nam) ? 29 : 28; // Tháng 2 phụ thuộc vào năm nhuận
    default:
        return 0; // Trả về 0 nếu tháng không hợp lệ
    }
}

// Hàm kiểm tra bộ ngày/tháng/năm có hợp lệ theo lịch hay không
bool kiemTraNgayHopLe(int ngay, int thang, int nam)
{
    // Kiểm tra giới hạn của ngày, tháng, năm
    if (ngay < 1 || ngay > traVeSoNgay(thang, nam) || thang < 1 || thang > 12 || nam < 1)
        return false;
    return true;
}

// Constructor mặc định thiết lập các giá trị ban đầu an toàn
NhanVien::NhanVien()
{
    this->hoTen = "";
    this->ngay = 1;
    this->thang = 1;
    this->nam = 1;
    this->luong = 0;
}

// Constructor có tham số
NhanVien::NhanVien(string ten, int d, int m, int y, long long l)
{
    this->hoTen = ten;
    this->ngay = d;
    this->thang = m;
    this->nam = y;
    this->luong = l;
}

// Destructor
NhanVien::~NhanVien() {}

// Hàm nhập thông tin chung (Họ tên, ngày sinh)
void NhanVien::nhap()
{
    cout << "Nhap ten NV: ";
    getline(cin, hoTen);

    // Lặp cho đến khi người dùng nhập vào một ngày tháng năm hợp lệ
    while (1)
    {
        ngay = kiemTraNhap("Nhap ngay sinh: ");
        thang = kiemTraNhap("Nhap thang sinh: ");
        nam = kiemTraNhap("Nhap nam sinh: ");

        if (kiemTraNgayHopLe(ngay, thang, nam))
            break;
        else
            cout << "Ngay thang nam khong hop le. Vui long nhap lai!\n";
    }
}

// Hàm xuất thông tin chung (Họ tên, ngày sinh)
void NhanVien::xuat()
{
    cout << hoTen << '\t' << ngay << "/" << thang << "/" << nam;
}

// Hàm tính lương mặc định ở lớp cha
void NhanVien::tinhLuong()
{
    this->luong = 0;
}
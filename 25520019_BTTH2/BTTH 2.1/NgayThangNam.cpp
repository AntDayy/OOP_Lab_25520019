#include <iostream>
#include <limits>
#include "NgayThangNam.h"

using namespace std;

/*
Ham kiem tra nguoi dung nhap
Nhap sai khi nguoi dung nhap ki tu dac biet (@#...), chuoi(abc...), so sai(123abc...)
Nhap sai thi bat nguoi dung nhap lai
Neu nguoi dung nhap dung thi return ve value
*/
int kiemTraNhap(const string &error)
{
    int value;

    while (1)
    {
        cout << error;
        if (cin >> value)
        {
            if (cin.peek() == '\n')
                break;
            else
                cout << "Vui long nhap lai! \n";
        }
        else
        {
            cout << "Vui long chi nhap so nguyen! \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}

/*
Ham kiem tra nam nhuan
Nam nhuan la nam chia het cho 400 hoac chia het cho 4 nhung khong chia het cho 100
*/
bool kiemTraNamNhuan(int nam)
{
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

/*
Ham tra ve so ngay co trong thang do
Thang 1, 3, 5, 7, 8, 10, 12 co 31 ngay
Thang 4, 6, 9, 11 co 30 ngay
Thang 2 co 29 ngay neu nam do la nam nhuan, nam khong nhuan thi co 28 ngay
*/
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
        return (kiemTraNamNhuan(nam) ? 29 : 28);
    default:
        return 0;
    }
}

/*
Ham kiem tra ngay thang nam co hop le hay khong
Nam hop le neu nam do khong am
Thang hop le la tu thang 1 den thang 12
Ngay hop le la tu ngay 1 den ngay toi da co trong thang do
*/
bool kiemTraHopLe(int ngay, int thang, int nam)
{
    if (nam <= 0 || thang > 12 || thang < 1)
        return false;
    if (ngay > traVeSoNgay(thang, nam) || ngay < 1)
        return false;
    return true;
}

/*
Ham nhap ngay thang nam
Neu nguoi dung nhap ngay thang nam khong hop le thi bat nhap lai
Nhap dung thi break
*/
void NgayThangNam::Nhap()
{
    while (1)
    {
        iNgay = kiemTraNhap("Nhap ngay: ");
        iThang = kiemTraNhap("Nhap thang: ");
        iNam = kiemTraNhap("Nhap nam: ");

        if (kiemTraHopLe(iNgay, iThang, iNam))
            break;
        else
            cout << "Ngay thang nam khong hop le. Vui long nhap lai! \n";
    }
}

// Ham xuat ngay thang nam
void NgayThangNam::Xuat()
{
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

/*
Ham tim ngay thang nam ke tiep
Lay ngay hien tai + 1
Neu ngay do lon hon so ngay toi da trong thang thi cho ngay do = 1 (ngay dau thang luon = 1)
Sau do tang thang them 1
Neu thang lon hon 12 thi cho thang = 1 va tang nam len 1
Return ve ngay ke tiep
*/
NgayThangNam NgayThangNam::TimNgayThangNamTiepTheo()
{
    NgayThangNam keTiep;
    keTiep.iNgay = iNgay;
    keTiep.iThang = iThang;
    keTiep.iNam = iNam;

    keTiep.iNgay++;

    if (keTiep.iNgay > traVeSoNgay(keTiep.iThang, keTiep.iNam))
    {
        keTiep.iNgay = 1;
        keTiep.iThang++;
        if (keTiep.iThang > 12)
        {
            keTiep.iThang = 1;
            keTiep.iNam++;
        }
    }
    return keTiep;
}
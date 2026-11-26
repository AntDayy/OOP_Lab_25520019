#include <iostream>
#include "GioPhutGiay.h"
#include <limits>

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
                cout << "Vui long nhap lai!\n";
        }
        else
        {
            cout << "Vui long chi nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return value;
}

/*
Ham kiem tra gio phut giay hop le
Gio hop le la gio tu 0 den 24
Phut giay hop le la phut giay tu 0 den 60
*/
bool kiemTraHopLe(int gio, int phut, int giay)
{
    if (gio < 0 || gio >= 24 || phut < 0 || phut >= 60 || giay < 0 || giay >= 60)
        return false;

    return true;
}

/*
Ham nhap gio phut giay
Kiem tra nguoi dung co nhap gio phut giay hop le hay khong
Neu khong hop le thi bat nhap lai
Neu nhap dung thi break
*/
void GioPhutGiay::Nhap()
{
    while (1)
    {
        iGio = kiemTraNhap("Nhap gio: ");
        iPhut = kiemTraNhap("Nhap phut: ");
        iGiay = kiemTraNhap("Nhap giay: ");

        if (kiemTraHopLe(iGio, iPhut, iGiay))
            break;
        else
            cout << "Gio phut giay ban nhap khong hop le. Vui long nhap lai!\n";
    }
}

/*
Ham xuat gio phut giay duoi dang gio:phut:giay
Neu gio phut hoac giay < 0 thi khi xuat them so 0 dang truoc (03:06:36)
*/
void GioPhutGiay::Xuat()
{
    cout << (iGio < 10 ? "0" : "") << iGio << ":"
         << (iPhut < 10 ? "0" : "") << iPhut << ":"
         << (iGiay < 10 ? "0" : "") << iGiay << endl;
}

/*
Ham tinh gio phut giay sau khi them 1 giay
Cong giay hien tai them 1
Neu giay >= 60 thi cho giay = 0, cong phut them 1
Neu phut >= 60 thi cho phut = 0, cong gio them 1
Neu gio == 24 thi cho gio = 0
*/
GioPhutGiay GioPhutGiay::TinhCongThemMotGiay()
{
    GioPhutGiay next;
    next.iGio = iGio;
    next.iPhut = iPhut;
    next.iGiay = iGiay + 1;

    if (next.iGiay >= 60)
    {
        next.iGiay = 0;
        next.iPhut++;
        if (next.iPhut >= 60)
        {
            next.iPhut = 0;
            next.iGio++;
        }
        if (next.iGio == 24)
            next.iGio = 0;
    }

    return next;
}
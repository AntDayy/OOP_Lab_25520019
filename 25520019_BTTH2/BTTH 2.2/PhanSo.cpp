#include <iostream>
#include <limits>
#include "PhanSo.h"
using namespace std;

// Ham tim UCLN
int timUCLN(int a, int b)
{
    if (b == 0)
        return a;
    return timUCLN(b, a % b);
}

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
Ham nhap phan so
Kiem tra nguoi dung co nhap mau so = 0 hay khong
Neu nguoi dung nhap sai thi bat nhap lai
Nhap dung thi thoat vong lap while (true)
*/
void PhanSo::Nhap()
{
    iTu = kiemTraNhap("Nhap tu so: ");

    while (1)
    {
        iMau = kiemTraNhap("Nhap mau so: ");

        if (iMau == 0)
            cout << "Mau so khong duoc bang 0. Vui long nhap lai mau so!\n";
        else
            break;
    }
}

// Ham xuat phan so
void PhanSo::Xuat()
{
    cout << iTu << "/" << iMau;
}

/*
Ham rut gon phan so
Tim UCLN cuar tu so va mau so
Lay tu so va mau so chia cho UCLN
Neu mau so < 0 thi chuyen dau ve tu
*/
void PhanSo::RutGon()
{
    int ucln = timUCLN(abs(iTu), abs(iMau));
    iTu /= ucln;
    iMau /= ucln;

    if (iMau < 0)
    {
        iTu = -iTu;
        iMau = -iMau;
    }
}

/*
Ham tinh tong giua hai phan so
Quy dong len roi thuc hien phep tinh cong
Rut gon truoc khi return ve ket qua
*/
PhanSo PhanSo::tinhTong(PhanSo &ps)
{
    PhanSo kq;
    kq.iTu = iTu * ps.iMau + ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

/*
Ham tinh hieu giua hai phan so
Quy dong len roi thuc hien phep tinh tru
Rut gon truoc khi return ve ket qua
*/
PhanSo PhanSo::tinhHieu(PhanSo &ps)
{
    PhanSo kq;
    kq.iTu = iTu * ps.iMau - ps.iTu * iMau;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

/*
Ham tinh tich giua hai phan so
Tich giua hai phan so ta lay tu nhan tu, mau nhan mau
Rut gon truoc khi return ve ket qua
*/
PhanSo PhanSo::tinhTich(PhanSo &ps)
{
    PhanSo kq;
    kq.iTu = iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.RutGon();
    return kq;
}

/*
Ham tinh thuong giua hai phan so
Thuong giua hai phan so ta lay phan so A nhan cho nghich dao phan so B
Rut gon truoc khi return ve ket qua
*/
PhanSo PhanSo::tinhThuong(PhanSo &ps)
{
    PhanSo kq;
    kq.iTu = iTu * ps.iMau;
    kq.iMau = iMau * ps.iTu;
    kq.RutGon();
    return kq;
}

/*
Ham so sanh hai phan so
Nhan cheo hai phan so
Return ve 1 neu A > B
          0     A = B
          -1    A < B
*/
int PhanSo::SoSanh(PhanSo ps)
{
    int left = iTu * ps.iMau;
    int right = ps.iTu * iMau;

    if (left > right)
        return 1;
    if (left == right)
        return 0;
    return -1;
}
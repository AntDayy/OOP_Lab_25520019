#include <iostream>
#include "SoPhuc.h"
#include <limits>
#include <cmath>

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

// Ham nhap so phuc
void SoPhuc::Nhap()
{
    iThuc = kiemTraNhap("Nhap phan thuc: ");
    iAo = kiemTraNhap("Nhap phan ao: ");
}

/*
Ham xuat so phuc
Neu phan thuc va phan ao = 0 thi cout 0 sau do thoat ham luon
Phan nao bang 0 thi khong xuat phan do
Xuat dau cua phan thuc
*/
void SoPhuc::Xuat()
{
    if (iThuc == 0 && iAo == 0)
    {
        cout << 0;
        return;
    }

    if (iThuc != 0)
    {
        cout << iThuc;
    }

    if (iAo != 0)
    {
        if (iThuc != 0)
        {
            if (iAo > 0)
                cout << " + " << iAo << "i";
            else
                cout << " - " << -iAo << "i";
        }
        else
        {
            cout << iAo << "i";
        }
    }
}

/*
Ham tinh tong giua hai so phuc
Tong cua hai so phuc la phan thuc cong voi phan thuc va phan ao cong voi phan ao
*/
SoPhuc SoPhuc::TinhTong(const SoPhuc &sp)
{
    SoPhuc tong;

    tong.iThuc = sp.iThuc + iThuc;
    tong.iAo = sp.iAo + iAo;

    return tong;
}

/*
Ham tinh hieu giua hai so phuc
Hieu cua hai so phuc la phan thuc tru phan thuc va phan ao tru phan ao
*/
SoPhuc SoPhuc::TinhHieu(const SoPhuc &sp)
{
    SoPhuc hieu;

    hieu.iThuc = iThuc - sp.iThuc;
    hieu.iAo = iAo - sp.iAo;

    return hieu;
}

/*
Ham tinh tich giua hai so phuc
Tich cua hai so phuc ta lay so phuc A nhan phan phoi voi so phuc B
*/
SoPhuc SoPhuc::TinhTich(const SoPhuc &sp)
{
    SoPhuc tich;

    tich.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
    tich.iAo = iThuc * sp.iAo + iAo * sp.iThuc;

    return tich;
}

// Ham tim UCLN
int timUCLN(int a, int b)
{
    if (b == 0)
        return a;
    return timUCLN(b, a % b);
}

/*
Ham tinh thuong giua hai so phuc
Vi day la phep chia nen ta can dua phan thuc va phan ao cua ket qua ve dang phan so
Tim mau, neu mau = 0 thi thoat ham ngay lap tuc
Tim tu thuc, mau thuc, tu ao va mau ao, UCLN thuc va UCLN ao
Rut gon va chuyen dau ve tu neu mau thuc < 0 va neu mau ao < 0
Neu tu thuc va tu ao = 0 thi cout 0 va thoat ham lap tuc
Thuc hien xuat giong ham xuat
*/
void SoPhuc::TinhThuong(const SoPhuc &sp)
{
    int mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;

    if (mau == 0)
    {
        cout << "LOI: Mau khong duoc bang 0";
        return;
    }

    int tuThuc = iThuc * sp.iThuc + iAo * sp.iAo;
    int tuAo = iAo * sp.iThuc - iThuc * sp.iAo;

    int uclnThuc = timUCLN(abs(tuThuc), abs(mau));
    int tuThucRutGon = tuThuc / uclnThuc;
    int mauThucRutGon = mau / uclnThuc;

    int uclnAo = timUCLN(abs(tuAo), abs(mau));
    int tuAoRutGon = tuAo / uclnAo;
    int mauAoRutGon = mau / uclnAo;

    if (mauThucRutGon < 0)
    {
        tuThucRutGon = -tuThucRutGon;
        mauThucRutGon = -mauThucRutGon;
    }
    if (mauAoRutGon < 0)
    {
        tuAoRutGon = -tuAoRutGon;
        mauAoRutGon = -mauAoRutGon;
    }

    if (tuThucRutGon == 0)
    {
        if (tuAoRutGon == 0)
        {
            cout << "0";
            return;
        }
    }
    else if (mauThucRutGon == 1)
    {
        cout << tuThucRutGon;
    }
    else
    {
        cout << tuThucRutGon << "/" << mauThucRutGon;
    }

    if (tuAoRutGon != 0)
    {
        if (tuThucRutGon != 0 && tuAoRutGon > 0)
            cout << " + ";
        if (tuThucRutGon != 0 && tuAoRutGon < 0)
        {
            cout << " - ";
            tuAoRutGon = -tuAoRutGon;
        }
        else if (tuAoRutGon < 0 && tuThucRutGon == 0)
        {
            cout << "-";
            tuAoRutGon = -tuAoRutGon;
        }

        if (mauAoRutGon == 1)
        {
            if (tuAoRutGon == 1)
                cout << "i";
            else
                cout << tuAoRutGon << "i";
        }
        else
        {
            cout << tuAoRutGon << "/" << mauAoRutGon << "i";
        }
    }
}
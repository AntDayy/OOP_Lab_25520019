#include <iostream>
#include <limits>
#include "CongTy.h"
#include "NhanVien.h"
#include "LapTrinhVien.h"
#include "KiemChungVien.h"

using namespace std;

// Kiểm tra nhập số nguyên hợp lệ
int kiemTraNhapCT(const string &prompt)
{
    int val;
    while (1)
    {
        cout << prompt;
        if (cin >> val)  // Kiểm tra nhập thành công
        {
            if (cin.peek() == '\n')  // Kiểm tra kết thúc bằng Enter
                break;
            else  // Có ký tự phụ sau số
            {
                cout << "[!] Loi. Vui long nhap lai!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else  // Nhập thất bại
        {
            cout << "[!] Loi. Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return val;
}

CongTy::CongTy() {}

CongTy::~CongTy()
{
    for (NhanVien *nv : ds)
        delete nv;
}

// Nhập danh sách nhân viên từ bàn phím
void CongTy::Nhap()
{
    int soNV;
    soNV = kiemTraNhapCT("Nhap so nhan vien trong cong ty: ");

    for (int i = 0; i < soNV; i++)
    {
        NhanVien *nv = nullptr;
        cout << "Nhap nhan vien thu " << i + 1 << "!\n";
        
        // Chọn loại nhân viên
        int luaChon;
        luaChon = kiemTraNhapCT("Chon loai nhan vien (1: Lap trinh vien, 2: Kiem chung vien): ");

        if (luaChon == 1)  // Lập trình viên
            nv = new LapTrinhVien();
        else if (luaChon == 2)  // Kiểm chứng viên
            nv = new KiemChungVien();
        else  // Lựa chọn không hợp lệ
        {
            cout << "Lua chon khong hop le. Vui long nhap lai!\n";
            i--;  // Nhập lại lần này
            continue;
        }

        nv->nhap();        // Nhập thông tin nhân viên
        nv->tinhLuong();   // Tính lương
        ds.push_back(nv);  // Thêm vào danh sách
    }
}

// Xuất toàn bộ danh sách nhân viên
void CongTy::Xuat()
{
    for (NhanVien *nv : ds)  // Duyệt qua tất cả nhân viên
        nv->xuat();  // Xuất thông tin từng nhân viên
}

// Xuất danh sách nhân viên có lương dưới trung bình
void CongTy::xuatDSNVCoLuongTBThap()
{
    if (ds.empty())  // Kiểm tra danh sách rỗng
    {
        cout << "Danh sach rong!\n";
        return;
    }

    // Tính lương trung bình
    double tongLuong = 0;
    int soNV = 0;
    for (NhanVien *nv : ds)
    {
        tongLuong += nv->getLuong();
        soNV++;
    }
    double luongTB = (double)tongLuong / soNV;

    // Xuất nhân viên có lương dưới TB
    for (NhanVien *nv : ds)
    {
        if (nv->getLuong() < luongTB)
            nv->xuat();
    }
}

// Xuất nhân viên có lương cao nhất
void CongTy::xuatNVLuongCaoNhat()
{
    NhanVien *NV = nullptr;
    double maxLuong = -1;

    // Tìm nhân viên có lương cao nhất
    for (NhanVien *nv : ds)
    {
        if (nv->getLuong() > maxLuong)
        {
            maxLuong = nv->getLuong();
            NV = nv;
        }
    }

    if (NV == nullptr)
        cout << "Khong ton tai nhan vien co luong cao nhat!\n";
    else
        NV->xuat();
}

// Xuất nhân viên có lương thấp nhất
void CongTy::xuatNVLuongThapNhat()
{
    if (ds.empty())  // Kiểm tra danh sách rỗng
    {
        cout << "Danh sach rong!\n";
        return;
    }

    NhanVien *NV = nullptr;
    double minLuong = ds[0]->getLuong();

    // Tìm nhân viên có lương thấp nhất
    for (NhanVien *nv : ds)
    {
        if (nv->getLuong() < minLuong)
        {
            minLuong = nv->getLuong();
            NV = nv;
        }
    }

    if (NV == nullptr)
        cout << "Khong ton tai nhan vien co luong thap nhat!\n";
    else
        NV->xuat();
}

// Xuất lập trình viên có lương cao nhất
void CongTy::xuatLTVLuongCaoNhat()
{
    NhanVien *cao = nullptr;
    double maxLuong = -1;

    // Tìm lập trình viên (getLoai() == 1) có lương cao nhất
    for (NhanVien *nv : ds)
    {
        if (nv->getLoai() == 1)  // Kiểm tra là lập trình viên
        {
            if (nv->getLuong() > maxLuong)
            {
                maxLuong = nv->getLuong();
                cao = nv;
            }
        }
    }

    if (cao == nullptr)
        cout << "Khong ton tai lap trinh vien co luong cao nhat!\n";
    else
        cao->xuat();
}

// Xuất kiểm chứng viên có lương thấp nhất
void CongTy::xuatKCVLuongThapNhat()
{
    if (ds.empty())  // Kiểm tra danh sách rỗng
    {
        cout << "Danh sach rong!\n";
        return;
    }

    NhanVien *thap = nullptr;
    double minLuong = ds[0]->getLuong();

    // Tìm kiểm chứng viên (getLoai() == 2) có lương thấp nhất
    for (NhanVien *nv : ds)
    {
        if (nv->getLoai() == 2)  // Kiểm tra là kiểm chứng viên
        {
            if (nv->getLuong() < minLuong)
            {
                minLuong = nv->getLuong();
                thap = nv;
            }
        }
    }

    if (thap == nullptr)
        cout << "Khong ton tai kiem chung vien co luong thap nhat!\n";
    else
        thap->xuat();
}
#include <iostream>
#include <limits>
#include "UIT.h"
#include "DaiHoc.h"
#include "CaoDang.h"

using namespace std;

// Kiểm tra nhập số nguyên hợp lệ
int kiemTraNhapUIT(const string &prompt)
{
    int val;
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

UIT::UIT() {}

UIT::~UIT()
{
    for (SinhVien *sv : ds)
        delete sv;
}

// Nhập danh sách sinh viên từ bàn phím
void UIT::Nhap()
{
    int soSV;
    // Nhập số sinh viên (phải > 0)
    while (1)
    {
        soSV = kiemTraNhapUIT("Nhap so sinh vien: ");
        if (soSV > 0)
            break;
        else
            cout << "Vui long nhap so sinh vien lon hon 0!\n";
    }

    // Nhập thông tin từng sinh viên
    for (int i = 0; i < soSV; i++)
    {
        int luaChon;
        SinhVien *sv = nullptr;
        cout << "Nhap sinh vien thu " << i + 1 << "!\n";

        // Chọn hệ sinh viên
        luaChon = kiemTraNhapUIT("Chon he sinh vien (1: He cao dang, 2: He dai hoc): ");

        if (luaChon == 1) // Cao Đẳng
            sv = new CaoDang();
        else if (luaChon == 2) // Đại Học
            sv = new DaiHoc();
        else // Lựa chọn không hợp lệ
        {
            cout << "Lua chon khong hop le. Vui long nhap lai!\n";
            i--; // Nhập lại lần này
            continue;
        }

        sv->nhap();       // Nhập thông tin sinh viên
        ds.push_back(sv); // Thêm vào danh sách
    }
}

// Xuất toàn bộ danh sách sinh viên
void UIT::Xuat()
{
    cout << "\n=== DANH SACH SINH VIEN UIT ===\n";
    for (SinhVien *sv : ds) // Duyệt qua tất cả sinh viên
        sv->xuat();         // Xuất thông tin từng sinh viên
}

// Xuất sinh viên đủ điều kiện tốt nghiệp
void UIT::xuatDSSVDuDKTotNghiep()
{
    cout << "\n=== DANH SACH SINH VIEN DU DIEU KIEN TOT NGHIEP ===\n";
    bool check = false;

    // Duyệt danh sách tìm sinh viên đủ điều kiện TN
    for (SinhVien *sv : ds)
    {
        if (sv->totNghiep()) // Kiểm tra điều kiện tốt nghiệp
        {
            sv->xuat();
            check = true;
        }
    }

    if (!check)
        cout << "Khong co sinh vien nao du dieu kien tot nghiep!\n";
}

// Xuất sinh viên không đủ điều kiện tốt nghiệp
void UIT::xuatDSSVKhongDuDKTotNghiep()
{
    cout << "\n=== DANH SACH SINH VIEN KHONG DU DIEU KIEN TOT NGHIEP ===\n";
    bool check = false;

    // Duyệt danh sách tìm sinh viên không đủ điều kiện TN
    for (SinhVien *sv : ds)
    {
        if (!sv->totNghiep()) // Kiểm tra điều kiện tốt nghiệp
        {
            sv->xuat();
            check = true;
        }
    }

    if (!check)
        cout << "Khong co sinh vien nao khong du dieu kien tot nghiep!\n";
}

// Xuất sinh viên Đại Học có DTB cao nhất
void UIT::xuatSVDHCoDTBCaoNhat()
{
    cout << "\n=== SINH VIEN HE DAI HOC CO DIEM TRUNG BINH CAO NHAT ===\n";
    SinhVien *maxSV = nullptr;
    double maxDiem = -1.0;

    // Tìm sinh viên Đại Học (getHe() == 2) có DTB cao nhất
    for (SinhVien *sv : ds)
    {
        if (sv->getHe() == 2) // Kiểm tra là Đại Học
        {
            if (sv->getDTB() > maxDiem) // Tìm DTB cao hơn
            {
                maxDiem = sv->getDTB();
                maxSV = sv;
            }
        }
    }

    if (maxSV == nullptr)
        cout << "Khong co sinh vien he dai hoc!\n";
    else
        maxSV->xuat();
}

// Xuất sinh viên Cao Đẳng có DTB cao nhất
void UIT::xuatSVCDCoDTBCaoNhat()
{
    cout << "\n=== SINH VIEN HE CAO DANG CO DIEM TRUNG BINH CAO NHAT ===\n";
    SinhVien *maxSV = nullptr;
    double maxDiem = -1.0;

    // Tìm sinh viên Cao Đẳng (getHe() == 1) có DTB cao nhất
    for (SinhVien *sv : ds)
    {
        if (sv->getHe() == 1) // Kiểm tra là Cao Đẳng
        {
            if (sv->getDTB() > maxDiem) // Tìm DTB cao hơn
            {
                maxDiem = sv->getDTB();
                maxSV = sv;
            }
        }
    }

    if (maxSV == nullptr)
        cout << "Khong co sinh vien he cao dang!\n";
    else
        maxSV->xuat();
}

// Đếm sinh viên mỗi loại không đủ điều kiện tốt nghiệp
void UIT::demSVMoiLoaiKhongDuDKTotNghiep()
{
    cout << "\n=== SO SINH VIEN MOI LOAI KHONG DU DIEU KIEN TOT NGHIEP ===\n";
    int demDH = 0; // Đếm Đại Học
    int demCD = 0; // Đếm Cao Đẳng

    // Duyệt danh sách đếm sinh viên không đủ điều kiện TN
    for (SinhVien *sv : ds)
    {
        if (!sv->totNghiep()) // Kiểm tra không đủ điều kiện TN
        {
            if (sv->getHe() == 1) // Cao Đẳng
                demCD++;
            else if (sv->getHe() == 2) // Đại Học
                demDH++;
        }
    }
    cout << "So sinh vien he cao dang: " << demCD << endl;
    cout << "So sinh vien he dai hoc: " << demDH << endl;
}
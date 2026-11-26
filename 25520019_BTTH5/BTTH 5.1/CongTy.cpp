#include <iostream>
#include <limits>
#include "CongTy.h"

using namespace std;

// Hàm hỗ trợ kiểm tra và ép buộc người dùng nhập đúng định dạng số nguyên
int kiemTraNhapCT(const string &prompt)
{
    int val;
    while (1) // Lặp cho đến khi nhập đúng
    {
        cout << prompt;
        if (cin >> val)
        {
            // Đảm bảo không có ký tự thừa (như chữ) phía sau số
            if (cin.peek() == '\n')
                break;
            else
                cout << "[!] Loi. Vui long nhap lai!\n";
        }
        else
        {
            // Xóa cờ lỗi và bỏ qua các ký tự sai trong bộ đệm nhập
            cout << "[!] Loi. Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return val;
}

// Constructor mặc định
CongTy::CongTy() {}

// Destructor: Giải phóng bộ nhớ động đã cấp phát cho các nhân viên
CongTy::~CongTy()
{
    for (NhanVien *nv : ds)
        delete nv;
}

// Hàm nhập danh sách số lượng và thông tin từng nhân viên
void CongTy::Nhap()
{
    int soNVSX;
    int soNVVP;

    // Yêu cầu nhập số lượng nhân viên phải là số không âm
    while (1)
    {
        soNVSX = kiemTraNhapCT("Nhap so nhan vien san xuat: ");
        soNVVP = kiemTraNhapCT("Nhap so nhan vien van phong: ");

        if (soNVSX < 0 || soNVVP < 0)
            cout << "Vui long nhap lai so nguyen duong!\n";
        else
            break;
    }

    // Nhập danh sách Nhân viên Sản xuất
    for (int i = 0; i < soNVSX; i++)
    {
        cout << "Nhap thong tin nhan vien san xuat thu " << i + 1 << " !\n";
        cin.ignore();
        NhanVien *nv = new NhanVienSX(); // Cấp phát động đối tượng NhanVienSX
        nv->nhap();                      // Gọi hàm nhập đa hình
        ds.push_back(nv);                // Thêm vào danh sách quản lý
    }

    // Nhập danh sách Nhân viên Văn phòng
    for (int i = 0; i < soNVVP; i++)
    {
        cout << "Nhap thong tin nhan vien van phong thu " << i + 1 << " !\n";
        cin.ignore();
        NhanVien *nv = new NhanVienVP(); // Cấp phát động đối tượng NhanVienVP
        nv->nhap();                      // Gọi hàm nhập đa hình
        ds.push_back(nv);                // Thêm vào danh sách quản lý
    }
}

// Hàm xuất danh sách toàn bộ nhân viên
void CongTy::Xuat()
{
    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    for (NhanVien *nv : ds)
        nv->xuat(); // Gọi hàm xuất đa hình
}

// Hàm tính tổng số tiền lương công ty phải trả
long long CongTy::tongLuong()
{
    long long tong = 0;
    for (NhanVien *nv : ds)
        tong += nv->getLuong();
    return tong;
}

// Hàm tìm và in ra nhân viên có mức lương thấp nhất
void CongTy::timLuongThapNhat()
{
    if (ds.empty())
    {
        cout << "Danh sach trong!\n";
        return;
    }

    // Giả sử nhân viên đầu tiên có lương thấp nhất
    NhanVien *nvMinLuong = ds[0];
    for (NhanVien *nv : ds)
    {
        if (nv->getLuong() < nvMinLuong->getLuong())
            nvMinLuong = nv; // Cập nhật nếu tìm thấy người có lương thấp hơn
    }
    cout << "\n=== NHAN VIEN CO LUONG THAP NHAT ===\n";
    nvMinLuong->xuat();
    cout << endl;
}

// Hàm tìm và in ra nhân viên lớn tuổi nhất (sinh vào ngày/tháng/năm nhỏ nhất)
void CongTy::timTuoiCaoNhat()
{
    if (ds.empty())
    {
        cout << "Danh sach trong!\n";
        return;
    }

    // Giả sử nhân viên đầu tiên lớn tuổi nhất
    NhanVien *nvTuoiCaoNhat = ds[0];
    for (NhanVien *nv : ds)
    {
        // So sánh năm sinh
        if (nv->getNam() < nvTuoiCaoNhat->getNam())
            nvTuoiCaoNhat = nv;
        else if (nv->getNam() == nvTuoiCaoNhat->getNam())
        {
            // Nếu năm sinh bằng nhau, so sánh tháng sinh
            if (nv->getThang() < nvTuoiCaoNhat->getThang())
                nvTuoiCaoNhat = nv;
            else if (nv->getThang() == nvTuoiCaoNhat->getThang())
            {
                // Nếu tháng sinh bằng nhau, so sánh ngày sinh
                if (nv->getNgay() < nvTuoiCaoNhat->getNgay())
                    nvTuoiCaoNhat = nv;
            }
        }
    }
    cout << "\n=== NHAN VIEN CO TUOI CAO NHAT ===\n";
    nvTuoiCaoNhat->xuat();
}
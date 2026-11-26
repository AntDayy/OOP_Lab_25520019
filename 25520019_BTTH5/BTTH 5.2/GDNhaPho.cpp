#include <iostream>
#include "GDNhaPho.h"

using namespace std;

// Hàm khởi tạo mặc định cho GDNhaPho
GDNhaPho::GDNhaPho()
{
    this->loaiNha = "";
    this->diaChi = "";
}

// Hàm khởi tạo có tham số cho GDNhaPho
GDNhaPho::GDNhaPho(string nha, string diachi)
{
    this->loaiNha = nha;
    this->diaChi = diachi;
}

// Hàm hủy GDNhaPho
GDNhaPho::~GDNhaPho() {}

// Hàm nhập thông tin riêng cho giao dịch Nhà Phố
void GDNhaPho::nhap()
{
    GiaoDich::nhap(); // Nhập thông tin chung từ lớp cha
    cin.ignore();     // Xóa bộ đệm trước khi nhập chuỗi dữ liệu chuỗi tiếp theo

    // Ràng buộc nhập đúng định dạng loại nhà (chấp nhận cả chữ hoa lẫn chữ thường)
    while (1)
    {
        cout << "Nhap loai nha (cao cap/thuong): ";
        getline(cin, loaiNha);

        // Xóa khoảng trắng ở đầu và cuối chuỗi
        loaiNha.erase(0, loaiNha.find_first_not_of(" \t\r\n"));
        loaiNha.erase(loaiNha.find_last_not_of(" \t\r\n") + 1);

        // Chuyển sang chữ thường để so sánh
        string loaiNhaLower = loaiNha;
        for (char &c : loaiNhaLower)
            c = tolower(c);

        if (loaiNhaLower == "cao cap" || loaiNhaLower == "thuong")
        {
            loaiNha = loaiNhaLower; // Lưu dạng chữ thường cho tính tiền
            break;
        }
        else
            cout << "[!] Loai nha khong hop le. Vui long nhap lai (cao cap/thuong)!\n";
    }

    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

// Hàm xuất thông tin chi tiết giao dịch Nhà Phố
void GDNhaPho::xuat()
{
    GiaoDich::xuat(); // Xuất thông tin chung
    cout << '\t' << loaiNha << '\t' << diaChi << endl;
}

// Hàm tính thành tiền cho giao dịch Nhà Phố
void GDNhaPho::tinhThanhTien()
{
    // Nhà cao cấp: tính 100% giá trị (diện tích * đơn giá)
    if (loaiNha == "cao cap")
        this->tien = dienTich * gia;
    // Nhà thường: được giảm 10% (nhân hệ số 0.9)
    else
        this->tien = dienTich * gia * 0.9;
}

// Trả về số định danh loại giao dịch Nhà Phố là 2
int GDNhaPho::getLoai()
{
    return 2;
}
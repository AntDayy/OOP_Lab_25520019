#include <iostream>
#include "GDDat.h"

using namespace std;

// Hàm khởi tạo mặc định cho GDDat
GDDat::GDDat()
{
    this->loaiDat = "";
}

// Hàm khởi tạo có tham số cho GDDat
GDDat::GDDat(string ld)
{
    this->loaiDat = ld;
}

// Hàm hủy GDDat
GDDat::~GDDat() {}

// Hàm nhập thông tin riêng cho giao dịch Đất
void GDDat::nhap()
{
    GiaoDich::nhap(); // Gọi hàm nhập của lớp cha để lấy thông tin chung
    cin.ignore();     // Xóa ký tự xuống dòng thừa trong bộ đệm trước khi dùng getline

    // Vòng lặp ràng buộc chỉ nhận loại đất là A, B hoặc C
    while (1)
    {
        cout << "Nhap loai dat (A/B/C): ";
        getline(cin, loaiDat);

        // Xóa khoảng trắng ở đầu và cuối chuỗi
        loaiDat.erase(0, loaiDat.find_first_not_of(" \t\r\n"));
        loaiDat.erase(loaiDat.find_last_not_of(" \t\r\n") + 1);

        // Chuyển sang chữ hoa để so sánh
        for (char &c : loaiDat)
            c = toupper(c);

        if (loaiDat == "A" || loaiDat == "B" || loaiDat == "C")
            break;
        else
            cout << "[!] Loai dat khong hop le. Vui long nhap lai (A/B/C)!\n";
    }
}

// Hàm xuất thông tin giao dịch Đất
void GDDat::xuat()
{
    GiaoDich::xuat();                // Xuất thông tin chung từ lớp cha
    cout << '\t' << loaiDat << endl; // Xuất thêm loại đất
}

// Hàm tính thành tiền cho giao dịch Đất dựa trên loại đất
void GDDat::tinhThanhTien()
{
    // Đất loại A: thành tiền = diện tích * đơn giá * 1.5
    if (loaiDat == "A")
        this->tien = dienTich * gia * 1.5;
    // Đất loại B, C: thành tiền = diện tích * đơn giá
    else
        this->tien = dienTich * gia;
}

// Trả về số định danh loại giao dịch Đất là 1
int GDDat::getLoai()
{
    return 1;
}
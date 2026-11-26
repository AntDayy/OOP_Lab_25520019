#include <iostream>
#include "KhachHang.h"

using namespace std;

// Constructor mặc định - khởi tạo tất cả giá trị bằng 0 hoặc xâu rỗng
KhachHang::KhachHang()
{
    this->ten = "";
    this->soHang = 0;
    this->gia = 0.0;
    this->tienTra = 0.0;
}

// Constructor có tham số - khởi tạo với tên, số lượng, giá
// Lưu ý: tienTra sẽ được tính sau bằng hàm tinhTien()
KhachHang::KhachHang(string t, int s, double g)
{
    this->ten = t;
    this->soHang = s;
    this->gia = g;
}

KhachHang::~KhachHang() {}

// Hàm nhập thông tin khách hàng từ bàn phím
// - Nhập tên (có thể có khoảng trắng)
// - Nhập số lượng hàng
// - Nhập giá từng sản phẩm
void KhachHang::nhap()
{
    cin.ignore();            // Xóa ký tự newline còn lại trong buffer
    getline(cin, this->ten); // Nhập tên (cho phép khoảng trắng)
    cin >> soHang >> gia;    // Nhập số lượng và giá
}

// Hàm hiển thị thông tin khách hàng
// - Hiển thị tên khách hàng
// - Hiển thị số tiền phải trả (đã tính qua hàm tinhTien)
void KhachHang::xuat()
{
    cout << this->ten << endl;     // In tên
    cout << this->tienTra << endl; // In số tiền phải trả
}

// Hàm ảo tính tiền (hàm cơ sở đặt tienTra = 0)
// Các lớp con sẽ override hàm này để tính tiền theo quy tắc riêng
void KhachHang::tinhTien()
{
    this->tienTra = 0.0;
}

// Hàm getter - trả về số tiền khách hàng phải trả
double KhachHang::getTien()
{
    return this->tienTra;
}
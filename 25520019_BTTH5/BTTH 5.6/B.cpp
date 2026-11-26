#include <iostream>
#include <algorithm>
#include "B.h"
#include "KhachHang.h"

using namespace std;

// Constructor mặc định - khởi tạo năm thân thiết = 0
B::B()
{
    this->namThanThiet = 0.0;
}

// Constructor có tham số - khởi tạo với năm thân thiết
B::B(double k)
{
    this->namThanThiet = k;
}

// Destructor
B::~B() {}

// Nhập thông tin khách hàng thân thiết
// - Gọi hàm nhập cơ sở từ lớp KhachHang
// - Nhập thêm năm thân thiết
void B::nhap()
{
    // Nhập tên, số lượng, giá từ lớp cha
    KhachHang::nhap();
    // Nhập thêm số năm là khách hàng thân thiết
    cin >> this->namThanThiet;
}

// Tính tiền khách hàng thân thiết
// Công thức: tienTra = (số lượng * giá) * (1 - min(năm * 0.05, 0.5)) * 1.1
// Giảm giá: 5% mỗi năm (tối đa 50% mỗi háng) + 10% VAT
void B::tinhTien()
{
    // Tính hệ số giảm giá: mỗi năm giảm 5%, tối đa 50%
    double heSoGiam = 1 - min(this->namThanThiet * 0.05, 0.5);
    // Giá sau giảm + 10% VAT
    this->tienTra = (this->soHang * this->gia) * heSoGiam * 1.1;
}
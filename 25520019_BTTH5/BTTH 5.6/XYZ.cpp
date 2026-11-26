#include <iostream>
#include "XYZ.h"
#include "A.h"
#include "B.h"
#include "C.h"

using namespace std;

// Constructor của lớp XYZ
XYZ::XYZ() {}

// Destructor của lớp XYZ
// Giải phóng bộ nhớng của tất cả các con trỏ khách hàng
XYZ::~XYZ()
{
    // Xóa từng khách hàng trong danh sách
    for (KhachHang *k : ds)
        delete k;
}

// Nhập danh sách khách hàng
// - Nhập số lượng khách hàng loại A (thường)
// - Nhập số lượng khách hàng loại B (thân thiết)
// - Nhập số lượng khách hàng loại C (VIP)
void XYZ::Nhap()
{
    int x, y, z; // Số lượng khách hàng loại A, B, C
    cin >> x >> y >> z;

    // Nhập x khách hàng loại A
    for (int i = 0; i < x; i++)
    {
        KhachHang *k = new A(); // Tạo khách hàng A
        k->nhap();              // Nhập thông tin
        k->tinhTien();          // Tính tiền
        ds.push_back(k);        // Thêm vào danh sách
    }

    // Nhập y khách hàng loại B
    for (int i = 0; i < y; i++)
    {
        KhachHang *k = new B(); // Tạo khách hàng B
        k->nhap();              // Nhập thông tin (văn bản đã nãn đó: năm thân thiết)
        k->tinhTien();          // Tính tiền
        ds.push_back(k);        // Thêm vào danh sách
    }

    // Nhập z khách hàng loại C
    for (int i = 0; i < z; i++)
    {
        KhachHang *k = new C(); // Tạo khách hàng C
        k->nhap();              // Nhập thông tin
        k->tinhTien();          // Tính tiền
        ds.push_back(k);        // Thêm vào danh sách
    }
}

// Hiển thị thông tin tất cả khách hàng
void XYZ::Xuat()
{
    for (KhachHang *k : ds)
        k->xuat(); // Gọi hàm xuat() của từng khách hàng
}

// Tính tổng số tiền thu được từ tất cả khách hàng
double XYZ::tongTienThuDuoc()
{
    double sum = 0; // Biến tích lũy
    for (KhachHang *k : ds)
        sum += k->getTien(); // Cộng tiền của từng khách hàng
    return sum;
}
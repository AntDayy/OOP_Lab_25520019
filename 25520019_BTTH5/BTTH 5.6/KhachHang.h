#ifndef KHACHHANG_H
#define KHACHHANG_H
#include <iostream>

using namespace std;

// Lớp cơ sở đại diện cho khách hàng
class KhachHang
{
protected:
    string ten;     // Tên khách hàng
    int soHang;     // Số lượng hàng
    double gia;     // Giá từng sản phẩm
    double tienTra; // Số tiền khách hàng phải trả

public:
    // Constructor mặc định - khởi tạo các giá trị bằng 0
    KhachHang();
    // Constructor có tham số - khởi tạo với tên, số lượng, giá
    KhachHang(string t, int s, double g);
    // Destructor
    ~KhachHang();

    // Hàm ảo để nhập thông tin khách hàng (có thể được override)
    virtual void nhap();
    // Hàm hiển thị thông tin khách hàng
    void xuat();
    // Hàm ảo để tính tiền (được override ở các lớp con)
    virtual void tinhTien();

    // Hàm trả về số tiền khách hàng phải trả
    double getTien();
};

#endif
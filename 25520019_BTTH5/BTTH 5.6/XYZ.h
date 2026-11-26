#ifndef XYZ_H
#define XYZ_H
#include "KhachHang.h"
#include <vector>

// Lớp XYZ: Đại diện cho cửa hàng, quản lý danh sách khách hàng
class XYZ
{
private:
    vector<KhachHang *> ds; // Danh sách con trỏ đến các khách hàng

public:
    XYZ();
    ~XYZ();

    // Hàm nhập số lượng khách hàng từng loại (A, B, C)
    void Nhap();
    // Hàm hiển thị thông tin tất cả khách hàng
    void Xuat();
    // Hàm tính tổng tiền thu được từ tất cả khách hàng
    double tongTienThuDuoc();
};

#endif
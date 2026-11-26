#include <iostream>
#include "XYZ.h"

using namespace std;

// Chương trình chính - Tính tiền bán hàng của cửa hàng
int main()
{
    XYZ ds; // Tạo đối tượng đại diện cho cửa hàng

    // Nhập danh sách khách hàng
    ds.Nhap();

    // Hiển thị thông tin tất cả khách hàng
    ds.Xuat();

    // Tính và in tổng số tiền thu được
    cout << ds.tongTienThuDuoc() << endl;

    return 0;
}
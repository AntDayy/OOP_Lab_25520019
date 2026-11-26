#ifndef B_H
#define B_H
#include "KhachHang.h"

// Lớp B: Khách hàng thân thiết (được giảm giá dựa vào năm thân thiết)
class B : public KhachHang
{
private:
    double namThanThiet; // Số năm khách hàng là thân thiết

public:
    B();
    B(double k);
    ~B();

    // Override: Nhập thêm số năm thân thiết
    void nhap() override;
    // Override: Tính tiền với giảm giá (tối đa 50%, cộng 10% VAT)
    void tinhTien() override;
};

#endif
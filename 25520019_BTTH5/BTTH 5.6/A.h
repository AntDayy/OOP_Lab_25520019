#ifndef A_H
#define A_H
#include "KhachHang.h"

// Lớp A: Khách hàng thường (tính tiền = số lượng * giá * 1.1)
class A : public KhachHang
{
public:
    A();
    ~A();

    // Override: Tính tiền khách hàng thường (cộng 10% VAT)
    void tinhTien() override;
};

#endif
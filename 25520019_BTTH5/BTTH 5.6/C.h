#ifndef C_H
#define C_H
#include "KhachHang.h"

// Lớp C: Khách hàng VIP (được giảm 50% giá, cộng 10% VAT)
class C : public KhachHang
{
public:
    C();
    ~C();

    // Override: Tính tiền khách hàng VIP (giảm 50%, cộng 10% VAT)
    void tinhTien() override;
};

#endif
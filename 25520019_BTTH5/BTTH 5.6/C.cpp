#include <iostream>
#include "C.h"

using namespace std;

// Constructor lớp C
C::C() {}

// Destructor lớp C
C::~C() {}

// Tính tiền khách hàng VIP
// Công thức: tienTra = số lượng * giá * 0.5 * 1.1
// Giảm 50% giá + 10% VAT
void C::tinhTien()
{
    // Tính giá sau giảm 50% và cộng 10% VAT
    this->tienTra = this->soHang * this->gia * 0.5 * 1.1;
}
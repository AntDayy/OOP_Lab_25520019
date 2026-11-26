#include <iostream>
#include "A.h"

using namespace std;

// Constructor lớp A
A::A() {}

// Destructor lớp A
A::~A() {}

// Tính tiền khách hàng thường
// Công thức: tienTra = số lượng * giá * 1.1 (cộng 10% VAT)
void A::tinhTien()
{
    // Tính tổng giá hàng + 10% VAT
    this->tienTra = this->soHang * this->gia * 1.1;
}
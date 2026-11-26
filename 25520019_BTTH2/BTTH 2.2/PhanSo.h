#ifndef PHANSO_H
#define PHANSO_H

class PhanSo
{
private:
    int iTu;
    int iMau;

public:
    void Nhap();
    void Xuat();
    void RutGon();

    PhanSo tinhTong(PhanSo &ps);
    PhanSo tinhHieu(PhanSo &ps);
    PhanSo tinhTich(PhanSo &ps);
    PhanSo tinhThuong(PhanSo &ps);

    int SoSanh(PhanSo ps); // 1: >, 0: =, -1: <
};

#endif

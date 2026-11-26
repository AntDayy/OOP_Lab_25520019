#ifndef SOPHUC_H
#define SOPHUC_H

class SoPhuc
{
private:
    int iThuc;
    int iAo;

public:
    void Nhap();
    void Xuat();

    SoPhuc TinhTong(const SoPhuc &sp);
    SoPhuc TinhHieu(const SoPhuc &sp);
    SoPhuc TinhTich(const SoPhuc &sp);
    void TinhThuong(const SoPhuc &sp);
};

#endif

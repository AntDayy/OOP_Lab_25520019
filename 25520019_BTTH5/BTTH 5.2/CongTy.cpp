#include <iostream>
#include <limits>
#include "CongTy.h"
#include "GDDat.h"
#include "GDNhaPho.h"
#include "GDCanHoChungCu.h"

using namespace std;

// Hàm hỗ trợ kiểm tra và nhập số nguyên hợp lệ riêng cho lớp Công Ty
int kiemTraNhapCT(const string &prompt)
{
    int val;
    while (1)
    {
        cout << prompt;
        if (cin >> val)
        {
            if (cin.peek() == '\n')
                break;
            else
                cout << "[!] Loi. Vui long nhap lai!\n";
        }
        else
        {
            cout << "[!] Loi. Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return val;
}

// Hàm khởi tạo mặc định lớp Công ty
CongTy::CongTy() {}

// Hàm hủy lớp Công ty nhằm giải phóng các vùng nhớ động đã cấp phát bằng từ khóa `new`
CongTy::~CongTy()
{
    // Duyệt qua từng con trỏ giao dịch trong vector để delete giải phóng bộ nhớ
    for (GiaoDich *gd : ds)
        delete gd;
}

// Hàm nhập danh sách các giao dịch vào hệ thống công ty
void CongTy::Nhap()
{
    int soGD;
    // Ràng buộc số lượng giao dịch phải lớn hơn 0
    while (1)
    {
        soGD = kiemTraNhapCT("Nhap so giao dich: ");

        if (soGD < 1)
            cout << "Vui long nhap so giao dich > 0";
        else
            break;
    }

    // Vòng lặp nhập chi tiết cho từng giao dịch
    for (int i = 0; i < soGD; i++)
    {
        int luaChon;
        GiaoDich *gd = nullptr; // Con trỏ lớp cha dùng để quản lý lớp con
        cout << "Nhap giao dich thu " << i + 1 << "!\n";
        luaChon = kiemTraNhapCT("Chon loai giao dich (1: Dat, 2: Nha pho, 3: Can ho chung cu): ");

        // Khởi tạo đối tượng tương ứng dựa trên lựa chọn (Áp dụng tính Đa hình)
        if (luaChon == 1)
            gd = new GDDat();
        else if (luaChon == 2)
            gd = new GDNhaPho();
        else if (luaChon == 3)
            gd = new GDCanHoChungCu();
        else
        {
            cout << "Lua chon khong hop le. Vui long nhap lai loai giao dich!\n";
            i--; // Giảm chỉ số i để nhập lại lượt này
            continue;
        }

        gd->nhap();          // Gọi hàm nhập tương ứng của loại bds đó
        gd->tinhThanhTien(); // Tính tiền ngay sau khi nhập xong dữ liệu số
        ds.push_back(gd);    // Thêm con trỏ vào danh sách quản lý
    }
}

// Hàm tính toán và in ra số lượng của từng loại giao dịch trong danh sách
void CongTy::tinhSoLuongTungLoai()
{
    int demDat = 0;
    int demNhaPho = 0;
    int demChungCu = 0;

    // Duyệt danh sách, kiểm tra mã loại của từng giao dịch để tăng biến đếm
    for (GiaoDich *gd : ds)
    {
        int loai = gd->getLoai();

        if (loai == 1)
            demDat++;
        else if (loai == 2)
            demNhaPho++;
        else if (loai == 3)
            demChungCu++;
    }

    cout << "\n=== SO LUONG TUNG LOAI GIAO DICH ===\n";
    cout << "So giao dich dat: " << demDat << endl;
    cout << "So giao dich nha pho: " << demNhaPho << endl;
    cout << "So giao dich can ho chung cu: " << demChungCu << endl;
}

// Hàm tính trung bình cộng thành tiền của riêng các giao dịch Căn hộ chung cư
void CongTy::tinhTrungBinhThanhTienChungCu()
{
    long long tongTien = 0;
    int soGiaoDichChungCu = 0;

    // Lọc và tích lũy tổng tiền từ các giao dịch chung cư (loại == 3)
    for (GiaoDich *gd : ds)
    {
        if (gd->getLoai() == 3)
        {
            soGiaoDichChungCu++;
            tongTien += gd->getTien();
        }
    }

    // Trường hợp danh sách không chứa căn hộ chung cư nào
    if (soGiaoDichChungCu == 0)
    {
        cout << "Khong co giao dich can ho chung cu trong danh sach!\n";
        return;
    }

    // Ép kiểu double để phép chia không bị mất phần thập phân
    cout << "\n Trung binh thanh tien cua giao dich can ho chung cu: " << (double)tongTien / soGiaoDichChungCu << endl;
}

// Hàm tìm và xuất thông tin của giao dịch Nhà Phố có thành tiền lớn nhất
void CongTy::timGDNhaPhoThanhTienCaoNhat()
{
    GiaoDich *gdnp = nullptr; // Con trỏ lưu vết giao dịch đắt nhất tìm được
    long long maxTien = 0;    // Biến lưu giá trị tiền cao nhất hiện tại

    // Duyệt danh sách tìm nhà phố (loại == 2) sở hữu mức tiền cao nhất
    for (GiaoDich *gd : ds)
    {
        if (gd->getLoai() == 2)
        {
            if (gd->getTien() > maxTien)
            {
                maxTien = gd->getTien();
                gdnp = gd; // Cập nhật con trỏ trỏ tới giao dịch lớn nhất
            }
        }
    }

    // Nếu không tìm thấy bất kỳ giao dịch nhà phố nào
    if (gdnp == nullptr)
    {
        cout << "Khong co giao dich nha pho trong danh sach!\n";
        return;
    }

    cout << "\n=== GIAO DICH NHA PHO CO THANH TIEN CAO NHAT ===\n";
    gdnp->xuat(); // Xuất thông tin chi tiết của giao dịch đắt nhất đó
}

// Hàm lọc và xuất toàn bộ danh sách giao dịch diễn ra vào Tháng 12 năm 2024
void CongTy::xuatDSGDThang12Nam2024()
{
    int count = 0; // Biến đếm số lượng giao dịch thỏa mãn điều kiện
    cout << "\n=== DANH SACH GIAO GICH TRONG THANG 12 NAM 2024 ===\n";

    // Duyệt qua mọi giao dịch và so sánh tháng, năm
    for (GiaoDich *gd : ds)
    {
        if (gd->getThang() == 12 && gd->getNam() == 2024)
        {
            gd->xuat();
            count++;
        }
    }

    // Nếu sau khi duyệt hết danh sách mà count vẫn bằng 0
    if (count == 0)
        cout << "Khong co giao dich nao trong thang 12 nam 2024 ca!\n";
}
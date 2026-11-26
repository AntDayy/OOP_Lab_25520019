#include <iostream>
#include "GiaoDich.h"
#include <limits>

using namespace std;

// Hàm hỗ trợ kiểm tra và nhập số nguyên (long long) hợp lệ
long long kiemTraNhap(const string &prompt)
{
    long long val;
    while (1)
    {
        cout << prompt;
        // Kiểm tra luồng nhập có thành công và đúng kiểu dữ liệu không
        if (cin >> val)
        {
            if (cin.peek() == '\n') // Đảm bảo không có ký tự thừa phía sau
                break;
            else
                cout << "[!] Loi. Vui long nhap lai!\n";
        }
        else
        {
            cout << "[!] Loi. Vui long nhap lai!\n";
            cin.clear();                                         // Xóa trạng thái lỗi của cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm nhập thừa
        }
    }
    return val;
}

// Hàm hỗ trợ kiểm tra và nhập số thực (double) hợp lệ
double kiemTraNhapDouble(const string &prompt)
{
    double val;
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

// Hàm kiểm tra năm nhuận
bool isNamNhuan(int nam)
{
    // Năm nhuận chia hết cho 400 hoặc chia hết cho 4 nhưng không chia hết cho 100
    return (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0));
}

// Hàm trả về số ngày tối đa trong một tháng của một năm cụ thể
int traVeSoNgay(int thang, int nam)
{
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        // Nếu là năm nhuận thì tháng 2 có 29 ngày, ngược lại 28 ngày
        return isNamNhuan(nam) ? 29 : 28;
    default:
        return 0;
    }
}

// Hàm kiểm tra tính hợp lệ của bộ ngày, tháng, năm
bool kiemTraNgayHopLe(int ngay, int thang, int nam)
{
    // Ngày phải nằm trong khoảng từ 1 đến số ngày tối đa của tháng đó, tháng từ 1-12, năm > 0
    if (ngay < 1 || ngay > traVeSoNgay(thang, nam) || thang < 1 || thang > 12 || nam < 1)
        return false;
    return true;
}

// Hàm khởi tạo mặc định cho GiaoDich
GiaoDich::GiaoDich()
{
    this->maGD = 0;
    this->ngay = 1;
    this->thang = 1;
    this->nam = 1;
    this->gia = 0.0;
    this->dienTich = 0.0;
    this->tien = 0.0;
}

// Hàm khởi tạo đầy đủ tham số cho GiaoDich
GiaoDich::GiaoDich(int ma, int ngay, int thang, int nam, long long gia, double s)
{
    this->maGD = ma;
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
    this->gia = gia;
    this->dienTich = s;
    this->tien = 0.0; // Thành tiền sẽ được tính sau khi nhập xong thông tin
}

// Hàm hủy của lớp GiaoDich
GiaoDich::~GiaoDich() {}

// Hàm nhập thông tin chung của một giao dịch
void GiaoDich::nhap()
{
    maGD = kiemTraNhap("Nhap ma giao dich: ");

    // Vòng lặp yêu cầu nhập ngày tháng năm cho đến khi hợp lệ
    while (1)
    {
        ngay = kiemTraNhap("Nhap ngay giao dich: ");
        thang = kiemTraNhap("Nhap thang giao dich: ");
        nam = kiemTraNhap("Nhap nam giao dich: ");

        if (kiemTraNgayHopLe(ngay, thang, nam))
            break;
        else
            cout << "Ngay thang nam khong hop le. Vui long nhap lai!\n";
    }

    // Yêu cầu đơn giá phải lớn hơn 0
    while (1)
    {
        gia = kiemTraNhap("Nhap don gia: ");

        if (gia <= 0)
            cout << "Vui long nhap don gia lon hon 0!\n";
        else
            break;
    }

    // Yêu cầu diện tích phải lớn hơn 0
    while (1)
    {
        dienTich = kiemTraNhapDouble("Nhap dien tich: ");

        if (dienTich <= 0)
            cout << "Vui long nhap dien tich lon hon 0!\n";
        else
            break;
    }
}

// Hàm xuất các thông tin chung của giao dịch
void GiaoDich::xuat()
{
    cout << maGD << '\t' << ngay << "/" << thang << "/" << nam << '\t' << gia << '\t' << dienTich;
}

// Hàm tính thành tiền mặc định (sẽ được ghi đè ở lớp con)
void GiaoDich::tinhThanhTien()
{
    this->tien = 0.0;
}

// Hàm lấy loại giao dịch mặc định
int GiaoDich::getLoai()
{
    return 0;
}

// Hàm lấy giá trị thành tiền
long long GiaoDich::getTien()
{
    return tien;
}

// Hàm lấy tháng giao dịch
int GiaoDich::getThang()
{
    return thang;
}

// Hàm lấy năm giao dịch
int GiaoDich::getNam()
{
    return nam;
}
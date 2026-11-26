#ifndef GIAODICH_H
#define GIAODICH_H

// Lớp cơ sở trừu tượng đại diện cho một Giao Dịch nói chung
class GiaoDich
{
protected:
    int maGD;             // Mã giao dịch
    int ngay, thang, nam; // Ngày, tháng, năm giao dịch
    long long gia;        // Đơn giá
    double dienTich;      // Diện tích bds
    long long tien;       // Thành tiền sau khi tính toán

public:
    // Hàm khởi tạo không tham số
    GiaoDich();

    // Hàm khởi tạo có tham số
    GiaoDich(int ma, int ngay, int thang, int nam, long long gia, double s);

    // Hàm hủy ảo để giải phóng vùng nhớ chính xác ở các lớp con
    virtual ~GiaoDich();

    // Hàm nhập thông tin giao dịch (ảo để lớp con ghi đè)
    virtual void nhap();

    // Hàm xuất thông tin giao dịch (ảo để lớp con ghi đè)
    virtual void xuat();

    // Hàm tính thành tiền theo công thức riêng của từng loại bds
    virtual void tinhThanhTien();

    // Hàm trả về loại giao dịch (1: Đất, 2: Nhà phố, 3: Chung cư)
    virtual int getLoai();

    // Các hàm Getter lấy giá trị thuộc tính
    long long getTien();
    int getThang();
    int getNam();
};

#endif
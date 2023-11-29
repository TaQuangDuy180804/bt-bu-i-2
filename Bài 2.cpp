#include <iostream>
#include <string>

using namespace std;

class DichVu {
private:
    int maDV;
    string tenDV;
    float giaCuoc;

public:
    DichVu() : maDV(0), tenDV(""), giaCuoc(0.0) {}

    void Nhap() {
        cout << "Nhap ma dich vu: ";
        cin >> maDV;
        cout << "Nhap ten dich vu: ";
        cin.ignore();
        getline(cin, tenDV);
        cout << "Nhap gia cuoc: ";
        cin >> giaCuoc;
    }

    void Xuat() const {
        cout << "Ma dich vu: " << maDV << ", Ten dich vu: " << tenDV << ", Gia cuoc: " << giaCuoc;
    }

    float LayGiaCuoc() const {
        return giaCuoc;
    }
};

class Nguoi {
private:
    string hoTen, diaChi, soDT;

public:
    Nguoi() : hoTen(""), diaChi(""), soDT("") {}

    void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap so dien thoai: ";
        cin >> soDT;
    }

    void Xuat() const {
        cout << "Ho ten: " << hoTen << ", Dia chi: " << diaChi << ", So dien thoai: " << soDT;
    }
};

class KhachHang : public Nguoi {
private:
    int soLuongDichVu;
    DichVu dv[100];

public:
    KhachHang() : soLuongDichVu(0) {}

    void Nhap() {
        Nguoi::Nhap();

        cout << "Nhap so luong dich vu da su dung: ";
        cin >> soLuongDichVu;

        for (int i = 0; i < soLuongDichVu; ++i) {
            cout << "Nhap thong tin dich vu thu " << i + 1 << ":\n";
            dv[i].Nhap();
        }
    }

    void Xuat() const {
        Nguoi::Xuat();

        cout << "\nCac dich vu da su dung:\n";
        for (int i = 0; i < soLuongDichVu; ++i) {
            dv[i].Xuat();
            cout << endl;
        }
    }

    float TongGiaCuoc() const {
        float tongGiaCuoc = 0.0;
        for (int i = 0; i < soLuongDichVu; ++i) {
            tongGiaCuoc += dv[i].LayGiaCuoc();
        }
        return tongGiaCuoc * 2; // Tổng gia cuoc = 2 lần tổng giá cước các dịch vụ
    }
};

int main() {
    // Nhập thông tin một người
    Nguoi nguoi;
    cout << "Nhap thong tin nguoi:\n";
    nguoi.Nhap();

    // Hiển thị thông tin người đó ra màn hình
    cout << "\nThong tin nguoi:\n";
    nguoi.Xuat();

    // Nhập thông tin của một khách hàng
    KhachHang khachHang;
    cout << "\nNhap thong tin khach hang:\n";
    khachHang.Nhap();

    // Hiển thị thông tin của khách hàng và dịch vụ khách hàng đã sử dụng
    cout << "\nThong tin khach hang va cac dich vu da su dung:\n";
    khachHang.Xuat();

    // Tính và hiển thị tổng gia cước khách hàng đã sử dụng
    cout << "\nTong gia cuoc khach hang da su dung: " << khachHang.TongGiaCuoc() << endl;

    return 0;
}

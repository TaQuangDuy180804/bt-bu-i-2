#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class DATE {
private:
    int ngay, thang, nam;

public:
    DATE() {
        ngay = 1;
        thang = 1;
        nam = 2000;
    }

    void nhap() {
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }

    void xuat() const {
        cout << ngay << "/" << thang << "/" << nam << endl;
    }

    int getNam() const {
        return nam;
    }
};

class MUONTRA : public DATE {
private:
    int maDocGia, maSach, soLuong;

public:
    static int soCauMuonTra;

    MUONTRA() {
        maDocGia = 0;
        maSach = 0;
        soLuong = 0;
    }

    void nhap() {
        cout << "Nhap ma doc gia: ";
        cin >> maDocGia;
        cout << "Nhap ma sach: ";
        cin >> maSach;
        DATE::nhap();
        cout << "Nhap so luong: ";
        cin >> soLuong;
        soCauMuonTra += soLuong;
    }

    void xuat() const {
        cout << "Ma doc gia: " << maDocGia << endl;
        cout << "Ma sach: " << maSach << endl;
        DATE::xuat();
        cout << "So luong: " << soLuong << endl;
    }

    static int tinhTongSoLuongMuonTra() {
        return soCauMuonTra;
    }

    int getMaDocGia() const {
        return maDocGia;
    }
};

int MUONTRA::soCauMuonTra = 0;

int main() {
    int n;
    cout << "Nhap so luong MUONTRA: ";
    cin >> n;

    vector<MUONTRA> danhSachMuonTra(n);

    // Nhập thông tin các MUONTRA
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin MUONTRA thu " << i + 1 << endl;
        danhSachMuonTra[i].nhap();
    }

    // In ra thông tin các MUONTRA
    cout << "Thong tin MUONTRA:" << endl;
    for (const auto& muontra : danhSachMuonTra) {
        muontra.xuat();
    }

    // Hiển thị độc giả mượn trước ngày 1/1/2020
    cout << "Doc gia muon truoc 1/1/2020: " << endl;
    for (const auto& muontra : danhSachMuonTra) {
        if (muontra.getNam() < 2020) {
            cout << muontra.getMaDocGia() << endl;
        }
    }

    // Tìm mã độc giả có số tiền cược nhiều nhất
    int maxSoLuong = numeric_limits<int>::min();
    int maDocGiaMax = -1;
    for (const auto& muontra : danhSachMuonTra) {
        if (muontra.tinhTongSoLuongMuonTra() > maxSoLuong) {
            maxSoLuong = muontra.tinhTongSoLuongMuonTra();
            maDocGiaMax = muontra.getMaDocGia();
        }
    }

    cout << "Doc gia co so tien muon nhieu nhat: " << maDocGiaMax << endl;

    return 0;
}

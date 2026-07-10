#include "CheckOut.h"

void checkOut(vector<Phong>& dsPhong) {
    int soPhong;
    wcout << L"Nhập số phòng muốn Check-out: ";
    wcin >> soPhong;

    for (auto& phong : dsPhong) {
        if (phong.soPhong == soPhong) {
            if (!phong.daDat) {
                wcout << RED << L"Phòng này đang trống!\n" << RESET;
                return;
            }
            double tienPhong = phong.giaPhong * phong.soNgayO;
            double tongTien = tienPhong + phong.tienDichVu;

            wcout << YELLOW << L"\n========================================\n";
            wcout << L"           HÓA ĐƠN THANH TOÁN           \n";
            wcout << L"========================================\n" << RESET;
            wcout << left << setw(18) << L"Phòng:" << phong.soPhong << L" (" << phong.loaiPhong << L")\n";
            wcout << left << setw(18) << L"Khách hàng:" << phong.khach.ten << L"\n";
            wcout << left << setw(18) << L"Số ngày ở:" << phong.soNgayO << L" ngày\n";
            wcout << L"----------------------------------------\n";
            wcout << fixed << setprecision(0);
            wcout << left << setw(22) << L"Tiền phòng:" << setw(12) << right << tienPhong << L" VND\n";
            wcout << left << setw(22) << L"Tiền dịch vụ:" << setw(12) << right << phong.tienDichVu << L" VND\n";
            wcout << L"----------------------------------------\n";
            wcout << RED << left << setw(22) << L"TỔNG CỘNG:" << setw(12) << right << tongTien << L" VND\n" << RESET;
            wcout << YELLOW << L"========================================\n" << RESET;

            phong.daDat = false; phong.khach = KhachHang(); phong.tienDichVu = 0; phong.soNgayO = 0;
            return;
        }
    }
    wcout << RED << L"Không tìm thấy phòng!\n" << RESET;
}

void ghiFile(const vector<Phong>& dsPhong, const string& filename) {
    wofstream f(filename);
    f.imbue(locale("")); 
    if (!f.is_open()) return;
    for (const auto& p : dsPhong) {
        f << p.soPhong << L"," << p.loaiPhong << L"," << p.giaPhong << L"," << p.daDat << L",";
        if (p.daDat) f << p.khach.ten << L"," << p.khach.cccd << L"," << p.khach.sdt << L",";
        else f << L"None,None,None,";
        f << p.tienDichVu << L"," << p.soNgayO << L"\n";
    }
    f.close();
    wcout << GREEN << L"Đã lưu dữ liệu thành công!\n" << RESET;
}

void docFile(vector<Phong>& dsPhong, const string& filename) {
    wifstream f(filename);
    f.imbue(locale(""));
    if (!f.is_open()) return;
    dsPhong.clear(); Phong p;
    while (f >> p.soPhong) {
        f.ignore(); getline(f, p.loaiPhong, L',');
        f >> p.giaPhong; f.ignore();
        f >> p.daDat; f.ignore();
        getline(f, p.khach.ten, L',');
        getline(f, p.khach.cccd, L',');
        getline(f, p.khach.sdt, L',');
        f >> p.tienDichVu; f.ignore();
        f >> p.soNgayO; f.ignore();
        dsPhong.push_back(p);
    }
    f.close();
    wcout << GREEN << L"Đã tải dữ liệu khách sạn.\n" << RESET;
}

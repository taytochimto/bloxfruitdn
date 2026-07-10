#include "CheckIn.h"

// Hàm quan trọng: Ngăn app bị văng (crash) nếu người dùng nhập chữ vào ô nhập số
int nhapSoNguyenSafe() {
    int value;
    while (true) {
        wcin >> value;
        if (wcin.fail()) {
            wcin.clear(); // Xóa cờ lỗi
            wcin.ignore(10000, L'\n'); // Dọn dẹp bộ nhớ đệm
            wcout << RED << L"Lỗi! Vui lòng chỉ nhập SỐ: " << RESET;
        } else {
            wcin.ignore(10000, L'\n');
            return value;
        }
    }
}

void checkIn(vector<Phong>& dsPhong) {
    wcout << L"Nhập số phòng muốn Check-in: ";
    int soPhong = nhapSoNguyenSafe();

    for (auto& phong : dsPhong) {
        if (phong.soPhong == soPhong) {
            if (phong.daDat) {
                wcout << RED << L"Phòng này đã có người ở!\n" << RESET;
                return;
            }
            wcout << L"Nhập tên khách hàng: ";
            getline(wcin, phong.khach.ten);
            wcout << L"Nhập CCCD: ";
            getline(wcin, phong.khach.cccd);
            wcout << L"Nhập Số Điện Thoại: ";
            getline(wcin, phong.khach.sdt);
            wcout << L"Nhập số ngày dự kiến ở: ";
            phong.soNgayO = nhapSoNguyenSafe();

            phong.daDat = true;
            wcout << GREEN << L"Check-in phòng " << soPhong << L" thành công!\n" << RESET;
            return;
        }
    }
    wcout << RED << L"Số phòng không tồn tại!\n" << RESET;
}
